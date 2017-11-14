/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package ArbolB;

import ListaOrdenada.ListaOrdenada;

/**
 *
 * @author andree
 */
public class Donante {

    public String identificador, nombres, apellidos;

    public ListaOrdenada lstDonaciones;

    public Donante() {
        identificador = "";
        nombres = "";
        apellidos = "";
        lstDonaciones = new ListaOrdenada();
    }

    public Donante(String identificador, String nombres, String apellidos) {
        this.identificador = identificador;
        this.nombres = nombres;
        this.apellidos = apellidos;
        lstDonaciones = new ListaOrdenada();
    }

}
