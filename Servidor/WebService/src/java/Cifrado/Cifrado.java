/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Cifrado;

/**
 *
 * @author andree
 */
public class Cifrado {

    String archivo_cifrado;
    String archivo_decifrado;

    public String getArchivo_cifrado() {
        return archivo_cifrado;
    }

    public void setArchivo_cifrado(String archivo_cifrado) {
        this.archivo_cifrado = archivo_cifrado;
    }

    public String getArchivo_decifrado() {
        return archivo_decifrado;
    }

    public void setArchivo_decifrado(String archivo_decifrado) {
        this.archivo_decifrado = archivo_decifrado;
    }

    private static Cifrado instancia = null;

    public static Cifrado getInstancia() {
        if (instancia == null) {
            instancia = new Cifrado();
        }
        return instancia;
    }

    public Cifrado() {
        archivo_cifrado = "";
    }

    public void Cifrar(String cadena) {
        archivo_cifrado = "";
        String[] numLineas = cadena.split(";");
        
        for (int i = 0; i < numLineas.length; i++) {
            String numLinea = numLineas[i];
            String[] tokens = numLinea.split(",");
            int contador = 0;
            for (String token : tokens) {
                String tok = Codificar(token);
                if (contador == 0) {
                    archivo_cifrado += tok;
                } else {
                    archivo_cifrado += "," + tok;
                }
                contador++;
            }
            archivo_cifrado += ";";
        }
    }

    public void Decifrar(String cadena) {
        archivo_decifrado = "";
        String[] numLineas = cadena.split(";");
        for (int i = 0; i < numLineas.length; i++) {
            String numLinea = numLineas[i];
            String[] tokens = numLinea.split(",");
            int contador = 0;
            for (String token : tokens) {
                String tok = Decodificar(token);
                if (contador == 0) {
                    archivo_decifrado += tok;
                } else {
                    archivo_decifrado += "," + tok;
                }
                contador++;
            }
            archivo_decifrado += ";";
        }
    }

    private String Codificar(String cadena) {
        String resultado = "";
        for (int i = 0; i < cadena.length(); i++) {
            switch (cadena.charAt(i)) {
                case 'a':
                    resultado += "k";
                    break;
                case 'b':
                    resultado += "j";
                    break;
                case 'c':
                    resultado += "r";
                    break;
                case 'd':
                    resultado += "s";
                    break;
                case 'e':
                    resultado += "z";
                    break;
                case 'f':
                    resultado += "v";
                    break;
                case 'g':
                    resultado += "a";
                    break;
                case 'h':
                    resultado += "c";
                    break;
                case 'i':
                    resultado += "b";
                    break;
                case 'j':
                    resultado += "g";
                    break;
                case 'k':
                    resultado += "h";
                    break;
                case 'l':
                    resultado += "o";
                    break;
                case 'm':
                    resultado += "q";
                    break;
                case 'n':
                    resultado += "m";
                    break;
                case 'o':
                    resultado += "d";
                    break;
                case 'p':
                    resultado += "n";
                    break;
                case 'q':
                    resultado += "t";
                    break;
                case 'r':
                    resultado += "x";
                    break;
                case 's':
                    resultado += "i";
                    break;
                case 't':
                    resultado += "e";
                    break;
                case 'u':
                    resultado += "y";
                    break;
                case 'v':
                    resultado += "f";
                    break;
                case 'w':
                    resultado += "l";
                    break;
                case 'x':
                    resultado += "p";
                    break;
                case 'y':
                    resultado += "u";
                    break;
                case 'z':
                    resultado += "w";
                    break;
                case '0':
                    resultado += "=";
                    break;
                case '1':
                    resultado += "!";
                    break;
                case '2':
                    resultado += "@";
                    break;
                case '3':
                    resultado += "(";
                    break;
                case '4':
                    resultado += ")";
                    break;
                case '5':
                    resultado += "$";
                    break;
                case '6':
                    resultado += "#";
                    break;
                case '7':
                    resultado += "-";
                    break;
                case '8':
                    resultado += "+";
                    break;
                case '9':
                    resultado += "*";
                    break;
                case '.':
                    resultado += "^";
                    break;
                case '/':
                    resultado += "_";
                    break;
                default:
                    //resultado +=cadena.charAt(i);
                    break;
            }
        }
        return resultado;
    }

    private String Decodificar(String cadena) {
        String resultado = "";
        for (int i = 0; i < cadena.length(); i++) {
            switch (cadena.charAt(i)) {
                case 'k':
                    resultado += "a";
                    break;
                case 'j':
                    resultado += "b";
                    break;
                case 'r':
                    resultado += "c";
                    break;
                case 's':
                    resultado += "d";
                    break;
                case 'z':
                    resultado += "e";
                    break;
                case 'v':
                    resultado += "f";
                    break;
                case 'a':
                    resultado += "g";
                    break;
                case 'c':
                    resultado += "h";
                    break;
                case 'b':
                    resultado += "i";
                    break;
                case 'g':
                    resultado += "j";
                    break;
                case 'h':
                    resultado += "k";
                    break;
                case 'o':
                    resultado += "l";
                    break;
                case 'q':
                    resultado += "m";
                    break;
                case 'm':
                    resultado += "n";
                    break;
                case 'd':
                    resultado += "o";
                    break;
                case 'n':
                    resultado += "p";
                    break;
                case 't':
                    resultado += "q";
                    break;
                case 'x':
                    resultado += "r";
                    break;
                case 'i':
                    resultado += "s";
                    break;
                case 'e':
                    resultado += "t";
                    break;
                case 'y':
                    resultado += "u";
                    break;
                case 'f':
                    resultado += "v";
                    break;
                case 'l':
                    resultado += "w";
                    break;
                case 'p':
                    resultado += "x";
                    break;
                case 'u':
                    resultado += "y";
                    break;
                case 'w':
                    resultado += "z";
                    break;
                case '=':
                    resultado += "0";
                    break;
                case '!':
                    resultado += "1";
                    break;
                case '@':
                    resultado += "2";
                    break;
                case '(':
                    resultado += "3";
                    break;
                case ')':
                    resultado += "4";
                    break;
                case '$':
                    resultado += "5";
                    break;
                case '#':
                    resultado += "6";
                    break;
                case '-':
                    resultado += "7";
                    break;
                case '+':
                    resultado += "8";
                    break;
                case '*':
                    resultado += "9";
                    break;
                case '^':
                    resultado += ".";
                    break;
                case '_':
                    resultado += "/";
                    break;
                default:
                    //resultado +=cadena.charAt(i);
                    break;
            }
        }
        return resultado;
    }
}
