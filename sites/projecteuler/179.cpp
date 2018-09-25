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
#define pb push_back
#define endl '\n'
#define int ll

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

//
const int MAXN = 1e7 + 10;

int sieve[MAXN];
int divi[MAXN];

void sie() {
	for (int i=0; i<MAXN; i++) sieve[i] = 1;

	for (ll i=2; i<MAXN; i++) {
		if (sieve[i] == 1) {
			sieve[i] = i;
			for (ll j=i*i; j<MAXN; j += i) {
				sieve[j] = i;
			}
		}
	}
}

main(){
	ios::sync_with_stdio(false), cin.tie(0);

	sie();

	for (int i=2; i<=10000000; i++) {
		map<int, int> mp;

		int x = i;

		while (x != 1) {
			mp[sieve[x]]++;
			x /= sieve[x];
		}

		ll qt = 1;

		for (auto i : mp) {
			qt *= (i.second + 1);
		}

		divi[i] = qt;
	}

	int ans = 0;
	for (int n=2; n<10000000; n++) {
		if (divi[n] == divi[n+1]) {
			ans++;
		}
	}

	cout << ans << endl;
} 