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
#include <unistd.h>
#include <utility>
#include <vector>
#define dbg(args...) //fprintf(stderr, args)
#define dbc(x) cerr << fixed << setprecision(12) << x << "\n"
#define dbn(x) cerr << fixed << setprecision(12) << #x << " == " << x << "\n"
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
typedef vector<int> vi;
typedef set<int> si;

const int INF = 0x3f3f3f3f;

//

vector<int> v;

int main(){
	ios::sync_with_stdio(false);

	freopen("haybales.in", "r", stdin);
	freopen("haybales.out", "w", stdout);

	int n, q; cin >> n >> q;

	for (int i=0; i<n; i++) {
		int x; cin >> x;

		v.pb(x);
	}

	sort(v.begin(), v.end());

	for (int i=0; i<q; i++) {
		int a, b; cin >> a >> b;

		vector<int>::iterator it1 = lower_bound(v.begin(), v.end(), a);
		vector<int>::iterator it2 = upper_bound(v.begin(), v.end(), b);

		if (it1 == v.end()) {
			cout << 0 << endl;
			continue;
		}

		cout << it2 - it1 << endl;
	}
}