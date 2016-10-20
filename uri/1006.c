#include<stdio.h>

int main()
{
	double gradeA, gradeB, gradeC;
	scanf("%lf", &gradeA);
	scanf("%lf", &gradeB);
	scanf("%lf", &gradeC);

	printf("MEDIA = %.1lf\n", (2*gradeA + 3*gradeB + 5*gradeC)/10);

	return 0;
}
