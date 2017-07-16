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

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

//
const int MAXN = 112345;

int n, k;
int bit[MAXN];
int bit1[MAXN];
int v[MAXN];

void update(int p, int value) {
	for (; p <= n; p += (p & -p)) bit[p] += value;
}
int sum(int p) {
	if (p == 0) return 0;
	return bit[p] + sum(p - (p & -p));
}

void update1(int p, int value) {
	for (; p <= n; p += (p & -p)) bit1[p] += value;
}
int sum1(int p) {
	if (p == 0) return 0;
	return bit1[p] + sum1(p - (p & -p));
}

int main(){
	ios::sync_with_stdio(false), cin.tie(0);

	while (cin >> n >> k) {
		m(bit, 0);
		m(bit1, 0);
		m(v, 0);

		for (int i=1; i<=n; i++) {
			cin >> v[i];

			if (v[i] < 0) {
				update1(i, 1);
			} else if (v[i] == 0) {
				update(i, 1);
			}
		}

		for (int i=0; i<k; i++) {
			char op; cin >> op;
			int a,b; cin >> a >> b;

			if (op == 'C') {
				if (v[a] > 0 && b == 0) {
					update(a, 1);
				} else if (v[a] > 0 && b < 0) {
					update1(a, 1);
				} else if (v[a] == 0 && b > 0) {
					update(a, -1);
				} else if (v[a] == 0 && b < 0) {
					update(a, -1);
					update1(a, 1);
				} else if (v[a] < 0 && b > 0) {
					update1(a, -1);
				} else if (v[a] < 0 && b == 0) {
					update(a, 1);
					update1(a, -1);
				}

				v[a] = b;
			} else {
				if (sum(b) - sum(a-1) > 0) {
					cout << '0';
				} else if ((sum1(b) - sum1(a-1)) % 2) {
					cout << '-';
				} else {
					cout << '+';
				}
			}
		}
		cout << endl;
	}
}