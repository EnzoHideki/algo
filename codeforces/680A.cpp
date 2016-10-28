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
#include <utility>
#include <unistd.h>
#include <vector>
#define dbg(args...) //fprintf(stderr, args)
#define dbc(x) //cerr << x << "\n"
#define dbn(x) //cerr << #x << " == " << x << "\n"
#define m(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,1,sizeof(x))
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

map<int, int> m;

int main(){
	ios::sync_with_stdio(false);

	int s = 0;
	for (int i=0; i<5; i++) {
		int a;
		cin >> a;
		m[a]++;
		s += a; 
	}


	int tira = 0;
	for (auto i:m) {
		dbn(tira);
		if (i.S == 2 && 2*i.F > tira) {
			dbn(i.S);
						dbn(i.F);
			tira = 2*i.F;
		} else if (i.S > 2 && 3*i.F > tira) {
			tira = 3*i.F;
		}
	}

	cout << s - tira << endl;
}