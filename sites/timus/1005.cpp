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
#include <bitset>
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

const int INF = 0x3f3f3f3f;

// Stone Pile

const int MAXN = 30;

int soma = 0;
int v[MAXN];
int n = 0;

int f(int i, int x){
	if(i == n-1){
		return abs(soma - 2*x);
	}

	return min(f(i+1, x+v[i+1]), f(i+1, x));
}

int main(){
	ios::sync_with_stdio(false);

	cin >> n;

	for(int i=0; i<n; i++){
		cin >> v[i];
		soma += v[i];
	}

	cout << f(-1,0) << endl;

	return 0;
}