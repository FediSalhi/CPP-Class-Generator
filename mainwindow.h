/************************************************************************************
 * Author               : Fedi Salhi <fadi.salhi@outlook.fr>
 * Creation Date        : 16/05/2021
 * Description          : Main window header file
 *
 * Revision No          : R001
 * Revision Date        :
 * Revision Description :
 *************************************************************************************/





#ifndef MAINWINDOW_H
#define MAINWINDOW_H

/****************** includes ******************/
#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QApplication>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QCheckBox>
#include <QLineEdit>
#include <QLabel>
#include <QGroupBox>
#include <QDateEdit>
#include <QTextBlock>
#include <QPushButton>
#include <QTextEdit>
#include "generatedclass.h"
#include <string>
#include <QMessageBox>
/**********************************************/

class MainWindow : public QWidget
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    void update_generated_string();

signals:

public slots:

    void generate_class();

private:
    QVBoxLayout* m_main_vertical_layout;

    /* class definiton */
    QFormLayout* m_definition_form_layout;
    QGroupBox* m_definition_groupbox;
    QLineEdit* m_name;
    QLineEdit* m_inherits;

    /* options */
    QVBoxLayout* m_option_layout;
    QGroupBox* m_option_groupbox;
    QCheckBox* m_check_box_1;
    QCheckBox* m_check_box_2;
    QCheckBox* m_check_box_3;

    /* comments */
    QFormLayout* m_comments_form_layout;
    QLineEdit* m_author;
    QDateEdit* m_creation_date;
    QTextEdit* m_text_block;
    QGroupBox* m_comment_groupbox;

    /* bottom buttons */
    QHBoxLayout* m_bottom_button_layout;
    QPushButton* m_generate_button;
    QPushButton* m_quit_button;

    /* generated window */
    GeneratedClass* m_generated_window;

    /* generated string */
    QString m_generated_string;


};

#endif // MAINWINDOW_H
