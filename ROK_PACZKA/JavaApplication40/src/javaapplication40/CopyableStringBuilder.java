/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package javaapplication40;

/**
 *
 * @author Tomek
 */
public class CopyableStringBuilder implements Copyable<CopyableStringBuilder> {
    private final StringBuilder text;
    
    public CopyableStringBuilder() {
        text = new StringBuilder();
    }
    
    public CopyableStringBuilder(StringBuilder text) {
        this.text = text;
    }
    
    public void append(String text) {
        this.text.append(text);
    }
    
    public void display() {
        System.out.println(text);
    }
    
    @Override
    public CopyableStringBuilder copy() {
      return new CopyableStringBuilder(new StringBuilder(text));
   }
}
