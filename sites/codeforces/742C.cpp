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

const int MAXN = 112;

vector<int> adj[MAXN];

int t = 0;
int parent[MAXN];
bool seen1[MAXN];
bool seen2[MAXN];
int n; 

bool cyc[MAXN];
vector<int> szcyc;

int lcm(int a, int b) {
	return a/__gcd(a,b)*b;
}

void dfs(int v) {
	for (auto i : adj[v]) {
		if (!seen2[i]) {
			seen2[i] = true;
			parent[i] = v;
			dfs(i);
		} else {
			int now = v;
			cyc[now] = true;

			int qtt = 1;

			while (now != i) {
				now = parent[now];
				cyc[now] = true;
				qtt++;
			}

			if (qtt % 2) {
				szcyc.pb(qtt);
			} else {
				szcyc.pb(qtt/2);
			}
		}
	}
}

void reset() {
	for (int i=1; i<=n; i++) {
		parent[i] = i;
	}
	m(seen2, false);
}

int main(){
	ios::sync_with_stdio(false), cin.tie(0);

	cin >> n;

	for (int i=1; i<=n; i++) {
		int x; cin >> x;
		adj[i].pb(x);
	}

	for (int i=1; i<=n; i++) {
		if (!seen1[i]) {
			seen1[i] = true;
			reset();
			dfs(i);
		}
	}

	for (int i=1; i<=n; i++) {
		if (!cyc[i]) {
			cout << -1 << endl;
			return 0;
		}
	}

	int ans = 1;
	for (auto i : szcyc) {
		ans = lcm(ans, i);
	}

	cout << ans << endl;
}