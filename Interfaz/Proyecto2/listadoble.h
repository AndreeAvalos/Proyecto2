#ifndef LISTADOBLE_H
#define LISTADOBLE_H
#include <donacion.h>
#include <QDebug>
#include <fstream>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <QString>


struct nodoD{
    Donacion *dato;
    nodoD *siguiente,*anterior;

    nodoD(Donacion *nodo){
        this->dato=nodo;
        this->siguiente=nullptr;
        this->anterior=nullptr;
    }

    Donacion* getDato(){
        return this->dato;
    }
};
using namespace std;
struct ListaDoble{
    nodoD *first, *last;
    int size;

    ListaDoble(){
        this->size=0;
        this->first=nullptr;
        this->last=nullptr;
    }

    bool agregar(Donacion *donacion){
        nodoD *nuevo = new nodoD(donacion);
        if(first==nullptr){
            first=nuevo;
            last=nuevo;
            size++;
            return true;
        }else{
            if(existe(donacion->nombre)==false){
                last->siguiente=nuevo;
                nuevo->anterior=last;
                last=nuevo;
                size++;
                return true;
            }else{
                //No se inserto por que ya esta repetido;
                qInfo()<<"Ya existe el registro";
                return false;
            }
        }
        //No se inserto;
        return false;
    }

    Donacion* get(int index){
        int fin = 0;
        Donacion *result = NULL;
        nodoD *temporal = first;

        while(index<fin){
        result = temporal->getDato();
        temporal =temporal->siguiente;

        }
        return result;
    }

    bool getDonacion(QString nombre, int unidades){
        nodoD *temp = first;
        while(temp!=nullptr){
            if(temp->getDato()->nombre==nombre){
                temp->getDato()->unidades+=unidades;
                return true;
            }else
                temp= temp->siguiente;
        }
        return false;
    }

    bool borrar(QString nombre){
        nodoD *temporal=first;
        while(temporal!=nullptr){
            if(temporal->getDato()->nombre==nombre){
                if(temporal==first){
                    first=temporal->siguiente;
                    delete temporal;
                    return true;
                }else{
                    if(temporal->siguiente==nullptr){
                        //qInfo()<<"el siguiente es nulo";
                        temporal->anterior->siguiente=nullptr;
                        delete temporal;
                    }else{
                        temporal->anterior->siguiente=temporal->siguiente;
                        delete temporal;
                        //qInfo()<< "el siguiente no es nulo es: "<<temporal->siguiente->dato->nombre;
                    }
                    return true;}
            }else
                temporal=temporal->siguiente;
        }
        return false;
    }

    bool existe(QString nombre){
        nodoD *temporal = first;

        while(temporal!= nullptr){
            if(temporal->getDato()->nombre==nombre){
                return true;
            }else
                temporal = temporal->siguiente;
        }
        return false;
    }
    QString imprimir(){
        QString result="";
        nodoD *temporal = first;
        if(first==nullptr){
        qInfo()<<"No exist valores en esta lista";
        }else{
            while(temporal!=nullptr){
                Donacion *auxiliar = temporal->getDato();
                //qInfo()<< auxiliar->nombre<<" ----- "<<auxiliar->unidades;
                result +="Nombre: "+auxiliar->nombre+" Unidades: "+QString::number(auxiliar->unidades)+"\n";
                temporal = temporal->siguiente;
            }
        }
        return result;
    }
    QString graficarLista(){
       // std::ofstream ficheroSalida;
        //ficheroSalida.open ("/home/andree/Escritorio/lista.txt");
        //ficheroSalida << "digraph{ bgcolor = gray \n node[fontcolor = \"white \", height = 0.5, color = \"white \"] \n [shape=rect, style=filled, color=blue] \n rankdir=UD \n edge  [color=\"white\", dir=fordware]\n";
        QString resul= "";

        nodoD *temp = first;

         while(temp!=nullptr){

             resul+='\"'+temp->dato->nombre+"\"[label=\" Nombre: "+temp->dato->nombre+" Unidades: "+QString::number(temp->dato->unidades)+"\"];\n";
             temp = temp->siguiente;
         }

         temp = first;
         while(temp!=nullptr){
             if(temp==first){
                 resul+='\"'+temp->dato->nombre+'\"';
             }else
                 resul+="-> \""+temp->dato->nombre+ '\"';
             temp = temp->siguiente;
         }

         //ficheroSalida<<resul.toStdString();
         //ficheroSalida<<"}";
         //ficheroSalida.close();
         //system("dot -Tpng /home/andree/Escritorio/lista.txt -o /home/andree/Escritorio/lista.png");
         return resul;
    }
};

#endif // LISTADOBLE_H
