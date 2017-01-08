package com.company;

public class Main {

    public static void main(String[] args) throws Exception {
        PriorityList<Double> list = new PriorityList();
        list.push(1.);
        list.push(2.);
        list.push(3.);


        for (Double d : list) {
            System.out.println(d);
        }
    }
}
