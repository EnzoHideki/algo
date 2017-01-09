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
#define dbc(x) cerr << x << "\n"
#define dbn(x) cerr << #x << " == " << x << "\n"
#define m(v,x) memset(v,x,sizeof(v))
#define pb push_back
#define eb emplace_back
#define F first
#define S second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int INF = 0x3f3f3f3f;

//

bool cmp (int a, int b) {return a > b;}

class SwapAndArithmetic {
	public:
	string able (vector<int> x) {
		sort(x.begin(), x.end());

		int d = x[1] - x[0];

		int ok = 1;

		for (int i=1; i<x.size(); i++) {
			if (x[i] != x[i-1] + d) {
				ok = 0;
			}
		}

		if (ok) return "Possible";

		sort(x.begin(), x.end(), cmp);

		d = x[1] - x[0];

		for (int i=1; i<x.size(); i++) {
			if (x[i] != x[i-1] + d) {
				return "Impossible";
			}
		}

		return "Possible";
	}
};
