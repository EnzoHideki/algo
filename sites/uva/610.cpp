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
#include <sstream>
#include <unistd.h>
#include <utility>
#include <vector>
#define dbc(x) //cerr << x << '\n'
#define dbn(x) //cerr << #x << " == " << x << '\n'
#define pb push_back
#define endl '\n'

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

//
const int MAXN = 1123;
int tempo = 0;
vector<int> adj[MAXN];
int parent[MAXN];
vector<pii> bridges;
int dfs_low[MAXN];
int pre[MAXN];

void apb(int u) {
	dfs_low[u] = pre[u] = tempo++;

	for (int x : adj[u]) {
		if (pre[x] == -1) {
			parent[x] = u;

			apb(x);

			bridges.push_back({u, x});

			if (dfs_low[x] > pre[u]) {	
				bridges.push_back({x, u});
			}

			dfs_low[u] = min(dfs_low[u], dfs_low[x]);
		} else if (parent[u] != x && pre[u] > pre[x]) {
			dfs_low[u] = min(dfs_low[u], pre[x]);
			bridges.push_back({u, x});
		}
	}
}

int main(){
	ios::sync_with_stdio(false), cin.tie(0);

	int n,m; 

	int test = 1;

	while (cin >> n >> m && (n != 0 || m != 0)) {
		for (int i=0; i<MAXN; i++) {
			adj[i].clear();
			dfs_low[i] = -1;
			pre[i] = -1;
			parent[i] = -1;
		}
		bridges.clear();

		for (int i=0; i<m; i++) {
			int a,b; cin >> a >> b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}

		for (int i=1; i<=n; i++) {
			if (pre[i] == -1) {
				apb(i);
			}
		}

		cout << test++ << endl << endl;

		for (pii p : bridges) {
			cout << p.first << " " << p.second << endl;
		}

		cout << "#" << endl;
	}
}