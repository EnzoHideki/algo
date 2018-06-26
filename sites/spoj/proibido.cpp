#include <bits/stdc++.h>
 
using namespace std;
 
const long MAXI = 140005;
int main(){
    long n; long long array[MAXI];
    
    scanf("%li", &n);
    
    for(int i = 0; i<n; i++){
        scanf("%lli", &array[i]);
    }
    
    sort(array, array+n);
 
    //vector<long long> ordered(array, array+n);
    
    //bubbleSort(ordered);
    
    /*for(int i = 0; i<n; i++){
        printf("%lli ", ordered.at(i));
    } printf("\n");*/
    
    long long input;
    
    while(scanf("%lli", &input) != EOF){
        long l = 0; long r = n-1;
        
        bool found = false;
        
        //printf("%lli ", input);
        
        while(r >= l && !found){
            long mid = (l+r)/2;
            
            if(input == array[mid]){
                printf("sim\n");
                found = true;
            } else if(input < array[mid]){
                r = mid-1;
            } else {
                l = mid+1;
            }
        }
        
        if(!found){
            printf("nao\n");
        }
    }
    
    return 0;
}