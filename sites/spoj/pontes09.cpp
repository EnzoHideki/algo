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
#define dbg(args...) fprintf(stderr, args)
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
 
const int MAXN = 1e3 + 10;
const int MAXM = 1e4 + 10;
const int INF = 0x3f3f3f3f;
 
//
 
int mat[MAXN][MAXN];
int dist[MAXN];
bool visto[MAXN];
int n, m;
 
void dijkstra(int v){
	for(int i=0; i<n+2; i++) dist[i] = mat[v][i];
	dist[v] = 0;
	visto[v] = true;
 
	while(true){
		int u = -1;
		int mdist = INF;
 
		for(int i=0; i<n+2; i++){
			if(!visto[i] && dist[i] < mdist){
				mdist = dist[i];
				u = i;
			}
		}
 
		if(u==-1) break;
 
		visto[u] = true;
 
		for(int i=0; i<n+2; i++){
			if(mat[u][i] != INF) dist[i] = min(dist[i], dist[u]+mat[i][u]);
		}
	}
}
 
int main (){
	cin >> n >> m;
 
	minf(mat);
 
	for(int i=0; i<m; i++){
		int a, b, c; cin >> a >> b >> c;
 
		mat[a][b] = min(mat[a][b], c);
		mat[b][a] = min(mat[b][a], c);
	}
 
	dijkstra(0);
 
	cout << dist[n+1] << "\n";
}