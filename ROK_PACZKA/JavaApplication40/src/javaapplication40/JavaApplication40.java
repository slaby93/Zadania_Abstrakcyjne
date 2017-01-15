/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package javaapplication40;

import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author Tomek
 */
public class JavaApplication40 {

    /**
     * @param args the command line arguments
     * @throws java.lang.InstantiationException
     * @throws java.lang.IllegalAccessException
     */
    public static void main(String[] args) throws InstantiationException, IllegalAccessException {
        List<Integer> ci = Arrays.asList(1, 8, 5, 4);
        System.out.println(ArrayUtils.sum(ci, new IntegerAdder()));
        CopyableStringBuilder text = new CopyableStringBuilder();
        text.append("aaab");
        text.append("cccd");
        text.display();
        CopyableStringBuilder copy = text.copy();
        copy.append("eeef");
        copy.append("gggh");
        text.display();
        copy.display();
        CloneAppender cloner = new CloneAppender();
        LinkedList<CopyableStringBuilder> foo = new LinkedList<>();
        foo.add(text);
        LinkedList<CopyableStringBuilder> collection = cloner.add(copy, 5, LinkedList.class);
        for (CopyableStringBuilder c : collection) {
            c.display();
        }
    }

}
