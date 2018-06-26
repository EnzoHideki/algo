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
#define dbc(x) //cerr << x << "\n"
#define dbn(x) //cerr << #x << " == " << x << "\n"
#define m(x) memset(x,0,sizeof(x))
#define bits(x) __builtin_popcount(x)
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

const int INF = 0x3f3f3f3f;
const int MAXN = 1123;

pii arv[MAXN];
map<pii, sii> adj;
map<pii, int> comp;
map<pii, sii>::iterator itadj;
map<pii, int>::iterator itcomp;


double dist(pii a, pii b){
	return sqrt((double) ((a.F-b.F)*(a.F-b.F) + (a.S-b.S)*(a.S-b.S)));
}

void dfs(pii a){
	sii::iterator its;
	for(its = adj[a].begin(); its != adj[a].end(); its++){
		if(!comp[*its]){
			comp[*its] = 1;
			dfs(*its);
		}
	}
}

int n,d;
int main(){
	cin >> n >> d;
	for(int i=0; i<n; i++){
		int x,y; cin >> x >> y;
		arv[i] = mp(x,y);
		comp[mp(x,y)] = 0;
	}
	for(int i=0; i<n-1; i++){
		for(int j=i+1; j<n; j++){
			if(dist(arv[i], arv[j]) <= (double) d){
				adj[arv[i]].insert(arv[j]);
				adj[arv[j]].insert(arv[i]);
			}
		}
	}
	dfs(arv[0]);
	int sum = 0;

	for(itcomp = comp.begin(); itcomp != comp.end(); itcomp++){
		sum += (*itcomp).S;
	}
	cout << ((sum==n)?"S":"N") << "\n";
	
	return 0;
}