import java.io.*;
import java.util.*;

public class Main {
    public static final int MAXN = 112345;
    public static int[] v = new int[MAXN];
    
    public static void main(String[] args) {
        MyScanner in = new MyScanner();
        PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));

        for (int i=0; i<MAXN; i++) v[i] = 0;

        int k = in.nextInt();
        int l = in.nextInt();
        int m = in.nextInt();
        int n = in.nextInt();
        int d = in.nextInt();

        int i = k;
        while (i <= d) {
            v[i] = 1;
            i += k;
        }
        i = l;
        while (i <= d) {
            v[i] = 1;
            i += l;
        }
        i = m;
        while (i <= d) {
            v[i] = 1;
            i += m;
        }
        i = n;
        while (i <= d) {
            v[i] = 1;
            i += n;
        }

        int ans = 0;
        for (int j=0; j<=d; j++) {
            ans += v[j];
        }

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