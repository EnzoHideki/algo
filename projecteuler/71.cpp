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
#define dbc(x) //cerr << x << '\n'
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

int a = 0;
int b = 0;

double dist = INF;

void test(int x) {
	int y = 3*x/7;

	while (__gcd(y,x) != 1) {
		y--;
	}

	if ((3.0/7.0) - double(y)/double(x) < dist) {
		dist = (3.0/7.0) - double(y)/double(x);
		a = y;
		b = x;
	}
}

int main(){
	ios::sync_with_stdio(false), cin.tie(0);

	for (int i=3; i<=1e6; i++) {
		if (i == 7) continue;
		test(i);
	}

	cout << a << endl;
}