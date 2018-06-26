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
#include <ctime>
#include <climits>
#define dbg(args...) fprintf(stderr, args)
#define dbc(x) cerr << x << "\n"
#define dbn(x) cerr << #x << " == " << x << "\n"
#define endl '\n'
#define m(x) memset((x),0,sizeof(x))
#define minf(x) memset((x),63,sizeof(x))
#define eb emplace_back
#define pb push_back
#define F first
#define S second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef set<int> si;
typedef set<pii> sii;

const int MAXM = 2e4 + 10;
const int MAXN = 1e4 + 10;
const int INF = 0x3f3f3f3f;

// Is it a tree

int comp[MAXN];
vi adj[MAXN];
queue<int> fila;

void bfs(int v){
	fila.push(v);

	while(!fila.empty()){
		int u = fila.front();
		fila.pop();

		for(auto i:adj[u]){
			if(!comp[i]){
				comp[i] = comp[u];
				fila.push(i);
			}
		}
	}
}

int main(){
	int n,m; cin >> n >> m;

	for(int i=0; i<m; i++){
		int x,y; cin >> x >> y;

		adj[x].pb(y);
		adj[y].pb(x);
	}

	comp[1] = 1;
	bfs(1);

	for(int i=1; i<=n; i++){
		if(!comp[i]){ 
			cout << "NO\n";
			return 0;
		}
	}

	if(n == m+1) cout << "YES" << endl;
	else cout << "NO" << endl;
}