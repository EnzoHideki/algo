#include <cstdio>
#include <iostream>
#include <cmath>
#include <math.h>
#include <cstdlib>
#include <algorithm>
#include <set>
#include <utility>
#include <vector>
#include <map>
#include <cstring>
#include <queue>
#include <ios>
#include <iomanip>
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
typedef vector<pii> vii;
typedef set<int> si;
typedef set<pii> sii;

const int INF = 0x3f3f3f3f;

// Non-Trivial Numbers

int crivo[1123];
vi primes;

int somaDiv(int n){
	int soma = 0;
	for(auto i : primes){
		if (i > sqrt(n)) break;
		if (n%i == 0) {
			if(i == n/i) soma += i;
			else soma += i + n/i;
		}
	}

	if(n == 1) return 0;
	else return soma+1;
}

int main(){
	ios::sync_with_stdio(false);

	crivo[0] = crivo[1] = 1;
	for(int i=2; i<550; i++){
		for(int j=2*i; j<1123; j+=i){
			crivo[j] = 1;
		}
	}

	for(int i=0; i<1123; i++){
		if(!crivo[i]) primes.pb(i);
	}

	int i,j; cin >> i >> j;

	double mn = (double) INF;

	ll ans;
	for (int k = i; k <= j; k++) {
		double dd = (double) somaDiv(k);
		dbn(mn);
		if(dd/(double) k < mn){
			mn = dd/(double) k;
			ans = k;
		}
	}

	cout << ans << endl;
}