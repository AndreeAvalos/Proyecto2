/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package WebService;

import ArbolB.ArbolB;
import ArbolB.Donante;
import Cifrado.Cifrado;
import GrafoDirigido.NodoGrafo;
import ListaOrdenada.ListaOrdenada;
import ListaOrdenada.NodoLO;
import java.util.ArrayList;
import javax.ws.rs.core.Context;
import javax.ws.rs.core.UriInfo;
import javax.ws.rs.Consumes;
import javax.ws.rs.Produces;
import javax.ws.rs.GET;
import javax.ws.rs.Path;
import javax.ws.rs.PUT;
import javax.ws.rs.core.MediaType;

/**
 * REST Web Service
 *
 * @author andree
 */
@Path("getDonaciones2")
public class GetDonacionesResource {

    @Context
    private UriInfo context;

    /**
     * Creates a new instance of GetDonacionesResource
     */
    public GetDonacionesResource() {
    }

    /**
     * Retrieves representation of an instance of
     * WebService.GetDonacionesResource
     *
     * @return an instance of java.lang.String
     */
    @GET
    @Produces(MediaType.APPLICATION_JSON)
    public String getJson() {
        //TODO return proper representation object
        String cadena = "";
        ArbolB nuevo = ArbolB.getInstancia();
        ArrayList<Donante> nuev = nuevo.getDonante();
        for (int i = 0; i < nuev.size(); i++) {
            System.out.println(nuev.get(i).identificador);
            ListaOrdenada temporal = nuev.get(i).lstDonaciones;

            NodoLO temp = temporal.getFirst();
            while (temp != null) {
                cadena += nuev.get(i).identificador + "," + nuev.get(i).nombres + "," + nuev.get(i).apellidos + "," + temp.dato.getFecha() + "," + temp.dato.getMonto();
                cadena += ";";
                temp = temp.siguiente;
            }
        }
        Cifrado cifrar = new Cifrado();
        cifrar.Cifrar(cadena);
        return cifrar.getArchivo_cifrado();
    }

    /**
     * PUT method for updating or creating an instance of GetDonacionesResource
     *
     * @param content representation for the resource
     */
    @PUT
    @Consumes(MediaType.APPLICATION_JSON)
    public void putJson(String content) {
    }
}
