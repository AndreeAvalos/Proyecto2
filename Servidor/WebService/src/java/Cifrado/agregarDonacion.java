/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Cifrado;

import ArbolB.ArbolB;
import ArbolB.Donacion;
import ArbolB.Donante;
import ArbolB.Generador;

/**
 *
 * @author andree
 */
public class agregarDonacion {

    public agregarDonacion() {
    }

    public void agregar(String cadena) {

        String[] numLineas = cadena.split(";");
        for (int i = 0; i < numLineas.length ; i++) {
            String[] tokens = numLineas[i].split(",");
            int contador = tokens.length;
            System.out.println(contador);
            ArbolB arbol =ArbolB.getInstancia();
            
            Donacion nueva = new Donacion(new Generador().generarID(10), tokens[4], tokens[3]);
            Donante nuevo = new Donante(tokens[0], tokens[1], tokens[2]);
            arbol.insert(nuevo, nueva);
            
        }

    }
}
