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
 
const int MAXN = 11234;
const int MAXK = 11234;
 
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
 
string tab[MAXN];
map<pii, vii> adj;
map<pii, int> comp;
int qtd[MAXN];
int ans[MAXN];
int n,m;
 
void dfs(pii v){
	for(auto i:adj[v]){
		dbg("par: %d %d\n", v.F, v.S);
		dbg("vizinho: %d %d\n", i.F, i.S);
 
		dbg("a\n");
		comp[i];
		dbg("b\n");
 
		if(!comp[i]){
			dbg("entr\n");
			comp[i] = comp[v];
			qtd[comp[i]]++;
			dfs(i);
		}
	}
}
 
bool val(int linha, int coluna){
	return (linha >= 0 && linha < n && coluna >= 0 && coluna < m);
}
 
int main(){
	cin >> n >> m;
 
	for(int i=0; i<n; i++){
		cin >> tab[i];
	}
 
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			for(int l=0; l<4; l++){
				if(val(i+dy[l], j+dx[l]) && tab[i][j] == '#' && tab[i+dy[l]][j+dx[l]] == '#')
					adj[{i,j}].pb({i+dy[l], j+dx[l]});
			}
		}
	}
 
	int aux = 1;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(tab[i][j] == '#' && comp[{i,j}] == 0){
				comp[{i,j}] = aux;
				qtd[aux]++;
				aux++;
				dfs({i,j});
			}
		}
	}
 
	int k; cin >> k;
	
	for(int i=0; i<k; i++){
		int l,c; cin >> l >> c;
 
		if(comp.find({l-1,c-1}) != comp.end()){
			ans[comp[{l-1,c-1}]]++;
		}
	}
 
	int res = 0;
 
	for(int i=1; i<= n*m; i++){
		//cout << qtd[i] << " " << ans[i] << "\n";
		res += (qtd[i] == ans[i] && qtd[i] != 0);
	}
 
	cout << res << "\n";
 
	return 0;
}