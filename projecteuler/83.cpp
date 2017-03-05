#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <functional>
#include <iomanip>
#include <ios>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <unistd.h>
#include <utility>
#include <vector>
#define dbg(args...) //fprintf(stderr, args)
#define dbc(x) cerr << x << '\n'
#define dbn(x) cerr << #x << " == " << x << '\n'
#define m(v,x) memset(v,x,sizeof(v))
#define pb push_back
#define endl '\n'
#define F first
#define S second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

//
const int MSZ = 80;
const int MAXN = MSZ + 10;
const int INF = 0x3f3f3f3f;

int mat[MAXN][MAXN];
int dist[MAXN*MAXN];
bool seen[MAXN*MAXN];

int di[] = {1,0,-1,0};
int dj[] = {0,1,0,-1};

bool val(pii p) {
	return p.F >= 0 && p.F < MSZ && p.S >= 0 && p.S < MSZ;
}

int conv(pii p) {
	return MSZ*p.F + p.S;
}

pii unconv(int x) {
	return {x/MSZ, x%MSZ};
}

queue<int> fila;

void dijkstra(pii v) {
	dist[conv(v)] = mat[0][0];
	fila.push(conv(v));

	while (true) {
		int u = -1;
		for (int i = 0; i < (int)fila.size(); i++) {
			int x = fila.front();
			fila.pop();

			if (seen[x] == false) {
				u = x;
				break;
			}
		}

		if (u == -1) break;
		seen[u] = true;

		pii pu = unconv(u);
		for (int i=0; i<4; i++) {
			pii nei = {pu.F + di[i], pu.S + dj[i]};

			if (val(nei) && dist[conv(nei)] > dist[u] + mat[nei.F][nei.S]) {
				dist[conv(nei)] = dist[u] + mat[nei.F][nei.S];
				seen[conv(nei)] = false;

 				fila.push(conv(nei));
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(false), cin.tie(0);

	m(dist,INF);

	for (int i=0; i<MSZ; i++) {
		for (int j=0; j<MSZ; j++) {
			cin >> mat[i][j];
		}
	}

	dijkstra({0,0});

	cout << dist[conv({MSZ-1,MSZ-1})] << endl;
}