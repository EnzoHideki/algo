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

const int L = 3e3 + 10;

//

map<pii, int> comp;
map<pii, sii> adj;
queue<pii> fila;

map<pii, int> cponto;
map<pii, sii> adjponto;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
int w,h;
bool val(pii a){
	return (a.F >= 0 && a.F < h && a.S < w && a.S >= 0);
}

void bfs(pii v){
	fila.push(v);

	while(!fila.empty()){
		pii x = fila.front();
		fila.pop();

		for(auto i:adj[x]){
			if(!comp[i]){
				comp[i] = comp[x];
				fila.push(i);
			}
		}
	}
}

void bfs2(pii v){
	fila.push(v);

	while(!fila.empty()){
		pii x = fila.front();
		fila.pop();

		for(auto i:adjponto[x]){
			if(!cponto[i]){
				cponto[i] = cponto[x];
				fila.push(i);
			}
		}
	}
}

int pontos[L];

int main(){
	string tab[MAXN];
	int nb = 1;
	while(cin >> w >> h && w != 0 && h != 0){
		m(pontos);
		comp.clear();
		adj.clear();
		cponto.clear();
		adjponto.clear();


		for(int i=0; i<MAXN; i++){
			tab[i] = "";
		}

		for(int i=0; i<h; i++){
			cin >> tab[i];
		}

		int aux = 1;

		for(int i=0; i<h; i++){
			for(int j=0; j<w; j++){
				for(int k=0; k<4; k++){
					if(val({i+dy[k], j+dx[k]}) && tab[i][j] != '.' && tab[i+dy[k]][j+dx[k]] != '.'){
						adj[{i,j}].insert({i+dy[k],j+dx[k]});
					}
				}
			}
		}

		for(int i=0; i<h; i++){
			for(int j=0; j<w; j++){
				if(!comp[{i,j}] && tab[i][j] != '.'){
					comp[{i,j}] = aux++;
					bfs({i,j});
				}
			}
		}

		for(int i=0; i<h; i++){
			for(int j=0; j<w; j++){
				for(int k=0; k<4; k++){
					if(val({i+dy[k], j+dx[k]}) && tab[i][j] == 'X' && tab[i+dy[k]][j+dx[k]] == 'X'){
						adjponto[{i,j}].insert({i+dy[k],j+dx[k]});
					}
				}
			}
		}

		int aux1 = 1;
		for(int i=0; i<h; i++){
			for(int j=0; j<w; j++){
				if(!cponto[{i,j}] && tab[i][j] == 'X'){
					cponto[{i,j}] = aux1++;
					bfs2({i,j});
				}
			}
		}

		int qtddados = 0;

		for(auto i:comp) qtddados = max(qtddados, i.S);

		for(auto i:comp) dbg("par: %d %d comp: %d\n", i.F.F, i.F.S, i.S);

		int cc = 1;
		int ind = 0;
		while(cc <= qtddados){
			set<int> qtdpontos = set<int>();
			for(auto a:comp){
				if(a.S == cc && tab[a.F.F][a.F.S] == 'X'){
					qtdpontos.insert(cponto[{a.F.F,a.F.S}]);
				}
			}

			pontos[ind++] = qtdpontos.size();
			cc++;
		}

		sort(pontos, pontos+qtddados);

		dbn(qtddados);
		cout << "Throw " << nb++ << "\n";
		for(int i = 0; i<qtddados; i++){
			cout << pontos[i] << " \n"[i==qtddados-1];
		}
		cout << "\n";
	}
	
}