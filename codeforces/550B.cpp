#include <cstdio>
#include <iostream>
#include <cmath>
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
#define dbc(x) cerr << x << "\n"
#define dbn(x) cerr << #x << " == " << x << "\n"
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
typedef vector<pii> vii;
typedef set<int> si;
typedef set<pii> sii;

const int INF = 0x3f3f3f3f;

// Preparing Olympiad

const int MAXN = 30;

int v[MAXN];
int n, l, r, x;
int mn = INF;
int mx = 0;

int solve(int i, int soma, int mn, int mx){
	if(i == n){
		if(soma >= l && soma <= r && mx - mn >= x) return 1;
		else return 0;
	}

	return solve(i+1, soma+v[i], min(mn, v[i]), max(mx, v[i])) + solve(i+1, soma, mn, mx); 
}

int main(){
	cin >> n >> l >> r >> x;
	for(int i=0; i<n; i++) cin >> v[i];
	cout << solve(0, 0, INF, 0) << endl;
}