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

int check(ll n) {
	double delta = (n-2)*(n-2) + 1000000;

   	double x2 = (2 - n + sqrt(delta))/2.0;

	return max(0ll, ll(floor(x2)));
}

int main(){
	ios::sync_with_stdio(false), cin.tie(0);

	int ans = 0;

	for (ll holes=1; holes<=250000; holes++) {
		ll n = holes+2;
		ans += check(n);
	}

	cout << ans << endl;
}