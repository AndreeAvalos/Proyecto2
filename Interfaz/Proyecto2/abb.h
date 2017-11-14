#ifndef ABB_H
#define ABB_H
#include<QDebug>
#include <fstream>
#include <iostream>
#include <string>
#include <stdlib.h>
#include "persona.h"

//Nodo del arbol binario de busqueda
struct nodoABB{
    //tipo de dato que deseamos guardar
    Persona *dato;
    //identificador
    int key;
    //hijos a izquierda y derecha
    struct nodoABB *izquierda,*derecha;

    //Constructor del nodo
    nodoABB(int dpi, Persona *cuerpo){
        this->dato=cuerpo;
        this->key=dpi;
        izquierda=nullptr;
        derecha=nullptr;
    }

    Persona* getValor(){
        return this->dato;
    }
};

//Estructura de arbol binario de busqueda
struct ArbolBinarioBusqueda{
    //nodo padre, o nodo principal
    nodoABB *raiz;
    //constructor del arbol
    ArbolBinarioBusqueda(){
        raiz=nullptr;
    }

    //Metodos publicos
public:
    //metodo de inserccion
    void insert(int nuevo, Persona *dato){

        if(raiz == nullptr){
            raiz= new nodoABB(nuevo,dato);
            return;
        }

        insertar(raiz,nuevo,dato);
    }
    //impresion en pre orden
    void preOrden(){
        pre(this->raiz);
    }
    //impresion en post orden
    void postOrden(){
        post(this->raiz);
    }
    //impresion in orden
    void inOrden(){
        in(this->raiz);
    }

    //Metodo de Busqueda
    Persona * buscar(int valor){
        return search(valor, raiz);
    }

    bool existe(int valor, nodoABB *pivote){
        if(pivote==nullptr)
            return false;
        if(pivote->key==valor)
            return true;
        else if(valor<pivote->key)
             existe(valor,pivote->izquierda);
        else if(valor>pivote->key)
             existe(valor,pivote->derecha);
        else
            return false;
        return false;
    }

    //Metodo de impresion de arbol;
    void impreArbol(){
        impreArbol(this->raiz,nullptr);
    }

    //Metodos privados
private:
    //Variable para escribir en el archivo
    std:: ofstream ficheroSalida;
    //metodo de inserccion
    void insertar(nodoABB *pivote, int nuevo, Persona *dato){

        if(nuevo>pivote->key){
            if(pivote->derecha==nullptr)
                pivote->derecha = new nodoABB(nuevo,dato);
            else
                insertar(pivote->derecha,nuevo,dato);
            return;
        }
        if(nuevo<pivote->key){
            if(pivote->izquierda==nullptr)
                pivote->izquierda= new nodoABB(nuevo,dato);
            else
                insertar(pivote->izquierda,nuevo,dato);
            return;
        }
        qInfo()<<"Nodo Repetido: "<< nuevo;
    }

    //metodo de imprension interno en orden (izquierda, raiz, derecha)
    void in(nodoABB *pivote){
        //se verifica si la raiz es nula
        if(pivote==nullptr)
            return;

        in(pivote->izquierda);
        qInfo()<<'\t'<<pivote->key;
        in(pivote->derecha);
    }
    //metodo de impresion interno post orden (izquierda, derecha, raiz)
    void post(nodoABB *pivote){
        if(pivote==nullptr)
            return;
        post(pivote->izquierda);
        post(pivote->derecha);
        qInfo()<<'\t'<<pivote->key;
    }
    //metodo de impresion interno pre orden (raiz, izquierda, derecha)
    void pre(nodoABB *pivote){
        if(pivote==nullptr)
            return;
        qInfo()<< '\t'<<pivote->key;
        pre(pivote->izquierda);
        pre(pivote->derecha);
    }

    Persona * search(int valor, nodoABB *pivote){
        if(pivote->key==valor)
            return pivote->dato;
        else{
            if(valor<pivote->key)
            search(valor,pivote->izquierda);
            else if(valor>pivote->key)
            search(valor,pivote->derecha);
        }
        return NULL;
    }
    void impreArbol(nodoABB *nodo, nodoABB *padre){
        if(nodo!=nullptr){
            if(padre==nullptr){
                ficheroSalida.open("/home/andree/Escritorio/EDDArchivos/ArbolBinario.txt");
                ficheroSalida << "digraph{ bgcolor = gray \n node[fontcolor = \"white \", height = 0.5, color = \"white \"] \n [shape=circle, style=filled, color=blue] \n rankdir=UD \n edge  [color=\"white\", dir=fordware]\n";
                ficheroSalida << '\"' << nodo->key << "\" ; \n";
                impreArbol(nodo->izquierda,nodo);
                impreArbol(nodo->derecha,nodo);
                ficheroSalida<<"}";
                ficheroSalida.close();
                qInfo()<<system("dot -Tpng /home/andree/Escritorio/EDDArchivos/ArbolBinario.txt -o /home/andree/Escritorio/EDDArchivos/ArbolBinario.png");
            }else{
                ficheroSalida << '\"'<< padre->key<< '\"'<< "->" << '\"'<< nodo->key<<"\" ; \n";
                impreArbol(nodo->izquierda,nodo);
                impreArbol(nodo->derecha,nodo);
            }
        }
    }
};


#endif // ABB_H
