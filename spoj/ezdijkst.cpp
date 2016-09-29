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
#include <climits>
#define dbg(args...) //fprintf(stderr, args)
#define dbc(x) //cerr << x << "\n"
#define dbn(x) //cerr << #x << " == " << x << "\n"
#define endl '\n'
#define m(x) memset((x),0,sizeof(x))
#define minf(x) memset((x),63,sizeof(x))
#define eb emplace_back
#define pb push_back
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
const int MAXN = 1e4 + 10;
const int INF = 0x3f3f3f3f;

// Easy Dijkstra Problem

vector<pii> adj[MAXN];
int v,k;

int d[MAXN];

void dijkstra(int vv){
	minf(d);
	d[vv] = 0;
	set<pii> s;
	s.insert({d[vv], vv});

	while(!s.empty()){
		int u = s.begin() -> second;
		s.erase(s.begin());

		for(auto i:adj[u]){
			if(d[i.first] > d[u] + i.second){
				s.erase({d[i.first], i.first});
				d[i.first] = d[u] + i.second;
				s.insert({d[i.first], i.first});				
			}
		}
	}
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;

	while(t--){
		for(int i=0; i<MAXN; i++) adj[i].clear();

		cin >> v >> k;

		while(k--){
			int a,b,c; cin >> a >> b >> c;

			adj[a].pb({b,c});
		}

		int aa,bb; cin >> aa >> bb;

		dijkstra(aa);

		if(d[bb] == INF) cout << "NO\n";
		else cout << d[bb] << endl;
	}
}