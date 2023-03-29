/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Package1;

import java.io.IOException;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author omara
 */
public class Thread1 extends Thread {

    private String initial;
    private int startingdepth;
    private int finaldepth;

    public Thread1(String initial, int startingdepth, int finaldepth) {
        this.initial = initial;
        this.startingdepth = startingdepth;
        this.finaldepth = finaldepth;
    }
    public void run()
    {
        try {
            URLvalidation.validate(initial, startingdepth, finaldepth);
        } catch (IOException ex) {
            Logger.getLogger(Thread1.class.getName()).log(Level.SEVERE, null, ex);
        } catch (InterruptedException ex) {
            Logger.getLogger(Thread1.class.getName()).log(Level.SEVERE, null, ex);
        }
    }

}
