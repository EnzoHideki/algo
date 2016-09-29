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
#define endl '\n'
#define bits(x) __builtin_popcount(x)
#define m(x) memset((x),0,sizeof(x))
#define minf(x) memset((x),63,sizeof(x))
#define eb emplace_back
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
const int MAXN = 1e1 + 10;
const int INF = 0x3f3f3f3f;

//
int n;
//int mat[MAXN*MAXN][MAXN*MAXN];
int dist[MAXN*MAXN][MAXN*MAXN];

int f(int x, int y){
	return y*n + x;
}

int main(){
	while(cin >> n && n!=0){
		//minf(mat);
		minf(dist);

		for(int j=n-1; j>=0; j--)
		for(int i=0; i<4*n; i++){
			int k;
			cin >> k;

			if(k){
				int x = i/4;
				switch(i%4){
					case 0:
						//mat[f(x,j)][f(x,j+1)] = 1;
						dist[f(x,j)][f(x,j+1)] = 1;
					break;
					case 1:
						//mat[f(x,j)][f(x,j-1)] = 1;
						dist[f(x,j)][f(x,j-1)] = 1;
					break;
					case 2:
						//mat[f(x,j)][f(x-1,j)] = 1;
						dist[f(x,j)][f(x-1,j)] = 1;
					break;
					case 3:
						//mat[f(x,j)][f(x+1,j)] = 1;
						dist[f(x,j)][f(x+1,j)] = 1;
					break;
				}
			}
		}

		for(int i=0; i<n*n; i++) for(int j=0; j<n*n; j++) for(int k=0; k<n*n; k++) dist[j][k] = min(dist[j][k], dist[j][i]+dist[i][k]);

		for(int i=0; i<n*n; i++) dist[i][i] = 0;

		int p; cin >> p;

		for(int i=0; i<p; i++){
			int x0, y0, x1, y1;
			cin >> x0 >> y0 >> x1 >> y1;

			if(dist[f(x0,y0)][f(x1,y1)]==INF) puts("Impossible");
			else cout << dist[f(x0,y0)][f(x1,y1)] << endl;
		}

		cout << endl;
	}
}




//solucao dijkstra abaixo


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
#define dbg(args...) fprintf(stderr, args)
#define dbc(x) cerr << x << "\n"
#define dbn(x) cerr << #x << " == " << x << "\n"
#define endl '\n'
#define bits(x) __builtin_popcount(x)
#define m(x) memset((x),0,sizeof(x))
#define minf(x) memset((x),63,sizeof(x))
#define eb emplace_back
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
const int MAXN = 1e1 + 10;
const int INF = 0x3f3f3f3f;

//
int n;
int mat[MAXN*MAXN][MAXN*MAXN];
int dist[MAXN*MAXN][MAXN*MAXN];
int seen[MAXN*MAXN];

int f(int x, int y){
	return y*n + x;
}

void dijkstra(int v){
	m(seen);

	for(int i=0; i<n*n; i++){
		dist[v][i] = mat[v][i];
	}

	seen[v] = 1;
	dist[v][v] = 0;

	while(true){
		int u=-1;
		int mdist = INF;

		for(int i=0; i<n*n; i++){
			if(!seen[i] && dist[v][i] < mdist){
				mdist = dist[v][i];
				u = i;
			}
		}

		if(u == -1) break;
		seen[u] = true;

		for(int i=0; i<n*n; i++){
			dist[v][i] = min(dist[v][i], dist[v][u]+mat[u][i]);
		}
	}
}

int main(){
	while(cin >> n && n!=0){
		minf(mat);
		minf(dist);

		for(int j=n-1; j>=0; j--)
		for(int i=0; i<4*n; i++){
			int k;
			cin >> k;

			if(k){
				int x = i/4;
				switch(i%4){
					case 0:
						mat[f(x,j)][f(x,j+1)] = 1;
						//dist[f(x,j)][f(x,j+1)] = 1;
					break;
					case 1:
						mat[f(x,j)][f(x,j-1)] = 1;
						//dist[f(x,j)][f(x,j-1)] = 1;
					break;
					case 2:
						mat[f(x,j)][f(x-1,j)] = 1;
						//dist[f(x,j)][f(x-1,j)] = 1;
					break;
					case 3:
						mat[f(x,j)][f(x+1,j)] = 1;
						//dist[f(x,j)][f(x+1,j)] = 1;
					break;
				}
			}
		}

		//for(int i=0; i<n*n; i++) for(int j=0; j<n*n; j++) for(int k=0; k<n*n; k++) dist[j][k] = min(dist[j][k], dist[j][i]+dist[i][k]);

		//for(int i=0; i<n*n; i++) dist[i][i] = 0;

		for(int i=0; i<n*n; i++) dijkstra(i);

		int p; cin >> p;

		for(int i=0; i<p; i++){
			int x0, y0, x1, y1;
			cin >> x0 >> y0 >> x1 >> y1;

			if(dist[f(x0,y0)][f(x1,y1)]==INF) puts("Impossible");
			else cout << dist[f(x0,y0)][f(x1,y1)] << endl;
		}

		cout << endl;
	}
}
*/