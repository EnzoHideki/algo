#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <ios>
#include <iomanip>
#include <queue>
#include <utility>
#include <set>
#include <map>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <climits>
#define dbg(args...) //fprintf(stderr, args)
#define dbc(x) //cerr << x << "\n"
#define dbn(x) //cerr << #x << " == " << x << "\n"
#define endl '\n'
#define m(x) memset((x),0,sizeof(x))
#define minf(x) memset((x),63,sizeof(x))
#define eb emplace_back
#define pb push_back
#define F first
#define S second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef set<int> si;
typedef set<pii> sii;

const int MAXM = 1e4 + 10;
const int MAXN = 1e5 + 10;
const int INF = 0x3f3f3f3f;

// Books

int v[MAXN];

int main(){
	int n, t; cin >> n >> t;

	for(int i=0; i<n; i++){
		cin >> v[i];
	}

	int l = 0, r = 0;

	int soma = 0, ans = 0, qtd = 0;

	while(r < n){
		dbg("l: %d r: %d soma: %d\n",l,r,soma);
		if(soma + v[r] <= t){
			soma += v[r];
			r++;
			qtd++;
		} else {
			dbn(qtd);
			ans = max(ans, qtd);

			soma += v[r];
			r++;
			soma -= v[l];
			l++;
		}
	}

	ans = max(ans, qtd);

	cout << ans << endl;
}