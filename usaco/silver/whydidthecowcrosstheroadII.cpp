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
#define dbc(x) //cerr << x << '\n'
#define dbn(x) //cerr << #x << " == " << x << '\n'
#define m(v,x) memset(v,x,sizeof(v))
#define pb push_back
#define endl '\n'
#define F first
#define S second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

//

const int MAXN = 112345;

int v[MAXN];
int ac[MAXN];

int main(){
	ios::sync_with_stdio(false), cin.tie(0);

	freopen("maxcross.in", "r", stdin);
	freopen("maxcross.out", "w", stdout);

	int n, k, b; cin >> n >> k >> b;

	for (int i=0; i<b; i++) {
		int x; cin >> x;
		v[x] = 1;
	}
	
	for (int i=1; i<=n; i++) {
		ac[i] = v[i] + ac[i-1];
	}

	int i = 1;
	int j = i + k - 1;

	int ans = 0x3f3f3f3f;

	while (j <= n) {
		ans = min(ans, ac[j] - ac[i-1]);

		i++;
		j++;
	}

	cout << ans << endl;
}