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
public class FloatAdder implements Adder<Float> {

    @Override
    public Float add(Float a, Float b) {
        return a + b;
    }

    @Override
    public Float zero() {
        return (float) 0;
    }

}
