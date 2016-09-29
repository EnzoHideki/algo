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

const int MAXM = 1e4 + 10;
const int MAXN = 5e2 + 10;
const int INF = 0x3f3f3f3f;

// Countries at War

int m[MAXN][MAXN];
int dist[MAXN][MAXN];
int seen[MAXN];
int n,e;

void dijkstra(int v){
	m(seen);

	for(int i=1; i<=n; i++){
		dist[v][i] = m[v][i];
	}

	dist[v][v] = 0;
	seen[v] = 1;

	while(true){
		int u=-1;
		int mdist = INF;

		for(int i=1; i<=n; i++){
			if(dist[v][i] < mdist && !seen[i]){
				u = i;
				mdist = dist[v][i];
			}
		}

		if(u == -1) break;
		seen[u] = 1;


		for(int i=1; i<=n; i++){
			if(m[u][i] != INF)
				dist[v][i] = min(dist[v][i], dist[v][u] + m[u][i]);
		}
	}
}

int main(){
	while(cin >> n >> e && (n!=0 || e!=0)){
		minf(dist);
		minf(m);

		while(e--){
			int x,y,h; cin >> x >> y >> h;

			m[x][y] = h;
			if(m[y][x] != INF) m[x][y] = m[y][x] = 0;
		}

		int k; cin >> k;

		while(k--){
			int o,d; cin >> o >> d;

			dijkstra(o);

			if(dist[o][d] != INF) cout << dist[o][d] << endl;
			else cout << "Nao e possivel entregar a carta" << endl;
		}
		cout << endl;
	}
}