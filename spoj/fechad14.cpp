#include <stdio.h>
 
int main(){
	int n, m;
	scanf("%d%d", &n, &m);
 
	int pinos[1001];
 
	int i = 0;
 
	for(i; i<n; i++){
		scanf("%d", &pinos[i]);
	}
 
	i = 0;
 
	int movements = 0;
 
	for(i; i < n-1; i++){
		if(pinos[i] != m){
			movements = movements + abs(m - pinos[i]);
			pinos[i+1] = pinos[i+1] + m - pinos[i];
			pinos[i] = m;
		}
	}
 
	printf("%d", movements);
 
	return 0;
} 