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
#define F first
#define S second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

//

string normalize(string s) {
	string x;
	for (int i=0; i<s.size(); i++) {
		if (s[i] == '\r') continue;
		x += s[i];
	}
	return x;
}

int main(){
	ios::sync_with_stdio(false), cin.tie(0);

	string s1,s2;
	while (getline(cin,s1) && getline(cin,s2)) {
		s1 = normalize(s1);
		s2 = normalize(s2);

		int ans = 0;
		for (int i=0; i<s1.size(); i++) {
			for (int j=0; j<s2.size(); j++) {
				if (s1[i] != s2[j]) continue;

				int sz = 0;
				for (int k=j; k<s2.size(); k++) {
					if (s1[i+(k-j)] != s2[k]) break;
					sz++;
				}

				ans = max(ans, sz);
			}
		}

		cout << ans << endl;
	}
}