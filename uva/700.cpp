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

const int INF = 0x3f3f3f3f;

//

int a[20][3];

int main(){
	ios::sync_with_stdio(false), cin.tie(0);

	int n;

	int count = 0;
	while (cin >> n && n) {
		count++;
		cout << "Case #" << count << ":" << endl;

		m(a,-1);

		for (int i=0; i<n; i++) {
			cin >> a[i][0] >> a[i][1] >> a[i][2];
		}

		int test = a[0][0];
		
		while (true) {
			int ok = 1;

			for (int i=1; i<n; i++) {
				if (test < a[i][1]) {
					ok=0;
					break;
				}

				if (((test - a[i][1]) % (a[i][2]-a[i][1])) + a[i][1] != a[i][0]) {
					ok=0;
					break;
				}
			}

			if (ok) {
				cout << "The actual year is " << test << "." << endl << endl;
				break;
			}

			test += a[0][2] - a[0][1];

			if (test >= 10000) {
				cout << "Unknown bugs detected." << endl << endl;
				break;
			}
		}
	}
} 


/*
Another solution

int ac[10010];

int main(){
	ios::sync_with_stdio(false), cin.tie(0);

	int n;

	int count = 0;
	while (cin >> n && n) {
		count++;
		cout << "Case #" << count << ":" << endl;

		m(ac,0);

		for (int i=0; i<n; i++) {
			int a,b,c;
			cin >> a >> b >> c;

			int year = a;
			while (year < 10000) {
				ac[year]++;
				year += c-b;
			}
		}

		bool ok = false;
		for (int i=0; i<10000; i++) {
			if (ac[i] == n) {
				cout << "The actual year is " << i << "." << endl << endl;
				ok = true;
				break;
			}
		}

		if (!ok) {
			cout << "Unknown bugs detected." << endl << endl;
		}
	}
}
*/