#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <ios>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <utility>
#include <unistd.h>
#include <vector>
#define dbg(args...) //fprintf(stderr, args)
#define dbc(x) cerr << x << "\n"
#define dbn(x) //cerr << #x << " == " << x << "\n"
#define m(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,1,sizeof(x))
#define minf(x) memset(x,63,sizeof(x))
#define pb push_back
#define eb emplace_back
#define F first
#define S second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef set<int> si;

const int INF = 0x3f3f3f3f;

//

ll po(ll x, ll e) {
	ll prod = 1;
	for (int i=0; i<e; i++) prod *= x;
	return prod;
}

bool check(ll n) {
	for (int i=0; i<10; i++) {
		if ((n/(ll) po(10,2*i)) % (ll) 10 != (ll) (10-i) % (ll) 10) {
			return false;
		}
	}

	return true;
}

int main(){
	ios::sync_with_stdio(false);
	ll i = 1e9;
	while (!check(i*i)) i++;
	cout << i << endl;
}