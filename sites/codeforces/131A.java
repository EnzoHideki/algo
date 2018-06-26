import java.io.*;
import java.util.*;

public class Main {
	public static final int MAXN = 112;
	public static int[] v = new int[MAXN];
	
	public static void main(String[] args) {
		MyScanner in = new MyScanner();
		PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));

		String a = in.nextLine();
		int len = a.length();

		boolean ok = true;
		for (int i=1; i<len; i++) {
			if (a.charAt(i) >= 'a' && a.charAt(i) <= 'z') {
				ok = false;
				break;
			}
		}

		if (ok) out.println(shift(a));
		else out.println(a);

		out.close();
	}

	public static String shift(String s){
		String ret = "";
		int ll = s.length();
		for (int i=0; i<ll; i++) {
			if (s.charAt(i) >= 'a' && s.charAt(i) <= 'z') {
				ret +=(char) (s.charAt(i) - 'a' + 'A');
			} else {
				ret += (char) (s.charAt(i) - 'A' + 'a');				
			}
		}

		return ret;
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