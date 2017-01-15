/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package javaapplication40;

import java.util.Objects;

/**
 *
 * @author Tomek
 * @param <X>
 * @param <Y>
 */
public class Pair<X, Y> {
    
    private final X x;
    private final Y y;
    
    public Pair(X x, Y y) {
        this.x = x;
        this.y = y;
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj) {
            return true;
        }
        if (obj == null) {
            return false;
        }
        if (getClass() != obj.getClass()) {
            return false;
        }
        final Pair<?, ?> other = (Pair<?, ?>) obj;
        if (!Objects.equals(this.x, other.x)) {
            return false;
        }
        if (!Objects.equals(this.y, other.y)) {
            return false;
        }
        return true;
    }

    @Override
    public int hashCode() {
        int hash = 5;
        hash = 37 * hash + Objects.hashCode(this.x);
        hash = 37 * hash + Objects.hashCode(this.y);
        return hash;
    }
    
    public static <X, Y> Pair<X,Y> of(X x, Y y) {
        return new Pair<>(x, y);
    }
    
}
