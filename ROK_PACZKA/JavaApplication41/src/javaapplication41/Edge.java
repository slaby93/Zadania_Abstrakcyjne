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
public class Edge<LabelType> implements LabeledEdge<LabelType> {
    public Edge() {
    }

    public Edge(LabeledVertex<?> from, LabeledVertex<?> to, LabelType label) {
        this.from = from;
        this.to = to;
        this.label = label;
    }

    @Override
    public LabeledVertex<?> getFrom() {
        return from;
    }

    @Override
    public LabeledVertex<?> getTo() {
        return to;
    }

    @Override
    public LabelType getLabel() {
        return label;
    }

    @Override
    public void setLabel(LabelType label) {
        this.label = label;
    }

    private LabeledVertex<?> from, to;

    private LabelType label;
}
