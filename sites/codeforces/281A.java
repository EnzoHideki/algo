import java.io.*;
import java.util.*;

public class Main {
    public static final int MAXN = 112;
    public static int[] v = new int[MAXN];
    
    public static void main(String[] args) {
        MyScanner in = new MyScanner();
        PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));

        String inp = in.nextLine();
        String res = "";

        if (inp.charAt(0) > 'Z') res += (char) (inp.charAt(0) - 'a' + 'A');
        else res += (char) (inp.charAt(0));
        
        for (int i = 1; i<inp.length(); i++) {
            res += inp.charAt(i);
        }

        out.println(res);
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