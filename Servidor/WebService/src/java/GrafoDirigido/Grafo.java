/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package GrafoDirigido;

import java.util.ArrayList;
import java.util.HashMap;

/**
 *
 * @author andree
 */
public class Grafo {

    private static Grafo instancia = null;
    HashMap<String, NodoGrafo> nodos;

    public static Grafo getInstancia() {
        synchronized (Grafo.class) {
            if (null == instancia) {
                instancia = new Grafo();
            }
        }
        return instancia;
    }

    private Grafo() {
        nodos = new HashMap<>();
    }

    public ArrayList<NodoGrafo> getNodos() {
        return new ArrayList<>(nodos.values());
    }

    public NodoGrafo obtenerNodo(String id) {
        return nodos.get(id);
    }

    public boolean agregarNodo(NodoGrafo nuevo) {
        String id = nuevo.getCodigo();
        if (nodos.containsKey(id)) {
            return false;
        }
        nodos.put(id, nuevo);
        return true;
    }

    public boolean actualizarNodo(String id, NodoGrafo nuevo) {
        if (!nodos.containsKey(id)) {
            return false;
        }
        nodos.replace(id, nuevo);
        return true;
    }

    public boolean borrarNodo(String id) {
        if (!nodos.containsKey(id)) {
            return false;
        }

        nodos.remove(id);
        return true;
    }

    public double calcularDistancia(String id, String id2) {
        double distancia;
        NodoGrafo PuntoA, PuntoB;
        PuntoA = obtenerNodo(id);
        PuntoB = obtenerNodo(id2);
        double x0, x1, y0, y1;
        x0 = PuntoB.getLongitud();
        x1 = PuntoA.getLongitud();
        y0 = PuntoB.getLatitud();
        y1 = PuntoA.getLatitud();
        double resultPrevio = Math.pow(y1 - y0, 2) + Math.pow(x1 - x0, 2);
        distancia = Math.sqrt(resultPrevio);
        return distancia;
    }
    //Variables posiblemente a utilizar
    private ArrayList<String> lstcaminos = new ArrayList<>();
    private ArrayList<Double> lstPeso = new ArrayList<>();
    private ArrayList<Camino> lstopciones = new ArrayList<>();

    private void caminoMasCorto(String puntoA, String puntoB) {
        lstcaminos.add(puntoA);
        if (puntoA.equals(puntoB)) {
            String result = "";
            for (int i = 0; i < lstcaminos.size(); i++) {
                if (i == 0) {
                    result = lstcaminos.get(i);
                } else {
                    result += "," + lstcaminos.get(i);
                }
            }
            double peso = 0;

            for (int i = 0; i < lstPeso.size(); i++) {
                peso += lstPeso.get(i);

            }
            lstopciones.add(new Camino(result, peso));
            //System.out.println("///peso/// " + peso + " ///ruta/// " + result);
            return;
        } else {
            NodoGrafo ptA = obtenerNodo(puntoA);
            if (ptA != null) {
                int numAristas = ptA.getAristas().size();
                for (int i = 0; i < numAristas; i++) {
                    double peso = ptA.getAristas().get(i).getMultiplicador() * this.calcularDistancia(puntoA, ptA.getAristas().get(i).getDestino());
                    lstPeso.add(peso);
                    caminoMasCorto(ptA.getAristas().get(i).getDestino(), puntoB);
                    lstPeso.remove(lstPeso.size() - 1);
                    lstcaminos.remove(lstcaminos.size() - 1);
                }
            } else {
                return;
            }
        }

    }

    private String getCamino() {
        String result = "No existe Camino";
        double menor = 10000000000.0;
        for (Camino lstopcione : lstopciones) {
            if (menor > lstopcione.getPeso()) {
                menor = lstopcione.getPeso();
                result = lstopcione.getCamino();
            }
        }
        if (!result.equals("No existe Camino")) {
            String[] temp = result.split(",");
            for (int i = 0; i < temp.length; i++) {
                NodoGrafo auxiliar = obtenerNodo(temp[i]);
                if (i == 0) {
                    result = "{lat:" + auxiliar.getLatitud() + ",lng:" + auxiliar.getLongitud() + "}";
                } else {
                    result += ",{lat:" + auxiliar.getLatitud() + ",lng:" + auxiliar.getLongitud() + "}";
                }
            }
        }
        return result;
    }

    public String Djkstra(String puntoA, String puntoB) {
        lstcaminos.clear();
        lstPeso.clear();
        lstopciones.clear();
        caminoMasCorto(puntoA, puntoB);
        return getCamino();
    }
}
