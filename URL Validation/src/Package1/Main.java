/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Package1;

import static Package1.URLvalidation.invalidnumber;
import static Package1.URLvalidation.validnumber;
import java.io.IOException;
import java.net.MalformedURLException;

/**
 *
 * @author omara
 */
public class Main {

    public static String urlll = "https://www.alexu.edu.eg/index.php/en/discover-au/4025-diamond-jubilee-celebrations-launch-in-alexandria-university";
    public static String urll = "https://www.google.com.eg/";
    public static String urllll = "https://74mazen74.github.io/74Mazen.github.io/";

    public static void main(String[] args) throws IOException, MalformedURLException, InterruptedException {
        new GUI().setVisible(true);

    }
}
