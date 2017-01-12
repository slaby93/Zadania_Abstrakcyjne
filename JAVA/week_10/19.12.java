package com.company;

import java.util.HashSet;
import java.util.List;
import java.util.Vector;

public class Main {

    public static Vector<Number> generateRandomVector(int numberOfNumbers) {
        Vector<Number> ve = new Vector<>();
        for (int i = 0; i < numberOfNumbers; i++) {
            ve.add((int) (Math.random() * (Integer.MAX_VALUE)));
        }
        return ve;

    }

    public static <T extends List> void wypisz(T arg, char separator) {
        for (int i = 0; i < arg.size(); i++) {
            System.out.print(arg.get(i) + " ");
            if (i != arg.size() - 1) {
                System.out.print(separator);
            }
        }
    }

    public static <T extends List<Double>> T zadanie3(T arg) {
        arg.sort((a, b) -> {
                    a = a - a.intValue();
                    b = b - b.intValue();
                    if (a < b) {
                        return -1;
                    } else if (a == b) {
                        return 0;
                    } else {
                        return 1;
                    }
                }
        );
        return arg;
    }

    public static <T extends Vector<Number>> T zadanie4(T arg) {
        return removeDups(arg);
    }

    public static <T extends Vector<Number>> void zadanie4(T arg1, T arg2) {
        arg1 = removeDups(arg1);
        arg2 = removeDups(arg2);

        System.out.println(arg1);
        System.out.println(arg2);
        arg1.retainAll(arg2);
        System.out.println(arg1);

    }

    public static <T extends Vector<Number>> T removeDups(T arg) {
        HashSet tmp = new HashSet(arg);
        arg.clear();
        arg.addAll(tmp);
        tmp.clear();
        return arg;
    }

    public static <T extends Vector<Number>> Integer zadanie5(T arg, int a, int b) {
        int iloscElementow = 0;
        for (Number n : arg) {
            if (a < n.doubleValue() && n.doubleValue() < b) {
                iloscElementow += 1;
            }
        }
        System.out.println("ILOSC ELEMENTOW " + iloscElementow);
        return iloscElementow;
    }

    public static <T extends Vector<Vector<Number>>> Vector<Number> zadanie6(T arg) {
        Vector<Number> wynik = new Vector<>();
        arg.stream().forEach(item -> wynik.add(item.size()));

        System.out.println("ZADANIE 6: " + wynik);
        return wynik;
    }


    public static void main(String[] args) {

//        for (Number i : generateRandomVector(7)) {
//            System.out.println(i);
//        }
//
//
//        wypisz(generateRandomVector(7), '<');
//
        Vector<Number> zad3 = new Vector<>();
        zad3.add(2.);
        zad3.add(3.);
        zad3.add(3.);
        zad3.add(3.);
        zad3.add(5.);

        Vector<Number> zad4 = new Vector<>();
        zad4.add(5.);
        zad4.add(6.);
        zad4.add(7.);
        zad4.add(8.);

//        zadanie3(zad3);

//        System.out.println("\n");

//        zadanie4(zad3);
//        zadanie4(zad3, zad4);

        Vector<Vector<Number>> lastManStanding = new Vector<>();
        lastManStanding.add(zad3);
        lastManStanding.add(zad4);

//        zadanie5(zad4, 5, 8);
        zadanie6(lastManStanding);

    }
}