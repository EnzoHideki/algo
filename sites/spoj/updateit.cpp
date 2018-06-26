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
typedef vector<pii> vii;
typedef set<int> si;
typedef set<pii> sii;

const int INF = 0x3f3f3f3f;

// Update the array!

const int MAXN = 1e4 + 10;

int v[MAXN], ac[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;

	while(t--){
		m(v);
		m(ac);

		int n,u; cin >> n >> u;

		while(u--){
			int l, r, val; cin >> l >> r >> val;
			v[l] += val;
			v[r+1] += -val;
		}

		ac[0] = v[0];
		for(int i=1; i<n; i++){
			ac[i] = v[i] + ac[i-1];
		}

		int q; cin >> q;
		while(q--){
			int ind; cin >> ind;
			cout << ac[ind] << endl;
		}
	}
}