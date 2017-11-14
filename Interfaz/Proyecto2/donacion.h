#ifndef DONACION_H
#define DONACION_H
#include <QString>
struct Donacion{
    QString categoria,nombre;
    int unidades;

    Donacion(){
        categoria="";
        nombre="";
        unidades=0;
    }
    Donacion(QString categoria,QString nombre){
        this->categoria=categoria;
        this->nombre=nombre;
        this->unidades=0;
    }
    Donacion(QString categoria,QString nombre, int unidades){
        this->categoria=categoria;
        this->nombre= nombre;
        this->unidades= unidades;
    }


};
#endif // DONACION_H
