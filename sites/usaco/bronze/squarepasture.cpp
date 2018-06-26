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

	freopen("square.in", "r", stdin);
	freopen("square.out", "w", stdout);

	int x1, y1, x2, y2, xx1, yy1, xx2, yy2;

	cin >> x1 >> y1 >> x2 >> y2 >> xx1 >> yy1 >> xx2 >> yy2;


	int x = min(x1, xx1);
	int xx = max(x2, xx2);

	int y = min(y1, yy1);
	int yy = max(y2, yy2);

	int l = max(xx - x, yy - y);

	cout << l * l << endl;
}