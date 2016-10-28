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

const int MAXN = 112;

int primes[15] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};

int main(){
	ios::sync_with_stdio(false);

	int i = 0;
	int times = 0;
	while (times < 2 && i < 15) {
		cout << primes[i] << endl;
		fflush(stdout);
		string res;
		cin >> res;
		if (res == "yes") {
			times++;

			if (i <= 3) {
				cout << primes[i]*primes[i] << endl;
				fflush(stdout);
				string res;
				cin >> res;
				if (res == "yes") {
					cout << "composite" << endl;
					return 0;
				}
			}
		}

		i++;
	}

	if (times >= 2) cout << "composite" << endl;
	else cout << "prime" << endl;
}