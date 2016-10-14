import java.io.*;
import java.util.*;

public class Main {
	public static final int MAXN = 112345;
	public static int[] v = new int[MAXN];
  public static void main(String[] args) {
      MyScanner in = new MyScanner();
      out = new PrintWriter(new BufferedOutputStream(System.out));
      //Scanner in = new Scanner(System.in);

     	int n = in.nextInt();

     	int i = 0;
     	for (; i<n; i++) v[i] = in.nextInt();

     	int m = in.nextInt();

	    for (; i<n+m; i++) v[i] = in.nextInt();

     	int k = in.nextInt();

     	Arrays.sort(v, 0, n+m);

     	int l = 0;
     	int r = 0;
     	int ans = 0;
     	while(true){
     		while(v[r] - v[l] <= k){
     			ans = Math.max(ans, v[r] - v[l]);
     			r++;

     			if(r >= n+m) break;
     		}
     		l++;
     		if(r >= n+m) break;
     	}

      for(i=0; i < n+m; i++){
        out.print(v[i]);
        out.print((new char[]{' ','\n'})[i== n+m-1?1:0]);
      }

     	out.println(ans);
      out.close();
  }

  public static PrintWriter out;

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