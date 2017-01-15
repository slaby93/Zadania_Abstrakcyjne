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
public class ShortAdder implements Adder<Short> {

    @Override
    public Short add(Short a, Short b) {
        return (short) (a + b);
    }

    @Override
    public Short zero() {
        return 0;
    }

}
