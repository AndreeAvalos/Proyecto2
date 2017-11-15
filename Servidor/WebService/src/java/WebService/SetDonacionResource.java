/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package WebService;

import ArbolB.ArbolB;
import Cifrado.Cifrado;
import Cifrado.agregarDonacion;
import java.io.IOException;
import java.util.logging.Level;
import java.util.logging.Logger;
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
@Path("setDonacion")
public class SetDonacionResource {

    @Context
    private UriInfo context;

    /**
     * Creates a new instance of SetDonacionResource
     */
    public SetDonacionResource() {
    }

    /**
     * Retrieves representation of an instance of WebService.SetDonacionResource
     *
     * @return an instance of java.lang.String
     */
    @GET
    @Produces(MediaType.APPLICATION_JSON)
    public String getJson() {
        //TODO return proper representation object
        ArbolB arbol = ArbolB.getInstancia();
        try {
            arbol.printGraphviz();
        } catch (IOException ex) {
            Logger.getLogger(SetDonacionResource.class.getName()).log(Level.SEVERE, null, ex);
        }
        return "Agreagado con Exito";
    }

    @POST
    public void set(String datos) {
        //Cifrado cifra = Cifrado.getInstancia();
        //cifra.Decifrar(datos);
        System.out.println(datos);
        new agregarDonacion().agregar(datos);
        ArbolB temporal = ArbolB.getInstancia();

    }

    /**
     * PUT method for updating or creating an instance of SetDonacionResource
     *
     * @param content representation for the resource
     */
    @PUT
    @Consumes(MediaType.APPLICATION_JSON)
    public void putJson(String content) {
    }
}
