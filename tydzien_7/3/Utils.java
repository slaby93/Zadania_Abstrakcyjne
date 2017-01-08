package com.company;

public class Utils {
    public static void print(PriorityList list) {
        StringBuilder sb = new StringBuilder();
        sb.append('[');
        if (list.top() != null) {
            PriorityList.Item tmp = list.top();
            while (tmp.hasNext()) {
                sb.append(tmp.toString());
                sb.append(", ");
                tmp = tmp.getNext();
            }
            sb.append(tmp.toString());
        }
        sb.append(']');
        System.out.println(sb.toString());
    }
}
