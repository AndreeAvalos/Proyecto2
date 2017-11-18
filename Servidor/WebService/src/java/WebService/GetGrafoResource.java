/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package WebService;

import GrafoDirigido.Arista;
import GrafoDirigido.Grafo;
import GrafoDirigido.NodoGrafo;
import javax.ws.rs.core.Context;
import javax.ws.rs.core.UriInfo;
import javax.ws.rs.Produces;
import javax.ws.rs.Consumes;
import javax.ws.rs.GET;
import javax.ws.rs.Path;
import javax.ws.rs.PUT;
import javax.ws.rs.core.MediaType;
import com.google.gson.Gson;
import com.google.gson.GsonBuilder;
import com.google.gson.*;

/**
 * REST Web Service
 *
 * @author andree
 */
@Path("getGrafo")
public class GetGrafoResource {

    @Context
    private UriInfo context;

    /**
     * Creates a new instance of GetGrafoResource
     */
    public GetGrafoResource() {
    }

    /**
     * Retrieves representation of an instance of WebService.GetGrafoResource
     *
     * @return an instance of java.lang.String
     */
    @GET
    @Produces(MediaType.APPLICATION_JSON)
    public String getJson() {
        //TODO return proper representation object
        Grafo grafito = Grafo.getInstancia();
        
        /*NodoGrafo nuevo = new NodoGrafo("1", "c01", "1234", "archivo", 2.3, 2.4);
        Arista arista = new Arista("c02", 1);
        nuevo.getAristas().add(arista);
        arista = new Arista("c03", 2.5);
        nuevo.getAristas().add(arista);
        grafito.agregarNodo(nuevo);

        nuevo = new NodoGrafo("2", "c02", "1234", "archivo", 2.9, 2.3);
        arista = new Arista("c03", 3);
        nuevo.getAristas().add(arista);
        grafito.agregarNodo(nuevo);

        nuevo = new NodoGrafo("3", "c03", "1234", "archivo", 5.8, 2.7);
        arista = new Arista("c04", 2.5);
        nuevo.getAristas().add(arista);
        grafito.agregarNodo(nuevo);

        nuevo = new NodoGrafo("4", "c04", "1234", "archivo", 7.60, 3.2);
        grafito.agregarNodo(nuevo);*/

        //grafito.getNodos();

        Gson gson = new GsonBuilder().setPrettyPrinting().create();

        String jsonString = gson.toJson(grafito.getNodos());
        
        return jsonString;
    }

    /**
     * PUT method for updating or creating an instance of GetGrafoResource
     *
     * @param content representation for the resource
     */
    @PUT
    @Consumes(MediaType.APPLICATION_JSON)
    public void putJson(String content) {
    }
}
