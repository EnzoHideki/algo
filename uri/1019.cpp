#include<stdio.h>

int main()
{
	int n; 
	int hours = 0;
	int minutes = 0;
	int seconds = 0;

	scanf("%d", &n);

	while(n>=3600){
		hours++;
		n -= 3600;
	}

	while(n>=60){
		minutes++;
		n -= 60;
	}

	while(n>=1){
		seconds++;
		n -= 1;
	}

	printf("%d:%d:%d\n", hours, minutes, seconds);

	return 0;
}
