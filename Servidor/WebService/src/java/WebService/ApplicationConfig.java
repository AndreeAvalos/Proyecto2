/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package WebService;

import java.util.Set;
import javax.ws.rs.core.Application;

/**
 *
 * @author andree
 */
@javax.ws.rs.ApplicationPath("app")
public class ApplicationConfig extends Application {

    @Override
    public Set<Class<?>> getClasses() {
        Set<Class<?>> resources = new java.util.HashSet<>();
        addRestResourceClasses(resources);
        return resources;
    }

    /**
     * Do not modify addRestResourceClasses() method.
     * It is automatically populated with
     * all resources defined in the project.
     * If required, comment out calling this method in getClasses().
     */
    private void addRestResourceClasses(Set<Class<?>> resources) {
        resources.add(WebService.DeleteLocalidadResource.class);
        resources.add(WebService.FreeLocalidadResource.class);
        resources.add(WebService.GetCaminoResource.class);
        resources.add(WebService.GetDonacionResource.class);
        resources.add(WebService.GetDonacionesResource.class);
        resources.add(WebService.GetGrafoResource.class);
        resources.add(WebService.GetLocalidadResource.class);
        resources.add(WebService.GetLocalidadesResource.class);
        resources.add(WebService.MakeDonacionResource.class);
        resources.add(WebService.ObtenerDonacionResource.class);
        resources.add(WebService.PutLocalidadResource.class);
        resources.add(WebService.SaveLocalidadResource.class);
        resources.add(WebService.SetAristaResource.class);
        resources.add(WebService.SetDonacionResource.class);
        resources.add(WebService.SetLocalidadResource.class);
    }
    
}
