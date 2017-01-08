package com.company;

import java.util.LinkedList;

public class Main {

    public static void main(String[] args) throws Exception {

        LinkedList<Double> ll = new LinkedList<>();
        ll.push(3.);
        ll.push(1.);
        ll.push(2.);

        PriorityList<Double> list = new PriorityList(ll);


        for (Double d : list) {
            System.out.println(d);
        }
    }
}
