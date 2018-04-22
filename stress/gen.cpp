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
#include <sys/time.h>
#define dbc(x) cerr << x << '\n'
#define dbn(x) cerr << #x << " == " << x << '\n'
#define m(v,x) memset(v,x,sizeof(v))
#define pb push_back
#define endl '\n'

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

//
// returns random integer in the interval [i,j]
ll random(ll i, ll j) {
	return rand() % (j-i+1) + i;
}

// returns random integer in the set of intervals {[i,j], [k,l], ...}
ll random(vector<pii> v) {
	vector<int> vv;
	for (pii p : v) {
		for (int i=p.first; i<=p.second; i++) {
			vv.push_back(i);
		}
	}

	sort(vv.begin(), vv.end());
	vv.resize(distance(vv.begin(), unique(vv.begin(), vv.end())));

	return vv[random(0,vv.size()-1)];
}

// prints line of n random integers in the interval [i,j] 
void line(ll n, ll i, ll j) {
	for (ll i=0; i<n; i++) cout << random(i,j) << " \n"[i==n-1];
}

/* returns random string of size sz
	mode 0: just upper-case characters
	mode 1: just lower-case characters
	mode 2: mixed
*/
string randomString(ll sz, ll mode, bool numberAllowed) {
	string ret = "";

	for (ll i=0; i<sz; i++) {
		if (numberAllowed) {
			if (mode == 0) {
				ret += char(random(vector<pii> {{48,57}, {65,90}}));
			} else if (mode == 1) {
				ret += char(random(vector<pii> {{48,57}, {97,122}}));
			} else {
				ret += char(random(vector<pii> {{48,57}, {97,122}, {65,90}}));
			}
		} else {
			if (mode == 0) {
				ret += char(random(65,90));
			} else if (mode == 1) {
				ret += char(random(97,122));
			} else {
				ret += char(random(vector<pii> {{97,122}, {65,90}}));
			}
		}	
	}

	return ret;
}

int main(){
	ios::sync_with_stdio(false), cin.tie(0);
	
	struct timeval time;
    gettimeofday(&time,NULL);
    srand((time.tv_sec * 1000) + (time.tv_usec / 1000));
	
	cout << randomString(10,2,1) << endl;

	cout << 1 << endl;
	ll n = random(1, 10);
	ll x = random(-10, 10);

	cout << n << " " << x << endl;

	for (int i=0; i<n; i++) {
		cout << random(-8,8) << " \n"[i==n-1];
	}
}