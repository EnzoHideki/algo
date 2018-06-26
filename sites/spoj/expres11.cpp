#include <bits/stdc++.h>
//#include <stdio.h>
 
using namespace std;
 
const int MAXN = 100005;
 
char pilha[MAXN], a[MAXN];
int livre = 0;
 
void empilha(char a){
    pilha[livre++] = a;
}
 
void desempilha(){
    livre--;
}
 
char topo(){
    return pilha[livre-1];
}
 
bool taVazia(){
    return livre == 0;
}
 
int main(){
    int t; scanf("%d", &t);
    
    for(int i = 0; i < t; i++){
        for(int j = 0; j < MAXN; j++){
            a[j] = 0;
            pilha[i] = 0;
        }
        livre = 0;
        
        scanf("%s", a);
        
        bool ended = false;
        
        for(int j = 0; j < MAXN; j++){
            if(a[j] == 0) break;
            
            if(a[j] == '[' || a[j] == '(' || a[j] == '{')
                empilha(a[j]);
            else {
                if ((a[j] == ']' && topo() == '[') || (a[j] == ')' && topo() == '(') || (a[j] == '}' && topo() == '{'))
                    desempilha();
                else {
                    printf("N\n");
                    ended = true;
                    break;
                }
            }
        }
        
        if(!ended) if(livre > 0) printf("N\n"); else printf("S\n"); 
    }
    
    return 0;
}