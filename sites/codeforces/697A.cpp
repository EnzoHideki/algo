#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <set>
#include <utility>
#include <vector>
#include <map>
#include <cstring>
#include <queue>
#include <ios>
#include <iomanip>
#define dbg(args...) //fprintf(stderr, args)
#define dbc(x) cerr << x << "\n"
#define dbn(x) cerr << #x << " == " << x << "\n"
#define m(x) memset(x,0,sizeof(x))
#define minf(x) memset(x,63,sizeof(x))
#define bits(x) __builtin_popcount(x)
#define pb push_back
#define eb emplace_back
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
const int MAXN = 112345;

int main(){
	//ios::sync_with_stdio(false);

	int t,s,x; cin >> t >> s >> x;

	if(x >= t && ((x-t)%s == 0 || ((x-t-1)%s == 0 && x != (t+1)))) cout << "YES" << endl;
	else cout << "NO" << endl;
}
