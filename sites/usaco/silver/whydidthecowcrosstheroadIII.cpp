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
#define dbc(x) //cerr << x << '\n'
#define dbn(x) //cerr << #x << " == " << x << '\n'
#define m(v,x) memset(v,x,sizeof(v))
#define pb push_back
#define endl '\n'
#define F first
#define S second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

//

const int MAXN = 112;

int n,k,r;
set<int> adj[MAXN*MAXN];
int comp[MAXN*MAXN];
int sz[MAXN*MAXN];

int di[] = {1,0,-1,0};
int dj[] = {0,1,0,-1};

int conv(int i, int j) {
	return n*(i-1) + j; 
}

bool val(int i, int j) {
	return i >= 1 && i <= n && j >= 1 && j <= n; 
}

void dfs(int v) {
	for (auto i : adj[v]) {
		if (comp[i] == -1) {
			comp[i] = comp[v];
			dfs(i);
		}
	}
}

void init() {
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=n; j++) {
			for (int k=0; k<4; k++) 
				if (val(i+di[k], j+dj[k])) {
					adj[conv(i,j)].insert(conv(i+di[k], j+dj[k]));
				}
		}
	}
}

int main(){
	ios::sync_with_stdio(false), cin.tie(0);

	freopen("countcross.in", "r", stdin);
	freopen("countcross.out", "w", stdout);

	cin >> n >> k >> r;

	init();

	for (int i=0; i<r; i++) {
		int a,b,c,d; cin >> a >> b >> c >> d;

		adj[conv(a,b)].erase(conv(c,d));
		adj[conv(c,d)].erase(conv(a,b));
	}

	m(comp,-1);

	int aux = 0;
	for (int i=1; i<=n*n; i++) {
		if (comp[i] == -1) {
			dbn(i);
			dbc("");
			comp[i] = ++aux;
			dfs(i);
		}
	}

	for (int i=0; i<k; i++) {
		int a,b; cin >> a >> b;

		dbn(conv(a,b));
		sz[comp[conv(a,b)]]++;
	}

	int ans = 0;

	for (int i=1; i<=aux; i++) {
		dbn(i);
		dbn(sz[i]);
		dbc("");
		ans += sz[i]*(k-sz[i]);
		k -= sz[i];
	}

	cout << ans << endl;
}