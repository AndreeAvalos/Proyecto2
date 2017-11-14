#ifndef LISTASIMPLE2_H
#define LISTASIMPLE2_H
#include "familia.h"

struct nodo2{
    Familia dato;
    nodo2 *siguiente,*anterior;

    nodo2(Familia dato){
        this->dato=dato;
        siguiente=nullptr;
    }

    Familia getDato(){
        return this->dato;
    }
};
struct ListaSimple2{
    nodo2 *first;
    nodo2 *last;

    int size;

    ListaSimple2(){
        first=nullptr;
        last=nullptr;
        size=0;
    }

    void agregar(Familia dato){
        nodo2 *nuevo = new nodo2(dato);
        if(first==nullptr){
            first=nuevo;
            last=nuevo;
            size++;
            return;
        }else{
            last->siguiente=nuevo;
            nuevo->anterior=last;
            last=nuevo;
            size++;
            return;
        }

    }

    Familia buscar(QString familia){
        nodo2 *temporal = first;
        while(temporal!=nullptr){
            if(temporal->getDato().codigo==familia){
                return temporal->getDato();
            }else
                temporal=temporal->siguiente;
        }
    }

    bool existe(QString val){
        nodo2 *temporal = first;
        while(temporal!=nullptr){
            if(temporal->getDato().codigo==val){
                return true;
            }else
            temporal=temporal->siguiente;
        }
        return false;
    }
    bool eliminar(QString val){
        //Creamos un nodo auxiliar el cual vamos utilizar para recorrer
        nodo2 *temporal = first;

        while(temporal!=nullptr){
            if(temporal->dato.codigo==val){
                if(temporal==first){
                    //hacemos que el nodo siguiente sea la raiz
                    first=temporal->siguiente;
                    //Borramos el espacio en memoria del nodo
                    delete temporal;
                    return true;
                }else if(temporal->siguiente==nullptr){
                    //el nodo anterior apunta hacia el nodo siguiente el cual es nulo
                    temporal->anterior->siguiente=nullptr;
                    //borramos el espacio en memoria del nodo
                    delete temporal;
                    return true;
                }else{
                    //el siguiente del anterior apunta hacia el siguiente del nodo a eliminar
                    temporal->anterior->siguiente=temporal->siguiente;
                    //eliminamos el nodo
                    delete temporal;
                    return true;
                }
            }
            //pasamos al siguiente nodo
            temporal=temporal->siguiente;
        }
        //si llego hasta aqui no se elimino el nodo
        return false;

    }

    void imprimir(){
        nodo2 *temporal = first;
        while(temporal!=nullptr){
            qInfo()<<temporal->getDato().codigo;
            temporal=temporal->siguiente;
        }

    }
};

#endif // LISTASIMPLE2_H
