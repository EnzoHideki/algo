#include <bits/stdc++.h>
using namespace std;

#define MAXN 105
int t, qtd, m;
set<char> test[MAXN];
char q, a;

int main(){
    ios::sync_with_stdio(0);
    
    cin >> t;
    while(t--){
        cin >> qtd >> m;
        
        for(int i=0; i<qtd; i++){
            test[i].clear();
            test[i].insert('A');
            test[i].insert('B');
            test[i].insert('C');
            test[i].insert('D');
        }
        
        for(int i=0; i<m; i++){
            for(int j=0; j<qtd; j++){
                cin >> q >> a;
                if(a=='F'){
                    test[j].erase(q);
                } else {
                    for(int k=0; k<4; k++){
                        if(k+'A'!=q) test[j].erase(k+'A');
                    }
                }
            }
        }
        
        for(int i=0; i<qtd; i++){
            if(test[i].size()==1){
                cout << *test[i].begin();
            } else {
                cout << "?";
            }
            if(i!=qtd-1) cout << " ";
        }
        cout << endl;
    }
    
    return 0;
}