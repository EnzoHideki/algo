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
#define dbn(x) cerr << fixed << setprecision(20) << #x << " == " << x << "\n"
#define m(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,1,sizeof(x))
#define minf(x) memset(x,63,sizeof(x))
#define pb push_back
#define F first
#define S second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int INF = 0x3f3f3f3f;

//

const double EPS = 1e-12;

int main(){
	ios::sync_with_stdio(false);
	ll ans = 0;
	ll i = 2;

	while (3*i - 1 <= 1e9) {
		if (i % 2000000 == 0) dbc(i);
		for (ll j=-1; j<=1; j+=2) {
			ll x = i+j;

			if (x%2 == 1 || x < 1 || 3*i + j > 1e9) continue;

			long double raiz = sqrt((long double) 4.0*i*i - x*x);
			long double dec = raiz - floor(raiz);

			long double first = x*dec/4.0;
			long double second = x*floor(raiz)/4.0;

			first = first - floor(first);
			second = second - floor(second);

			double diff = first + second;
			if ((diff > -EPS && diff < EPS) || 
				(diff > -EPS + 1.0 && diff < EPS + 1.0) || 
				(diff > -EPS + 2.0 && diff < EPS + 2.0)) {
				ans += 3*i + j;
			}
		}

		i++;
	}

	cout << ans << endl;
}
