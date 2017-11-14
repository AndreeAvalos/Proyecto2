/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package WebService;

import Cifrado.Cifrado;
import Cifrado.traerLocalidad;
import javax.ws.rs.core.Context;
import javax.ws.rs.core.UriInfo;
import javax.ws.rs.Produces;
import javax.ws.rs.Consumes;
import javax.ws.rs.GET;
import javax.ws.rs.Path;
import javax.ws.rs.PUT;
import javax.ws.rs.core.MediaType;

/**
 * REST Web Service
 *
 * @author andree
 */
@Path("getLocalidades")
public class GetLocalidadesResource {

    @Context
    private UriInfo context;

    /**
     * Creates a new instance of GetLocalidadesResource
     */
    public GetLocalidadesResource() {
    }

    /**
     * Retrieves representation of an instance of
     * WebService.GetLocalidadesResource
     *
     * @return an instance of java.lang.String
     */
    @GET
    @Produces(MediaType.APPLICATION_JSON)
    public String getJson() {
        //TODO return proper representation object
        Cifrado cifrar = Cifrado.getInstancia();
        traerLocalidad localidad = new traerLocalidad();
        cifrar.Cifrar(localidad.getLocalidades());
        return cifrar.getArchivo_cifrado();
    }

    /**
     * PUT method for updating or creating an instance of GetLocalidadesResource
     *
     * @param content representation for the resource
     */
    @PUT
    @Consumes(MediaType.APPLICATION_JSON)
    public void putJson(String content) {
    }
}
