/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package WebService;

import ArbolB.Donacion;
import GrafoDirigido.Grafo;
import java.util.ArrayList;
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
@Path("getDonaciones")
public class ObtenerDonacionResource {

    @Context
    private UriInfo context;

    /**
     * Creates a new instance of ObtenerDonacionResource
     */
    public ObtenerDonacionResource() {
    }

    /**
     * Retrieves representation of an instance of WebService.ObtenerDonacionResource
     * @param usuario
     * @return an instance of java.lang.String
     */
    @GET
    @Produces(MediaType.APPLICATION_JSON)
    public String getJson(@QueryParam("usuario") String usuario) {
        //TODO return proper representation object
        return "no lo hice xd";
    }

    /**
     * PUT method for updating or creating an instance of ObtenerDonacionResource
     * @param content representation for the resource
     */
    @PUT
    @Consumes(MediaType.APPLICATION_JSON)
    public void putJson(String content) {
    }
}
