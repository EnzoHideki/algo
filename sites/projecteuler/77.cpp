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
const int MAXP = 5e3 + 10;
const int MAXN = 1e7 + 10;
bool sieve[MAXN];
vector<int> primes;
int memo[MAXP][MAXP];

void sie() {
	for (ll i=2; i<MAXN; i++) {
		if (sieve[i]) {
			primes.pb(i);
			for (ll j=i*i; j<MAXN; j+=i) {
				sieve[j] = false;
			}
		}
	}
}

int dp(int num, int prev) {
	assert(prev < MAXP && num < MAXP);
	if (num == 0) return memo[0][prev] = 1;

	if (memo[num][prev] == -1) {
		int ans = 0;
		int ind = upper_bound(primes.begin(), primes.end(), min(num, prev)) - primes.begin();

		for (int i=ind-1; i>=0; i--) {
			assert(i < MAXN);
			ans += dp(num - primes[i], primes[i]);
		}

		memo[num][prev] = ans;
	}

	return memo[num][prev];
}

int main(){
	ios::sync_with_stdio(false), cin.tie(0);

	m(sieve, true);
	m(memo, -1);

	sieve[0] = sieve[1] = false;
	sie();

	for (int i=0; i<MAXP-10; i++) {
		if (dp(i,MAXP-5) >= 5000) {
			dbn(i);
			return 0;
		}
	}
}