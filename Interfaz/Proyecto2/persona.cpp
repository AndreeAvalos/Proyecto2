#include "persona.h"

Persona::Persona()
{
    this->apellido="";
    this->nombre="";
    this->dpi="";
    this->edad="";
}

Persona::Persona(QString dpi, QString edad, QString nombre, QString apellido, QString genero)
{
    this->dpi=dpi;
    this->edad=edad;
    this->nombre=nombre;
    this->apellido=apellido;
    this->genero=genero;
}
