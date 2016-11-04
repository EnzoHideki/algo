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
#define dbg(args...) fprintf(stderr, args)
#define dbc(x) cerr << x << "\n"
#define dbn(x) cerr << #x << " == " << x << "\n"
#define bits(x) __builtin_popcount(x)
#define m(x) memset((x),0,sizeof(x))
#define pb push_back
#define mp make_pair
#define F first
#define S second
 
using namespace std;
 
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
 
const int MAXN = 1123;
 
vi adj[MAXN];
int comp[MAXN];
 
void dfs(int v){
	for(auto i:adj[v]){
		if(!comp[i]){
			comp[i] = comp[v];
			dfs(i);
		}
	}
}
 
int main(){
	int n, a; cin >> n >> a;
 
	int aux =1;
	for(int i=1; i<=a; i++){
		int c, d;
		cin >> c >> d;
 
		adj[c].pb(d);
		adj[d].pb(c);
	}
 
	for(int i=1; i<=n; i++){
		if(!comp[i]){
			comp[i] = aux++;
			dfs(i);
		}
	}
 
	cout << *(max_element(comp, comp+n+1)) << "\n";
 
	return 0;
}