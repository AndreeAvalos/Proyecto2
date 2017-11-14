/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package ListaOrdenada;

import ArbolB.Donacion;

/**
 *
 * @author andree
 */
public class ListaOrdenada {

    private NodoLO first;
    private int size;

    public ListaOrdenada() {
        first = null;
        size = 0;
    }

    public boolean isEmpty() {
        return first == null;
    }

    public void agregar(Donacion val) {
        NodoLO nuevo = new NodoLO(val);
        if (isEmpty() == true) {
            first = nuevo;
            size++;
            return;
        }
        if (first.siguiente == null) {
            int comparison = val.getFecha().compareTo(first.dato.getFecha());
            if (comparison > 0) {
                first.siguiente = nuevo;
                size++;
                return;
            }
            if (comparison < 0) {
                nuevo.siguiente = first;
                first = nuevo;
                size++;
                return;
            }
            return;
        }

        NodoLO aux = first;
        NodoLO ant = null;
        int comparison;
        while (aux.siguiente != null) {
            comparison = val.getFecha().compareTo(aux.dato.getFecha());
            if (comparison > 0) {
                ant = aux;
                aux = aux.siguiente;
                continue;
            }
            if (comparison < 0) {
                if (ant == null) {
                    nuevo.siguiente = first;
                    first = nuevo;
                } else {
                    ant.siguiente = nuevo;
                    nuevo.siguiente = aux;
                }
                size++;
                return;
            }
            return;
        }
        comparison = val.getFecha().compareTo(aux.dato.getFecha());
        if (comparison > 0) {
            aux.siguiente = nuevo;
        }
        if (comparison <= 0) {
            if (ant == null) {
                nuevo.siguiente = first;
                first = nuevo;

            } else {
                ant.siguiente = nuevo;
                nuevo.siguiente = aux;
            }
        }
        size++;

    }

    public void imprimir() {
        NodoLO temporal = first;
        while(temporal!=null){
            System.out.println(temporal.dato.getFecha());
            temporal = temporal.siguiente;
        }
        
    }

    //--------------------- GETS y SETS------------------------
    public NodoLO getFirst() {
        return first;
    }

    public void setFirst(NodoLO first) {
        this.first = first;
    }

    public int getSize() {
        return size;
    }

    public void setSize(int size) {
        this.size = size;
    }

}
