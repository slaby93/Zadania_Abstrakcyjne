/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package javaapplication41;

import java.util.Iterator;

/**
 *
 * @author Tomek
 * @param <NodeLabelType>
 * @param <EdgeLabelType>
 */
public interface LabeledGraph<NodeLabelType, EdgeLabelType> {
    Iterator<? extends LabeledVertex<NodeLabelType>> vertexIterator();

    Iterator<? extends LabeledEdge<EdgeLabelType>> edgeIterator(LabeledVertex<NodeLabelType> vertex);

    LabeledEdge<EdgeLabelType> getEdge(LabeledVertex<NodeLabelType> from, LabeledVertex<NodeLabelType> to);
}
