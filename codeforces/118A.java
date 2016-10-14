import java.io.*;
import java.util.*;

public class Tas {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        String s = in.nextLine();

        for(int i=0; i<s.length(); i++){
        	s = s.replaceAll(new Character(s.charAt(i)).toString(), new Character(s.charAt(i)).toString().toLowerCase());
        }

        s = s.replace("a", "");
        s = s.replace("e", "");
        s = s.replace("i", "");
        s = s.replace("o", "");
        s = s.replace("u", "");
        s = s.replace("y", "");

        String ans = "";

        for(int i=0; i<s.length(); i++){
        	ans += '.';
        	ans += s.charAt(i);
        }

        System.out.println(ans);
    }
}