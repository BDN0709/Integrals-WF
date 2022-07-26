#pragma once

#define NULL 0

// �������� ���������� �� ������ �������� ������� �� ���������� ���������, �� ������ ����� �������� �������� �������
// � ��� ������ ���������� ��
System::Void CalculateInter::MyForm::button_DO_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (OKinputValues())  // ���� ������� �������� ��������� ��������� "true", ����� ����� ��� ���������� �������
	{
		// ������� ������� (��������� ��� �������������� �����������)
		chart->Series[0]->Points->Clear();
		chart->Series[1]->Points->Clear();

		// �������� � ������� ������ ������� ������� 
		label_a->Text = "a";
		label_b->Text = "b";
		label_integrFunction->Text = "f(x)dx";

		// "�������" ��������� ������� � ���� ������ ������������:
		double a = Convert::ToDouble(textBox_a->Text), b = Convert::ToDouble(textBox_b->Text);

		if (b < a)
		{
			MessageBox::Show("ʳ���� ������ �� ���� ���� �������� ����� �� ���� �������!", "�������!",
				MessageBoxButtons::OK, MessageBoxIcon::Error);

			return;
		}
		else if (b == a)
		{  // � �������, ���� ������� ������ ������������ = ���� ������ ������������, ���� ���������� ������ � �����.
			//  �� �� ����� ������ ���������� ����������, ������� �� ���������� ����� �������� = 0. �������� ��:
			label_a->Text = textBox_a->Text;
			label_b->Text = textBox_b->Text;
			label_integrFunction->Text = comboBox_integrFunction->SelectedItem->ToString() + "dx = 0";

			chart->Series[0]->Points->AddXY(a, a);  // ������ ������������ ��� ��������� ��������� ���������� �� �����

			return;
		}
		else
		{ // ���� ���� �������� ����� ���: 

			int N = Convert::ToInt64(numeric_NumSegments->Value); // ������� ������� ������� ������������ 

			double accuracy = pow(10, -Convert::ToInt64(numeric_accuracy->Value)); // ���������� ������� 

			double h = (b - a) / N;  // ���������� ����

			std::vector <MyPoint> points;  // ��������� ������ ����� ��� �������

			// �� ������ ��� �������� �� ������� ������� �����. ���������, �� ���� ������� ���� ��������� ���������, 
			// ��� �������� ���� � �����:
			float Integral = CalculateIntegral(Functions(comboBox_integrFunction->SelectedIndex),
				Methods(comboBox_methodIntegr->SelectedIndex), a, b, h, accuracy, points);

			// ��������� ������� �����
			for (int i = 0; i < points.size(); i++)
			{
				// ������ ������ ������� �� ���������� �������
				chart->Series[0]->Points->AddXY(points.at(i).Graphic.x, points.at(i).Graphic.y);

				// ���� ����� ��������� �������� - ������ �������� ������������� ������ ������������
				if (points.at(i).Explanation.x != NULL && points.at(i).Explanation.y != NULL)
					chart->Series[1]->Points->AddXY(points.at(i).Explanation.x, points.at(i).Explanation.y);
			}

			// ��������� ���������� �� ��������� �� �������� ���������:
			label_a->Text = textBox_a->Text;
			label_b->Text = textBox_b->Text;
			label_integrFunction->Text = comboBox_integrFunction->SelectedItem->ToString() + "dx = " + Integral;
		}
	}

	return System::Void();
}

// ������� - ���� ������, �� �������� �� �������� ��������� �� ���������� �����
bool CalculateInter::MyForm::OKinputValues()
{

	// ���� �������� ����������

	if (textBox_a->Text == "" && textBox_b->Text == "")
	{
		MessageBox::Show("������ ������� �� ����� ������ ������������!", "�������!",
			MessageBoxButtons::OK, MessageBoxIcon::Error);

		return false;
	}
	else
	{
		if (textBox_a->Text == "")
		{
			MessageBox::Show("������ ������� ������ ������������!", "�������!",
				MessageBoxButtons::OK, MessageBoxIcon::Error);

			return false;
		}
		else if (textBox_b->Text == "")
		{
			MessageBox::Show("������ ����� ������ ������������!", "�������!",
				MessageBoxButtons::OK, MessageBoxIcon::Error);

			return false;
		}
		else
		{
			for (int i = 0; i < textBox_a->Text->Length; i++)
			{
				if (((textBox_a->Text[i] < '0' || textBox_a->Text[i] > '9') && textBox_a->Text[i] != ',' && textBox_a->Text[i] != '-') || textBox_a->Text[i] == '.')
				{
					MessageBox::Show("� ���� ������� ������ ������������ ������� ���������� ���!", "�������!",
						MessageBoxButtons::OK, MessageBoxIcon::Error);

					return false;
				}
				if (i == textBox_a->Text->Length - 1 && textBox_a->Text[i] == '-')
				{
					MessageBox::Show("�������� �������� ������� ������ ������������ �� ���� ������������ ������ \"-\"!", "�������!",
						MessageBoxButtons::OK, MessageBoxIcon::Error);

					return false;
				}
			}
			for (int i = 0; i < textBox_b->Text->Length; i++)
			{
				if (((textBox_b->Text[i] < '0' || textBox_b->Text[i] > '9') && textBox_b->Text[i] != ',' && textBox_b->Text[i] != '-') || textBox_b->Text[i] == '.')
				{
					MessageBox::Show("� ���� ���� ������ ������������ ������� ���������� ���!", "�������!",
						MessageBoxButtons::OK, MessageBoxIcon::Error);

					return false;
				}
				if (i == textBox_b->Text->Length - 1 && textBox_b->Text[i] == '-')
				{
					MessageBox::Show("�������� �������� ���� ������ ������������ �� ���� ������������ ������ \"-\"!", "�������!",
						MessageBoxButtons::OK, MessageBoxIcon::Error);

					return false;
				}
			}
		}
	}

	// ���� �������� ������ ������������ �������

	if (comboBox_integrFunction->SelectedItem == nullptr)
	{
		MessageBox::Show("������ ������������ �������!", "�������!",
			MessageBoxButtons::OK, MessageBoxIcon::Error);

		return false;
	}

	// ���� �������� ������ ������ ������������

	if (comboBox_methodIntegr->SelectedItem == nullptr)
	{
		MessageBox::Show("������ ����� ������������!", "�������!",
			MessageBoxButtons::OK, MessageBoxIcon::Error);

		return false;
	}

	// ���� �������� ���������� ����� � ������� ������������ ������ ѳ������

	if (comboBox_methodIntegr->SelectedIndex == Simpsons && numeric_NumSegments->Value % 2 != 0)
	{
		MessageBox::Show("��� ����, ��� ������������ ������� ѳ������, ������� ������� ������������ ������� ���� ������!"
			, "�����!", MessageBoxButtons::OK, MessageBoxIcon::Warning);

		return false;
	}

	// �� �������� ��������:

	return true;
}

// �������� ���������� �� ������ "�����"
System::Void CalculateInter::MyForm::�����ToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (MessageBox::Show("�� �������, �� ������ �����?", "�����!", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == Windows::Forms::DialogResult::Yes)
		Application::Exit();

	return System::Void();
}