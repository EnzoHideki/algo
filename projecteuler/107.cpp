#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <functional>
#include <iomanip>
#include <ios>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <unistd.h>
#include <utility>
#include <vector>
#define dbg(args...) //fprintf(stderr, args)
#define dbc(x) cerr << x << '\n'
#define dbn(x) cerr << #x << " == " << x << '\n'
#define m(v,x) memset(v,x,sizeof(v))
#define pb push_back
#define endl '\n'

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

//

const int MAXN = 112;

int n, k, pai[MAXN], peso[MAXN];
typedef pair<int, pii> edge;
#define F first
#define S second.first
#define T second.second

vector<edge> ve;
vector<string> in;

void init() { for (int i=0; i<MAXN; i++) pai[i] = i; }

int find(int x){
	if(pai[x]==x) return x;
	return pai[x]=find(pai[x]);
}
 
void join(int x, int y){
	x=find(x);
	y=find(y);
	
	if(x==y) return;
	
	if(peso[x]<peso[y]){		
		pai[x]=y;
	}
	if(peso[x]>peso[y]){		
		pai[y]=x;
	}
	
	if(peso[x]==peso[y]){
		pai[x]=y;
		peso[y]++;		
	}
}


vector<string> split(string s, string del) {
	vector<string> ret;
	char* aux = (char *) malloc(s.size() + 10);
	strcpy(aux, s.c_str());
	for (char *p = strtok(aux,del.c_str()); p; p = strtok(NULL, del.c_str()))
		ret.pb(string(p));
	return ret;
}

int main(){
	ios::sync_with_stdio(false), cin.tie(0);

	init();

	string s;
	int totalweight = 0;
	int shrinkedweight = 0;

	int line = 1;
	while (cin >> s) {
		vector<string> inp = split(s, ",");
 
		for (int i=0; i<int(inp.size()); i++) {
			if (inp[i] == "-") continue;

			int wei = stoi(inp[i]);

			ve.pb({wei, {line, i+1}});
			totalweight += wei;
		}

		line++;
	}

	sort(ve.begin(), ve.end());

	for (edge e : ve) {
		if (find(e.S) == find(e.T)) continue;

		join(e.S, e.T);
		shrinkedweight += e.F;
	}

	totalweight /= 2;

	cout << totalweight - shrinkedweight << endl;
}