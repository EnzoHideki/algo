#include <stdio.h>


long long fib(int n){
	long long f[n+1];

	f[0] = 0;
	f[1] = 1;

	long long i;
	for(i = 2; i<=n; i++){
		f[i] = f[i-1] + f[i-2];
	}

	return f[n];

	/*if(n <= 1){
		return n;
	} else {
		return fib(n-1) + fib(n-2);
	}*/
}


int main(){
	int t;
	scanf("%d", &t);

	int numbers[t];

	int i = 0;

	for(i; i<t; i++){
		scanf("%d", &numbers[i]);
	}

	i = 0;

	for(i; i<t; i++){
		printf("Fib(%d) = %lli\n", numbers[i], fib(numbers[i]));
	}

	return 0;
}
