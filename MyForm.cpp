// Функции формы
#include "MyForm.h"
#include "Functions.h"

std::vector<std::string> filt; //Массив фильтров

[STAThread]
void main(array<String^>^ arg) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    ParseLog::MyForm form;
    Application::Run(% form);
}

// Добавление фильтра через текстовое поле в форме
System::Void ParseLog::MyForm::addFilter_Click(System::Object^ sender, System::EventArgs^ e)
{
    String^ curr_filt = filters->Text->ToString();
    if (curr_filt != "") {
        filt.push_back(convert_String_to_string(curr_filt));
        filters->Text = "";
        filtList->Text += curr_filt + "\n";
    }
}

// Анализ исходного текстового файла
System::Void ParseLog::MyForm::res_Click(System::Object^ sender, System::EventArgs^ e)
{
    String^ ex = existence->Text->ToString();
    if (ex == "yes") {
        select_strings(filt, true);
        MessageBox::Show("Data selected", "");
        MyForm::Close();
    }
    else if (ex == "no") {
        select_strings(filt, false);
        MessageBox::Show("Data selected", "");
        MyForm::Close();
    }
    else
        MessageBox::Show("Choose existence", "Error");
}
