/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package WebService;

import GrafoDirigido.Grafo;
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
@Path("deleteLocalidad")
public class DeleteLocalidadResource {

    @Context
    private UriInfo context;

    /**
     * Creates a new instance of DeleteLocalidadResource
     */
    public DeleteLocalidadResource() {
    }

    /**
     * Retrieves representation of an instance of
     * WebService.DeleteLocalidadResource
     *
     * @param codigo
     * @return an instance of java.lang.String
     */
    @GET
    @Produces(MediaType.APPLICATION_JSON)
    public String getJson(@QueryParam("codigo") String codigo) {
        //TODO return proper representation object
        boolean estado = false;
        Grafo nuevo = Grafo.getInstancia();
        estado = nuevo.borrarNodo(codigo);
        return estado + "";
    }

    /**
     * PUT method for updating or creating an instance of
     * DeleteLocalidadResource
     *
     * @param content representation for the resource
     */
    @PUT
    @Consumes(MediaType.APPLICATION_JSON)
    public void putJson(String content) {
    }
}
