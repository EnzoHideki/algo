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
#include <unistd.h>
#include <utility>
#include <vector>
#define dbg(args...) //fprintf(stderr, args)
#define dbc(x) cerr << x << '\n'
#define dbn(x) cerr << #x << " == " << x << '\n'
#define m(v,x) memset(v,x,sizeof(v))
#define pb push_back
#define endl '\n'
#define F first
#define S second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int INF = 0x3f3f3f3f;

//

const int MAXN = 1123456;

int memo[MAXN];
int fat[MAXN];
int ans = 0;

int f(int x) {
	if (x == 0) {
		return fat[0] = 1;
	}

	if (fat[x] == -1) {
		fat[x] = x*f(x-1);
	}

	return fat[x];
}

int rec(int x, int times) {
	if (times > 61) {
		return memo[x] = INF;
	}

	if (memo[x] == -1) {
		memo[x] = 0;
		string s = to_string(x);
		int sum = 0;
		for (auto i : s) {
			sum += f(i-'0');
		}

		memo[x] = 1 + rec(sum, times+1);
	}

	if (memo[x] == 60) {
		ans++;
	}
	
	return memo[x];
}


int main(){
	ios::sync_with_stdio(false), cin.tie(0);

	m(fat,-1);
	m(memo,-1);

	for (int i=1; i<=1000000; i++) {
		rec(i,1);
	}

	cout << ans << endl;
}