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

int cups[12][12];
int one;

void enche(int a, int h, int t) {
	if (t == 0) return;

	if (t >= one - cups[h][a]) {
		t -= (one - cups[h][a]);
		cups[h][a] = one;
	} else {
		cups[h][a] += t;
		t = 0;
		return;
	}

	if (h + 1 > 10) return;

	enche(a, h+1, t/2);
	enche(a+1, h+1, t/2);
}

int main(){
	ios::sync_with_stdio(false);

	int n, t; cin >> n >> t;

	one = 1<<n;

	enche(0,0,t*one);

	int ans = 0;
	for (int i=0; i<n; i++) for (int j=0; j<12; ans += cups[i][j]/one, j++);

	cout << ans << endl;
}