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
const int MAXN = 5e7;
vector<int> primes;
bool sieve[MAXN];

bool check[MAXN];

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

int main(){
	ios::sync_with_stdio(false), cin.tie(0);

	m(sieve, true);
	sieve[0] = sieve[1] = false;

	sie();

	for (ll j : primes) {
		if (j*j > MAXN) break;

		for (ll k : primes) {
			if (k*k*k > MAXN) break;

			for (ll l : primes) {
				if (l*l*l*l > MAXN) break;

				if (j*j + k*k*k + l*l*l*l < MAXN) {
					check[j*j + k*k*k + l*l*l*l] = true;
				}
			}
		}
	}

	ll ans = 0;
	for (int i=0; i<MAXN; i++) {
		if (check[i]) {
			ans++;
		}
	}

	cout << ans << endl;
}