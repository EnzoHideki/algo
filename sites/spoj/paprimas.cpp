#include <stdio.h>
#include <math.h>
#include <string.h>
 
int main(){
	char words[25];
	char results[5000][25];
	
	int palavra = 0;
 
    while(scanf("%s", words) != EOF){
    	int sum = 0;
 
    	int i = 0;
    	for(i; i<strlen(words); i++){
    		if((words[i]>64 && words[i]<91)){
    			sum += words[i] - 38;
    		}
    		if((words[i]>96 && words[i]<123)){
    			sum += words[i] - 96;
    		}
    	}
       	i = 2;
	    int notPrime = 0;
 
	    if(sum == 1 || sum == 2){
	    	notPrime = 0;
	    } else {
	    	for(i; i <= sqrt(sum); i++){
		    	if(sum % i == 0){
					notPrime = 1;
					break;
		    	}
	    	}
	    }
 
	    if(notPrime){
	    	strcpy(results[palavra], "It is not a prime word.");
	    } else {
			strcpy(results[palavra], "It is a prime word.");
	    }
 
	    palavra++;
    }
 
    int i = 0;
	for(i; i<palavra; i++){
		printf("%s\n", results[i]);
	}
 
    
 
    return 0;
}