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
@Path("getCamino")
public class GetCaminoResource {

    @Context
    private UriInfo context;

    /**
     * Creates a new instance of GetCaminoResource
     */
    public GetCaminoResource() {
    }

    /**
     * Retrieves representation of an instance of WebService.GetCaminoResource
     * @param puntoA
     * @param puntoB
     * @return an instance of java.lang.String
     */
    @GET
    @Produces(MediaType.APPLICATION_JSON)
    public String getJson(@QueryParam("pta") String puntoA, @QueryParam("ptb")String puntoB) {
        //TODO return proper representation object
        Grafo grago = Grafo.getInstancia();
        return grago.Djkstra(puntoA, puntoB);
    }

    /**
     * PUT method for updating or creating an instance of GetCaminoResource
     * @param content representation for the resource
     */
    @PUT
    @Consumes(MediaType.APPLICATION_JSON)
    public void putJson(String content) {
    }
}
