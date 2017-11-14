#include "mainwindow.h"
#include <QApplication>



int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
/*
    Persona nueva;
    nueva.apellido="Avalos";
    int key =1;

    ArbolBinarioBusqueda arbolb;
    arbolb.insert(22,nueva);
    arbolb.insert(23,nueva);
    arbolb.insert(3,nueva);
    qInfo()<<arbolb.existe(5,arbolb.raiz);
    qInfo()<<arbolb.buscar(22).apellido;
    //arbolb.inOrden();
    //arbolb.impreArbol();
*/


    return a.exec();
}
