#include "familia.h"

Familia::Familia()
{
    this->codigo="";
    this->arbol=nullptr;
}

Familia::Familia(QString codigo)
{
    this->codigo=codigo;
    this->arbol= new ArbolBinarioBusqueda();
}
