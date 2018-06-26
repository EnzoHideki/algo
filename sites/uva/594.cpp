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

int main(){
	ios::sync_with_stdio(false), cin.tie(0);

	int n;

	while (cin >> n) {
		bitset<32> b(n);

		for (int j=0; j<2; j++) {
			for (int i=0; i<8; i++) {
				bool tmp = b[8*j + i];
				b[8*j + i] = b[8*(3-j) + i];
				b[8*(3-j) + i] = tmp;
			}
		}

		cout << n << " converts to " << int(b.to_ulong()) << endl;
	}
}