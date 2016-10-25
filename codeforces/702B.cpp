#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <ios>
#include <iomanip>
#include <queue>
#include <utility>
#include <set>
#include <map>
#include <vector>
#include <cstdlib>
#include <ctime>
#define dbg(args...) //fprintf(stderr, args)
#define dbc(x) //cerr << x << "\n"
#define dbn(x) cerr << #x << " == " << x << "\n"
#define endl '\n'
#define bits(x) __builtin_popcount(x)
#define m(x) memset((x),0,sizeof(x))
#define minf(x) memset((x),63,sizeof(x))
#define pb push_back
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

map<ll, ll> inst;

int main(){
	ios::sync_with_stdio(false);

	ll n; cin >> n;

	ll ans = 0;
	for (ll i=0; i<n; i++) {
		ll a; cin >> a;

		ll aux = 0;
		while((ll) (1LL << aux) <= (ll) 1e10 + 10) {
			//dbn((1LL << aux));
			if ((1LL << aux) > a) {
				ll s = (1LL << aux) - a;
				if (inst.find(s) != inst.end()) {
					ans += inst[s];
				}
			}

			aux++;
		}

		if (inst.find(a) != inst.end()) inst[a]++;
		else inst[a] = 1;
	}

	cout << ans << endl;
}