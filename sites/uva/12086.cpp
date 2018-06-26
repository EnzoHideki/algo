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
#define dbg(args...) fprintf(stderr, args)
#define dbc(x) cerr << x << '\n'
#define dbn(x) cerr << setprecision(20) << #x << " == " << x << '\n'
#define m(v,x) memset(v,x,sizeof(v))
#define pb push_back
#define endl '\n'
#define F first
#define S second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int INF = 0x3f3f3f3f;

//

const int MAXN = 212345;

int ft[MAXN];

int n;

void update(int i, int val){
	//n is the biggest possible value for p
	for (; i <= n; i += i & -i) ft[i] += val;
}

// sum of values of indexes from 1 to p
int sum(int i){
	int ans = 0;
	for (; i; i -= i & -i) ans += ft[i];
	return ans;
}

int main(){
	ios::sync_with_stdio(false), cin.tie(0);

	int caso = 0;

	while (cin >> n && n != 0) {
		m(ft,0);

		for (int i=1; i<=n; i++) {
			int x; cin >> x;

			update(i, x);
		}

		if (++caso != 1) {
			cout << endl;
		}

		cout << "Case " << caso << ":" << endl;

		string s;
		while (cin >> s && s != "END") {
			int a,b;
			cin >> a >> b;

			if (s == "M") {
				cout << sum(b) - sum(a-1) << endl;	
			} else {
				update(a, b-(sum(a)-sum(a-1)));
			}
		}
	}
}