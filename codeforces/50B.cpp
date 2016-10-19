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
#define m1(x) memset((x),0,sizeof(x))
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

int main(){
	ios::sync_with_stdio(false);

	string s;
	cin >> s;

	int len = s.size();
	ll ans = len;

	map<char,ll> m;

	for (int i=0; i<len; i++) {
		if (m.find(s[i]) == m.end()) {
			m[s[i]] = 1;
		} else {
			m[s[i]]++;			
		}
	}

	for (auto i:m) {
		ans += i.S*(i.S-1);
	}

	cout << ans << endl;
}