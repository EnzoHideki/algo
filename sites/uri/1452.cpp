#include <cstdio>
#include <iostream>
#include <algorithm>
#include <set>
#include <utility>
#include <vector>
#include <map>
#define dbg(args...) //fprintf(stderr, args)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int MAXN = 212;

set<string> ser[MAXN];

int main(){
	int m, n;
	
	while(cin >> n >> m && n != 0 && m != 0){
		for(int i=0; i<MAXN; i++) ser[i].clear();
		
		for(int i=0; i<n; i++){
			int a; cin >> a;
			for(int j=0; j<a; j++){
				string app; cin >> app;
				ser[i].insert(app);
			}
		}
		
		int cont = 0;
		for(int i=0; i<m; i++){
			int numpre; cin >> numpre;
			set<string> precisa;
			precisa.clear();
			for(int j=0; j<numpre; j++){
				string apppre; cin >> apppre;
				precisa.insert(apppre);
			}
			
			for(int j=0; j<n; j++)
				for(auto k:precisa)
					if(ser[j].find(k)!=ser[j].end()){
						dbg("i: %d j: %d\n",i,j);
						cont++;
						break;
					}
		}
		
		cout << cont << endl;
	}
}
