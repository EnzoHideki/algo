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
const int MAXN = 312345;

int squares[MAXN];
int typ[1123456];

void init() {
    for (int i=1; i<MAXN; i++) {
        squares[i] = 4 * (i-1);
    }
}

int main(){
	ios::sync_with_stdio(false), cin.tie(0);

    init();

    for (int i=3; i<250000; i++) {
        int sq = squares[i];

        int j = i;
        while (sq <= 1000000) {
            typ[sq]++;
            sq+=squares[j+2];
            j+=2;
        }
    }

    int ans = 0;
    for (int i=0; i<=1000000; i++) {
        if (typ[i] >= 1 && typ[i] <= 10) {
            ans++;
        }
    }

    cout << ans << endl;
}