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
#define dbg(args...) fprintf(stderr, args)
#define dbc(x) cerr << x << "\n"
#define dbn(x) cerr << #x << " == " << x << "\n"
#define endl '\n'
#define bits(x) __builtin_popcount(x)
#define m(x) memset((x),0,sizeof(x))
#define minf(x) memset((x),63,sizeof(x))
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef set<int> si;
typedef set<pii> sii;

const int MAXM = 1e2 + 10;
const int MAXN = 1e2 + 10;
const int INF = 0x3f3f3f3f;

//
int v[MAXN][2*MAXM];

int main(){
	int n, m; cin >> n >> m;

	for(int j=0; j<n; j++)
	for(int i=0; i<2*m; i++){
		cin >> v[j][i];
	}

	
	int cont = 0;
	for(int j=0; j<n; j++)
	for(int i=0; i<2*m; i+=2){
		if(v[j][i] == 1 || v[j][i+1] == 1) cont++;
	}	

	cout << cont << endl;

}
