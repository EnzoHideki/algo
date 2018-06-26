import java.io.*;
import java.util.*;

public class Main {
    public static final int MAXN = 112;
    //public static int[] v = new int[MAXN];
    public static int[] poss = {4,7,44,47,74,77,444,447,474,477,744,747,774,777};
    public static void main(String[] args) {
        MyScanner in = new MyScanner();
        PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));

        String inp = in.nextLine();

        int aux = 0;
        String hello = "hello";
        for (int i=0; i<inp.length(); i++) {
            if (inp.charAt(i) == hello.charAt(aux)) aux++;

            if (aux == 5) {
                out.println("YES");
                break;
            }
        }

        if (aux != 5) out.println("NO");

        out.close();
    }

    public static class MyScanner {
        BufferedReader br;
        StringTokenizer st;

        public MyScanner() {
             br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                      e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        String nextLine(){
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }
}