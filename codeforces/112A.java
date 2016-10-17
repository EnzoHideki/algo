import java.io.*;
import java.util.*;

public class Main {
	public static final int MAXN = 112345;
	//public static int[] v = new int[MAXN];
	
	public static void main(String[] args) {
		MyScanner in = new MyScanner();
		PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));

		String f, s;
		f = in.nextLine();
		s = in.nextLine();

		int len = f.length();
		for (int i=0; i<len; i++) {
			int a,b;

			char now = f.charAt(i);
			if (now >= 'a' && now <= 'z') a = now - 'a' + 1;
			else a = now - 'A' + 1;

			now = s.charAt(i);
			if (now >= 'a' && now <= 'z') b = now - 'a' + 1;
			else b = now - 'A' + 1;

			if (a < b) {
				out.println(-1);
				out.close();
				return;
			} else if (a > b) {
				out.println(1);
				out.close();
				return;
			}
		}

		out.println(0);
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
