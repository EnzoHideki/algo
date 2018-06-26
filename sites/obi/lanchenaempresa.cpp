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

const int MAXS = 3e2 + 10;
const int MAXC = 5e4 + 10;
const int INF = 0x3f3f3f3f;

//

int mat[MAXS][MAXS];
int dist[MAXS][MAXS];

int main(){
	int s,c; cin >> s >> c;

	minf(mat);
	minf(dist);

	for(int i=0; i<c; i++){
		int a,b,d; cin >> a >> b >> d;

		mat[a][b] = min(mat[a][b],d);
		mat[b][a] = min(mat[b][a],d);
		dist[a][b] = min(dist[a][b],d);
		dist[b][a] = min(dist[b][a],d);
	}

	for(int i=1; i<=s; i++) for(int j=1; j<=s; j++) for(int k=1; k<=s; k++) (k==j?dist[k][j]=0:dist[k][j] = min(dist[k][j], dist[i][j]+dist[k][i]));

	int ans = INF;
	for(int i=1; i<=s; i++){

		int m =0 ;
		for(int j=1; j<=s; j++){
			m = max(m,dist[i][j]);
		}
		ans = min(ans, m);
	}

	cout << ans << "\n";
}


//solucao com varios dijkstra abaixo

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

const int MAXS = 3e2 + 10;
const int MAXC = 5e4 + 10;
const int INF = 0x3f3f3f3f;

//

int mat[MAXS][MAXS];
int dist[MAXS][MAXS];
int seen[MAXS];
int s,c;

int dijkstra(int v){
	m(seen);

	dist[v][v] = 0;
	seen[v] = 1;

	while(true){
		int u = -1;
		int mdist = INF;

		for(int i=1;i<=s; i++){
			if(!seen[i] && dist[v][i] < mdist){
				mdist = dist[v][i];
				u = i;
			}
		}

		if(u == -1) break;

		seen[u]=1;

		for(int i=1; i<=s; i++){
			dist[v][i] = min(dist[v][i], dist[v][u]+mat[u][i]);
		}
	}

	return *(max_element(dist[v]+1, dist[v]+s+1));
}

int main(){
	cin >> s >> c;

	minf(mat);
	minf(dist);

	for(int i=0; i<c; i++){
		int a,b,d; cin >> a >> b >> d;

		mat[a][b] = min(mat[a][b],d);
		mat[b][a] = min(mat[b][a],d);
		dist[a][b] = min(dist[a][b],d);
		dist[b][a] = min(dist[b][a],d);
	}

	int ans = INF;
	for(int i=1; i<=s; i++){
		ans = min(ans, dijkstra(i));
	}

	cout << ans << "\n";
}

*/