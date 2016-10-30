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
#define dbc(x) cerr << x << "\n"
#define dbn(x) cerr << #x << " == " << x << "\n"
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

const double EPS = 1e-9;
const int cte = 10000;
ll x = 3;
ll dfsz = 0;

vector<ll> pent = {1,5};
vector<ll> diff = {4};

bool isP(ll n){
	if (n <= 0) return false;
	double frac = (1+sqrt(1+24*n))/6;
	return round(frac) - frac < EPS and round(frac) - frac > -EPS;
}

void calc(int n){
	for (int i=0; i<n; i++) {
		pent.pb((ll)(x*(3*x-1)/2));
		diff.pb(pent[x-1] - pent[x-2]);
		dfsz++;
		x++;
	}
}

int main(){
	ios::sync_with_stdio(false);

	calc(cte);

	int i = 0;

	while (true) {
		int aux = 0;
		
		while (pent[i] >= diff[aux] && aux < dfsz) aux++;

		for (int j=aux; j>=0; j--) {
			for (int k=j-1; k>=0; k--) {
				if (pent[j] - pent[k] == pent[i] && isP(pent[j] + pent[k])) {
					cout << pent[j] << endl;
					cout << pent[k] << endl;
					cout << pent[i] << endl;
					return 0;
				}

				if (pent[j] - pent[k] > pent[i]) break;
			}
		}
		i++;

		if (i % cte == 0) calc(cte);
	}
}