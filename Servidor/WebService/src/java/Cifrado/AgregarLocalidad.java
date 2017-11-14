/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Cifrado;

import GrafoDirigido.Arista;
import GrafoDirigido.Grafo;
import GrafoDirigido.NodoGrafo;

/**
 *
 * @author andree
 */
public class AgregarLocalidad {

    public AgregarLocalidad() {
    }

    public void agregar(String cadena) {

        String[] numLineas = cadena.split(";");
        for (int i = 0; i < numLineas.length; i++) {
            String[] tokens = numLineas[i].split(",");
            int contador = tokens.length;
            System.out.println(contador);
            NodoGrafo nuevo = new NodoGrafo(tokens[1], tokens[0], tokens[2], tokens[5], Double.parseDouble(tokens[3]), Double.parseDouble(tokens[4]));

            if (contador >= 8) {
                int j = 6;
                while (j < contador - 1) {
                    Arista arista = new Arista(tokens[j], Double.parseDouble(tokens[j + 1]));
                    nuevo.getAristas().add(arista);
                    j += 2;
                }
            }

            Grafo grafo = Grafo.getInstancia();

            System.out.println(grafo.agregarNodo(nuevo) + "");

        }

    }
}
