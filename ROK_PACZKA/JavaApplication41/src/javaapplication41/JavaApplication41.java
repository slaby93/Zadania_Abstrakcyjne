/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package javaapplication41;

/**
 *
 * @author Tomek
 */
public class JavaApplication41 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        /*NeighbourhoodMapGraph<String, String> graph = new NeighbourhoodMapGraph<>();
        LabeledVertex<String> v1 = graph.addVertex("aaa");
        LabeledVertex<String> v2 = graph.addVertex("bbb");
        graph.addEdge(v1, v2, "ccc");
        graph.addEdge(v2, v1, "ddd");
        LabeledGraphDescriptor<String, String> output = new LabeledGraphDescriptor<>(graph);
        System.out.println(output.toString());*/
        EditableGraph<String, Double> g = new NeighbourhoodMapGraph<>();
        @SuppressWarnings("unchecked") // nie ma tablic generycznych
        LabeledVertex<String>[] vs = new LabeledVertex[]{
            g.addVertex("pierwszy"),
            g.addVertex("następny"),
            g.addVertex("kolejny"),
            g.addVertex("ostatni")

        };
        g.addEdge(vs[0], vs[1], 35.0);
        g.addEdge(vs[0], vs[3], 15.1);
        g.addEdge(vs[1], vs[2], 12.9);
        g.addEdge(vs[3], vs[2], -1.3);
        g.addEdge(vs[3], vs[0], 125.0);
        g.addEdge(vs[2], vs[0], 5.5);
        System.out.println(new LabeledGraphDescriptor<>(g));
        System.out.println("-----");
        vs[2].setLabel("zmieniony");
        g.getEdge(vs[2], vs[0]).setLabel(34.0);
        g.removeEdge(vs[3], vs[0]);
        g.removeVertex(vs[1]);
        System.out.println(new LabeledGraphDescriptor<>(g));
        // TODO code application logic here
    }

}
