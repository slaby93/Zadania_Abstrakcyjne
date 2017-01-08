package com.company;

public class Main {

    public static void main(String[] args) throws Exception {
        PriorityList list = new PriorityList<Double>();
        list.push(1);
        list.push(2);
        list.push(3);
        System.out.println(list.toString());
        list.pop();
        System.out.println(list.toString());
        list.pop();
        System.out.println(list.toString());
        list.pop();
        System.out.println(list.toString());
    }
}
