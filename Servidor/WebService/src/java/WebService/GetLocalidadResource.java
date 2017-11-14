/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package WebService;

import GrafoDirigido.Grafo;
import GrafoDirigido.NodoGrafo;
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
@Path("getLocalidad")
public class GetLocalidadResource {

    @Context
    private UriInfo context;

    /**
     * Creates a new instance of GetLocalidadResource
     */
    public GetLocalidadResource() {
    }

    /**
     * Retrieves representation of an instance of
     * WebService.GetLocalidadResource
     *
     * @param codigo
     * @param password
     * @return an instance of java.lang.String
     */
    @GET
    @Produces(MediaType.APPLICATION_JSON)
    public String getJson(@QueryParam("codigo") String codigo, @QueryParam("password") String password) {
        //TODO return proper representation object
        Grafo grafo = Grafo.getInstancia();
        NodoGrafo temporal = grafo.obtenerNodo(codigo);
        if (temporal.getCodigo().equals(codigo) && temporal.getPassword().equals(password)) {

            return temporal.getArchivo();
        } else {
            return "Operacion no se pudo completar....";
        }
    }

    /**
     * PUT method for updating or creating an instance of GetLocalidadResource
     *
     * @param content representation for the resource
     */
    @PUT
    @Consumes(MediaType.APPLICATION_JSON)
    public void putJson(String content) {
    }
}
