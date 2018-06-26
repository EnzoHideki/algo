#include <bits/stdc++.h>
#define debug(args...) //fprintf(stderr, args)
using namespace std;
 
const int MAXN = 112345;
int vetor[MAXN], cnt;
 
void merge(int ini, int fim){
	if(ini == fim) return;
	
	int mid = (ini+fim)/2;
	merge(ini, mid);
	merge(mid+1, fim);
	
	int aux[fim-ini+1], i = ini, k = 0;
	for(int j = mid+1; j <= fim+1; j++){
		if(i == mid+1){ for(int h = j; h <= fim; h++) aux[k++] = vetor[h]; break;}
		if(j == fim+1){ for(int h = i; h <= mid; h++) aux[k++] = vetor[h]; break;}
		
		while(vetor[j] > vetor[i] && i <= mid){ aux[k++] = vetor[i++]; debug("%d\n", i);}
		aux[k++] = vetor[j];
		cnt+= mid-i+1;
	}
	
	for(int i = ini; i <= fim; i++) vetor[i] = aux[i-ini];
}
 
int main(){
    int n; cin >> n;
	for(int i = 0; i < n; i++) scanf("%d", &vetor[i]);
	merge(0, n-1);
	printf("%d\n", cnt);
	return 0;
}