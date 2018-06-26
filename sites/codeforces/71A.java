import java.io.*;
import java.util.*;

public class Tas {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int n = in.nextInt();
        in.nextLine();
        for (int i=0; i<n; i++) {
        	String s = in.nextLine();

        	if (s.length() <= 10) System.out.println(s);
        	else System.out.println(Character.toString(s.charAt(0))+Integer.toString(s.length()-2)+Character.toString(s.charAt(s.length()-1)));
        }
    }
}