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
#include <utility>
#include <unistd.h>
#include <vector>
#define dbg(args...) //fprintf(stderr, args)
#define dbc(x) //cerr << x << "\n"
#define dbn(x) cerr << #x << " == " << x << "\n"
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
typedef set<int> si;

const int INF = 0x3f3f3f3f;

//

int main(){
	ios::sync_with_stdio(false);

	ll t; cin >> t;

	while (t--) {
		ll ans = 0;
		ll inp; cin >> inp;
		ll a = (inp-1)/3;
		ll b = (inp-1)/5;
		ll c = (inp-1)/15;
		ans = (a*(a+1)*3)/2 + (b*(b+1)*5)/2 - (c*(c+1)*15)/2;
		cout << ans << endl;
	}
}