package com.company;

import java.util.Collection;

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

    public static <T> T sum(Collection<T> collection) {
        T sum = null;
        for (T item : collection) {
            if (sum == null) {
                sum = item;
                continue;
            }
//            sum += item;
        }
        return sum;
    }

    interface Addable<T> {
        public T add(T value);
    }

    public static <T extends Addable<T>> T sumWorking(Collection<T> collection) {
        T sum = null;
        for (T item : collection) {
            if (sum == null) {
                sum = item;
                continue;
            }
            sum = sum.add(item);
        }
        return sum;
    }
}
