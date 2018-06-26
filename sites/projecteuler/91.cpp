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
const double EPS = 1e-9;
const double PI = acos(-1.0);

typedef complex<double> point;
#define X real
#define Y imag

double angle(point a, point b, point c) {
	return abs(remainder(arg(a-b) - arg(c-b), 2*PI));
}

int conv(int x, int y) {
	return 51*y+x;
}

point unconv(int xx) {
	return {double(xx%51), double(xx/51)};
}

int main(){
	ios::sync_with_stdio(false), cin.tie(0);

	point a(0,0);

	int ans = 0;

	for (int i=1; i<=51*51 - 1; i++) {
		for (int j=i+1; j<=51*51 - 1; j++) {
			point b = unconv(i);
			point c = unconv(j);

			if (abs(angle(a,b,c) - 0.5*PI) < EPS ||
				abs(angle(b,a,c) - 0.5*PI) < EPS ||
				abs(angle(a,c,b) - 0.5*PI) < EPS) {
				ans++;
			}
		}
	}

	cout << ans << endl;
}