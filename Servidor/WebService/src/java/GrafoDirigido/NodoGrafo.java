/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package GrafoDirigido;

import java.util.ArrayList;

/**
 *
 * @author andree
 */
public class NodoGrafo {

    private String nombre, codigo, password, archivo;
    private double lat, lng;
    private ArrayList<Arista> aristas;

    public NodoGrafo(String nombre, String codigo, String password, String archivo, double latitud, double longitud) {
        this.nombre = nombre;
        this.codigo = codigo;
        this.password = password;
        this.archivo = archivo;
        this.lat = latitud;
        this.lng = longitud;
        this.aristas = new ArrayList<>();
    }

    public String getNombre() {
        return nombre;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    public String getCodigo() {
        return codigo;
    }

    public void setCodigo(String codigo) {
        this.codigo = codigo;
    }

    public String getPassword() {
        return password;
    }

    public void setPassword(String password) {
        this.password = password;
    }

    public String getArchivo() {
        return archivo;
    }

    public void setArchivo(String archivo) {
        this.archivo = archivo;
    }

    public double getLatitud() {
        return lat;
    }

    public void setLatitud(double lat) {
        this.lat = lat;
    }

    public double getLongitud() {
        return lng;
    }

    public void setLongitud(double longitud) {
        this.lng = longitud;
    }

    public ArrayList<Arista> getAristas() {
        return aristas;
    }

    public void setAristas(ArrayList<Arista> aristas) {
        this.aristas = aristas;
    }

}
