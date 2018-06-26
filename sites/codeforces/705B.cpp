#include <cstdio>
#include <iostream>
#include <cmath>
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
#define m(x) memset(x,0,sizeof(x))
#define pb push_back
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pair<int,int> > vii;

const int inf = 0x3f3f3f3f;
const int MAXN = 112345;

int main(){
	ll n; cin >> n;

	ll s = 0;
	for(ll i=0; i<n; i++){
		ll a; cin >> a;

		s+=(a-1);

		cout << "21"[s%2] << "\n";
	}
}
