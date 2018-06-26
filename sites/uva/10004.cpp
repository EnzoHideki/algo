#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
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
#define dbc(x) //cerr << x << "\n"
#define dbn(x) //cerr << #x << " == " << x << "\n"
#define m(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,-1,sizeof(x))
#define minf(x) memset(x,63,sizeof(x))
#define pb push_back
#define eb emplace_back
#define F first
#define S second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef set<int> si;

const int INF = 0x3f3f3f3f;

//

const int MAXV = 212;

int v, e;

vi adj[MAXV];
int cor[MAXV];

int dfs(int x){
	for (auto i:adj[x]) {
		if (cor[i] == -1) {
			cor[i] = !cor[x];
			if (dfs(i) == 0) return 0;
		} else if (cor[i] == cor[x]) return 0;
	}

	return 1;
}

int main(){
	ios::sync_with_stdio(false);

	while (cin >> v && v != 0) {
		cin >> e;

		for (int i=0; i<MAXV; i++) adj[i].clear();

		for (int i=0; i<e; i++) {
			int a,b; cin >> a >> b;

			adj[a].pb(b);
			adj[b].pb(a);
		}

		m1(cor);
		cor[0] = 0;

		if (dfs(0)) cout << "BICOLORABLE." << endl;
		else cout << "NOT BICOLORABLE." << endl;
	}
}