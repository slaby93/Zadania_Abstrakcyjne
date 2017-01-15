/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package javaapplication40;

import java.util.Calendar;
import java.util.Collections;
import java.util.HashMap;
import java.util.Map;

/**
 *
 * @author Tomek
 */
public class Vet {

    private final Map<Calendar, Animal> scheduler;

    public Vet() {
        scheduler = new HashMap<>();
    }

    public void makeAnAppointment(Calendar calendar, Animal animal) {
        scheduler.put(calendar, animal);
    }

    public void makeManyAppointments(Map<? extends Calendar, ? extends Animal> map) {
        scheduler.putAll(map);
    }

    public Map<Calendar, Animal> getScheduler() {
        return Collections.unmodifiableMap(scheduler);
    }

    public Map<Calendar, Animal> getModifableScheduler() {
        return scheduler;
    }

}
