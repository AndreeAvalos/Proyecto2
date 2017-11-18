#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtNetwork>
#include <stdio.h>
#include <string.h>
#include "ui_mainwindow.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QFile>
#include "codificador.h"

#define 	TOPEVECTOR 	200

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_4_clicked()
{
   ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_pushButton_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_pushButton_7_clicked()
{
    ui->dock_albergue->setCurrentIndex(0);
}

void MainWindow::on_pushButton_8_clicked()
{
    ui->dock_albergue->setCurrentIndex(2);
}

void MainWindow::on_pushButton_9_clicked()
{
    ui->dock_albergue->setCurrentIndex(3);
}

void MainWindow::on_pushButton_10_clicked()
{
    ui->dock_albergue->setCurrentIndex(1);
}

void MainWindow::on_pushButton_11_clicked()
{
    QString fileNames = QFileDialog::getOpenFileName(this, tr("Open File"),"/path/to/file/",tr("TXT Files (*.txt)"));
    cargarArchivo(fileNames);
    ui->lineEdit->setText(fileNames);
}

void MainWindow::cargarArchivo(QString ruta)
{

    fstream ficheroEntrada;//para leer el archivo
    string linea;//
    archivito="";
    archivo="";
    ficheroEntrada.open(ruta.toStdString(), ios::in);//abrimos el archivo con su ubicacion
    while (! ficheroEntrada.eof() ) {
        getline(ficheroEntrada,linea);//leemos linea por linea el archivo
        //archivo.append(QString::fromStdString(linea));//lo adjuntamos al archivo
        archivito+=linea;
       // qInfo()<<QString::fromStdString(linea);
    }
    ficheroEntrada.close();




}

void MainWindow::on_pushButton_12_clicked()
{
    ListaSimple lst;
    string st = archivito;

    char str[st.length()+1];
    strcpy(str, st.c_str());
    char * pch;
    //printf ("Splitting string \"%s\" into tokens:\n",str);

    pch = strtok (str,";");

     while (pch != NULL)
     {
         std::string someString(pch);
         lst.agregar(someString);
         pch = strtok (NULL, ";");
     }
        qInfo()<<"Numero de elementos a insertar: "<<lst.size;

     nodo *temporal = lst.first;

    while(temporal!=nullptr){
         ListaSimple lst2;
         string st2= temporal->getDato();

         char str2[st2.length()+1];
         strcpy(str2, st2.c_str());

         char *pch2;
         //printf ("Splitting string \"%s\" into tokens:\n",str);
         qInfo()<<"";
         pch2 = strtok (str2,",");

         while (pch2 != NULL)
         {
             std:: string str(pch2);
             std::string someString=Decodificar(str);

             lst2.agregar(someString);
             pch2 = strtok (NULL, ",");
         }
         nodo *temp = lst2.first;

         while(temp!=nullptr){
             if(temp==lst2.first)
                 archivo.append(QString::fromStdString(temp->dato));
            else
                 archivo.append(","+QString::fromStdString(temp->dato));
             temp = temp->siguiente;
         }

         archivo.append(";");


         temporal=temporal->siguiente;
     }


    QEventLoop eventLoop;

    QNetworkAccessManager mgr;
    QObject::connect(&mgr, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));

    QNetworkRequest req( QUrl( QString("http://localhost:8080/WebService/app/setLocalidad") ) );
    req.setRawHeader("Content-Type", "application/json");
    QNetworkReply *reply = mgr.post(req,archivo);

    eventLoop.exec();


    if (reply->error() == QNetworkReply::NoError) {
        //success
        QNetworkReply *respuesta= mgr.get(req);
        eventLoop.exec();
        qDebug() << "Success" << respuesta->readAll();
        delete respuesta;
        delete reply;

    } else {
        //failure
        qDebug() << "Failure" <<reply->errorString();
        delete reply;
    }

}

string MainWindow::Codificar(string str)
{

    std::transform(str.begin(), str.end(), str.begin(), ::tolower);

    string resultado;

    for(int i=0; i<str.length();i++){
        //qInfo()<<str[i];
        switch (str[i]) {
        case 'a':
            resultado+="k";
            break;
        case 'b':
            resultado+="j";
            break;
        case 'c':
            resultado+="r";
            break;
        case 'd':
            resultado+="s";
            break;
        case 'e':
            resultado+="z";
            break;
        case 'f':
            resultado+="v";
            break;
        case 'g':
            resultado+="a";
            break;
        case 'h':
            resultado+="c";
            break;
        case 'i':
            resultado+="b";
            break;
        case 'j':
            resultado+="g";
            break;
        case 'k':
            resultado+="h";
            break;
        case 'l':
            resultado+="o";
            break;
        case 'm':
            resultado+="q";
            break;
        case 'n':
            resultado+="m";
            break;
        case 'o':
            resultado+="d";
            break;
        case 'p':
            resultado+="n";
            break;
        case 'q':
            resultado+="t";
            break;
        case 'r':
            resultado+="x";
            break;
        case 's':
            resultado+="i";
            break;
        case 't':
            resultado+="e";
            break;
        case 'u':
            resultado+="y";
            break;
        case 'v':
            resultado+="f";
            break;
        case 'w':
            resultado+="l";
            break;
        case 'x':
            resultado+="p";
            break;
        case 'y':
            resultado+="u";
            break;
        case 'z':
            resultado+="w";
            break;
        case 0x30:
            resultado+="=";
            break;
        case 0x31:
            resultado+="!";
            break;
        case 0x32:
            resultado+="@";
            break;
        case 0x33:
            resultado+="(";
            break;
        case 0x34:
            resultado+=")";
            break;
        case 0x35:
            resultado+="$";
            break;
        case 0x36:
            resultado+="#";
            break;
        case 0x37:
            resultado+=":";
            break;
        case 0x38:
            resultado+="+";
            break;
        case 0x39:
            resultado+="*";
            break;
        case '.':
            resultado+="^";
            break;

        case '/':
            resultado+="_";
            break;
        case '-':
            resultado+=">";
        default:
            //resultado+=str[i];
            break;
        }
    }
    //qInfo()<<"palabra a codificar "<<QString::fromStdString(str)<<" palabra codificada: "<<QString::fromStdString(resultado);
    return  resultado;

}

string MainWindow::Decodificar(string str)
{


    std::transform(str.begin(), str.end(), str.begin(), ::tolower);

    string resultado;

    for(int i=0; i<str.length();i++){
        //qInfo()<<str[i];
        switch (str[i]) {
        case 'k':
            resultado+="a";
            break;
        case 'j':
            resultado+="b";
            break;
        case 'r':
            resultado+="c";
            break;
        case 's':
            resultado+="d";
            break;
        case 'z':
            resultado+="e";
            break;
        case 'v':
            resultado+="f";
            break;
        case 'a':
            resultado+="g";
            break;
        case 'c':
            resultado+="h";
            break;
        case 'b':
            resultado+="i";
            break;
        case 'g':
            resultado+="j";
            break;
        case 'h':
            resultado+="k";
            break;
        case 'o':
            resultado+="l";
            break;
        case 'q':
            resultado+="m";
            break;
        case 'm':
            resultado+="n";
            break;
        case 'd':
            resultado+="o";
            break;
        case 'n':
            resultado+="p";
            break;
        case 't':
            resultado+="q";
            break;
        case 'x':
            resultado+="r";
            break;
        case 'i':
            resultado+="s";
            break;
        case 'e':
            resultado+="t";
            break;
        case 'y':
            resultado+="u";
            break;
        case 'f':
            resultado+="v";
            break;
        case 'l':
            resultado+="w";
            break;
        case 'p':
            resultado+="x";
            break;
        case 'u':
            resultado+="y";
            break;
        case 'w':
            resultado+="z";
            break;
        case '=':
            resultado+="0";
            break;
        case '!':
            resultado+="1";
            break;
        case '@':
            resultado+="2";
            break;
        case '(':
            resultado+="3";
            break;
        case ')':
            resultado+="4";
            break;
        case '$':
            resultado+="5";
            break;
        case '#':
            resultado+="6";
            break;
        case ':':
            resultado+="7";
            break;
        case '+':
            resultado+="8";
            break;
        case '*':
            resultado+="9";
            break;
        case '^':
            resultado+=".";
            break;
        case '_':
            resultado+="/";
            break;
        case '>':
            resultado+="-";
        default:
            //resultado+=str[i];
            break;
        }
    }
    //qInfo()<<"palabra a codificar "<<QString::fromStdString(str)<<" palabra codificada: "<<QString::fromStdString(resultado);
    return  resultado;

}

void MainWindow::on_pushButton_13_clicked()
{
    QEventLoop eventLoop;

    QNetworkAccessManager mgr;
    QObject::connect(&mgr, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));

    QNetworkRequest req( QUrl( QString("http://localhost:8080/WebService/app/getLocalidades") ) );
    req.setRawHeader("Content-Type", "application/json");
    QNetworkReply *reply = mgr.get(req);

    eventLoop.exec();


    if (reply->error() == QNetworkReply::NoError) {
        //success
        qDebug() << "Success: Localidades traidas con exito";
        escribirArchivo(reply->readAll());
        delete reply;

    } else {
        //failure
        qDebug() << "Failure" <<reply->errorString();
        delete reply;
    }

}

void MainWindow::escribirArchivo(QByteArray cuerpo)
{
    ofstream ficheroSalida;
     ficheroSalida.open ("/home/andree/Escritorio/EDDArchivos/localidades.txt");
     ficheroSalida << cuerpo.toStdString();
     ficheroSalida.close();
}

void MainWindow::on_pushButton_16_clicked()
{
    QString fileNames = QFileDialog::getOpenFileName(this, tr("Open File"),"/path/to/file/",tr("TXT Files (*.txt)"));
    cargarArchivo(fileNames);
    ui->lineEdit_2->setText(fileNames);
}

void MainWindow::on_pushButton_14_clicked()
{
    ListaSimple lst;
    string st = archivito;

    char str[st.length()+1];
    strcpy(str, st.c_str());
    char * pch;
    //printf ("Splitting string \"%s\" into tokens:\n",str);

    pch = strtok (str,";");

     while (pch != NULL)
     {
         std::string someString(pch);
         lst.agregar(someString);
         pch = strtok (NULL, ";");
     }
        qInfo()<<"Numero de elementos a insertar: "<<lst.size;

     nodo *temporal = lst.first;

    while(temporal!=nullptr){
         ListaSimple lst2;
         string st2= temporal->getDato();

         char str2[st2.length()+1];
         strcpy(str2, st2.c_str());

         char *pch2;
         //printf ("Splitting string \"%s\" into tokens:\n",str);
         qInfo()<<"";
         pch2 = strtok (str2,",");

         while (pch2 != NULL)
         {
             std:: string str(pch2);
             std::string someString=Decodificar(str);

             lst2.agregar(someString);
             pch2 = strtok (NULL, ",");
         }
         nodo *temp = lst2.first;

         while(temp!=nullptr){
             if(temp==lst2.first)
                 archivo.append(QString::fromStdString(temp->dato));
            else
                 archivo.append(","+QString::fromStdString(temp->dato));
             temp = temp->siguiente;
         }

         archivo.append(";");


         temporal=temporal->siguiente;
     }
    qInfo()<<archivo;

    QEventLoop eventLoop;

    QNetworkAccessManager mgr;
    QObject::connect(&mgr, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));

    QNetworkRequest req( QUrl( QString("http://localhost:8080/WebService/app/setDonacion") ) );
    req.setRawHeader("Content-Type", "application/json");
    QNetworkReply *reply = mgr.post(req,archivo);

    eventLoop.exec();


    if (reply->error() == QNetworkReply::NoError) {
        //success
        QNetworkReply *respuesta= mgr.get(req);
        eventLoop.exec();
        qDebug() << "Success" << respuesta->readAll();
        delete respuesta;
        delete reply;

    } else {
        //failure
        qDebug() << "Failure" <<reply->errorString();
        delete reply;
    }

}

void MainWindow::on_btn_agregarFamilia_clicked()
{
    QString codigo=ui->familia_albergue->text();
    QString nombre = ui->nombre_familia->text();
    QString apellido = ui->apellidos_familia->text();
    QString edad = ui->edad_familia->text();
    QString genero = ui->genero_familia->text();
    Persona *nuevo = new Persona(codigo,edad,nombre,apellido,genero);
    Familia nueva(codigo);
    nueva.arbol->insert(codigo.toInt(),nuevo);
    nueva.arbol->impreArbol();
    lstfamilias.agregar(nueva);
}

void MainWindow::on_btn_agregarPersona_clicked()
{
    QString familia = ui->dpi_familia->text();
    QString codigo = ui->dpi_individuo->text();
    QString nombre = ui->nombre_individuo->text();
    QString apellido = ui->apellidos_individuo->text();
    QString edad = ui->edad_individuo->text();
    QString genero = ui->genero_individuo->text();
    Persona *nuevo = new Persona(codigo,edad,nombre,apellido,genero);
   if(lstfamilias.existe(familia)==true){
        Familia getFamilia = lstfamilias.buscar(familia);
        getFamilia.arbol->insert(codigo.toInt(),nuevo);
        getFamilia.arbol->impreArbol();
    }
}

void MainWindow::on_pushButton_18_clicked()
{
    ui->Cfamilia_modificar->clear();

    if(lstfamilias.first==nullptr){}
    else{
   nodo2 *temporal = lstfamilias.first;

   while(temporal!=nullptr){
       ui->Cfamilia_modificar->addItem(temporal->getDato().codigo);
       temporal = temporal->siguiente;
   }
    }
}

void MainWindow::llenarCombo(nodoABB *pivote)
{
    //se verifica si la raiz es nula
    if(pivote==nullptr)
        return;

    llenarCombo(pivote->izquierda);
   // qInfo()<<'\t'<<pivote->key;
    ui->cIndividuo_modificar->addItem(QString::number(pivote->key));
    llenarCombo(pivote->derecha);

}


void MainWindow::on_Cfamilia_modificar_currentIndexChanged(int index)
{
    key= index;
}

void MainWindow::on_cIndividuo_modificar_currentIndexChanged(int index)
{
    key2=index;

    QString codigo = ui->cIndividuo_modificar->itemText(index);
    QString fami= ui->Cfamilia_modificar->itemText(key);
    //qInfo()<<codigo<<"-"<<fami;
    Familia temp= lstfamilias.buscar(fami);

    bool temporal = temp.arbol->existe(codigo.toInt(),temp.arbol->raiz);

    qInfo()<<temporal;

    if(temporal==true){
        Persona  *nuevo = temp.arbol->buscar(codigo.toInt());
        qInfo()<< nuevo->nombre;
        ui->nombre_modificar->setText(nuevo->nombre);
        ui->apellidos_modificar->setText(nuevo->apellido);
        ui->edad_modificar->setText(nuevo->edad);
       ui->genero_modificar->setText(nuevo->genero);
    }
}

void MainWindow::on_pushButton_19_clicked()
{
    ui->cIndividuo_modificar->clear();
    QString codigo = ui->Cfamilia_modificar->itemText(key);
    llenarCombo(lstfamilias.buscar(codigo).arbol->raiz);
}

void MainWindow::on_pushButton_20_clicked()
{
    lstfamilias.buscar( ui->Cfamilia_modificar->itemText(key)).arbol->impreArbol();
}

void MainWindow::on_pushButton_17_clicked()
{

    QString codigo = ui->cIndividuo_modificar->itemText(key2);
    QString fami= ui->Cfamilia_modificar->itemText(key);
    qInfo()<<codigo<<"-"<<fami;
    bool temporal = lstfamilias.buscar(fami).arbol->existe(codigo.toInt(),lstfamilias.buscar(fami).arbol->raiz);
    qInfo()<<temporal;
    if(temporal==true){
        Persona  *nuevo = lstfamilias.buscar(fami).arbol->buscar(codigo.toInt());
        nuevo->apellido=ui->apellidos_modificar->text();
        nuevo->nombre=ui->nombre_modificar->text();
        nuevo->edad=ui->edad_modificar->text();
        nuevo->genero=ui->genero_modificar->text();
    }

}

void MainWindow::on_eliminar_familia_clicked()
{
    qInfo()<< lstfamilias.eliminar(ui->cFamilia_eliminar->itemText(key));
    lstfamilias.imprimir();
}

void MainWindow::on_cFamilia_eliminar_currentIndexChanged(int index)
{
    key = index;
}

void MainWindow::on_Cindividuo_eliminar_currentIndexChanged(int index)
{
    key2=index;
}

void MainWindow::on_pushButton_21_clicked()
{
    ui->cFamilia_eliminar->clear();
    nodo2 *temporal = lstfamilias.first;
    while(temporal!=nullptr){
        ui->cFamilia_eliminar->addItem(temporal->dato.codigo);
        temporal=temporal->siguiente;
    }

}

void MainWindow::on_pushButton_6_clicked()
{
        ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_pushButton_23_clicked()
{
    QJsonDocument doc;
    ui->puntoa->clear();
    ui->puntob->clear();

    QEventLoop eventLoop;

    QNetworkAccessManager mgr;
    QObject::connect(&mgr, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));

    QNetworkRequest req( QUrl( QString("http://localhost:8080/WebService/app/getGrafo") ) );
    req.setRawHeader("Content-Type", "application/json");
    QNetworkReply *reply = mgr.get(req);

    eventLoop.exec();
    QByteArray json;

    if (reply->error() == QNetworkReply::NoError) {
        //success
        qDebug() << "Localidades traidas";
        //escribirArchivo(reply->readAll());
        json=reply->readAll();
        delete reply;

    } else {
        //failure
        qDebug() << "Failure" <<reply->errorString();
        delete reply;
    }

    ofstream ff;
     ff.open ("/home/andree/Escritorio/EDDArchivos/localidades.json");
     ff <<json.toStdString();
     ff.close();

    doc=QJsonDocument::fromJson(json);
    QFile defaultTextFile("/home/andree/Escritorio/EDDArchivos/mapa.html");
    defaultTextFile.open(QIODevice::ReadOnly);
    QString html = defaultTextFile.readAll();
    QString markers = "";
    //QString json = ui->textEdit->toPlainText();
    //json = tr("[{\"donador\":\"%1\",\"monto\":%2,\"voucher\":\"%3\"},{\"donador\":\"%1\",\"monto\":%2,\"voucher\":\"%3\"}]").arg(1, 2, 3);
    //qInfo()<<json.toUtf8();
    //QJsonDocument doc = QJsonDocument::fromJson(json.toUtf8());

    qInfo()<< doc.isArray();
    if(doc.isArray()){
        QJsonArray array = doc.array();
        //qInfo()<<array.size();
        for(int i = 0; i < array.size(); i++){
            QJsonObject elem = array[i].toObject();
            /*
                    var marker = new google.maps.Marker({
                        map: map,
                        position: {14.0, -90.0},
                        title: 'Hello World!'
                    });*/
            ui->puntoa->addItem(elem["codigo"].toString());
            ui->puntob->addItem(elem["codigo"].toString());
            markers.append(QString("var marker%1 = new google.maps.Marker({map: map,position: {lat:%2, lng:%3},title: '%4',icon:image});\n")
                           .arg(
                               QString::number(i),
                               QString::number(elem["lat"].toDouble()),
                           QString::number(elem["lng"].toDouble()),
                    elem["codigo"].toString()
                    ));
        }
    }

    //markers.append(QString("var marker3 = new google.maps.Marker({position: myLatLng,map: map,title: 'Hello World!',icon:image});\n \t\t\t\t"));
    //markers.append(QString("var marker4 = new google.maps.Marker({position: {lat:14, lng:-90},map: map,title: 'Hello World!',icon:image2});\n"));

    //markers.append(QString("var marker4 = new google.maps.Marker({map: map,position: {lat:44.0, lng:55},title: '2',icon:image});\n"));


    //ui->textEdit->setText(html.toUtf8());
    //qInfo()<<html;



        //view->setContent(html.toUtf8());

    view->setContent(html.replace("//###",markers).toUtf8());
    ofstream ficheroSalida;
    ficheroSalida.open ("/home/andree/Escritorio/EDDArchivos/mapas.html");
    ficheroSalida << html.toStdString();
    ficheroSalida.close();
    //ui->webView->setContent(html.replace("###",markers).toUtf8());







    //view->load(QUrl("https://www.google.es/maps"));
    ui->gridLayout->removeWidget(view);
    ui->gridLayout->addWidget(view);
    //view->
    //ui->stackedWidget_3->addWidget(view);
    view->show();
}

//metodo para traer donaciones
void MainWindow::on_pushButton_15_clicked()
{
    QEventLoop eventLoop;

    QNetworkAccessManager mgr;
    QObject::connect(&mgr, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));

    QNetworkRequest req( QUrl( QString("http://localhost:8080/WebService/app/getDonaciones2") ) );
    req.setRawHeader("Content-Type", "application/json");
    QNetworkReply *reply = mgr.get(req);

    eventLoop.exec();


    if (reply->error() == QNetworkReply::NoError) {
        //success
        qDebug() << "Success: Donaciones traidas con exito";
        escribirArchivo(reply->readAll());
        delete reply;

    } else {
        //failure
        qDebug() << "Failure" <<reply->errorString();
        delete reply;
    }

}
//Metodo de cifrado
void MainWindow::on_pushButton_24_clicked()
{
    QString ruta = QFileDialog::getOpenFileName(this, tr("Open File"),"/path/to/file/",tr("CSV Files (*.csv)"));

    fstream ficheroEntrada;//para leer el archivo
    string linea;//
    archivito="";
    archivo="";

    ficheroEntrada.open(ruta.toStdString(), ios::in);//abrimos el archivo con su ubicacion
    while (! ficheroEntrada.eof() ) {
        getline(ficheroEntrada,linea);//leemos linea por linea el archivo
        //archivo.append(QString::fromStdString(linea));//lo adjuntamos al archivo
        archivito+=linea;
       // qInfo()<<QString::fromStdString(linea);
    }
    ficheroEntrada.close();


    ListaSimple lst;
    string st = archivito;

    char str[st.length()+1];
    strcpy(str, st.c_str());
    char * pch;
    //printf ("Splitting string \"%s\" into tokens:\n",str);

    pch = strtok (str,";");

     while (pch != NULL)
     {
         std::string someString(pch);
         lst.agregar(someString);
         pch = strtok (NULL, ";");
     }
        qInfo()<<"Numero de elementos a insertar: "<<lst.size;

     nodo *temporal = lst.first;

    while(temporal!=nullptr){
         ListaSimple lst2;
         string st2= temporal->getDato();

         char str2[st2.length()+1];
         strcpy(str2, st2.c_str());

         char *pch2;
         //printf ("Splitting string \"%s\" into tokens:\n",str);
         qInfo()<<"";
         pch2 = strtok (str2,",");

         while (pch2 != NULL)
         {
             std:: string str(pch2);
             std::string someString=Codificar(str);

             lst2.agregar(someString);
             pch2 = strtok (NULL, ",");
         }
         nodo *temp = lst2.first;

         while(temp!=nullptr){
             if(temp==lst2.first)
                 archivo.append(QString::fromStdString(temp->dato));
            else
                 archivo.append(","+QString::fromStdString(temp->dato));
             temp = temp->siguiente;
         }

         archivo.append(";");


         temporal=temporal->siguiente;
     }

    ofstream ficheroSalida;
     ficheroSalida.open ("/home/andree/Escritorio/EDDArchivos/codificado.txt");
     ficheroSalida << archivo.toStdString();
     ficheroSalida.close();

}

void MainWindow::on_pushButton_25_clicked()
{
    QString ruta = QFileDialog::getOpenFileName(this, tr("Open File"),"/path/to/file/",tr("CSV Files (*.txt)"));

    fstream ficheroEntrada;//para leer el archivo
    string linea;//
    archivito="";
    archivo="";

    ficheroEntrada.open(ruta.toStdString(), ios::in);//abrimos el archivo con su ubicacion
    while (! ficheroEntrada.eof() ) {
        getline(ficheroEntrada,linea);//leemos linea por linea el archivo
        //archivo.append(QString::fromStdString(linea));//lo adjuntamos al archivo
        archivito+=linea;
       // qInfo()<<QString::fromStdString(linea);
    }
    ficheroEntrada.close();


    ListaSimple lst;
    string st = archivito;

    char str[st.length()+1];
    strcpy(str, st.c_str());
    char * pch;
    //printf ("Splitting string \"%s\" into tokens:\n",str);

    pch = strtok (str,";");

     while (pch != NULL)
     {
         std::string someString(pch);
         lst.agregar(someString);
         pch = strtok (NULL, ";");
     }
        //qInfo()<<"Numero de elementos a insertar: "<<lst.size;

     nodo *temporal = lst.first;

    while(temporal!=nullptr){
         ListaSimple lst2;
         string st2= temporal->getDato();

         char str2[st2.length()+1];
         strcpy(str2, st2.c_str());

         char *pch2;
         //printf ("Splitting string \"%s\" into tokens:\n",str);
        // qInfo()<<"";
         pch2 = strtok (str2,",");

         while (pch2 != NULL)
         {
             std:: string str(pch2);
             std::string someString=Decodificar(str);

             lst2.agregar(someString);
             pch2 = strtok (NULL, ",");
         }
         nodo *temp = lst2.first;

         while(temp!=nullptr){
             if(temp==lst2.first)
                 archivo.append(QString::fromStdString(temp->dato));
            else
                 archivo.append(","+QString::fromStdString(temp->dato));
             temp = temp->siguiente;
         }

         archivo.append(";\n");


         temporal=temporal->siguiente;
     }

    ofstream ficheroSalida;
     ficheroSalida.open ("/home/andree/Escritorio/EDDArchivos/decodificado.csv");
     ficheroSalida << archivo.toStdString();
     ficheroSalida.close();
}
//Boton para eliminar individuo
void MainWindow::on_eliminar_familia_2_clicked()
{
    QString codigo = ui->Cindividuo_eliminar->itemText(key2);
    QString fami= ui->cFamilia_eliminar->itemText(key);
    //qInfo()<<codigo<<"-"<<fami;
    Familia temp= lstfamilias.buscar(fami);

}
//Boton para poder insertar una donacion
void MainWindow::on_pushButton_26_clicked()
{

    QString codigo = ui->acopio_categoria->text();
    QString nombre = ui->acopio_nombre->text();
    int cantidad = ui->spinBox->value();
    Codificador cod;
    int codi = cod.getCodigo(codigo);
    Donacion *nuevo = new Donacion(codigo,nombre,cantidad);
    Tabla->insertar(codi,nuevo);

    ui->textEdit_2->clear();
    ui->textEdit_2->setText(Tabla->imprimir());
}

void MainWindow::on_pushButton_27_clicked()
{
    Tabla->graficarTabla();
}

void MainWindow::on_pushButton_28_clicked()
{
    QString codigo = ui->codigo_locacion->text();
    QString nombre = ui->nombre_latitud->text();
    double latitud = ui->latitud_locacion->value();
    double longitud = ui->longitud_locacion->value();
    QString password = ui->pass_locacion->text();
    QString nArchivo = ui->archivo_locacion->text();



    QString json=tr("%1,%2,%3,%4,%5,%6;").arg(codigo, nombre,password,QString::number(latitud),QString::number(longitud),nArchivo);
    string str= json.toStdString();
    std::transform(str.begin(), str.end(), str.begin(), ::tolower);
    json=QString::fromStdString(str);
    QEventLoop eventLoop;

    qInfo()<<json.toUtf8();
    QNetworkAccessManager mgr;
    QObject::connect(&mgr, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));

    QNetworkRequest req( QUrl( QString("http://localhost:8080/WebService/app/setLocalidad") ) );
    req.setRawHeader("Content-Type", "application/json");
    QNetworkReply *reply = mgr.post(req,json.toUtf8());

    eventLoop.exec();


    if (reply->error() == QNetworkReply::NoError) {
        //success
        QNetworkReply *respuesta= mgr.get(req);
        eventLoop.exec();
        qDebug() << "Success" << respuesta->readAll();
        delete respuesta;
        delete reply;

    } else {
        //failure
        qDebug() << "Failure" <<reply->errorString();
        delete reply;
    }

}

void MainWindow::on_pushButton_29_clicked()
{
    QString inicio = ui->inicio_arista->text();
    QString destino = ui->destino_arista->text();
    double multiplicador = ui->multiplicador_arista->value();

    const QString url=tr("http://localhost:8080/WebService/app/setArista?codigo=%1&destino=%2&multiplicador=%3").arg(inicio,destino,QString::number(multiplicador));
    QEventLoop eventLoop;

    QNetworkAccessManager mgr;
    QObject::connect(&mgr, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));

    QNetworkRequest req( QUrl( QString(url.toUtf8()) ) );
    req.setRawHeader("Content-Type", "application/json");
    QNetworkReply *reply = mgr.get(req);

    eventLoop.exec();


    if (reply->error() == QNetworkReply::NoError) {
        //success
        qDebug() << reply->readAll();
        delete reply;

    } else {
        //failure
        qDebug() << "Failure" <<reply->errorString();
        delete reply;
    }


}

void MainWindow::on_pushButton_30_clicked()
{
    QString json;
    QString codigo = ui->codigo_locacion->text();
    QString nombre = ui->nombre_latitud->text();
    double latitud = ui->latitud_locacion->value();
    double longitud = ui->longitud_locacion->value();
    QString password = ui->pass_locacion->text();
    QString nArchivo = ui->archivo_locacion->text();

    json=tr("{\"nombre\":\"%1\",\"codigo\"​:\"%2\",\"password\"​:\"%3\",\"lat\"​:%4,\"lng\"​:%5,\"archivo\"​:\"%6\"}").arg(nombre,codigo,password,QString::number(latitud),QString::number(longitud),nArchivo);
    qInfo()<<json;
    QEventLoop eventLoop;

    QNetworkAccessManager mgr;
    QObject::connect(&mgr, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));

    QNetworkRequest req( QUrl( QString("http://localhost:8080/WebService/app/putLocalidad") ) );
    req.setRawHeader("Content-Type", "application/json");
    QNetworkReply *reply = mgr.post(req,json.toUtf8());

    eventLoop.exec();


    if (reply->error() == QNetworkReply::NoError) {
        //success
        qDebug() << reply->readAll();
        delete reply;

    } else {
        //failure
        qDebug() << "Failure" <<reply->errorString();
        delete reply;
    }


}
void MainWindow::on_pushButton_31_clicked()
{
    QString inicio = ui->eliminar_localidad->text();

    const QString url=tr("http://localhost:8080/WebService/app/deleteLocalidad?codigo=%1").arg(inicio);
    QEventLoop eventLoop;

    QNetworkAccessManager mgr;
    QObject::connect(&mgr, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));

    QNetworkRequest req( QUrl( QString(url.toUtf8()) ) );
    req.setRawHeader("Content-Type", "application/json");
    QNetworkReply *reply = mgr.get(req);

    eventLoop.exec();


    if (reply->error() == QNetworkReply::NoError) {
        //success
        qDebug() << reply->readAll();
        delete reply;

    } else {
        //failure
        qDebug() << "Failure" <<reply->errorString();
        delete reply;
    }

}

void MainWindow::on_pushButton_32_clicked()
{
    QFile defaultTextFile("/home/andree/Escritorio/EDDArchivos/mapas.html");
    defaultTextFile.open(QIODevice::ReadOnly);
    QString html = defaultTextFile.readAll();
    QString puntoa = ui->puntoa->itemText(key);
    QString puntob=ui->puntob->itemText(key2);

    const QString url=tr("http://localhost:8080/WebService/app/getCamino?pta=%1&ptb=%2").arg(puntoa,puntob);
    QEventLoop eventLoop;

    QNetworkAccessManager mgr;
    QObject::connect(&mgr, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));

    QNetworkRequest req( QUrl( QString(url.toUtf8()) ) );
    req.setRawHeader("Content-Type", "application/json");
    QNetworkReply *reply = mgr.get(req);

    eventLoop.exec();


    if (reply->error() == QNetworkReply::NoError) {
        //success
        qDebug() << "camino mas optimo xd";

        QString repla = tr("var puntos_linea = [%1]; var linea = new google.maps.Polyline({path: puntos_linea,geodesic: true, strokeColor: '#FF0000',strokeOpacity: 1.0,strokeWeight: 2}); \n linea.setMap(map);").
                arg(QString::fromStdString(reply->readAll().toStdString()));

        view->setContent(html.replace("//^",repla).toUtf8());
        ofstream ficheroSalida;
        ficheroSalida.open ("/home/andree/Escritorio/EDDArchivos/finalizado.html");
        ficheroSalida << html.toStdString();
        ficheroSalida.close();
        delete reply;

    } else {
        //failure
        qDebug() << "Failure" <<reply->errorString();
        delete reply;
    }
}

void MainWindow::on_puntoa_currentIndexChanged(int index)
{
    key=index;
}

void MainWindow::on_puntob_currentIndexChanged(int index)
{
    key2=index;
}

void MainWindow::on_pushButton_33_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}

//boton para mandar donacion
void MainWindow::on_pushButton_34_clicked()
{
    QString dpi= ui->dpi_donacion->text();
    QString nombres = ui->nombres_donacion->text();
    QString apellidos = ui->apellidos_donacion->text();
    QString fecha = ui->fecha_donacion->text();
    QString monto = ui->monto_donacion->text();

    QString donacion = tr("%1,%2,%3,%4,%5").arg(dpi,nombres,apellidos,fecha,monto);

    QEventLoop eventLoop;

    QNetworkAccessManager mgr;
    QObject::connect(&mgr, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));

    QNetworkRequest req( QUrl( QString("http://localhost:8080/WebService/app/setDonacion") ) );
    req.setRawHeader("Content-Type", "application/json");
    QNetworkReply *reply = mgr.post(req,donacion.toUtf8());

    eventLoop.exec();


    if (reply->error() == QNetworkReply::NoError) {
        //success
        QNetworkReply *respuesta= mgr.get(req);
        eventLoop.exec();
        qDebug() << "Success" << respuesta->readAll();

        delete respuesta;
        delete reply;

    } else {
        //failure
        qDebug() << "Failure" <<reply->errorString();
        delete reply;
    }

}

void MainWindow::on_Carchivo_informacion_clicked()
{
    QString fileNames = QFileDialog::getOpenFileName(this, tr("Open File"),"/path/to/file/",tr("JSON Files (*.json)"));
    cargarArchivo(fileNames);
    ui->archivo_informacion->setText(fileNames);

}

//BOTON para agregar a lista de donaciones
void MainWindow::on_pushButton_35_clicked()
{
    QString codigo = ui->categoria_entrega->text();
    QString nombre = ui->nombre_entrega->text();
    QString unidad = ui->unidades_entrega->text();
    //ui->lst_entrega->clear();
    ui->lst_entrega->append(codigo+" --- "+nombre+" --- "+unidad);
    //bool ok;
    //qInfo()<<unidad.toInt();

    Donacion *temp = new Donacion(codigo,nombre,unidad.toInt());
    qInfo()<<temp->unidades;
    lstDonaciones->agregar(temp);

}

void MainWindow::on_pushButton_36_clicked()
{
    ui->lst_entrega->clear();
    QString codigo;
    QString nombre;
    int unidad;

    Codificador cod;
    nodoD *temp = lstDonaciones->first;

    while(temp!=nullptr){
        codigo=temp->dato->categoria;
        nombre=temp->dato->nombre;
        unidad=temp->dato->unidades;
        int codi = cod.getCodigo(codigo);
        //qInfo()<<"Unidades paso 1 : "<<unidad;
        Tabla->Reduce_AND_Delete(codi,nombre,unidad);

        temp=temp->siguiente;
    }

    //lstDonaciones->borrarLista();
    lstDonaciones=new ListaDoble();


}
//Boton para actualizar tabla
void MainWindow::on_pushButton_37_clicked()
{
    ui->textEdit_2->clear();
    ui->textEdit_2->setText(Tabla->imprimir());
}

void MainWindow::on_cIndividuo_modificar_activated(const QString &arg1)
{

}

// metodo para traer familias
void MainWindow::on_pushButton_22_clicked()
{
    ui->Cindividuo_eliminar->clear();
    QString codigo = ui->cFamilia_eliminar->itemText(key);
    llenarCombo2(lstfamilias.buscar(codigo).arbol->raiz);
}
//metodo para llenar combo2
void MainWindow::llenarCombo2(nodoABB *pivote)
{
    if(pivote==nullptr)
        return;

    llenarCombo2(pivote->izquierda);
   // qInfo()<<'\t'<<pivote->key;
    ui->Cindividuo_eliminar->addItem(QString::number(pivote->key));
    llenarCombo2(pivote->derecha);

}
