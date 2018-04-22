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

int a[123];
int ac[123];

int main(){
	ios::sync_with_stdio(false), cin.tie(0);

	int t; cin >> t;

	while (t--) {
		int n, x; cin >> n >> x;
		
		for (int i=1; i<=n; i++) {
			cin >> a[i];
		}

		for (int i=1; i<=n; i++) {
			ac[i] = ac[i-1] + a[i];
		}

		for (int i=1; i<=n; i++) {
			for (int j=1; j<=n-i+1; j++) {
				if (ac[j+i-1] - ac[j-1] >= x) {
					cout << i << endl;
					return 0;
				}
			}
		}
		cout << -1 << endl;
	}
}