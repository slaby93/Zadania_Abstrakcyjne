package com.company;


import java.util.Collection;
import java.util.Iterator;

public class PriorityList<T extends Comparable> implements Iterable<T> {

    private Item<T> head;

    PriorityList() {
    }

    PriorityList(Collection<T> collection) {
        for (T item : collection) {
            this.push(item);
        }
    }

    public void pop() {
        if (this.head != null && this.head.next != null) {
            this.head = this.head.next;
            this.head.previous = null;
            return;
        }
        this.head = null;
    }

    public Item<T> top() {
        return this.head;
    }

    public void push(T value) {
        if (head == null) {
            head = new Item(value);
            return;
        }
        insertNewElement(head, value, true);

    }

    public void insertNewElement(Item item, T value, boolean isHead) {
        switch (item.value.compareTo(value)) {
            case 1:
                // ON LEFT
                onLeft(item, value, isHead);
                return;
            case 0:
                // ON EQUAL
                onRight(item, value, isHead);
                return;
            case -1:
                // ON RIGHT
                onRight(item, value, isHead);
        }
    }

    public void onLeft(Item item, T value, boolean isHead) {
        Item newItem = new Item(value);
        newItem.next = item;
        if (item.previous != null) {
            item.previous.next = newItem;
            newItem.previous = item.previous;
        }
        item.previous = newItem;
        if (isHead) {
            this.head = newItem;
        }
    }

    public void onRight(Item item, T value, boolean isHead) {
        if (item.next == null) {
            Item newItem1 = new Item(value);
            item.next = newItem1;
            newItem1.previous = item;
            return;
        }
        insertNewElement(item.next, value, false);
    }

    @Override
    public String toString() {
        StringBuilder result = new StringBuilder();
        result.append('[');
        Item tmp = head;
        if (tmp != null) {
            while (tmp.hasNext()) {
                result.append(tmp.value);
                result.append(", ");
                tmp = tmp.next;
            }
            result.append(tmp.value);
        }
        result.append(']');
        return result.toString();
    }

    @Override
    public Iterator<T> iterator() {
        return new Iterator<T>() {

            Item<T> current = head;


            @Override
            public boolean hasNext() {
                return current != null;
            }

            @Override
            public T next() {
                T val = current.value;
                current = current.getNext();
                return val;
            }
        };
    }


    class Item<T extends Comparable> {
        private final T value;
        private Item<T> next;
        private Item<T> previous;

        Item(T value) {
            this.value = value;
        }

        public boolean hasNext() {
            return this.next != null;
        }

        public Item<T> getNext() {
            return this.next;
        }

        @Override
        public String toString() {
            return value.toString();
        }
    }
}
