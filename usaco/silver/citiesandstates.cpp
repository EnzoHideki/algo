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

set<pair<string, string> > s1;
set<pair<string, string> > s2;

set<pair<pair<string, string>, pair<string, string> > > pares;

set<pair<string, string> >::iterator it;

int main(){
	ios::sync_with_stdio(false);

	freopen("citystate.in", "r", stdin);
	freopen("citystate.out", "w", stdout);

	int n; cin >> n;

	for (int i=0; i<n; i++) {
		string a, b; cin >> a >> b;

		s1.insert({a,b});
		s2.insert({b,a});
	}


	for (auto i:s1) {
		string search = i.F.substr(0,2);

		for(it = s2.lower_bound({search, ""}); it != s2.end(); it++) {
			if ((*it).F != search) break;

			if (pares.find({{i.F, i.S}, {(*it).S, (*it).F}}) != pares.end()) continue;

			if ((*it).S.substr(0,2) == i.S) pares.insert({{(*it).S, (*it).F}, {i.F, i.S}});
		}
	}

	/*for (auto i:pares) {
		cout << i.F.F << " " << i.F.S << " " << i.S.F << " " << i.S.S << endl;
	}*/
	cout << pares.size() << endl;
}