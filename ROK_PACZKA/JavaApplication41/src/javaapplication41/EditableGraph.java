/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package javaapplication41;

/**
 *
 * @author Tomek
 * @param <NodeLabelType>
 * @param <EdgeLabelType>
 */
public interface EditableGraph<NodeLabelType, EdgeLabelType> extends LabeledGraph<NodeLabelType, EdgeLabelType> {
    LabeledVertex<NodeLabelType> addVertex(NodeLabelType label);

    LabeledEdge<EdgeLabelType> addEdge(LabeledVertex<NodeLabelType> from, LabeledVertex<NodeLabelType> to, EdgeLabelType label);
    
    void removeVertex(LabeledVertex<NodeLabelType> v);

    LabeledEdge<EdgeLabelType> removeEdge(LabeledVertex<NodeLabelType> from, LabeledVertex<NodeLabelType> to);
}
