/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package WebService;

import GrafoDirigido.Arista;
import GrafoDirigido.Grafo;
import GrafoDirigido.NodoGrafo;
import javax.faces.convert.DoubleConverter;
import javax.persistence.Convert;
import javax.ws.rs.core.Context;
import javax.ws.rs.core.UriInfo;
import javax.ws.rs.Produces;
import javax.ws.rs.Consumes;
import javax.ws.rs.GET;
import javax.ws.rs.Path;
import javax.ws.rs.PUT;
import javax.ws.rs.QueryParam;
import javax.ws.rs.core.MediaType;

/**
 * REST Web Service
 *
 * @author andree
 */
@Path("setArista")
public class SetAristaResource {

    @Context
    private UriInfo context;

    /**
     * Creates a new instance of SetAristaResource
     */
    public SetAristaResource() {
    }

    /**
     * Retrieves representation of an instance of WebService.SetAristaResource
     *
     * @param codigo
     * @param destino
     * @param multiplicador
     * @return an instance of java.lang.String
     */
    @GET
    @Produces(MediaType.APPLICATION_JSON)
    public String getJson(@QueryParam("codigo") String codigo, @QueryParam("destino") String destino, @QueryParam("multiplicador") String multiplicador) {
        //TODO return proper representation object
        Grafo grafito = Grafo.getInstancia();
        NodoGrafo temporal = grafito.obtenerNodo(codigo);
        String agregado = "FALSE";
        if (temporal != null) {
            agregado = "TRUE";
            temporal.getAristas().add((new Arista(destino, Double.parseDouble(multiplicador))));
        }

        return agregado;
    }

    /**
     * PUT method for updating or creating an instance of SetAristaResource
     *
     * @param content representation for the resource
     */
    @PUT
    @Consumes(MediaType.APPLICATION_JSON)
    public void putJson(String content) {
    }
}
