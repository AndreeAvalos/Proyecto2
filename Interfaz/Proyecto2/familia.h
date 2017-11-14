#ifndef FAMILIA_H
#define FAMILIA_H
#include "abb.h"

class Familia
{
public:
    QString codigo;
    ArbolBinarioBusqueda *arbol;
    Familia();
    Familia(QString codigo);
};

#endif // FAMILIA_H
