#include <algorithm>
#include <bitset>
#include <cassert>
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

const int MAXN = 1e5 + 10;
const int MOD = 1e9 + 7;

int v[MAXN];

int toN(char c){
	if (c >= '0' && c <= '9') return c-'0';
	else if (c >= 'A' && c <= 'Z') return c-'A'+10;
	else if (c >= 'a' && c <= 'z') return c-'a'+36;
	else if (c == '-') return 62;
	else if (c == '_') return 63;

	assert(0);
}

int main(){
	ios::sync_with_stdio(false);

	string s; cin >> s;

	int len = s.size();

	int zeros = 0;
	for (int i=0; i<len; i++) {
		zeros += (6 - __builtin_popcount(toN(s[i])));
	}

	ll ans = 1;
	for (int i=0; i<zeros; i++) {
		ans = (ans * 3) % MOD; 
	}

	cout << ans << endl;
}