/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package javaapplication41;

import java.util.Collection;
import java.util.Iterator;
import java.util.LinkedList;

/**
 *
 * @author Tomek
 * @param <NodeLabelType>
 * @param <EdgeLabelType>
 */
public class NeighbourhoodMapGraph<NodeLabelType, EdgeLabelType> implements EditableGraph<NodeLabelType, EdgeLabelType> {

    public NeighbourhoodMapGraph() {
        nodes = new LinkedList<>();
    }

    public NeighbourhoodMapGraph(Collection<NodeLabelType> collection) {
        nodes = new LinkedList<>();
        for (NodeLabelType label : collection) {
            nodes.add(new Vertex<>(label));
        }
    }

    @Override
    public LabeledVertex<NodeLabelType> addVertex(NodeLabelType label) {
        Vertex<NodeLabelType> node = new Vertex<>(label);
        nodes.add(node);
        return node;
    }

    @Override
    public LabeledEdge<EdgeLabelType> addEdge(LabeledVertex<NodeLabelType> from, LabeledVertex<NodeLabelType> to, EdgeLabelType label) {
        Edge<EdgeLabelType> edge = new Edge<>(from, to, label);
        ((Vertex<NodeLabelType>) from).addEdge(to, edge);
        return edge;
    }

    @Override
    public void removeVertex(LabeledVertex<NodeLabelType> v) {
        for (LabeledVertex<NodeLabelType> node : nodes) {
            ((Vertex<NodeLabelType>) node).removeEdge(v);
        }
        nodes.remove(v);
    }

    @Override
    public LabeledEdge<EdgeLabelType> removeEdge(LabeledVertex<NodeLabelType> from, LabeledVertex<NodeLabelType> to) {
        return (LabeledEdge<EdgeLabelType>) ((Vertex<NodeLabelType>) from).removeEdge(to);
    }

    @Override
    public Iterator<? extends LabeledVertex<NodeLabelType>> vertexIterator() {
        return nodes.iterator();
    }

    @Override
    public Iterator<? extends LabeledEdge<EdgeLabelType>> edgeIterator(LabeledVertex<NodeLabelType> vertex) {
        return (Iterator<? extends LabeledEdge<EdgeLabelType>>) ((Vertex<NodeLabelType>) vertex).edgeIterator();
    }

    @Override
    public LabeledEdge<EdgeLabelType> getEdge(LabeledVertex<NodeLabelType> from, LabeledVertex<NodeLabelType> to) {
        return (LabeledEdge<EdgeLabelType>) ((Vertex<NodeLabelType>) from).getEdge(to);
    }

    private final LinkedList<LabeledVertex<NodeLabelType>> nodes;
}
