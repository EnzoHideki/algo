import java.io.*;
import java.util.*;

public class Main {
    public static final int MAXN = 112;
    public static int[] v = new int[MAXN];
    
    public static void main(String[] args) {
        MyScanner in = new MyScanner();
        PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));

        int n = in.nextInt();

        int sum = 0;
        for (int i=0; i<n; i++) {
            v[i] = in.nextInt();
            sum += v[i];
        }

        Arrays.sort(v, 0, n);

        int h = 0, ans = 0;
        while (2*h <= sum) {
            h += v[n-1-ans];
            ans++;
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