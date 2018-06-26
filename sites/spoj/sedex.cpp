#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int n, a, l, p;
    
    scanf("%d%d%d%d", &n, &a, &l, &p);
    
    if(a>=n && l>=n && p>=n){
        printf("S");
    } else {
        printf("N");
    }
}