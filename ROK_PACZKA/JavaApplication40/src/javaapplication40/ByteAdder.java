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
public class ByteAdder implements Adder<Byte> {

    @Override
    public Byte add(Byte a, Byte b) {
        return (byte) (a + b);
    }

    @Override
    public Byte zero() {
        return 0;
    }

}
