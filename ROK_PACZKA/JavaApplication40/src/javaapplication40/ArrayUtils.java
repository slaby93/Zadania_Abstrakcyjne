/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package javaapplication40;

import java.util.List;

/**
 *
 * @author Tomek
 */
public class ArrayUtils {

    public static <T extends Number & Comparable> T max(List<T> list, int begin, int end) {
        T result = list.get(begin);
        for (int i = begin + 1; i < end; i++) {
            if (list.get(i).compareTo(result) > 0) {
                result = list.get(i);
            }
        }
        return result;
    }

    public static <T extends Number> double sum(List<T> list) {
        double result = 0;
        for (T item : list) {
            result += item.doubleValue();
        }
        return result;
    }

    public static <T extends Number> int countIf(List<T> list, Tester<T> tester) {
        int result = 0;
        for (T item : list) {
            if (tester.test(item)) {
                result++;
            }
        }
        return result;
    }

    public static <T extends Number> T sum(List<T> list, Class<T> clazz) {
        double result = 0;
        for (T item : list) {
            result += item.doubleValue();
        }
        if (clazz.equals(Byte.class)) {
            return (T) (Number) (byte) result;
        } else if (clazz.equals(Double.class)) {
            return (T) (Number) result;
        } else if (clazz.equals(Float.class)) {
            return (T) (Number) (float) result;
        } else if (clazz.equals(Integer.class)) {
            return (T) (Number) (int) result;
        } else if (clazz.equals(Long.class)) {
            return (T) (Number) (long) result;
        } else {
            return (T) (Number) (short) result;
        }
    }

    public static <T extends Number> T sum(List<T> list, Adder<T> adder) {
        T result = adder.zero();
        for (T item : list) {
            result = adder.add(result, item);
        }
        return result;
    }

}
