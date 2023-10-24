#pragma once
#include <QtWidgets/QMainWindow>
#include "ui_ClassicCryptography.h"
#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>

QT_BEGIN_NAMESPACE
namespace Ui { class ClassicCryptographyClass; };
QT_END_NAMESPACE

class ClassicCryptography : public QMainWindow
{
    Q_OBJECT

private:
    std::string remove_punctuation(std::string text);
    std::string to_uppercase(std::string input);
    //std::string removeTildes(const std::string& input);
public:
    ClassicCryptography(QWidget *parent = nullptr);
    std::string preprocessing(std::string text);
    std::string permutation_series(std::string text);
    ~ClassicCryptography();

private slots:
    void on_encrypt_clicked();
    void on_clear_clicked();
    void on_exit_clicked();
private:
    Ui::ClassicCryptographyClass *ui;
};
