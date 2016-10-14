import java.io.*;
import java.util.*;

public class Main {
	public static final int MAXN = 112345;
	//public static int[] v = new int[MAXN];
	
	public static void main(String[] args) {
		MyScanner in = new MyScanner();
		PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));

		int n = in.nextInt();
		int one = 0, two = 0, three = 0;
		int ans = n;
		for (int i=0; i<n; i++) {
			switch (in.nextInt()) {
				case 1:
					one++;
					break;
				case 2:
					two++;
					break;
				case 3:
					three++;
					break;
			}
		}

		ans -= Math.min(three, one);

		one -= Math.min(three, one);
		three -= Math.min(three, one);

		ans -= two/2;
		
		if (two % 2 == 1) {
			if (one > 1) {
				ans -= 2;
				one -= 2;
			} else if (one == 1) {
				ans--;
				one--;
			}
		}
		
		ans -= (one - ((one+3)/4));

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