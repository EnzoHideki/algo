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
#define dbc(x) cerr << fixed << setprecision(40) << x << "\n"
#define dbn(x) //cout << fixed << setprecision(40) << #x << " == " << x << "\n"
#define m(v,x) memset(v,x,sizeof(v))
#define pb push_back
#define eb emplace_back
#define F first
#define S second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int INF = 0x3f3f3f3f;

//

typedef complex<double> point;

const double PI = acos(-1.0);

int main() {
	ios::sync_with_stdio();

	int t; cin >> t;

	point b(50,50);

	for (int i=1; i<=t; i++) {
		int p, x, y; cin >> p >> x >> y;

		if (p == 0) {
			cout << "Case #" << i << ": white" << endl;
			continue;
		}

		double angle = (((double) p)/100.0) * 2.0 * PI;

		double angpoint = fmod((atan2(y-50,x-50) + 2*PI), (2*PI));

		if (angpoint <= PI/2.0) {
			angpoint = PI/2.0 - angpoint;
		} else {
			angpoint = PI/2.0 + 2*PI - angpoint;
		}

		if (angpoint <= angle && abs(b-point(x,y)) <= 50.0) {
			cout << "Case #" << i << ": black" << endl;
		} else {
			cout << "Case #" << i << ": white" << endl;
		}
	}
}