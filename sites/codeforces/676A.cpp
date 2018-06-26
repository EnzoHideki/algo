#include <algorithm>
#include <bitset>
#include <cmath>
#include <climits>
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
#include <vector>
#define dbg(args...) fprintf(stderr, args)
#define dbc(x) cerr << x << "\n"
#define dbn(x) cerr << #x << " == " << x << "\n"
#define endl '\n'
#define m(x) memset((x),0,sizeof(x))
#define m1(x) memset((x),1,sizeof(x))
#define minf(x) memset((x),63,sizeof(x))
#define eb emplace_back
#define pb push_back
#define F first
#define S second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef set<int> si;

const int INF = 0x3f3f3f3f;

//

const int MAXN = 112;

int v[MAXN];

int main(){
	ios::sync_with_stdio(false);

	 int n;
	 cin >> n;

	 int inda, indb;
	 for (int i=0; i<n; i++) {
	 	int a;
	 	cin >> a;

	 	if (a == 1) {
	 		inda = i;
	 	}

	 	if (a == n) {
	 		indb = i;
	 	}
	 }

	 cout << max(inda, max(indb, max(n-inda-1, n-indb-1))) << endl;
}