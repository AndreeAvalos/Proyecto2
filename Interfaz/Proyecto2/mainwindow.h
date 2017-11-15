#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <iostream>
#include<fstream>
#include <QDebug>
#include <QtWebKitWidgets>
#include "listasimple.h"
#include "listasimple2.h"
#include "tablahash.h"

using namespace std;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

    //metodo para cargar archivo
    void cargarArchivo(QString ruta);

    void on_pushButton_12_clicked();

    //Metodo de codificacion
    string Codificar(string );

    //Metodo de decodificacion
    string Decodificar(string);

    void on_pushButton_13_clicked();

    void escribirArchivo(QByteArray cuerpo);

    void on_pushButton_16_clicked();

    void on_pushButton_14_clicked();

    void on_btn_agregarFamilia_clicked();

    void on_btn_agregarPersona_clicked();

    void on_pushButton_18_clicked();

    void llenarCombo(nodoABB *pivote);

    void on_Cfamilia_modificar_currentIndexChanged(int index);

    void on_cIndividuo_modificar_currentIndexChanged(int index);

    void on_pushButton_19_clicked();

    void on_pushButton_20_clicked();

    void on_pushButton_17_clicked();

    void on_eliminar_familia_clicked();

    void on_cFamilia_eliminar_currentIndexChanged(int index);

    void on_Cindividuo_eliminar_currentIndexChanged(int index);

    void on_pushButton_21_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_23_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_24_clicked();

    void on_pushButton_25_clicked();

    void on_eliminar_familia_2_clicked();

    void on_pushButton_26_clicked();

    void on_pushButton_27_clicked();

    void on_pushButton_28_clicked();

    void on_pushButton_29_clicked();

    void on_pushButton_30_clicked();

    void on_pushButton_31_clicked();

    void on_pushButton_32_clicked();

    void on_puntoa_currentIndexChanged(int index);

    void on_puntob_currentIndexChanged(int index);

    void on_pushButton_33_clicked();

    void on_pushButton_34_clicked();

    void on_Carchivo_informacion_clicked();

    void on_pushButton_35_clicked();

    void on_pushButton_36_clicked();

    void on_pushButton_37_clicked();

private:
    Ui::MainWindow *ui;
    QByteArray archivo;
    string archivito;
    ListaSimple2 lstfamilias;
    int key=0;
    int key2 =0;
    QWebView *view = new QWebView(nullptr);
    TablaHash *Tabla = new TablaHash(29);
    ListaDoble *lstDonaciones = new ListaDoble();



};

#endif // MAINWINDOW_H
