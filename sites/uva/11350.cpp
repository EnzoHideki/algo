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

pair<ll,ll> go(string s, pair<ll,ll> l, pair<ll,ll> r) {
	pair<ll,ll> now = {l.first + r.first, l.second + r.second};
	if (s.size() == 0) {
		return now;
	} else {
		if (s[0] == 'L') {
			return go(s.substr(1), l, now);
		} else {
			return go(s.substr(1), now, r);
		}
	}
}

int main(){
	ios::sync_with_stdio(false), cin.tie(0);

	int n; cin >> n;

	while (n--) {
		pair<ll,ll> l = {0,1};
		pair<ll,ll> r = {1,0};

		string s; cin >> s;

		pair<ll,ll> p = go(s,l,r);
		cout << p.first << "/" << p.second << endl;
	}
}