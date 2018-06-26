#include <bits/stdc++.h>
 
using namespace std;
 
const int MAXN = 1020; 
int fila[10][MAXN], ind[10], first[10];
 
int main(){
    int c, n, counter = 0;
    
    scanf("%d%d", &c, &n);
    
    for(int i = 0; i < 10; i++){
    	for(int j = 0; j < MAXN; j++) fila[i][j] = 0;
    	ind[i] = 0; first[i] = 0;
    }
    
    for(int i = 0; i < n; i++){
    	int t, d, leastTimeStack = 11000, leastBusy;
    	scanf("%d%d", &t, &d);
    	
    	for(int j = 0; j < c; j++){
    		int TimeStack = 0;
    		for(int l = 0; l < MAXN; l++) TimeStack += fila[j][l];
            
            TimeStack += first[j];
    		
    		if(TimeStack < leastTimeStack){
    			leastTimeStack = TimeStack;
    			leastBusy = j;
    		}
    	}
        
        if(leastTimeStack <= t){
            for(int i = 0; i < MAXN; i++) fila[leastBusy][i] = 0;
            first[leastBusy] = t;
        } else {
            if(leastTimeStack - t  > 20) counter++;
        }
    	
    	fila[leastBusy][ind[leastBusy]] = d;
        
    	ind[leastBusy]++;
    }
    printf("%d\n", counter);
    
    return 0;
}