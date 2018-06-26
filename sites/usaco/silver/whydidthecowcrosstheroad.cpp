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
#define dbc(x) cerr << x << "\n"
#define dbn(x) cerr << fixed << setprecision(30) <<  #x << " == " << x << "\n"
#define m(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,-1,sizeof(x))
#define minf(x) memset(x,63,sizeof(x))
#define pb push_back
#define eb emplace_back
#define F first
#define S second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int INF = 0x3f3f3f3f;

//

multiset<int> chickens;
multiset<pii> cows;

int main(){
	ios::sync_with_stdio(false);
	freopen("helpcross.in", "r", stdin);
	freopen("helpcross.out", "w", stdout);

	int c,n; cin >> c >> n;

	for (int i=0; i<c; i++) {
		int x; cin >> x;
		chickens.insert(x);
	}

	for (int i=0; i<n; i++) {
		int x,y; cin >> x >> y;
		cows.insert({y,x});
	}

	int ans = 0;
	for (auto i : cows) {
		multiset<int>::iterator it = chickens.lower_bound(i.S);

		if (it != chickens.end() && *it <= i.F) {
			ans++;
			chickens.erase(it);
		}
	}

	cout << ans << endl;
}