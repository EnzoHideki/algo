import java.io.*;
import java.util.*;

public class Main {
	public static final int MAXN = 112;
	public static int[] v = new int[MAXN];
	
	public static void main(String[] args) {
		MyScanner in = new MyScanner();
		PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));

		String input = in.nextLine();
		int len = input.length();
		int ind = 0;
		for (int i=0; i<len; i++) {
			if (i%2!=1) {
				v[ind++] = Integer.parseInt(Character.toString(input.charAt(i)));
			}
		}

		Arrays.sort(v, 0, ind);

		for (int i=0; i<len; i++) {
			if (i%2!=1) {
				out.print(v[i/2]);
			} else {
				out.print('+');
			}
		}

		out.println();
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