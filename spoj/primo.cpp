#include <stdio.h>
#include <math.h>
 
int main(){
	int n;
 
	scanf("%d", &n);
 
	if(n == 1){
		printf("nao\n");
		return 0;
	}
 
	int i = 2;
 
	int isPrime = 1;
	while(i <= sqrt(n)){
		if(n % i == 0){
			isPrime = 0;
		}
		i++;
	}
 
	if(isPrime){
		printf("sim\n");
	} else {
		printf("nao\n");
	}
 
	return 0;
} 