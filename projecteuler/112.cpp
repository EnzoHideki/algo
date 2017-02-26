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
#include <unistd.h>
#include <utility>
#include <vector>
#define dbg(args...) //fprintf(stderr, args)
#define dbc(x) cerr << x << '\n'
#define dbn(x) cerr << setprecision(15) << fixed << #x << " == " << x << '\n'
#define m(v,x) memset(v,x,sizeof(v))
#define pb push_back
#define endl '\n'
#define F first
#define S second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

//

const double EPS = 1e-9;

ll po(ll x, ll e) { return e == 0 ? 1 : x*po(x, e-1); }

int digitAt(ll n, int pos) {
	return (n/po(10,pos)) % 10;
}

bool isIncreasing(int n) {
	int sz = floor(log10(n)+1);

	for (int i=1; i<sz; i++) {
		if (digitAt(n,i) > digitAt(n,i-1)) {
			return false;
		}
	}

	return true;
}

bool isDrecreasing(int n) {
	int sz = floor(log10(n)+1);
	
	for (int i=1; i<sz; i++) {
		if (digitAt(n,i) < digitAt(n,i-1)) {
			return false;
		}
	}

	return true;
}

int main(){
	ios::sync_with_stdio(false), cin.tie(0);

	int nn = 100;
	int bouncy = 0;

	while (true) {
		if (!isDrecreasing(nn) && !isIncreasing(nn)) {
			bouncy++;
		}

		double ratio = double(bouncy)/double(nn);

		if (ratio >= 0.99 - EPS) {
			cout << nn << endl;
			return 0;
		}

		nn++;
	}
}