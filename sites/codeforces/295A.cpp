#include <cstdio>
#include <iostream>
#include <cmath>
#include <math.h>
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
#define m1(x) memset(x,1,sizeof(x))
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

//

const int MAXN = 112345;

ll v[MAXN];
struct op{
	ll l,r,d;

	op(){}

	op(ll ka, ll kaa, ll kaaa){
		l = ka;
		r = kaa;
		d = kaaa;
	}
};

op ve[MAXN];

ll opera[MAXN];
ll ac[MAXN];
ll add[MAXN];
//ll addc[MAXN];
ll addac[MAXN];
ll addac1[MAXN];

int main(){
	ios::sync_with_stdio(false);

	//double now = clock();

	ll n,m,k; cin >> n >> m >> k;

	for(int i=0; i<n; i++) cin >> v[i];

	for(int i=1; i<=m; i++){
		ll l, r, d; cin >> l >> r >> d;

		ve[i] = op(l,r,d);
	}

	for(int i=0; i<k; i++){
		ll x,y; cin >> x >> y;

		opera[x]++;
		opera[y+1]--;
	}

	ac[1] = opera[1];
	//dbn(ac[1]);
	for(int i=2; i<=m; i++){
		ac[i] = opera[i] + ac[i-1];
		//dbn(ac[i]);
	}

	for(int i=1; i<=m; i++){
		/*add[ve[i].l] = ac[i]*ve[i].d;
		add[ve[i].r] = -ac[i]*ve[i].d;*/
		add[i] = ac[i]*ve[i].d;
	}

	for(int i=1; i<=n; i++) dbn(add[i]);



	for(int i=1; i<=m; i++){
		addac[ve[i].l] += add[i];
		addac[ve[i].r+1] -= add[i];
	}

	

	addac1[1] = addac[1];
	for(int i=2; i<=n; i++){
		addac1[i] = addac1[i-1] + addac[i];
	}


	for(int i=1; i<=n+1; i++){
		dbn(addac[i]);
	}


	/*addc[1] = add[1];
	dbn(addc[1]);
	for(int i=2; i<n; i++){
		addc[i] = add[i]+addc[i-1];
		dbn(addc[i]);
	}*/

	for(int i=0; i<n; i++){
		v[i] += addac1[i+1];
		cout << v[i] << " \n"[i==n-1];
	}

	//cout << (clock()-now) / CLOCKS_PER_SEC << endl;
}