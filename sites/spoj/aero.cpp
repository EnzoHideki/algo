#include <stdio.h>
#include <algorithm>
 
using namespace std;
 
int main(){
	int i, j, A, V;
	
	//creates and initializes the tests array with zeros
	static int tests[1000][1000];
 
 
	int testNumber = 0;
 
	while(scanf("%d%d", &A, &V) && A != 0 && V != 0){
		//creates and initializes the airports array with zeros
		int airports[105];
		for(i = 0; i <= A; i++){
			airports[i] = 0;
		}
		
		//populates airports array with the number of transactions
		for(i = 0; i < 2*V; i++){
			int index;
			scanf("%d", &index);
			airports[index]++;
		}
		
		//prints the airports array for debugging
		/*for(i = 0; i <= 5; i++){
			printf("%d ", airports[i]);
		}*/
		
		//gets the biggest value of transactions at the airports
		int biggest = 0;
		for(i = 1; i <= A; i++){
			if(airports[i] > biggest){
				biggest = airports[i];
			}
		}
		
		testNumber++;
		printf("Teste %d\n", testNumber);
		
		int first = 1;
		for(j = 1; j <= A; j++){
			if(airports[j] == biggest){
				if (!first) putchar(' ');
				else first = 0;
				printf("%d", j);
			}
		}
		printf("\n\n");
	}
	return 0;
} 