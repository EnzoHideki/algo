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
#define dbn(x) //cerr << #x << " == " << x << '\n'
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

const int ballsUrn = 70;
const int mustTake = 20;
const int colors = 7;

double e[colors + 10];

void expected(int colorsUsed, int ballsTaken, double prob) {
	if (ballsTaken == mustTake) {
		e[colorsUsed] += prob;
		return;
	}

	int remaining = ballsUrn-ballsTaken;
	
	double probCur = 1.0;

	if (ballsTaken < colorsUsed*(ballsUrn/colors)) {
		double probStill = double((colorsUsed*(ballsUrn/colors)) - ballsTaken)/remaining;
		expected(colorsUsed, ballsTaken+1, prob*probStill);
		probCur -= probStill;
	}
	
	if (colorsUsed < colors) {
		expected(colorsUsed+1, ballsTaken+1, prob*probCur);		
	}
}

int main(){
	ios::sync_with_stdio(false), cin.tie(0);

	double ans = 0.0;

	expected(1,1,1.0);

	for (int i=1; i<=colors; i++) {
		ans += e[i]*i;
	}

	cout << fixed << setprecision(10) <<  ans << endl;
}