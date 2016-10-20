#include<stdio.h>

int main()
{
	int i = 1;
	int iterator = 1;

	while(i<=9){
		printf("I=%d J=%d\n", i, i+7-iterator);
		if(iterator==3){
			i = i + 2;
			iterator = 1;
		} else {
			iterator++;
		}	
	}

	return 0;
}
