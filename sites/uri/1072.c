#include<stdio.h>

int main()
{
	int n;
	scanf("%d", &n);

	int nstatic = n;
	int in = 0;
	int out = 0;
	int x[10000];	

	while(n>0){
		scanf("%d", &x[n-1]);
		n--;
	}
	
	int i;
	for(i = 0; i < nstatic; i++){
		if(x[i]>=10 && x[i]<=20){
			in++;		
		} else {
			out++;		
		}
	}

	printf("%d in\n%d out\n", in, out);

	return 0;
}
