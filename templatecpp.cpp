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

int main(){
	//ios::sync_with_stdio(false);

	ll r, g, b;

	//scanf("%I64x%I64x%I64x",&r,&g,&b);
	cin >> hex >> r >> g >> b;

	ll a = r/g;
	ll c = g/b;

	ll ans = 1 + a*a + a*a*c*c;

	cout << uppercase << hex << ans << endl;
	//printf("%I64x\n",ans);
}