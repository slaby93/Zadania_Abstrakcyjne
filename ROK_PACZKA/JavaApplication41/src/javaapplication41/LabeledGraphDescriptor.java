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
public class LabeledGraphDescriptor<NodeLabelType, EdgeLabelType> {
    public LabeledGraphDescriptor(EditableGraph<NodeLabelType, EdgeLabelType> graph) {
        this.graph = graph;
    }

    @Override
    public String toString() {
        StringBuilder output = new StringBuilder();
        output.append("Wierzchołki:\n");
        Iterator<? extends LabeledVertex<NodeLabelType>> vertices = graph.vertexIterator();
        while (vertices.hasNext()) {
            LabeledVertex<NodeLabelType> vertex = vertices.next();
            output.append(vertex.getLabel());
            output.append(": ");
            Iterator<? extends LabeledEdge<EdgeLabelType>> neighbours = graph.edgeIterator(vertex);
            while (neighbours.hasNext()) {
                LabeledEdge<EdgeLabelType> edge = neighbours.next();
                output.append(edge.getTo().getLabel());
                output.append(" (");
                output.append(edge.getLabel());
                output.append("), ");
            }
            output.setLength(output.length() - 2);
            output.append("\n");
        }
        output.setLength(output.length() - 1);
        return output.toString();
    }

    private final EditableGraph<NodeLabelType, EdgeLabelType> graph;
}
