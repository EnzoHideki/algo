#include<stdio.h>

int main()
{
	int requested; 
	int cont100 = 0;
	int cont50 = 0;
	int cont20 = 0;
	int cont10 = 0;
	int cont5 = 0;
	int cont2 = 0;
	int cont1 = 0;

	scanf("%d", &requested);
	printf("%d\n", requested);

	while(requested>=100){
		cont100++;
		requested -= 100;
	}

	while(requested>=50){
		cont50++;
		requested -= 50;
	}

	while(requested>=20){
		cont20++;
		requested -= 20;
	}

	while(requested>=10){
		cont10++;
		requested -= 10;
	}

	while(requested>=5){
		cont5++;
		requested -= 5;
	}

	while(requested>=2){
		cont2++;
		requested -= 2;
	}

	while(requested>=1){
		cont1++;
		requested -= 1;
	}

	printf("%d nota(s) de R$ 100,00\n%d nota(s) de R$ 50,00\n%d nota(s) de R$ 20,00\n%d nota(s) de R$ 10,00\n%d nota(s) de R$ 5,00\n%d nota(s) de R$ 2,00\n%d nota(s) de R$ 1,00\n", cont100, cont50, cont20, cont10, cont5, cont2, cont1);

	return 0;
}
