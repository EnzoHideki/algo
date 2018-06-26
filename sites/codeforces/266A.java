import java.io.*;
import java.util.*;

public class Main {
    public static final int MAXN = 112345;
    public static int[] v = new int[MAXN];
    
    public static void main(String[] args) {
        MyScanner in = new MyScanner();
        PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));

        int n = in.nextInt();

        String input = in.nextLine();

        int i = 1, len = input.length();
        char now = input.charAt(0);
        int qtt = 1, ans = 0;
        while (i < len) {
            char next = input.charAt(i); 
            if (now != next) {
                ans += qtt-1;
                now = next;
                qtt = 1;
            } else {
                qtt++;
            }

            i++;
        }

        if (qtt > 0) ans += qtt-1;
        
        out.println(ans);
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