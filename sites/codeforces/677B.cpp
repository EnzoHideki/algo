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

int v[MAXN];

int main(){
	ios::sync_with_stdio(false);

	ll n, k, h; cin >> n >> h >> k;

	for (ll i=0; i<n; i++) cin >> v[i];

	ll j=1;

	ll contain = v[0];
	ll time = 0;

	while (contain || j <= n-1) {
		while (contain < h && j <= n-1) {
			if (v[j] + contain <= h) {
				contain += v[j];
				j++;
			} else break;
		}
		
		if (contain < k) {
			time++;
			contain = 0;
		} else {
			time += contain/k;
			contain = contain - (contain/k)*k;
		}
	}

	cout << time << endl;
}