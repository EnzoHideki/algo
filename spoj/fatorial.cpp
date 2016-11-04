#include <bits/stdc++.h>
#define debug(args...) //fprintf(stderr, args)
using namespace std;
 
typedef long long ll;
 
const int MAXN = 1123456;
ll num[MAXN];
 
int main(){
	int n, cont = 1;
	
	num[0] = 1;
	for(int i = 1; i <= MAXN; i++){
		ll prod = i*num[i-1];
 
		while(prod % 10 == 0 && prod != 0) prod /= 10;
 
		num[i] = prod % 100000;
	}
	
	while(scanf("%d", &n) != EOF) printf("Instancia %d\n%d\n", cont++, num[n]%10);
	
	return 0;
}