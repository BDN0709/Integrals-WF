#pragma once

namespace CalculateInter 
{

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:


	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ выходToolStripMenuItem1;






	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::NumericUpDown^ numeric_NumSegments;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::ComboBox^ comboBox_methodIntegr;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::ComboBox^ comboBox_integrFunction;
	private: System::Windows::Forms::Button^ button_DO;
	private: System::Windows::Forms::TextBox^ textBox_a;
	private: System::Windows::Forms::TextBox^ textBox_b;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label_a;
	private: System::Windows::Forms::Label^ label_b;
	private: System::Windows::Forms::Label^ label_integrFunction;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::NumericUpDown^ numeric_accuracy;










	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Title^ title1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Title());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->выходToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->numeric_NumSegments = (gcnew System::Windows::Forms::NumericUpDown());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->comboBox_methodIntegr = (gcnew System::Windows::Forms::ComboBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->comboBox_integrFunction = (gcnew System::Windows::Forms::ComboBox());
			this->button_DO = (gcnew System::Windows::Forms::Button());
			this->textBox_a = (gcnew System::Windows::Forms::TextBox());
			this->textBox_b = (gcnew System::Windows::Forms::TextBox());
			this->chart = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label_a = (gcnew System::Windows::Forms::Label());
			this->label_b = (gcnew System::Windows::Forms::Label());
			this->label_integrFunction = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->numeric_accuracy = (gcnew System::Windows::Forms::NumericUpDown());
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numeric_NumSegments))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numeric_accuracy))->BeginInit();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->BackColor = System::Drawing::Color::Transparent;
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->выходToolStripMenuItem1 });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1435, 24);
			this->menuStrip1->TabIndex = 2;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// выходToolStripMenuItem1
			// 
			this->выходToolStripMenuItem1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Italic,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->выходToolStripMenuItem1->Name = L"выходToolStripMenuItem1";
			this->выходToolStripMenuItem1->Size = System::Drawing::Size(51, 20);
			this->выходToolStripMenuItem1->Text = L"Вихід";
			this->выходToolStripMenuItem1->Click += gcnew System::EventHandler(this, &MyForm::выходToolStripMenuItem1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(12, 47);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(284, 23);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Початок відрізка інтегрування:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(12, 99);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(271, 23);
			this->label3->TabIndex = 7;
			this->label3->Text = L"Кінець відрізка інтегрування:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(12, 153);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(315, 23);
			this->label4->TabIndex = 8;
			this->label4->Text = L"Кількість проміжків інтегрування:";
			// 
			// numeric_NumSegments
			// 
			this->numeric_NumSegments->BackColor = System::Drawing::SystemColors::ControlDark;
			this->numeric_NumSegments->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->numeric_NumSegments->Location = System::Drawing::Point(333, 153);
			this->numeric_NumSegments->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 276447231, 23283, 0, 0 });
			this->numeric_NumSegments->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numeric_NumSegments->Name = L"numeric_NumSegments";
			this->numeric_NumSegments->Size = System::Drawing::Size(81, 29);
			this->numeric_NumSegments->TabIndex = 9;
			this->numeric_NumSegments->ThousandsSeparator = true;
			this->numeric_NumSegments->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(12, 263);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(268, 23);
			this->label5->TabIndex = 10;
			this->label5->Text = L"Метод обчислення інтеграла:";
			// 
			// comboBox_methodIntegr
			// 
			this->comboBox_methodIntegr->BackColor = System::Drawing::SystemColors::ControlDark;
			this->comboBox_methodIntegr->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox_methodIntegr->DropDownWidth = 222;
			this->comboBox_methodIntegr->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->comboBox_methodIntegr->Font = (gcnew System::Drawing::Font(L"Times New Roman", 11.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->comboBox_methodIntegr->FormattingEnabled = true;
			this->comboBox_methodIntegr->ImeMode = System::Windows::Forms::ImeMode::Off;
			this->comboBox_methodIntegr->Items->AddRange(gcnew cli::array< System::Object^  >(5) {
				L"Метод лівих прямокутників", L"Метод центральних прямокутників",
					L"Метод правих прямокутників", L"Метод трапецій", L"Метод Сімпсона"
			});
			this->comboBox_methodIntegr->Location = System::Drawing::Point(286, 265);
			this->comboBox_methodIntegr->Name = L"comboBox_methodIntegr";
			this->comboBox_methodIntegr->Size = System::Drawing::Size(244, 25);
			this->comboBox_methodIntegr->TabIndex = 11;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label6->Location = System::Drawing::Point(12, 208);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(226, 23);
			this->label6->TabIndex = 12;
			this->label6->Text = L"Підінтегральна функція:";
			// 
			// comboBox_integrFunction
			// 
			this->comboBox_integrFunction->BackColor = System::Drawing::SystemColors::ControlDark;
			this->comboBox_integrFunction->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox_integrFunction->DropDownWidth = 222;
			this->comboBox_integrFunction->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->comboBox_integrFunction->Font = (gcnew System::Drawing::Font(L"Times New Roman", 11.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->comboBox_integrFunction->FormattingEnabled = true;
			this->comboBox_integrFunction->ImeMode = System::Windows::Forms::ImeMode::Off;
			this->comboBox_integrFunction->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"sin(x)", L"cos(x)", L"tg(x)", L"ctg(x)" });
			this->comboBox_integrFunction->Location = System::Drawing::Point(244, 210);
			this->comboBox_integrFunction->Name = L"comboBox_integrFunction";
			this->comboBox_integrFunction->Size = System::Drawing::Size(244, 25);
			this->comboBox_integrFunction->TabIndex = 13;
			// 
			// button_DO
			// 
			this->button_DO->AutoEllipsis = true;
			this->button_DO->BackColor = System::Drawing::SystemColors::ControlDark;
			this->button_DO->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->button_DO->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_DO->Location = System::Drawing::Point(16, 374);
			this->button_DO->Name = L"button_DO";
			this->button_DO->Size = System::Drawing::Size(595, 34);
			this->button_DO->TabIndex = 14;
			this->button_DO->Text = L"Обчислити інтеграл та побудувати графік функції\r\n\r\n";
			this->button_DO->UseVisualStyleBackColor = false;
			this->button_DO->Click += gcnew System::EventHandler(this, &MyForm::button_DO_Click);
			// 
			// textBox_a
			// 
			this->textBox_a->BackColor = System::Drawing::SystemColors::ControlDark;
			this->textBox_a->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox_a->Location = System::Drawing::Point(302, 46);
			this->textBox_a->Name = L"textBox_a";
			this->textBox_a->Size = System::Drawing::Size(86, 26);
			this->textBox_a->TabIndex = 15;
			this->textBox_a->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBox_b
			// 
			this->textBox_b->BackColor = System::Drawing::SystemColors::ControlDark;
			this->textBox_b->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox_b->Location = System::Drawing::Point(302, 99);
			this->textBox_b->Name = L"textBox_b";
			this->textBox_b->Size = System::Drawing::Size(86, 26);
			this->textBox_b->TabIndex = 16;
			this->textBox_b->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// chart
			// 
			this->chart->BorderlineWidth = 2;
			chartArea1->InnerPlotPosition->Auto = false;
			chartArea1->InnerPlotPosition->Height = 85.90832F;
			chartArea1->InnerPlotPosition->Width = 85.90832F;
			chartArea1->InnerPlotPosition->X = 11.60136F;
			chartArea1->InnerPlotPosition->Y = 3.80599F;
			chartArea1->Name = L"ChartArea1";
			this->chart->ChartAreas->Add(chartArea1);
			this->chart->Cursor = System::Windows::Forms::Cursors::Default;
			legend1->BackColor = System::Drawing::Color::White;
			legend1->DockedToChartArea = L"ChartArea1";
			legend1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 8));
			legend1->HeaderSeparator = System::Windows::Forms::DataVisualization::Charting::LegendSeparatorStyle::DashLine;
			legend1->IsDockedInsideChartArea = false;
			legend1->IsTextAutoFit = false;
			legend1->ItemColumnSpacing = 20;
			legend1->LegendStyle = System::Windows::Forms::DataVisualization::Charting::LegendStyle::Column;
			legend1->MaximumAutoSize = 44;
			legend1->Name = L"Legend";
			legend1->ShadowColor = System::Drawing::Color::Silver;
			legend1->TextWrapThreshold = 10;
			legend1->Title = L"Умовні позначення";
			legend1->TitleBackColor = System::Drawing::Color::White;
			legend1->TitleFont = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			legend1->TitleSeparator = System::Windows::Forms::DataVisualization::Charting::LegendSeparatorStyle::ThickLine;
			this->chart->Legends->Add(legend1);
			this->chart->Location = System::Drawing::Point(720, 27);
			this->chart->Name = L"chart";
			series1->BorderWidth = 3;
			series1->ChartArea = L"ChartArea1";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series1->Color = System::Drawing::Color::Red;
			series1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			series1->Legend = L"Legend";
			series1->Name = L"f(x)";
			series2->ChartArea = L"ChartArea1";
			series2->Color = System::Drawing::Color::CornflowerBlue;
			series2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			series2->Legend = L"Legend";
			series2->Name = L"Графічне представлення методу інтегрування";
			this->chart->Series->Add(series1);
			this->chart->Series->Add(series2);
			this->chart->Size = System::Drawing::Size(699, 289);
			this->chart->TabIndex = 17;
			this->chart->Text = L"chart";
			title1->BackColor = System::Drawing::Color::White;
			title1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			title1->Name = L"Title1";
			title1->Text = L"Графік функції та графічне представлення методу інтегрування";
			this->chart->Titles->Add(title1);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(718, 364);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(36, 55);
			this->label1->TabIndex = 18;
			this->label1->Text = L"∫";
			// 
			// label_a
			// 
			this->label_a->AutoSize = true;
			this->label_a->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->label_a->Location = System::Drawing::Point(722, 416);
			this->label_a->Name = L"label_a";
			this->label_a->Size = System::Drawing::Size(21, 24);
			this->label_a->TabIndex = 20;
			this->label_a->Text = L"a";
			this->label_a->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// label_b
			// 
			this->label_b->AutoSize = true;
			this->label_b->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->label_b->Location = System::Drawing::Point(728, 337);
			this->label_b->Name = L"label_b";
			this->label_b->Size = System::Drawing::Size(21, 24);
			this->label_b->TabIndex = 21;
			this->label_b->Text = L"b";
			this->label_b->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_integrFunction
			// 
			this->label_integrFunction->AutoSize = true;
			this->label_integrFunction->Font = (gcnew System::Drawing::Font(L"Times New Roman", 20.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->label_integrFunction->Location = System::Drawing::Point(744, 370);
			this->label_integrFunction->Name = L"label_integrFunction";
			this->label_integrFunction->Size = System::Drawing::Size(83, 31);
			this->label_integrFunction->TabIndex = 22;
			this->label_integrFunction->Text = L"f(x)dx";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label7->Location = System::Drawing::Point(12, 317);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(189, 23);
			this->label7->TabIndex = 23;
			this->label7->Text = L"Точність обчислень:";
			// 
			// numeric_accuracy
			// 
			this->numeric_accuracy->BackColor = System::Drawing::SystemColors::ControlDark;
			this->numeric_accuracy->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->numeric_accuracy->Location = System::Drawing::Point(207, 317);
			this->numeric_accuracy->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 6, 0, 0, 0 });
			this->numeric_accuracy->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numeric_accuracy->Name = L"numeric_accuracy";
			this->numeric_accuracy->Size = System::Drawing::Size(55, 29);
			this->numeric_accuracy->TabIndex = 24;
			this->numeric_accuracy->ThousandsSeparator = true;
			this->numeric_accuracy->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Silver;
			this->ClientSize = System::Drawing::Size(1435, 460);
			this->Controls->Add(this->numeric_accuracy);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label_integrFunction);
			this->Controls->Add(this->label_b);
			this->Controls->Add(this->label_a);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->chart);
			this->Controls->Add(this->textBox_b);
			this->Controls->Add(this->textBox_a);
			this->Controls->Add(this->button_DO);
			this->Controls->Add(this->comboBox_integrFunction);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->comboBox_methodIntegr);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->numeric_NumSegments);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->menuStrip1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->MainMenuStrip = this->menuStrip1;
			this->MaximizeBox = false;
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Калькулятор інтегралів певних функцій";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numeric_NumSegments))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numeric_accuracy))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void button_DO_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void выходToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e);
private: bool OKinputValues();

};
}