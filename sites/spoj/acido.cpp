#include <bits/stdc++.h>
 
using namespace std;
 
const int MAXN = 305;
char fita[MAXN], pilha[MAXN];
int livre;
 
void empilha(char element){
    pilha[livre++] = element;
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
    scanf("%s", fita);
    
    while(fita[0] != 0){
        int size = strlen(fita), count = 0;
        
        for(int i = 0; i<size; i++){
            if(!taVazia() && (  (fita[i] == 'C' && topo() ==  'F') || (fita[i] == 'F' && topo() ==  'C') ||
                                (fita[i] == 'B' && topo() ==  'S') || (fita[i] == 'S' && topo() ==  'B'))){
                desempilha();
                count++;
            } else empilha(fita[i]);
        }
        
        printf("%d\n", count);
        for(int i = 0; i < MAXN; i++) fita[i] = pilha[i] = 0;
        scanf("%s", fita);
        livre = 0;
    }
    
    return 0;
} 