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

int main(){
	ios::sync_with_stdio(false);

	ll n, k; cin >> n >> k;

	ll ans = k * ((n+k-1)/k);
	if (ans == n) cout << ans + k << endl;
	else cout << ans << endl; 
}