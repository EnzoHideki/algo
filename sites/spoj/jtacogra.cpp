#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int n, t, v;
    
    scanf("%d", &n);
    
    int prod = 0;
    
    for(int i = 0; i < n; i++){
        scanf("%d%d", &t, &v);
        
        prod+= t*v;
    }
    
    printf("%d", prod);
}