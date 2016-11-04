#include <stdio.h>
#include <algorithm>
#include <math.h>
 
using namespace std;
 
const long long maximo = 45005;
 
int main(){
	long long i, n, m, numbers[maximo], orders[maximo];
	
	scanf("%lld%lld", &n, &m);
	
	for(i = 0; i < n; i++){
		scanf("%lld", &numbers[i]);
	}
	
	for(i = 0; i < m; i++){
		scanf("%lld", &orders[i]);
	}
	
	long long time = 0;
	
	long long l,r,mid;
	
	long long atual = 0;
	
	for(i = 0; i < m; i++){
		int delivered = 0;
		l = 0;
		r = n-1;
		
		while(!delivered){
			mid = (l+r)/2;
			
			if(orders[i] == numbers[mid]){
				delivered = 1;
			} else if(orders[i] > numbers[mid]){
				l = mid + 1;
			} else {
				r = mid - 1;
			}
		}
		time += abs(mid - atual);
		
		atual = mid; 
	}
	
	/*for(i = 0; i < m; i++){
		int delivered = 0;
		while(!delivered){
			if(orders[i] > numbers[house]){
				time++;
				house++;
			} else {
				if(orders[i] < numbers[house]){
					time++;
					house--;
				} else {
					delivered = 1;
				}
			}
		}
	}*/
	
	printf("%lld\n", time);
	
	return 0;
} 