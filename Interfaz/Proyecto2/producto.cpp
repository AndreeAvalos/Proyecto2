#include "producto.h"

Producto::Producto()
{
    this->codigo="";
    this->nombre="";
    this->cantidad=0;
}

Producto::Producto(QString codigo, QString nombre, int cantidad)
{
    this->codigo=codigo;
    this->nombre=nombre;
    this->cantidad=cantidad;
}
