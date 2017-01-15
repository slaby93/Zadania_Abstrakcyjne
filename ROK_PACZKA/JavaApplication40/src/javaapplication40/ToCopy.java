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
public class ToCopy implements Copyable<ToCopy> {
   @Override
   public ToCopy copy() {
      return new ToCopy();
   }
}
