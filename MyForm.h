// Графический интерфейс
#pragma once

namespace ParseLog {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
		}

	protected:
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::TextBox^ filters;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::ComboBox^ existence;

	private: System::Windows::Forms::Button^ addFilter;
	private: System::Windows::Forms::Button^ res;
	private: System::Windows::Forms::Label^ filtList;

	private:
		System::ComponentModel::Container ^components;
		
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->filters = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->existence = (gcnew System::Windows::Forms::ComboBox());
			this->addFilter = (gcnew System::Windows::Forms::Button());
			this->res = (gcnew System::Windows::Forms::Button());
			this->filtList = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();

			// label1
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(61, 37);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(93, 24);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Enter filter";

			// filters - поле для ввода фильтров
			this->filters->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->filters->Location = System::Drawing::Point(65, 64);
			this->filters->Name = L"filters";
			this->filters->Size = System::Drawing::Size(212, 28);
			this->filters->TabIndex = 1;

			// label2
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(61, 206);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(180, 24);
			this->label2->TabIndex = 2;
			this->label2->Text = L"String contains filters";

			// existence - поле, определяющее, какие строки нужно вывести
			// (содержащие или не содержащие фильтры)
			this->existence->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->existence->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->existence->FormattingEnabled = true;
			this->existence->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"yes", L"no" });
			this->existence->Location = System::Drawing::Point(65, 233);
			this->existence->Name = L"existence";
			this->existence->Size = System::Drawing::Size(128, 30);
			this->existence->TabIndex = 3;
			this->existence->UseWaitCursor = true;

			// addFilter - кнопка добавления фильтра
			this->addFilter->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->addFilter->Location = System::Drawing::Point(65, 116);
			this->addFilter->Name = L"addFilter";
			this->addFilter->Size = System::Drawing::Size(212, 35);
			this->addFilter->TabIndex = 4;
			this->addFilter->Text = L"Add filter";
			this->addFilter->UseVisualStyleBackColor = true;
			this->addFilter->Click += gcnew System::EventHandler(this, &MyForm::addFilter_Click);

			// res - анализ текстового файла по введенным данным
			this->res->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->res->Location = System::Drawing::Point(65, 314);
			this->res->Name = L"res";
			this->res->Size = System::Drawing::Size(212, 35);
			this->res->TabIndex = 5;
			this->res->Text = L"Select";
			this->res->UseVisualStyleBackColor = true;
			this->res->Click += gcnew System::EventHandler(this, &MyForm::res_Click);

			// filtList - поле, отображающее все фильтры
			this->filtList->AutoSize = true;
			this->filtList->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->filtList->Location = System::Drawing::Point(379, 64);
			this->filtList->Name = L"filtList";
			this->filtList->Size = System::Drawing::Size(0, 24);
			this->filtList->TabIndex = 6;

			// MyForm
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(642, 445);
			this->Controls->Add(this->filtList);
			this->Controls->Add(this->res);
			this->Controls->Add(this->addFilter);
			this->Controls->Add(this->existence);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->filters);
			this->Controls->Add(this->label1);
			this->HelpButton = true;
			this->Name = L"MyForm";
			this->SizeGripStyle = System::Windows::Forms::SizeGripStyle::Hide;
			this->Text = L"Parse";
			this->ResumeLayout(false);
			this->PerformLayout();
		}

	private: System::Void addFilter_Click(System::Object^, System::EventArgs^);
	private: System::Void res_Click(System::Object^, System::EventArgs^);

};
}
