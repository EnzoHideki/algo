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
const int MAXR = 100;
const int MAXP = 100;

ll memo[10][MAXR][MAXP];

ll dp(int sz, int remain, int toput) {
    if (toput*sz > remain || toput <= 0) {
        return 0;
    }

    if (memo[sz][remain][toput] != -1) {
        return memo[sz][remain][toput];
    } else if (toput == 1) {
        return remain - (sz - 1);
    }

    int mx = remain - 2 - sz*(toput-1);

    ll ret = 0;
    for (int i=0; i<=mx; i++) {
        ret += dp(sz, remain-(i+sz), toput-1);
    }

    return memo[sz][remain][toput] = ret;
}

int main(){
	ios::sync_with_stdio(false), cin.tie(0);

    m(memo, -1);

    ll ans = 0;

    for (int j=2; j<=4; j++) {
        for (int i=1; i<=50/j; i++) {
            ans += dp(j, 50, i);
        }
    }

    cout << ans << endl;
}