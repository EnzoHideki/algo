#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <functional>
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
#define dbc(x) cerr << x << '\n'
#define dbn(x) cerr << #x << " == " << x << '\n'
#define m(v,x) memset(v,x,sizeof(v))
#define pb push_back
#define endl '\n'
#define F first
#define S second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

//
const int MAXN = 112;

ll memo[MAXN];

ll dp(ll size) {
	if (size < -1) return 0;
	if (size == -1) return 1;
	if (size < 3) return memo[size] = 1;

	if (memo[size] == -1) {
		ll ans = 0;
		for (ll i = 3; i <= size; i++) {
			ans += dp(size-i-1);
		}
		ans += dp(size-1);
		memo[size] = ans;
	}
	
	return memo[size];
}

int main(){
	ios::sync_with_stdio(false), cin.tie(0);

	m(memo,-1);

	cout << dp(50) << endl;
}