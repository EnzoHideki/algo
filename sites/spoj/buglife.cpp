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

// A Bug's Life

const int MAXB = 2e3 + 10;
const int MAXI = 1e6 + 10;

vi adj[MAXB];
int cor[MAXB];

bool dfs(int v){
	bool ret = false;
	for(auto i:adj[v])
		if(!cor[i]){
			cor[i] = ((cor[v]==2)?1:2);
			ret = (ret || dfs(i));
		} else if(cor[i] == cor[v]) return true;

	return ret;
}

int main(){
	int t; cin >> t;

	for(int j=1; j<=t; j++){
		int b, i; cin >> b >> i;

		for(int k=0; k<MAXB; k++) adj[k].clear();

		while(i--){
			int x,y; cin >> x >> y;

			adj[x].pb(y);
			adj[y].pb(x);
		}

		bool cond = false;
		m(cor);

		for(int k=1; k<=b; k++){
			if(!cor[k]){
				cor[k] = 1;
				cond = (cond || dfs(k));
			}
		} 

		cout << "Scenario #" << j << ":\n";
		if(cond) cout << "Suspicious bugs found!" << endl;
		else cout << "No suspicious bugs found!" << endl;
	}
}