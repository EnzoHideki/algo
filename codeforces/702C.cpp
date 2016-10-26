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
typedef set<int> si;

const int INF = 0x3f3f3f3f;

//

const int MAXN = 112345;

int ci[MAXN], to[MAXN];

int main(){
	ios::sync_with_stdio(false);

	int n, m; cin >> n >> m;

	for (int i=0; i<n; i++) {
		cin >> ci[i];
	}

	for (int i=0; i<m; i++) {
		cin >> to[i];
	}

	int ans = 0;
	for (int i=0; i<n; i++) {
		int ant;

		if (upper_bound(to, to+m, ci[i]) != lower_bound(to, to+m, ci[i]))
			ant = 0;
		else if (ci[i] < to[0])
			ant = to[0] - ci[i]; 
		else if (ci[i] > to[m-1]) 
			ant = ci[i] - to[m-1];
		else 
			ant = min(*upper_bound(to, to+m, ci[i]) - ci[i], ci[i] - *(lower_bound(to, to+m, ci[i]) - 1));

		ans = max(ans, ant);
	}

	cout << ans << endl;
}