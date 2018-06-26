#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <set>
#include <utility>
#include <vector>
#include <map>
#include <cstring>
#include <queue>
#include <ios>
#include <iomanip>
#define dbg(args...) //fprintf(stderr, args)
#define dbc(x) cerr << x << "\n"
#define dbn(x) cerr << #x << " == " << x << "\n"
#define m(x) memset(x,0,sizeof(x))
#define minf(x) memset(x,63,sizeof(x))
#define bits(x) __builtin_popcount(x)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef set<int> si;
typedef set<pii> sii;

const int INF = 0x3f3f3f3f;

//

const ll MAXN = 1e12 + 10;
const ll MM = 1123456;

set<ll> fa;
int crivo[MM];
vi primes;

map<ll, int> fat;

bool isPrime(ll n){
	for(auto i: primes){
		if(i > sqrt(n)){
			break;
		}

		if(n%i == 0) return false;
	}

	return true;
}

int main(){
	ios::sync_with_stdio(false);

	crivo[0] = crivo[1] = 1;

	for(int i=2; i<MM; i++){
		for(int j=2*i; j < MM; j+=i){
				crivo[j] = 1;
		}
	}

	for(int i=2; i<MM; i++){
		if(crivo[i] == 0) primes.pb(i);
	}

	//

	ll n; cin >> n;

	ll naux = n;

	sort(primes.begin(), primes.end());

	for(auto i:primes){
		if(i > sqrt(naux)) break;

		while(n%i==0){
			if(fat.find(i) == fat.end()){
				fat[i] = 1;
			} else fat[i]++;


			if(isPrime(n/i)){
				if(fat.find(n/i) == fat.end()){
					fat[n/i] = 1;
				} else fat[n/i]++;
			}

			n/=i;
		}
	}


	for(auto i : fat){
		if(i.S >= 2) i.S--;
	}

	ll ans = 1;
	for(auto i : fat){
		ans*=i.F;
	}

	if(ans == 1){
		cout << n << endl;
	} else {
		cout << ans << endl;
	}
}