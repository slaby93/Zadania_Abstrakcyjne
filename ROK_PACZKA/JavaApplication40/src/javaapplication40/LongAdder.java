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
public class LongAdder implements Adder<Long> {

    @Override
    public Long add(Long a, Long b) {
        return a + b;
    }

    @Override
    public Long zero() {
        return (long) 0;
    }
    
}
