#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <ios>
#include <iomanip>
#include <queue>
#include <utility>
#include <set>
#include <map>
#include <vector>
#include <cstdlib>
#include <ctime>
#define dbg(args...) fprintf(stderr, args)
#define dbc(x) cerr << x << "\n"
#define dbn(x) cerr << #x << " == " << x << "\n"
#define endl '\n'
#define bits(x) __builtin_popcount(x)
#define m(x) memset((x),0,sizeof(x))
#define minf(x) memset((x),63,sizeof(x))
#define pb push_back
#define mp make_pair
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

const int MAXN = 1e5 + 10;

int v[MAXN];

int main(){
	ios::sync_with_stdio(false);

	int n; cin >> n;

	int k = 0;

	int ans = 0;
	int aa = 0;

	for (int i=0; i<n; i++) {
		int a; cin >> a;

		if (a > k) ans++;
		else aa = max(aa, ans), ans = 1;

		k = a;
	}
	aa = max(aa, ans);

	cout << aa << endl;
}