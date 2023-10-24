#include "ClassicCryptography.h"

std::string ClassicCryptography::remove_punctuation(std::string text)
{
    std::string result = text;
    result.erase(std::remove(result.begin(), result.end(), ' '), result.end());
    result.erase(std::remove(result.begin(), result.end(), ','), result.end());
    result.erase(std::remove(result.begin(), result.end(), '.'), result.end());
    result.erase(std::remove(result.begin(), result.end(), '¿'), result.end());
    result.erase(std::remove(result.begin(), result.end(), '?'), result.end());
    result.erase(std::remove(result.begin(), result.end(), ';'), result.end());
    return result;
}

std::string ClassicCryptography::to_uppercase(std::string input)
{
    std::string result = input;
    for (char& c : result)
    {
        if (std::islower(c))
        {
            c = std::toupper(c);
        }
    }
    return result;
}

ClassicCryptography::ClassicCryptography(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ClassicCryptographyClass())
{
    ui->setupUi(this);
}

std::string ClassicCryptography::preprocessing(std::string text)
{
    std::string pre1 = remove_punctuation(text);
    //std::string pre2 = removeTildes(pre1);
    std::string result = to_uppercase(pre1);
    return result;
}

std::string ClassicCryptography::permutation_series(std::string text)
{
    std::vector<int> found_positions;
    std::string cipher;
    for (long long unsigned int i = 0; i < text.size(); i++)
    {
        if (i % 3 == 0)
        {
            auto it = std::find(found_positions.begin(), found_positions.end(), i);
            if (it == found_positions.end())
            {
                found_positions.push_back(i);
                cipher += text[i];
            }
        }
    }
    for (long long unsigned int i = 0; i < text.size(); i += 2)
    {
        auto it = std::find(found_positions.begin(), found_positions.end(), i);
        if (it == found_positions.end())
        {
            found_positions.push_back(i);
            cipher += text[i];
        }
    }
    for (long long unsigned int i = 0; i < text.size(); i++)
    {
        if (i % 4 == 0)
        {
            auto it = std::find(found_positions.begin(), found_positions.end(), i);
            if (it == found_positions.end())
            {
                found_positions.push_back(i);
                cipher += text[i];
            }
        }
    }
    
    for (long long unsigned int i = 0; i < text.size(); i++)
    {

        if (i % 2 != 0)
        {
            auto it = std::find(found_positions.begin(), found_positions.end(), i);
            if (it == found_positions.end())
            {
                found_positions.push_back(i);
                cipher += text[i];
            }
        }
    }
    
    return cipher;
}

//std::string removeTildes(const std::string& input)
//{
//    setlocale(LC_CTYPE, "C");
//    std::string result = input;
//    for (char& c : result)
//    {
//        switch (c)
//        {
//        case 'á': c = 'a'; break;
//        case 'é': c = 'e'; break;
//        case 'í': c = 'i'; break;
//        case 'ó': c = 'o'; break;
//        case 'ú': c = 'u'; break;
//        case 'ü': c = 'u'; break;
//        case 'ñ': c = 'n'; break;
//        case 'Á': c = 'A'; break;
//        case 'É': c = 'E'; break;
//        case 'Í': c = 'I'; break;
//        case 'Ó': c = 'O'; break;
//        case 'Ú': c = 'U'; break;
//        case 'Ü': c = 'U'; break;
//        case 'Ñ': c = 'N'; break;
//        }
//    }
//    return "result";
//}
void ClassicCryptography::on_encrypt_clicked()
{
    if (ui->input->toPlainText().isEmpty())
    {
        this->ui->warning->setText("No hay texto de entrada");
    }
    else
    {
        QString temp = ui->input->toPlainText();
        std::string input = temp.toStdString();
        std::string preProcess = this->preprocessing(input);
        std::string cipher = this->permutation_series(preProcess);
        this->ui->output->setText(QString::fromStdString(cipher));
    }
}
void ClassicCryptography::on_clear_clicked()
{
    this->ui->input->clear();
    this->ui->output->clear();
}

void ClassicCryptography::on_exit_clicked()
{
    this->close();
}
ClassicCryptography::~ClassicCryptography()
{
    delete ui;
}