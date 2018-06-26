#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int n;
    
    int aux = 1;
    while(true){
        scanf("%d", &n);
        
        if(n==0) break;
 
        char player1[15], player2[15];
 
        scanf("%s", player1); 
        scanf("%s", player2);
 
        printf("Teste %d\n", aux++);
 
        for(int i = 0; i < n; i++){
            int a, b;
 
            scanf("%d%d", &a, &b);
 
            if((a + b) % 2 == 0){ printf("%s\n", player1); } else { printf("%s\n", player2); }
        } printf("\n");
    }
    
    return 0;
} 