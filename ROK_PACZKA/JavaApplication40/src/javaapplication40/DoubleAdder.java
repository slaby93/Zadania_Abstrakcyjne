/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package javaapplication40;

/**
 *
 * @author Tomek
 */
public class DoubleAdder implements Adder<Double> {

    @Override
    public Double add(Double a, Double b) {
        return a + b;
    }

    @Override
    public Double zero() {
        return (double) 0;
    }

}
