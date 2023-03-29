
import java.io.IOException;
import java.net.ConnectException;
import java.net.URL;
import org.jsoup.HttpStatusException;
import org.jsoup.Jsoup;
import org.jsoup.nodes.Document;
import org.jsoup.nodes.Element;
import org.jsoup.select.Elements;

public class test {
    public static int validnumber=0;
    public static int invalidnumber=0;
    public static int x;

    public static void main(String[] args) throws IOException {
        String urlll = "https://www.alexu.edu.eg/index.php/en/discover-au/4025-diamond-jubilee-celebrations-launch-in-alexandria-university";
        String urll = "https://www.google.com.eg/";
        Document doc = null;
        URL url = new URL(urll);
        String base = url.getProtocol() + "://" + url.getHost();
        try {
            doc = Jsoup.connect(urll).get();
        } catch (ConnectException ex) {
            System.err.println("connectException");
        } catch (HttpStatusException ex) {
            System.err.println("HttpStatusException");
        }
        Elements links = doc.select("a[href]");
        x = links.size();
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
            try {
                Document d = Jsoup.connect(s[j]).get();
                System.out.println(j + " valid: " + s[j]);
                validnumber=validnumber+1;
            } catch (Exception ex) {
                System.err.println(j + " invalid: " + s[j]);
                invalidnumber=invalidnumber+1;
            }
        }
        System.out.println("valid: "+validnumber);
        System.out.println("invalid: "+invalidnumber);
    }

}
