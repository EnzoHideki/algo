#include <algorithm>
#include <bitset>
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
#include <utility>
#include <unistd.h>
#include <vector>
#define dbg(args...) //fprintf(stderr, args)
#define dbc(x) //cerr << x << "\n"
#define dbn(x) //cerr << #x << " == " << x << "\n"
#define m(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,1,sizeof(x))
#define minf(x) memset(x,63,sizeof(x))
#define pb push_back
#define eb emplace_back
#define F first
#define S second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef set<int> si;
typedef set<pii> sii;

const int INF = 0x3f3f3f3f;

//

int main(){
	ios::sync_with_stdio(false);
	int n; cin >> n;
	int a = 0;
	while (1234567*a <= n) {
		dbn(a);
		if (1234567*a == n) {
			cout << "YES" << endl;
			return 0;
		}

		int b = 0;
		while (1234567*a + 123456*b <= n) {
			dbn(b);
			if (1234567*a + 123456*b == n) {
				cout << "YES" << endl;
				return 0;
			}

			if ((n - 1234567*a - 123456*b) % 1234 == 0) {
				cout << "YES" << endl;
				return 0;
			}
			
			b++;
		}
		a++;
	}

	cout << "NO" << endl;

	return 0;
}