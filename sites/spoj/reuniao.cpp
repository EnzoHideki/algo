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
#define dbg(args...) //fprintf(stderr, args)
#define dbc(x) cerr << x << "\n"
#define dbn(x) cerr << #x << " == " << x << "\n"
#define bits(x) __builtin_popcount(x)
#define m(x) memset((x),0,sizeof(x))
#define minf(x) memset((x),63,sizeof(x))
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
 
const int MAXM = 1e4 + 10;
const int MAXN = 1e2 + 10;
const int INF = 0x3f3f3f3f;
 
//
 
int dist[MAXN][MAXN];
int mat[MAXN][MAXN];
 
int main(){
	int n, m; cin >> n >> m;
 
	minf(mat);
	minf(dist);
 
	for(int i=0; i<m; i++){
		int u,v,w; cin >> u >> v >> w;
 
		int &a = mat[u][v];
		int &b = mat[v][u];
 
		int &c = dist[u][v];
		int &d = dist[v][u];
 
		a = min(a, w);
		b = min(b, w);
		c = min(c, w);
		d = min(d, w);
	}
 
	for(int i=0; i<n; i++) for(int j=0; j<n; j++) for(int k=0; k<n; k++) dist[j][k] = min(dist[j][k], dist[i][j]+dist[i][k]);
 
	int ans = INF;
	for(int i=0; i<n; i++){
		int ma=0;
		for(int j=0; j<n; j++){
			ma=max(dist[i][j],ma);
		}
		ans = min(ma, ans);
	}
	cout << ans << "\n";
}


//usando dijkstra abaixo

/*
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
#define dbg(args...) //fprintf(stderr, args)
#define dbc(x) //cerr << x << "\n"
#define dbn(x) //cerr << #x << " == " << x << "\n"
#define bits(x) __builtin_popcount(x)
#define m(x) memset((x),0,sizeof(x))
#define minf(x) memset((x),63,sizeof(x))
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

const int MAXM = 1e4 + 10;
const int MAXN = 1e2 + 10;
const int INF = 0x3f3f3f3f;

//

int dist[MAXN][MAXN];
int mat[MAXN][MAXN];
int seen[MAXN];
int n, m;

int dijkstra(int s){
	m(seen);

	for(int i=0; i<n; i++){
		dist[s][i] = mat[s][i];
	}

	dist[s][s] = 0;
	seen[s] = 1;

	int ret = 0;

	while(true){
		int u = -1;
		int mdist = INF;

		for(int i=0; i<n; i++){
			if(!seen[i] && dist[s][i]<mdist){
				mdist = dist[s][i];
				u = i;
			}
		}

		if(u == -1) break;

		seen[u] = 1;

		for(int i=0; i<n; i++){
			
			if(dist[u][i] != INF){
				dist[i][s] = dist[s][i] = min(dist[s][i], dist[s][u]+mat[u][i]);
				ret = max(ret, dist[s][i]);
			}
		}
	}

	ret = 0;
	for(int i=0; i<n; i++){
		ret = max(ret, dist[s][i]);
	}

	return ret;
}

int main(){
	cin >> n >> m;

	minf(mat);
	minf(dist);

	for(int i=0; i<m; i++){
		int u,v,w; cin >> u >> v >> w;

		int &a = mat[u][v];
		int &b = mat[v][u];

		int &c = dist[u][v];
		int &d = dist[v][u];

		a = min(a, w);
		b = min(b, w);
		c = min(c, w);
		d = min(d, w);
	}

	int ans = INF;
	for(int i=0; i<n; i++){
		int k = dijkstra(i);
		ans = min(ans, k);
	}

	cout << ans << "\n";
}

*/