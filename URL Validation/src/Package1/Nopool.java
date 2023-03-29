/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Package1;

/**
 *
 * @author omara
 */
public class Nopool {

    private static int numberofthreads;

    Nopool(int j) {
        numberofthreads=j;
    }

   

    public static int getNumberofthreads() {
        return numberofthreads;
    }
}
