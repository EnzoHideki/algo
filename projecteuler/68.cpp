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

//

const int MAXN = 2*3*4*5*6*7*8*9;

int v[] = {1,2,3,4,5,6,7,8,9};
set<string> ans;

bool checkSum() {
	int ss = v[0] + v[4] + v[5];

	if (10 + v[8] + v[4] != ss) {
		return false;
	}

	for (int i=1; i<4; i++) {
		if (v[i] + v[i+4] + v[i+5] != ss) {
			return false;
		}
	}

	return true;
}

int getIndLeast() {
	int ind = 0;

	for (int i = 1; i < 4; i++) {
		if (v[i] < v[ind]) {
			ind = i;
		}
	}

	return ind;
}

string build(int ind) {
	int times = 0;
	string ret = "";

	while (times < 5) {
		int cur = (ind + times)%5;

		if (cur == 4) {
			ret += "10" + to_string(v[8]) + to_string(v[4]);
		} else {
			ret += to_string(v[cur]) + to_string(v[cur + 4]) + to_string(v[cur + 5]);
		}

		times++;
	}

	return ret;
}


int main(){
	ios::sync_with_stdio(false), cin.tie(0);

	for (int i=0; i<MAXN; i++) {
		if (checkSum()) {
			int xx = getIndLeast();
			ans.insert(build(xx));
		}

		next_permutation(v,v+9);
	}

	cout << *ans.rbegin() << endl;
}