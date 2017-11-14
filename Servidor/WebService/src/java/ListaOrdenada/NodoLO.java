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
public class NodoLO {

    public NodoLO siguiente, anterior;
    public Donacion dato;

    public NodoLO(Donacion dato) {
        this.dato = dato;
        this.siguiente = null;
        this.anterior = null;
    }

}
