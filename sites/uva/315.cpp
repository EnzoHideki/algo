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
int n;

int parent[MAXN];
vector<int> filhos[MAXN];

int dfs_num[MAXN];
int dfs_low[MAXN];
bool seen[MAXN];
vector<int> adj[MAXN];
bool art[MAXN];
int t = 0;

void init() {
	m(seen, false);
	m(art, false);
	m(filhos, 0);
	t = 0;
	for (int i=0; i<MAXN; i++) {
		adj[i].clear();
		parent[i] = i;
	}
}

void dfs(int v) {
	dfs_num[v] = t++;
	for (auto i : adj[v]) {
		if (seen[i] == false) {
			parent[i] = v;
			seen[i] = true;
			dfs(i);
		}
	}
}

int dfs1(int v) {
	dfs_low[v] = dfs_num[v];

	for (auto i : adj[v]) {
		if (seen[i] == false) {
			seen[i] = true;
			filhos[v].pb(i);
			dfs_low[v] = min(dfs_low[v], dfs1(i));
		} else {
			if (parent[v] != i) {
				dfs_low[v] = min(dfs_low[v], dfs_num[i]);
			}
		}
	}

	return dfs_low[v];
}

vector<int> split(string s, string del) {
	char* vs = (char *) malloc(s.size() + 5);
	strcpy(vs, s.c_str());
	vector<int> ret;
	for (char* p = strtok(vs, del.c_str()); p; p = strtok(NULL, del.c_str()))
		ret.pb(stoi(string(p)));
	return ret;
}

int main(){
	ios::sync_with_stdio(false), cin.tie(0);

	while (cin >> n && n != 0) {
		init();
		string s;
		getline(cin, s);
		while (true) {
			getline(cin, s);
			vector<int> lin = split(s, " ");

			int place = lin[0];

			if (place == 0) break;

			for (int i=1; i<(int)lin.size(); i++) {
				adj[lin[i]].pb(place);
				adj[place].pb(lin[i]);
			}
		}

		seen[1] = true;
		dfs(1);

		m(seen, false);
		seen[1] = true;
		dfs1(1);

		for (int i=1; i<=n; i++) {
			if (parent[i] == i) {
				if (filhos[i].size() > 1) {
					art[i] = true;
				}
			} else {
				if (filhos[i].size() >= 1) {
					bool isart = false;

					for (int x : filhos[i]) {
						if (dfs_low[x] >= dfs_num[i]) {
							isart = true;
							break;
						}
					}

					if (isart) art[i] = true;
				}
			}
		}

		int ans = 0;

		for (int i=1; i<=n; i++) {
			if (art[i]) {ans++;}
		}

		cout << ans << endl;
	}
}