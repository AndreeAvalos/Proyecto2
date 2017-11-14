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
import javax.ws.rs.POST;
import javax.ws.rs.Path;
import javax.ws.rs.PUT;
import javax.ws.rs.core.MediaType;
import com.google.gson.JsonArray;
import com.google.gson.JsonElement;
import com.google.gson.JsonObject;
import com.google.gson.JsonParser;

/**
 * REST Web Service
 *
 * @author andree
 */
@Path("putLocalidad")
public class PutLocalidadResource {

    @Context
    private UriInfo context;

    /**
     * Creates a new instance of PutLocalidadResource
     */
    public PutLocalidadResource() {
    }

    /**
     * Retrieves representation of an instance of
     * WebService.PutLocalidadResource
     *
     * @return an instance of java.lang.String
     */
    @GET
    @Produces(MediaType.APPLICATION_JSON)
    public String getJson() {
        //TODO return proper representation object
        throw new UnsupportedOperationException();
    }

    @POST
    @Consumes(MediaType.APPLICATION_JSON)
    public String create(String nueva) {
        JsonParser parser = new JsonParser();
        boolean estado=false;
        // Obtain Array
        JsonArray gsonArr = parser.parse(nueva).getAsJsonArray();

        // for each element of array
        for (JsonElement obj : gsonArr) {

            // Object of array
            JsonObject gsonObj = obj.getAsJsonObject();

            // Primitives elements of object
            int dorsal = gsonObj.get("dorsal").getAsInt();
            String name = gsonObj.get("name").getAsString();
            String team = gsonObj.get("team").getAsString();

            String codigo = gsonObj.get("codigo").getAsString();
            String nombre = gsonObj.get("nombre").getAsString();
            String password = gsonObj.get("password").getAsString();
            double latitud = gsonObj.get("lat").getAsDouble();
            double longitud = gsonObj.get("lng").getAsDouble();
            String archivo = gsonObj.get("archivo").getAsString();

            NodoGrafo mod = new NodoGrafo(nombre, codigo, password, archivo, latitud, longitud);
            Grafo grafo = Grafo.getInstancia();
            estado = grafo.actualizarNodo(codigo, mod);

        }
        return "Estado: " + estado;
    }

    /**
     * PUT method for updating or creating an instance of PutLocalidadResource
     *
     * @param content representation for the resource
     */
    @PUT
    @Consumes(MediaType.APPLICATION_JSON)
    public void putJson(String content) {
    }
}
