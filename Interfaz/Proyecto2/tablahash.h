#ifndef TABLAHASH_H
#define TABLAHASH_H

#include <fstream>
#include <iostream>
#include <string>
#include <stdlib.h>
#include "listadoble.h"
#include <QString>

class Nodo
{
public:
    int id; //identificador del nodo
    ListaDoble* lst;
    /*Aqui podes declarar cualquier variable
     *Para guardar lo que necesites*/
    bool eliminado; //Esta variable esta para saber si el nodo se inserto anteriormente y fue eliminado
    Nodo(int id, Donacion *valor); //Constructor
};

class TablaHash
{
public:
    Nodo **Tabla; //Este es un arreglo de nodos, ** significa que esta creando arreglos de espacios de memorias
    TablaHash(int TAMTABLA); // constructor, manda como parametro el tamanio de la tabla, recordar que siempre es un numero primo
    bool existe(int id);
    void insertar(int id, Donacion* valor);
    void borrar(int id);
    QString imprimir();
    int getTamTabla();
    bool eliminar(int id,QString nombre);
    void graficarTabla();
    void Reduce_AND_Delete(int codigo,QString nombre,int unidades);
private:
    int TAMTABLA;
    int numElementos;
    double factorCarga;
    int posicionTabla(int id); // Metodo de funcion dispersa
    int siguienteTam(int tam); //  obtiene el siguiente numero primo
    void rehashing(int tam); // si exede el factor de carga, cambiar tamanio de la tabla;
    ListaDoble* getDonacion(int id);
};

#endif // TABLAHASH_H
