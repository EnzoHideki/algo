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
#include <sstream>
#include <unistd.h>
#include <utility>
#include <vector>
#define dbc(x) cerr << x << '\n'
#define dbn(x) cerr << #x << " == " << x << '\n'
#define m(v,x) memset(v,x,sizeof(v))
#define pb push_back
#define endl '\n'

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

//
map<ll, pair<ll,ll>> mp;

ll po[12];

void f(ll x) {
	string ss = to_string(x);
	ll sum = 0;
	for (char c : ss) {
		sum += po[c-'0'];
	}

	if (mp.find(sum) == mp.end()) {
		mp[sum] = {1,x};
	} else {
		mp[sum].first++;
		mp[sum].second = min(mp[sum].second, x); 
	}
}

int main(){
	ios::sync_with_stdio(false), cin.tie(0);

	po[0] = 1;
	for (int i=1; i<=9; i++) {
		po[i] = 70*po[i-1];
	}

	for (ll x=1; x<=2000000; x++) {
		f(x*x*x);
	}

	ll ans = 0x3f3f3f3f3f3f3f3f;
	for (auto i : mp) {
		if (i.second.first == 5) {
			ans = min(ans, i.second.second);
		}
	}

	dbn(ans);
}