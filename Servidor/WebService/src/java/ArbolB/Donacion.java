/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package ArbolB;

/**
 *
 * @author andree
 */
public class Donacion {

    private String numVoucher, monto, fecha;

    public Donacion(String numVoucher, String monto, String fecha) {
        this.numVoucher = numVoucher;
        this.monto = monto;
        this.fecha = fecha;
    }

    public String getNumVoucher() {
        return numVoucher;
    }

    public void setNumVoucher(String numVoucher) {
        this.numVoucher = numVoucher;
    }

    public String getMonto() {
        return monto;
    }

    public void setMonto(String monto) {
        this.monto = monto;
    }

    public String getFecha() {
        return fecha;
    }

    public void setFecha(String fecha) {
        this.fecha = fecha;
    }

}
