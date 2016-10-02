#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <set>
#include <utility>
#include <vector>
#include <map>
#include <cstring>
#include <queue>
#include <ios>
#include <iomanip>
#define dbg(args...) //fprintf(stderr, args)
#define dbc(x) cerr << x << "\n"
#define dbn(x) cerr << #x << " == " << x << "\n"
#define m(x) memset(x,0,sizeof(x))
#define bits(x) __builtin_popcount(x)
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

const int INF = 0x3f3f3f3f;
const int MAXN = 1e4 + 10;

//

vi adj[MAXN];
int comp[MAXN];
//int dp[MAXN];
queue<int> fila;

int esc[MAXN];

void bfs(int v){
	fila.push(v);

	while(!fila.empty()){
		int x = fila.front();
		fila.pop();

		esc[x] = 1;
		for(auto i:adj[x]){
			if(!esc[i]){
				esc[i]=1;
				fila.push(i);
			}
		}
	}
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t; cin >> t;

	for(int i=0; i<t; i++){
		m(adj);
		m(comp);
		m(esc);

		int n,m,l; cin >> n >> m >> l;

		for(int j=0; j<m; j++){
			int a,b; cin >> a >> b;

			adj[a].pb(b);
		}


		for(int j=0; j<l; j++){
			int x; cin >> x;

			if(!esc[x]){
				bfs(x);
			}
		}

		int ans=0;
		for(int j=1; j<=n; j++){
			ans += esc[j];
		}

		cout << ans << "\n";

	}
}