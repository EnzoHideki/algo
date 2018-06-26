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

int main(){
	ios::sync_with_stdio(false);

	freopen("cowsignal.in", "r", stdin);
	freopen("cowsignal.out", "w", stdout);

	int m, n, k; cin >> m >> n >> k;

	for (int i=0; i<m; i++) {
		string s; cin >> s;

		string res = "";

		for (int i=0; i<s.size(); i++) for (int j=0; j<k; j++) res += s[i];

		for (int j=0; j<k; j++) cout << res << endl;
	}
}