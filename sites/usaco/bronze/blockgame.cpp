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

map<char, int> mp1;
map<char, int> mp2;
map<char, int> mp;

map<char, int> gen;

int main(){
	ios::sync_with_stdio(false);

	freopen("blocks.in", "r", stdin);
	freopen("blocks.out", "w", stdout);

	int n; cin >> n;

	for (int i=0; i<n; i++) {
		string a, b; cin >> a >> b;

		mp1.clear();
		mp2.clear();
		mp.clear();

		for (int i=0; i<a.size(); i++) {
			mp1[a[i]]++;
		}

		for (int i=0; i<b.size(); i++) {
			mp2[b[i]]++;
		}

		for (auto i:mp1) mp[i.F] = max(mp[i.F], mp1[i.F]);
		for (auto i:mp2) mp[i.F] = max(mp[i.F], mp2[i.F]);

		for (auto i:mp) gen[i.F] += mp[i.F];
	}

	for (char c = 'a'; c <= 'z'; c++) {
		cout << gen[c] << endl;
	}
}