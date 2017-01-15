/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package javaapplication40;

import java.util.Collection;

/**
 *
 * @author Tomek
 */
public class CloneAppender {

    public <U extends Copyable<U>, V extends Collection<? super U>> V add(U object, int n, Class<V> clazz) throws InstantiationException, IllegalAccessException {
        V collection = clazz.newInstance();
        for (int i = 0; i < n; i++) {
            collection.add(object.copy());
        }
        return collection;
    }
}
