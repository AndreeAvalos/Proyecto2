#ifndef LISTASIMPLE_H
#define LISTASIMPLE_H
#include <string>
#include <QDebug>

using namespace std;
struct nodo{
    string dato;
    nodo *siguiente;

    nodo(string dato){
        this->dato=dato;
        siguiente=nullptr;
    }

    string getDato(){
        return this->dato;
    }
};
struct ListaSimple{
    nodo *first;
    nodo *last;

    int size;

    ListaSimple(){
        first=nullptr;
        last = nullptr;
        size=0;
    }

    void agregar(string dato){
        nodo *nuevo = new nodo(dato);
        if(first==nullptr){
            first=nuevo;
            last=nuevo;
            size++;
            return;
        }else{
            last->siguiente=nuevo;
            last=nuevo;
            size++;
            return;
        }

    }
    void imprimir(){
        nodo *temporal = first;
        while(temporal!=nullptr){
            qInfo()<<QString::fromStdString(temporal->getDato());
            temporal=temporal->siguiente;
        }

    }
};
#endif // LISTASIMPLE_H
