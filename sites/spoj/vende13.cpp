#include <stdio.h>
#include <algorithm>
 
using namespace std;
 
int main(){
	long long i, n, k;
	
	scanf("%lld%lld", &n, &k);
	
	long long array[n];
	
	for(i = 0; i < n; i++){
		scanf("%lld", &array[i]);
	}
	
	long long menor = 1000005;
	
	sort(array, array + n);
	
	for(i = 0; i < k+1; i++){
		long long diff = array[i+(n-k-1)] - array[i];
		if(diff < menor) menor = diff;
	}
	
	printf("%lli\n", menor);
	
	return 0;
}