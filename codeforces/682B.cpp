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
#include <utility>
#include <unistd.h>
#include <vector>
#define dbg(args...) //fprintf(stderr, args)
#define dbc(x) cerr << x << "\n"
#define dbn(x) cerr << #x << " == " << x << "\n"
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
typedef set<int> si;

const int INF = 0x3f3f3f3f;

//

const int MAXN = 112345;

int v[MAXN];

int main(){
	ios::sync_with_stdio(false);

	int n; cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}


	if (n == 1) {
		cout << 2 << endl;
		return 0;
	}
	
	sort(v, v+n);

	if (v[0] > 1) v[0] = 1;
	for (int i=1; i < n; i++) {
		if (v[i] > v[i-1]) {
			v[i] = v[i-1]+1;
		}
	}

	cout << v[n-1] + 1 << endl;
}