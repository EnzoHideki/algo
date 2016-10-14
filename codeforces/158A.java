import java.io.*;
import java.util.*;

public class Tas {
	public static final int MAXN = 112345;
	static int v[] = new int[MAXN];
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int n = in.nextInt();
        int k = in.nextInt();

        for(int i=0; i<n; i++){
        	v[i] = in.nextInt();
        }

        int i=0;
        while(v[i] > 0){
        	if(v[i] >= v[k-1]) i++;
        	else break;
        }

        System.out.println(i);
    }
}