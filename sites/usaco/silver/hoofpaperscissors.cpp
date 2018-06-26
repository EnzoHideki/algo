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
#define dbc(x)// cerr << x << "\n"
#define dbn(x) cerr << #x << " == " << x << "\n"
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
const int MAXN = 112345;

int p[MAXN];
int h[MAXN];
int s[MAXN];

int main() {
	ios::sync_with_stdio(false);

	freopen("hps.in", "r", stdin);
	freopen("hps.out", "w", stdout);

	int n; cin >> n;

	for (int i=1; i<=n; i++) {
		char c; cin >> c;

		switch (c) {
			case 'S':
				s[i] = 1+s[i-1];
				p[i] = p[i-1];
				h[i] = h[i-1];
			break;
			case 'P':
				p[i] = 1+p[i-1];
				s[i] = s[i-1];
				h[i] = h[i-1];
			break;
			case 'H':
				h[i] = 1+h[i-1];
				p[i] = p[i-1];
				s[i] = s[i-1];
			break;
			default:
				assert(0);
			break;
		}
	}

	int ans = 0;
	for (int i=1; i<=n; i++) {
		int ff = max(h[i],max(s[i],p[i]));
		int ss = max(h[n]-h[i], max(s[n]-s[i], p[n]-p[i]));

		ans = max(ans, ff+ss);
	}

	cout << ans << endl;
}