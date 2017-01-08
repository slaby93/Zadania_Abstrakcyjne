package com.company;

import java.util.HashSet;
import java.util.List;
import java.util.Vector;
import java.util.concurrent.ThreadLocalRandom;

public class Main {

    public static Vector<Number> zadanie1(int numberOfNumbers) {
        Vector<Number> result = new Vector();
        ThreadLocalRandom
                .current()
                .ints(Integer.MIN_VALUE, Integer.MAX_VALUE)
                .limit(numberOfNumbers)
                .forEach(result::add);
        return result;
    }

    /**
     * Wypisz
     *
     * @param arg
     * @param separator
     * @param <T>
     */
    public static <T extends List> void zadanie2(T arg, char separator) {
        arg
                .stream()
                .forEach((item) -> System.out.print(item + " " + Character.toString(separator) + " "));
    }

    /**
     * Sort by fractional part of number
     *
     * @param arg
     * @param <T>
     * @return
     */
    public static <T extends List<Double>> T zadanie3(T arg) {
        arg.sort((a, b) -> {
                    a = a - a.intValue();
                    b = b - b.intValue();
                    return a.compareTo(b);
                }
        );
        return arg;
    }

    /**
     * Remove duplicates
     *
     * @param arg
     * @param <T>
     * @return
     */
    public static <T extends Vector<Number>> T zadanie4(T arg) {
        return removeDups(arg);
    }

    /**
     * Intersection of sets
     *
     * @param arg1
     * @param arg2
     * @param <T>
     */
    public static <T extends Vector<Number>> Vector<Number> zadanie4(T arg1, T arg2) {
        arg1 = removeDups(arg1);
        arg2 = removeDups(arg2);
        arg1.retainAll(arg2);
        return arg1;
    }

    public static <T extends Vector<Number>> T removeDups(T arg) {
        HashSet tmp = new HashSet(arg);
        arg.clear();
        arg.addAll(tmp);
        tmp.clear();
        return arg;
    }

    /**
     * Returns number of elements between a < ? < b
     *
     * @param arg
     * @param a
     * @param b
     * @param <T>
     * @return
     */
    public static <T extends Vector<Number>> Integer zadanie5a(T arg, int a, int b) {
        int result = 0;
        for (Number n : arg) {
            if (a < n.doubleValue() && n.doubleValue() < b) {
                result += 1;
            }
        }
        return result;
    }

    /**
     * Return vector containing length of supplied vectors eg [[...5],[...3]] = [5,3]
     *
     * @param arg
     * @param <T>
     * @return
     */
    public static <T extends Vector<Vector<Number>>> Vector<Number> zadanie5b(T arg) {
        Vector<Number> result = new Vector<>();
        arg.stream().forEach(item -> result.add(item.size()));
        return result;
    }


    public static void main(String[] args) {
        /**
         * Zadanie 1
         */
//        zadanie1(7).stream().forEach(System.out::println);
        /**
         * Zadanie 2
         */
//        zadanie2(zadanie1(7), '<');
        /**
         * Zadanie 3
         */
//        Vector<Double> zad3 = new Vector<>();
//        zad3.add(2.7);
//        zad3.add(3.2);
//        zad3.add(3.1);
//        zad3.add(3.1);
//        zad3.add(5.5);
//        System.out.println(zadanie3(zad3));
        /**
         * Zadanie 4
         */
//        Vector<Number> zad4a = new Vector<>();
//        zad4a.add(5.);
//        zad4a.add(5.);
//        zad4a.add(5.);
//        zad4a.add(6.);
//        zad4a.add(6.);
//        zad4a.add(6.);
//        zad4a.add(7.);
//        zad4a.add(7.);
//        zad4a.add(7.);
//        zad4a.add(7.);
//        zad4a.add(8.);
//
//        Vector<Number> zad4b = new Vector<>();
//        zad4b.add(5.);
//
//        System.out.println(zadanie4(zad4a)); // REMOVED DUPLICATES
//
//        System.out.println(zadanie4(zad4a, zad4b)); // INTERSECTION
        /**
         * Zadanie 5
         */
//        Vector<Number> zad5a = new Vector<>();
//        Vector<Number> zad5b = new Vector<>();
//        zad5a.add(1);
//        zad5a.add(2);
//        zad5a.add(3);
//        zad5a.add(4);
//        zad5a.add(5);
//
//        zad5b.add(2);
//        zad5b.add(3);
//        zad5b.add(4);
//        zad5b.add(4);
//
//        Vector<Vector<Number>> vector = new Vector<>();
//
//        vector.add(zad5a);
//        vector.add(zad5b);
//
//        System.out.println(zadanie5a(zad5a, 3, 20)); // Number of elements between 3 and 20 | [4,5] = 2
//        System.out.println(zadanie5b(vector)); // zad5a.length = 5, zad5b.length = 4 | [5,4]
    }
}
