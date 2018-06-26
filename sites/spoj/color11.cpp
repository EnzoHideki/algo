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
#define dbc(x) //cerr << x << "\n"
#define dbn(x) //cerr << #x << " == " << x << "\n"
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
typedef vector<pair<int,int> > vii;
typedef set<int> si;

const int INF = 0x3f3f3f3f;
const int MAXN = 112345;

int n,m,x,y,k;

set<pii> holes;
map<pii, vii> adj;
map<pii, int> comp;

int dx[8] = {-1,0,1,-1,1,-1,0,1};
int dy[8] = {1,1,1,0,0,-1,-1,-1};

bool val(pii a){
	return (a.F >= 1 && a.F <= n && a.S >=1 && a.S <= m);
}

queue<pii> fila;

int ans = 0;

int bfs(pii v){
	ans++;
	fila.push(v);

	while(!(fila.empty())){
		pii x = fila.front();
		fila.pop();

		for(auto i:adj[x]){
			if(!comp[i]){
				comp[i] = comp[x];
				ans++;
				fila.push(i);
			}
		}
	}

	return ans;
}

int main(){
	cin >> n >> m >> x >> y >> k;

	for(int i=0; i<k; i++){
		int a,b; cin >> a >> b;
		holes.insert({a,b});
	}
	dbc(1);
	for(int i=1; i<=n; i++){
		dbc(91);
		for(int j=1; j<=m; j++){
			dbc(92);
			for(int k=0; k<8; k++){
				dbc(93);
				if(val({i+dy[k],j+dx[k]}) && (holes.find({i+dy[k],j+dx[k]}) == holes.end())){
					adj[{i,j}].pb({i+dy[k],j+dx[k]});
				}
			}
		}		
	}
	dbc(90);
	comp[{x,y}]=1;
	cout << bfs({x,y}) << "\n";

	return 0;
}