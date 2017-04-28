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
#include <windows.h>
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
const int MAXN = 1123456;

int memo[MAXN];
bool seen[MAXN];

vector<set<ll> > vs;

int f(int n) {
	if (memo[n] == -1) {
		int s = 1;
		for (ll i=2; i*i<=n; ++i) {
			if (n % i == 0) {
				if (i == n / i) {
					s += i;
				} else {
					s += i + (n/i);
				}
			}
		}

		memo[n] = s;
	}

	return memo[n];
}

int main(){
	ios::sync_with_stdio(false), cin.tie(0);

	m(memo, -1);

	for (int i=1; i<1000000; ++i) {
		if (i % 10000 == 0) dbn(i);
		set<ll> ss;

		bool ok = false;
		int x = i;
		while (true) {
			if (ss.count(x)) {
				break;
			} else {
				ss.insert(x);
				x = f(x);

				if (x == i) {
					ok = true;
					break;
				}

				if (x >= 1000000) {
					break;
				}
			}
		}

		if (ok) vs.pb(ss);
	}

	int mx = -1;
	int aa = 0;
	for (int i=0; i<int(vs.size()); ++i) {
		if (int(vs[i].size()) > mx) {
			mx = vs[i].size();
			aa = i;
		}
	}

	cout << *vs[aa].begin() << endl;
}