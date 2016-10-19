import java.io.*;
import java.util.*;

public class Main {
    public static final int MAXN = 112345;
    public static int[] v = new int[MAXN];
    
    public static void main(String[] args) {
        MyScanner in = new MyScanner();
        PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));

        int a = in.nextInt();
        int n = in.nextInt();
        
        String inp = in.nextLine();

        if (a == 1) {
            out.println(inp);
            out.close();
            return;
        }

        for (int i=0; i<n; i++) {
            inp = update(inp);
        }

        out.println(inp);
        out.close();
    }

    static String update(String s) {
        String res = "";

        int i = 1;
        while (i < s.length()) {
            if (s.charAt(i-1) == 'B' && s.charAt(i) == 'G') {
                res += "GB";
                if (i+2 <= s.length()-1) i += 2;
                else if (i+1 <= s.length()-1){
                   res += s.charAt(i+1); 
                   break;
                }
                else break;
            } else {
                res += s.charAt(i-1);

                if (i == s.length()-1) {
                    res += s.charAt(i);
                }

                i++;
            }
        }
        
        return res;
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