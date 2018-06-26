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

const int MAXN = 1e2 + 10;

//

string tab[MAXN];
map<pii, sii> adj;
map<pii, int> comp;
queue<pii> fila;

int dx[8] = {-1,0,1,-1,1,-1,0,1};
int dy[8] = {1,1,1,0,0,-1,-1,-1};
int m,n;
bool val(pii a){
	return (a.F >= 0 && a.F < m && a.S >= 0 && a.S < n);
}

void bfs(pii v){
	fila.push(v);

	while(!fila.empty()){
		pii x = fila.front();
		fila.pop();

		for(auto i:adj[x]){
			if(!comp[i]){
				fila.push(i);
				comp[i] = comp[x];
			}
		}
	}
}
int main(){
	while(cin >> m >> n && m != 0){
		int aux = 1;

		for(int i = 0; i<MAXN; i++) tab[i] = "";
		adj.clear();
		comp.clear();

		for(int i=0; i<m; i++)	cin >> tab[i];

		for(int i=0; i<m; i++){
			for(int j=0; j<n; j++){
				for(int k=0; k<8; k++){
					if(val({i+dy[k], j+dx[k]}) && tab[i][j] == '@' && tab[i+dy[k]][j+dx[k]] == '@'){
						adj[{i,j}].insert({i+dy[k],j+dx[k]});
					}
				}
			}
		}

		for(int i=0; i<m; i++){
			for(int j=0; j<n; j++){
				if(tab[i][j] == '@' && !comp[{i,j}]){
					comp[{i,j}] = aux++;
					bfs({i,j});
				}
			}
		}

		int m = 0;
		for(auto i:comp) m = max(m,i.S);
		cout << m << "\n";
	}
}