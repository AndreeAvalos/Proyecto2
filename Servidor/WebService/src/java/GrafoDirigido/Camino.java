/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package GrafoDirigido;

/**
 *
 * @author andree
 */
public class Camino {

    private String camino;
    private double peso;

    public Camino() {

    }

    public Camino(String camino, double peso) {
        this.camino = camino;
        this.peso = peso;
    }

    public String getCamino() {
        return camino;
    }

    public void setCamino(String camino) {
        this.camino = camino;
    }

    public double getPeso() {
        return peso;
    }

    public void setPeso(double peso) {
        this.peso = peso;
    }

}
