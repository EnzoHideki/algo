import java.io.*;
import java.util.*;

public class Tas {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int m = in.nextInt();
        int n = in.nextInt();

        if ((n % 2 == 1) && (m % 2 == 1)) {
        	System.out.println((n*m-1)/2);
        } else {
        	System.out.println((n*m)/2);
        }
    }
}