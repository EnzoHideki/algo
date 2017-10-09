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

ll powmod(ll a,ll b,ll mod) {
	ll res=1;
	a%=mod; 
	assert(b>=0); 
	for(;b;b>>=1){
		if(b&1)res=res*a%mod;
		a=a*a%mod;
	}
	return res;
}
//
const int MAXN = 100000010;
bool sieve[MAXN];
vector<int> primes;

void sie() {
	for (ll i=2; i < MAXN; i++) {
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

	dbn(primes.size());

	ll ans = 0;
	for (ll p : primes) {
		if (p >= 5 && p < 100000000) {
			ll cur = p-1;
			ll now = p-1;

			for (int i=1; i<=4; i++) {
				cur = (cur * powmod(p-i,p-2,p)) % p;
				now = (now + cur) % p;
			}

			ans += now;
		}
	}

	dbn(ans);
}