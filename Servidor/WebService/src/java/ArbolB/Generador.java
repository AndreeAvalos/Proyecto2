/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package ArbolB;

import java.util.ArrayList;

/**
 *
 * @author andree
 */
public class Generador {

    ArrayList<String> lst;

    public Generador() {
        lst = new ArrayList<>();
        lst.add("a");
        lst.add("b");
        lst.add("c");
        lst.add("d");
        lst.add("e");
        lst.add("f");
        lst.add("g");
        lst.add("h");
        lst.add("i");
        lst.add("j");
        lst.add("k");
        lst.add("l");
        lst.add("m");
        lst.add("n");
        lst.add("o");
        lst.add("p");
        lst.add("q");
        lst.add("r");
        lst.add("s");
        lst.add("t");
        lst.add("u");
        lst.add("v");
        lst.add("w");
        lst.add("x");
        lst.add("y");
        lst.add("z");
        lst.add("0");
        lst.add("1");
        lst.add("2");
        lst.add("3");
        lst.add("4");
        lst.add("5");
        lst.add("6");
        lst.add("7");
        lst.add("8");
        lst.add("9");

    }

    public String generarID(int num) {
        String cadena = "";
        for (int i = 0; i < num; i++) {
            int valor = (int) (Math.random() * 34);
            cadena += lst.get(valor);
        }
        return cadena;
    }
}
