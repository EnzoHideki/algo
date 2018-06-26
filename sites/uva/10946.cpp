#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <ios>
#include <iomanip>
#include <queue>
#include <utility>
#include <set>
#include <map>
#include <vector>
#include <cstdlib>
#define dbg(args...) //fprintf(stderr, args)
#define dbc(x) //cerr << x << "\n"
#define dbn(x) //cerr << #x << " == " << x << "\n"
#define bits(x) __builtin_popcount(x)
#define m(x) memset((x),0,sizeof(x))
#define pb push_back
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef set<int> si;
typedef set<pii> sii;

const int MAXN = 5e1 + 10;

//
sii analis;
pair<int, char> ans[MAXN*MAXN];
string aaaa[MAXN];
multiset<pair<int, char> >::reverse_iterator rit;
map<pii, sii> adj;

int dx[8] = {-1,0,1,0,-1,1,-1,1};
int dy[8] = {0,1,0,-1,1,1,-1,-1};

int x,y;
bool val(pii a){
	return (a.F>=0 && a.F<x && a.S>=0 && a.S<y);
}

int qtd;
void dfs(pii v){
	for(auto i:adj[v]){
		if(analis.find(i) == analis.end()){
			analis.insert(i);
			qtd++;
			dfs(i);
		}
	}
}

bool ord(pii a, pii b){
	return ((a.F > b.F)?true:(a.F==b.F?(a.S < b.S):false));
}
int main(){
	string tab[MAXN];
	int aa =1;
	while(cin >> x >> y && x!=0 && y!=0){
		adj.clear();
		m(ans);
		analis.clear();

		for(int i=0; i<x; i++){
			cin >> tab[i];
		}

		for(int i=0; i<x; i++){
			for(int j=0; j<y; j++){
				for(int k=0; k<4; k++){
					if(val({i+dy[k], j+dx[k]}) && tab[i][j]!='.' && tab[i][j] == tab[i+dy[k]][j+dx[k]]){
						adj[{i,j}].insert({i+dy[k], j+dx[k]});
					}
				}
			}
		}

		int ind = 0;

		for(int i=0; i<x; i++){
			for(int j=0; j<y; j++){
				qtd = 0;
				if(analis.find({i,j}) == analis.end() && tab[i][j] != '.'){
					analis.insert({i,j});
					qtd++;
					dfs({i,j});
					ans[ind++] = {qtd, tab[i][j]};
				}
			}
		}

		sort(ans, ans+ind, ord);

		cout << "Problem " << aa++ << ":\n";
		for(int i=0; i<ind; i++){
			cout << ans[i].S << " " << ans[i].F << "\n";
		}
	}
}