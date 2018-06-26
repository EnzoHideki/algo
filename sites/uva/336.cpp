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
#define dbc(x)// cerr << x << "\n"
#define dbn(x) cerr << #x << " == " << x << "\n"
#define m(v,x) memset(v,x,sizeof(v))
#define pb push_back
#define eb emplace_back
#define F first
#define S second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int INF = 0x3f3f3f3f;

//

const int MAXN = 1123456;

vector<int> adj[MAXN];
queue<int> fila;

int dist[MAXN];

set<int> qtd;

int bfs(int v, int ttl, int n) {
	fila.push(v);

	int count = n;

	m(dist,-1);
	dist[v] = 0;

	while (!fila.empty()) {
		int x = fila.front();
		fila.pop();

		for (auto i : adj[x]) {
			if (dist[i] == -1) {
				dist[i] = dist[x] + 1;

				if (dist[i] <= ttl) {
					count--;
				}
				fila.push(i);
			}
		}
	}

	return count;
}

int main() {
	ios::sync_with_stdio(false);

	int nc;

	int caso = 1;

	while (cin >> nc && nc != 0) {
		for (int i=0; i<MAXN; i++) {
			adj[i].clear();
		}

		qtd.clear();

		for (int i=0; i<nc; i++) {
			int a, b; cin >> a >> b;

			qtd.insert(a);
			qtd.insert(b);

			adj[a].pb(b);
			adj[b].pb(a);
		}

		int node,ttl;
		while (cin >> node >> ttl && (node != 0 || ttl != 0)) {
			cout << "Case " << caso++ << ": " << bfs(node,ttl,qtd.size()-1) << " nodes not reachable from node " << node << " with TTL = " << ttl << "." << endl;
		}
	}
}