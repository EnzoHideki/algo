#include <stdio.h>

int main(){
	int n[20];

	int i = 0;

	for(i; i<20; i++){
		scanf("%d", &n[i]);
	}

	i = 0;

	for(i; i<10; i++){
		int tmp = n[i];
		n[i] = n[19-i];
		n[19-i] = tmp;
	}

	i = 0;

	for(i; i<20; i++){
		printf("N[%d] = %d", i, n[i]);
		printf("\n");
	}

	return 0;
}
