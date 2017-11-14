/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package WebService;

import ArbolB.ArbolB;
import ArbolB.Donacion;
import ArbolB.Donante;
import ArbolB.Generador;
import javax.persistence.QueryHint;
import javax.ws.rs.core.Context;
import javax.ws.rs.core.UriInfo;
import javax.ws.rs.Produces;
import javax.ws.rs.Consumes;
import javax.ws.rs.GET;
import javax.ws.rs.POST;
import javax.ws.rs.Path;
import javax.ws.rs.PUT;
import javax.ws.rs.QueryParam;
import javax.ws.rs.core.MediaType;

/**
 * REST Web Service
 *
 * @author andree
 */
@Path("makeDonacion")
public class MakeDonacionResource {

    @Context
    private UriInfo context;

    /**
     * Creates a new instance of MakeDonacionResource
     */
    public MakeDonacionResource() {
    }

    /**
     * PUT method for updating or creating an instance of MakeDonacionResource
     *
     * @param content representation for the resource
     */
    @PUT
    @Consumes(MediaType.APPLICATION_JSON)
    public void putJson(String content) {
    }

    /**
     * Retrieves representation of an instance of
     * WebService.MakeDonacionResource
     *
     * @param usuario
     * @param fecha
     * @param monto
     * @return an instance of java.lang.String
     *
     */
    @GET
    @Consumes(MediaType.APPLICATION_JSON)
    public String create(@QueryParam("usuario") String usuario, @QueryParam("fecha") String fecha, @QueryParam("monto") String monto) {
        ArbolB arbol = ArbolB.getInstancia();
        Donante temp = arbol.getDonante(usuario);
        if (temp != null) {
            Generador generador = new Generador();
            Donacion nueva = new Donacion(generador.generarID(15), monto, fecha);
            temp.lstDonaciones.agregar(nueva);
            return "Agregado con Exito";
        } else {
            return "No se puede Agregar";
        }
    }
}
