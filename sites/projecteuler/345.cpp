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
const int MAXT = 15;
int mat[MAXT][MAXT];
int memo[1<<20];

int bitat(int x, int i) {
	x >>= i;
	return x%2;
}

int setbit(int x, int i) {
	int tmp = 1 << i;
	x |= tmp;
	return x | tmp;
}

int dp(int x) {
	int pos = __builtin_popcount(x);

	if (pos == MAXT) {
		return 0;
	}

	if (memo[x] == -1) {
		int ans = 0;
		for (int i=0; i<MAXT; i++) {
			if (bitat(x, i) == 0) {
				ans = max(ans, mat[pos][i] + dp(setbit(x, i)));
			}
		}
		memo[x] = ans;
	}

	return memo[x];
}

int main(){
	ios::sync_with_stdio(false), cin.tie(0);

	m(memo, -1);

	for (int i=0; i<MAXT; i++) {
		for (int j=0; j<MAXT; j++) {
			cin >> mat[i][j];
		}
	}

	cout << dp(0) << endl;
}