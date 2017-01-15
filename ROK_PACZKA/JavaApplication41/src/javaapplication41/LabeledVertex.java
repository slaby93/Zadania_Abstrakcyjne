/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package javaapplication41;

/**
 *
 * @author Tomek
 * @param <LabelType>
 */
public interface LabeledVertex<LabelType> {
    LabelType getLabel();

    void setLabel(LabelType label);
}
