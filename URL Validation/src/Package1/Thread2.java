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
public class Thread2 extends Thread{
	
     private String initial;
     private int startingdepth;
     private int finaldepth;

   public Thread2(String initial, int startingdepth, int finaldepth) {
        this.initial = initial;
        this.startingdepth = startingdepth;
        this.finaldepth = finaldepth;
    }

   

    public void run()
    {
        URLvalidation.valid(initial,startingdepth,finaldepth);
    }

}
