/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Package1;

import java.io.IOException;
import java.net.ConnectException;
import java.net.MalformedURLException;
import java.net.URL;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.logging.Level;
import java.util.logging.Logger;
import org.jsoup.HttpStatusException;
import org.jsoup.Jsoup;
import org.jsoup.nodes.Document;
import org.jsoup.select.Elements;

/**
 *
 * @author omara
 */
public class URLvalidation {

    public static int validnumber = 0;
    public static int invalidnumber = 0;
    public static int x = 0;
    static ExecutorService ex = Executors.newFixedThreadPool(Nopool.getNumberofthreads());

    public static void validate(String initiallink, int startingdepth, int finaldepth) throws MalformedURLException, IOException, InterruptedException {
        Thread2 t2 = null;
        URL url = new URL(initiallink);
        Document doc = null;
        String base = url.getProtocol() + "://" + url.getHost();
        if (valid(initiallink)) {
            doc = Jsoup.connect(initiallink).get();
            Elements links = doc.select("a[href]");
            x = links.size();
            if (x > 0) {
                String s[] = new String[x];
                for (int i = 0; i < links.size(); i++) {
                    s[i] = links.get(i).attr("href");
                    if (!s[i].startsWith("http")) {
                        s[i] = base + s[i];
                    }
//                System.out.println(s[i]);
                }
                System.out.println(x);
                for (int j = 0; j < links.size(); j++) {   
                            t2 = new Thread2(s[j], startingdepth + 1, finaldepth);
                            ex.execute(t2);
                }
            }
        }
    }

    public static boolean valid(String s, int startingdepth, int finaldepth) {
        Document doc = null;
        try {
            doc = Jsoup.connect(s).get();
            System.out.println("valid: " + s);
            validnumber = validnumber + 1;
            Thread1 t = null;
            if (startingdepth < finaldepth) {
                t = new Thread1(s, startingdepth + 1, finaldepth);
                ex.execute(t);
            }
            return true;
        } catch (ConnectException ex) {
            System.out.println("invalid: " + s);
            invalidnumber = invalidnumber + 1;
            return false;
        } catch (HttpStatusException ex) {
            System.out.println("invalid: " + s);
            invalidnumber = invalidnumber + 1;
            return false;
        } catch (IOException ex) {
            System.out.println("invalid: " + s);
            invalidnumber = invalidnumber + 1;
            return false;
        } catch (IllegalArgumentException ex) {
            System.out.println("invalid: " + s);
            invalidnumber = invalidnumber + 1;
            return false;
        }
    }

    public static boolean valid(String s) {
        Document doc = null;
        try {
            doc = Jsoup.connect(s).get();
            return true;
        } catch (ConnectException ex) {
            System.out.println("invalid initial: " + s);
            return false;
        } catch (HttpStatusException ex) {
            System.out.println("invalid initial: " + s);
            return false;
        } catch (IOException ex) {
            System.out.println("invalid initial: " + s);
            return false;
        } catch (IllegalArgumentException ex) {
            System.out.println("invalid initial: " + s);
            return false;
        }
    }
}
