#pragma once

#define NULL 0

// обробник натискання на кнопку побудови графіка та обчислення інтеграла, що делегує логіку програми відповідній функції
// а сам виконує оформлення ІК
System::Void CalculateInter::MyForm::button_DO_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (OKinputValues())  // якщо функція перевірки повернула значенння "true", тобто вхідні дані відповідають вимогам
	{
		// чистимо графіки (необхідно при багаторазовому використанні)
		chart->Series[0]->Points->Clear();
		chart->Series[1]->Points->Clear();

		// записуємо у відповідні лейбли загальні відомості 
		label_a->Text = "a";
		label_b->Text = "b";
		label_integrFunction->Text = "f(x)dx";

		// "парсимо" значенння початку і кінця відрізка інтегрування:
		double a = Convert::ToDouble(textBox_a->Text), b = Convert::ToDouble(textBox_b->Text);

		if (b < a)
		{
			MessageBox::Show("Кінець відрізка не може бути чисельно менше за його початок!", "Помилка!",
				MessageBoxButtons::OK, MessageBoxIcon::Error);

			return;
		}
		else if (b == a)
		{  // у випадку, коли початок відрізка інтегрування = кінцю відрізка інтегрування, маємо вироджений відрізок у точку.
			//  Не має сенсу робити математичні обчислення, оскільки за означенням такий інтеграл = 0. Запишемо це:
			label_a->Text = textBox_a->Text;
			label_b->Text = textBox_b->Text;
			label_integrFunction->Text = comboBox_integrFunction->SelectedItem->ToString() + "dx = 0";

			chart->Series[0]->Points->AddXY(a, a);  // будуємо псевдографік для уникнення відсутності зображення на ньому

			return;
		}
		else
		{ // якщо маємо правильні вхідні дані: 

			int N = Convert::ToInt64(numeric_NumSegments->Value); // зчитуємо кількість проміжків інтегрування 

			double accuracy = pow(10, -Convert::ToInt64(numeric_accuracy->Value)); // обчислюємо точність 

			double h = (b - a) / N;  // обчислюємо крок

			std::vector <MyPoint> points;  // створюємо список точок для графіка

			// усі зчитані дані передаємо на обробку функції логіки. Результат, що вона поверне буде значенням інтеграла, 
			// тож заносимо його у змінну:
			float Integral = CalculateIntegral(Functions(comboBox_integrFunction->SelectedIndex),
				Methods(comboBox_methodIntegr->SelectedIndex), a, b, h, accuracy, points);

			// ітеруємось списком точок
			for (int i = 0; i < points.size(); i++)
			{
				// будуємо графік функції за отриманими точками
				chart->Series[0]->Points->AddXY(points.at(i).Graphic.x, points.at(i).Graphic.y);

				// якщо точки пояснення визначені - будуємо графічне представлення методу інтегрування
				if (points.at(i).Explanation.x != NULL && points.at(i).Explanation.y != NULL)
					chart->Series[1]->Points->AddXY(points.at(i).Explanation.x, points.at(i).Explanation.y);
			}

			// оновлюємо інформацію на інтерфейсі та виводимо результат:
			label_a->Text = textBox_a->Text;
			label_b->Text = textBox_b->Text;
			label_integrFunction->Text = comboBox_integrFunction->SelectedItem->ToString() + "dx = " + Integral;
		}
	}

	return System::Void();
}

// функція - член классу, що перевіряє усі елементи керування на коректність даних
bool CalculateInter::MyForm::OKinputValues()
{

	// блок перевірки текстбоксів

	if (textBox_a->Text == "" && textBox_b->Text == "")
	{
		MessageBox::Show("Введіть початок та кінець відрізка інтегрування!", "Помилка!",
			MessageBoxButtons::OK, MessageBoxIcon::Error);

		return false;
	}
	else
	{
		if (textBox_a->Text == "")
		{
			MessageBox::Show("Введіть початок відрізка інтегрування!", "Помилка!",
				MessageBoxButtons::OK, MessageBoxIcon::Error);

			return false;
		}
		else if (textBox_b->Text == "")
		{
			MessageBox::Show("Введіть кінець відрізка інтегрування!", "Помилка!",
				MessageBoxButtons::OK, MessageBoxIcon::Error);

			return false;
		}
		else
		{
			for (int i = 0; i < textBox_a->Text->Length; i++)
			{
				if (((textBox_a->Text[i] < '0' || textBox_a->Text[i] > '9') && textBox_a->Text[i] != ',' && textBox_a->Text[i] != '-') || textBox_a->Text[i] == '.')
				{
					MessageBox::Show("У поле початку відрізка інтегрування введено недопустимі дані!", "Помилка!",
						MessageBoxButtons::OK, MessageBoxIcon::Error);

					return false;
				}
				if (i == textBox_a->Text->Length - 1 && textBox_a->Text[i] == '-')
				{
					MessageBox::Show("Чисельне значення початку відрізка інтегрування не може закінчуватися знаком \"-\"!", "Помилка!",
						MessageBoxButtons::OK, MessageBoxIcon::Error);

					return false;
				}
			}
			for (int i = 0; i < textBox_b->Text->Length; i++)
			{
				if (((textBox_b->Text[i] < '0' || textBox_b->Text[i] > '9') && textBox_b->Text[i] != ',' && textBox_b->Text[i] != '-') || textBox_b->Text[i] == '.')
				{
					MessageBox::Show("У поле кінця відрізка інтегрування введено недопустимі дані!", "Помилка!",
						MessageBoxButtons::OK, MessageBoxIcon::Error);

					return false;
				}
				if (i == textBox_b->Text->Length - 1 && textBox_b->Text[i] == '-')
				{
					MessageBox::Show("Чисельне значення кінця відрізка інтегрування не може закінчуватися знаком \"-\"!", "Помилка!",
						MessageBoxButtons::OK, MessageBoxIcon::Error);

					return false;
				}
			}
		}
	}

	// блок перевірки вибору підінтегральної функції

	if (comboBox_integrFunction->SelectedItem == nullptr)
	{
		MessageBox::Show("Оберіть підінтегральну функцію!", "Помилка!",
			MessageBoxButtons::OK, MessageBoxIcon::Error);

		return false;
	}

	// блок перевірки вибору методу інтегрування

	if (comboBox_methodIntegr->SelectedItem == nullptr)
	{
		MessageBox::Show("Оберіть метод інтегрування!", "Помилка!",
			MessageBoxButtons::OK, MessageBoxIcon::Error);

		return false;
	}

	// блок перевірки коректності даних у випадку використання методу Сімпсона

	if (comboBox_methodIntegr->SelectedIndex == Simpsons && numeric_NumSegments->Value % 2 != 0)
	{
		MessageBox::Show("Для того, щоб скористатись методом Сімпсона, кількість проміжків інтегрування повинна бути парною!"
			, "Увага!", MessageBoxButtons::OK, MessageBoxIcon::Warning);

		return false;
	}

	// всі перевірки пройдено:

	return true;
}

// обробник натискання на кнопку "Вихід"
System::Void CalculateInter::MyForm::выходToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (MessageBox::Show("Ви впевнені, що хочете вийти?", "Увага!", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == Windows::Forms::DialogResult::Yes)
		Application::Exit();

	return System::Void();
}