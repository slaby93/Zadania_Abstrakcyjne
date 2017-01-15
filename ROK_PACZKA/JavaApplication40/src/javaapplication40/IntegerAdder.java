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
public class IntegerAdder implements Adder<Integer> {

    @Override
    public Integer add(Integer a, Integer b) {
        return a + b;
    }

    @Override
    public Integer zero() {
        return 0;
    }

}
