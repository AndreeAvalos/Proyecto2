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
public class Arista {

    private String destino;
    private double multiplicador;

    public Arista() {
    }

    public Arista(String destino, double multiplicador) {
        this.destino = destino;
        this.multiplicador = multiplicador;
    }

    public String getDestino() {
        return destino;
    }

    public void setDestino(String destino) {
        this.destino = destino;
    }

    public double getMultiplicador() {
        return multiplicador;
    }

    public void setMultiplicador(double multiplicador) {
        this.multiplicador = multiplicador;
    }


}
