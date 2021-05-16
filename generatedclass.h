/************************************************************************************
 * Author               : Fedi Salhi <fadi.salhi@outlook.fr>
 * Creation Date        : 16/05/2021
 * Description          : Generated window header file
 *
 * Revision No          : R001
 * Revision Date        :
 * Revision Description :
 *************************************************************************************/




#ifndef GENERATEDCLASS_H
#define GENERATEDCLASS_H

/****************** includes ******************/
#include <QWidget>
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
/**********************************************/

class GeneratedClass : public QWidget
{
    Q_OBJECT
public:
    explicit GeneratedClass(QWidget *parent = nullptr);
    void put_text(QString string);

signals:

public slots:

private:
    QTextEdit* m_text_block;
    QPushButton* m_close_button;
    QVBoxLayout* m_main_vertical_layout;
};

#endif // GENERATEDCLASS_H
