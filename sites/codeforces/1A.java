import java.io.*;
import java.util.*;

public class Tas {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        long n = in.nextLong();
        long m = in.nextLong();
        long a = in.nextLong();

        long k1 = (n+a-1)/a;
        long k2 = (m+a-1)/a;

        System.out.println(k1*k2);
    }
}