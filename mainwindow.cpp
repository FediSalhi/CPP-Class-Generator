/************************************************************************************
 * Author               : Fedi Salhi <fadi.salhi@outlook.fr>
 * Creation Date        : 16/05/2021
 * Description          : Main window class implementation file
 *
 * Revision No          : R001
 * Revision Date        :
 * Revision Description :
 *************************************************************************************/




/****************** includes ******************/
#include "mainwindow.h"
/**********************************************/

MainWindow::MainWindow(QWidget *parent) : QWidget(parent)
{

   /* class definition */
   m_name = new QLineEdit();
   m_inherits = new QLineEdit();

   m_definition_form_layout = new QFormLayout();
   m_definition_form_layout->addRow("Name:", m_name);
   m_definition_form_layout->addRow("Inherits:", m_inherits);

   m_definition_groupbox = new QGroupBox("Class information");
   m_definition_groupbox->setLayout(m_definition_form_layout);

   /* options */
   m_check_box_1 = new QCheckBox("Protect the header against multiple inclusions");
   m_check_box_2 = new QCheckBox("Generate a default constructor");
   m_check_box_3 = new QCheckBox("Generate a destructor");

   m_option_layout = new QVBoxLayout();

   m_option_layout->addWidget(m_check_box_1);
   m_option_layout->addWidget(m_check_box_2);
   m_option_layout->addWidget(m_check_box_3);

   m_option_groupbox = new QGroupBox("Options");
   m_option_groupbox->setLayout(m_option_layout);

   /* comments */
   m_author = new QLineEdit();
   m_creation_date = new QDateEdit();
   m_text_block = new QTextEdit();

   m_comments_form_layout = new QFormLayout();
   m_comments_form_layout->addRow("Author:", m_author);
   m_comments_form_layout->addRow("Creation date:", m_creation_date);
   m_comments_form_layout->addRow("Class brief:", m_text_block);

   m_comment_groupbox = new QGroupBox("Add comments");
   m_comment_groupbox->setLayout(m_comments_form_layout);

   /* bottom buttons */
   m_generate_button = new QPushButton("Generate !");
   m_quit_button = new QPushButton("Quit");

   m_bottom_button_layout = new QHBoxLayout();
   m_bottom_button_layout->addWidget(m_generate_button);
   m_bottom_button_layout->addWidget(m_quit_button);


   /* add all group boxes to main layout */
    m_main_vertical_layout = new QVBoxLayout;
    m_main_vertical_layout->addWidget(m_definition_groupbox);
    m_main_vertical_layout->addWidget(m_option_groupbox);
    m_main_vertical_layout->addWidget(m_comment_groupbox);
    m_main_vertical_layout->addLayout(m_bottom_button_layout);

    setLayout(m_main_vertical_layout);

    QObject::connect(m_generate_button, SIGNAL(clicked()), this, SLOT(generate_class()));
    QObject::connect(m_quit_button, SIGNAL(clicked()), qApp, SLOT(quit()));

}

void MainWindow::generate_class()
{
    m_generated_window = new GeneratedClass();

    /* check class name is not empty */
    if (m_name->text().isEmpty())
    {
        QMessageBox::critical(this, "Error", "Class name can't be empty!, try again");
    }
    else
    {
        update_generated_string();
        m_generated_window->put_text(m_generated_string);
        m_generated_window->setWindowTitle("Generated Class");
        m_generated_window->show();
    }
}

void MainWindow::update_generated_string()
{

    /* start a clean string */
    m_generated_string.clear();

    /* author */
    m_generated_string.push_back("/*\n");
    m_generated_string.push_back("Author  :  ");
    m_generated_string.push_back(m_author->text());
    m_generated_string.push_back("\n");
    /* creation date */
    m_generated_string.push_back("Creation date  :  ");
    m_generated_string.push_back(m_creation_date->text());
    m_generated_string.push_back("\n\n");
    /* brief */
    m_generated_string.push_back("Brief  :\n");
    m_generated_string.push_back(m_text_block->toPlainText());
    m_generated_string.push_back("\n*/\n\n");

    /* multiple inclusions protection */
    if (m_check_box_1->isChecked())
    {
        m_generated_string.push_back("#ifndef HEADER_"+m_name->text().toUpper()+"\n"+"#define HEADER_"+m_name->text().toUpper()+"\n\n");
    }

    /* class generation */
    m_generated_string.push_back("class  "+m_name->text()+"  :  "+"public  "+m_inherits->text()+"\n");
    m_generated_string.push_back("{\n        public:");

    if (m_check_box_2->isChecked())
    {
        m_generated_string.push_back("\n                "+m_name->text()+"();");
    }

    if (m_check_box_3->isChecked())
    {
        m_generated_string.push_back("\n              ~"+m_name->text()+"();");
    }

    m_generated_string.push_back("\n\n        protected:");
    m_generated_string.push_back("\n\n        private:");
    m_generated_string.push_back("\n\n};");

    if (m_check_box_1->isChecked())
    {
        m_generated_string.push_back("\n\n#endif");
    }


}
