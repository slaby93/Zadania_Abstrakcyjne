package com.company;

public class Main {

    public static void main(String[] args) throws Exception {
        PriorityList list = new PriorityList<Integer>();
        list.push(1);
        list.push(2);
        list.push(3);
        Utils.print(list);
    }
}
