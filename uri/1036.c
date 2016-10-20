#include<stdio.h>
#include<math.h>

int main()
{
	double a,b,c,root1,root2;
	scanf("%lf", &a);
	scanf("%lf", &b);
	scanf("%lf", &c);

	double delta = (b*b) - (4*a*c);

	if(delta<0 || a==0){
		printf("Impossivel calcular\n");
		return 0;
	}

	root1 = ((-1)*b + sqrt(delta))/(2*a);
	root2 = ((-1)*b - sqrt(delta))/(2*a);

	printf("R1 = %.5lf\nR2 = %.5lf\n", root1, root2);

	return 0;
}
