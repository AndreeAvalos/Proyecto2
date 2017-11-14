/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Cifrado;

import GrafoDirigido.Arista;
import GrafoDirigido.Grafo;
import GrafoDirigido.NodoGrafo;
import java.util.ArrayList;

/**
 *
 * @author andree
 */
public class traerLocalidad {

    public traerLocalidad() {
    }

    public String getLocalidades() {
        Grafo grafo = Grafo.getInstancia();
        String resultado = "";
        ArrayList<NodoGrafo> lst = grafo.getNodos();
        for (NodoGrafo nodografo : lst) {
            resultado += nodografo.getCodigo()+","+nodografo.getNombre() + "," + nodografo.getPassword()+"," + nodografo.getLatitud()+"," + nodografo.getLongitud()+"," + nodografo.getArchivo();
            ArrayList<Arista> aristas = nodografo.getAristas();
            resultado = aristas.stream().map((arista) -> ","+arista.getDestino()+"," + arista.getMultiplicador()).reduce(resultado, String::concat);
            resultado += ";";
        }
        return resultado;
    }
}
