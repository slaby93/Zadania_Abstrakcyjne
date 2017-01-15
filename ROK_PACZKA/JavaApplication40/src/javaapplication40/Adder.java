/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package javaapplication40;

/**
 *
 * @author Tomek
 * @param <T>
 */
public interface Adder<T> {
    
    T add(T a, T b);
    
    T zero();
    
}
