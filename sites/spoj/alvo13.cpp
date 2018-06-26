#include <bits/stdc++.h>
 
using namespace std;
 
const long BOUND = 100005;
    
long long power(long long a, int b){
    int i; long long prod = 1;
    
    for(i = 0; i < b; i++){
        prod *= a;
    }
    
    return prod;
}
 
int main(){
    long long c, t, i, j, radius[BOUND];
    
    scanf("%lld%lld", &c, &t);
    
    for(i = 0; i < c; i++){
        scanf("%lld", &radius[i]);
    }
    
    long long points = 0, x, y;
    
    for(i = 0; i < t; i++){
        scanf("%lld%lld", &x, &y);
        
        /*for(j = 0; j < c; j++){
            if(power(x,2) + power(y,2) <= power(radius[j],2)){
                points += c-j; 
                break;
            }
        }*/
        
        long long l = 0, r = c; 
        
        int found = 0; 
        
        long long squares = power(x,2) + power(y,2);
        
        //printf("xÂ² + yÂ² = %li\n", squares);
        
        while(l < r){
            long long mid = (l+r)/2;
            
            if(squares <= power(radius[mid],2)){
                r = mid;
            } else {
                l = mid + 1;
            }
            
           
        }
        
        points += c - l;
    }
    
    printf("%lld\n", points);
    
    return 0;
} 