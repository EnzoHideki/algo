#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <functional>
#include <iomanip>
#include <ios>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <unistd.h>
#include <utility>
#include <vector>
#define dbc(x) cerr << x << '\n'
#define dbn(x) cerr << #x << " == " << x << '\n'
#define m(v,x) memset(v,x,sizeof(v))
#define pb push_back
#define endl '\n'

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

//
const int MAX = 100;

int memo[110][110];

ll ans;

int cc = 0;

vector<int> v;

void rec() {
	if (v.size() == 4) {
		int cur = 0;
		for (int i=0; i<4; i++) {
			cur += memo[v[i]][v[(i+1)%4]];
			cur += v[i];
		}

		cur -= 3;

		if (int(sqrt(cur)) * int(sqrt(cur)) == cur) {
			ans++;
		}

		return;
	}


	for (int j=1; j<=MAX; j++) {
		v.pb(j);
		rec();
		v.pop_back();
	}
}

int main(){
	ios::sync_with_stdio(false), cin.tie(0);

	for (int i=1; i<=MAX; i++) {
		for (int j=i; j<=MAX; j++) {
			int b = i + j + __gcd(i,j);
			memo[i][j] = memo[j][i] = (i*j-b)/2 + 1;
		}
	}

	for (int i=1; i<=MAX; i++) {
		v.pb(i);
		rec();
		v.pop_back();
	}
	cout << ans << endl;	
}