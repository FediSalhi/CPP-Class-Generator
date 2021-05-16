/************************************************************************************
 * Author               : Fedi Salhi <fadi.salhi@outlook.fr>
 * Creation Date        : 16/05/2021
 * Description          : Generated window class implementation file
 *
 * Revision No          : R001
 * Revision Date        :
 * Revision Description :
 *************************************************************************************/





/****************** includes ******************/
#include "generatedclass.h"
/**********************************************/

GeneratedClass::GeneratedClass(QWidget *parent) : QWidget(parent)
{
    m_text_block = new QTextEdit();
    m_close_button = new QPushButton("close");
    m_main_vertical_layout = new QVBoxLayout();
    m_main_vertical_layout->addWidget(m_text_block);
    m_main_vertical_layout->addWidget(m_close_button);
    setLayout(m_main_vertical_layout);

    QObject::connect(m_close_button, SIGNAL(clicked()), qApp, SLOT(quit()));
}
void GeneratedClass::put_text(QString string)
{
    m_text_block->append(string);
}
