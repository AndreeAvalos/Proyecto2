#ifndef PERSONA_H
#define PERSONA_H
#include <QString>

class Persona
{
public:
    QString dpi,edad;
    QString nombre,apellido,genero;
    Persona();
    Persona(QString dpi,QString edad, QString nombre, QString apellido,QString genero);
};

#endif // PERSONA_H
