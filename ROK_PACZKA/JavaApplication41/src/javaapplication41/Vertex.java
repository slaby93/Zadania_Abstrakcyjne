/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package javaapplication41;

import java.util.Iterator;
import java.util.LinkedHashMap;

/**
 *
 * @author Tomek
 * @param <LabelType>
 */
public class Vertex<LabelType> implements LabeledVertex<LabelType> {
    public Vertex() {
    }

    public Vertex(LabelType label) {
        neighbourhood = new LinkedHashMap<>();
        this.label = label;
    }

    @Override
    public LabelType getLabel() {
        return label;
    }

    @Override
    public void setLabel(LabelType label) {
        this.label = label;
    }

    public void addEdge(LabeledVertex<LabelType> to, LabeledEdge<?> edge) {
        neighbourhood.put(to, edge);
    }

    public LabeledEdge<?> getEdge(LabeledVertex<LabelType> to) {
        return neighbourhood.get(to);
    }

    public LabeledEdge<?> removeEdge(LabeledVertex<LabelType> to) {
        return neighbourhood.remove(to);
    }

    public Iterator<? extends LabeledEdge<?>> edgeIterator() {
        return neighbourhood.values().iterator();
    }

    private LinkedHashMap<LabeledVertex<LabelType>, LabeledEdge<?>> neighbourhood;

    private LabelType label;
}
