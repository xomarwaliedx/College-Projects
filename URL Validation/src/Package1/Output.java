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
public class Output {

    public static void setValid(int valid) {
        Output.valid = valid;
    }

    public static void setInvalid(int invalid) {
        Output.invalid = invalid;
    }

    public static void setTime(long time) {
        Output.time = time;
    }



    public static int getValid() {
        return valid;
    }

    public static int getInvalid() {
        return invalid;
    }

    public static long getTime() {
        return time;
    }

    
    private static int valid;
    private static int invalid;
    private static long time;
    
}
