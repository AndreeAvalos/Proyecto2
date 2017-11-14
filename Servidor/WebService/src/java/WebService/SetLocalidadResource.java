/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package WebService;

import Cifrado.AgregarLocalidad;
import Cifrado.Cifrado;
import javax.ws.rs.core.Context;
import javax.ws.rs.core.UriInfo;
import javax.ws.rs.Produces;
import javax.ws.rs.Consumes;
import javax.ws.rs.GET;
import javax.ws.rs.POST;
import javax.ws.rs.Path;
import javax.ws.rs.PUT;
import javax.ws.rs.core.MediaType;

/**
 * REST Web Service
 *
 * @author andree
 */
@Path("setLocalidad")
public class SetLocalidadResource {
    
    @Context
    private UriInfo context;

    /**
     * Creates a new instance of SetLocalidadResource
     */
    public SetLocalidadResource() {
    }

    /**
     * Retrieves representation of an instance of
     * WebService.SetLocalidadResource
     *
     * @return an instance of java.lang.String
     */
    @GET
    @Produces(MediaType.APPLICATION_JSON)
    public String getJson() {
        //TODO return proper representation object
        return "Exito";
    }
    
    @POST
    public void set(String datos) {
        Cifrado cifra = Cifrado.getInstancia();
        //cifra.Decifrar(datos);
        System.out.println(datos);
        AgregarLocalidad agregar = new AgregarLocalidad();
        agregar.agregar(datos);
        
    }

    /**
     * PUT method for updating or creating an instance of SetLocalidadResource
     *
     * @param content representation for the resource
     */
    @PUT
    @Consumes(MediaType.APPLICATION_JSON)
    public void putJson(String content) {
    }
}
