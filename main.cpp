/************************************************************************************
 * Author               : Fedi Salhi <fadi.salhi@outlook.fr>
 * Creation Date        : 16/05/2021
 * Description          : main file
 *
 * Revision No          : R001
 * Revision Date        :
 * Revision Description :
 *************************************************************************************/




/****************** includes ******************/
#include "mainwindow.h"
/**********************************************/

int main(int argc, char* argv[])
{

    QApplication my_app(argc, argv);
    MainWindow main_window;
    main_window.setWindowTitle("Class Generator");
    main_window.show();
    my_app.exec();

    return 0;
}
