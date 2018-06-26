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
#define dbg(args...) fprintf(stderr, args)
#define dbc(x) cerr << x << "\n"
#define dbn(x) cerr << #x << " == " << x << "\n"
#define bits(x) __builtin_popcount(x)
#define m(x) memset((x),0,sizeof(x))
#define pb push_back
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int MAXN = 1123456;

set<pair<string, string> > s;
map<string, int> qtd;

set<string> fanf;

map<string,int> ans;
vector<pair<string,int> > v;

bool ord(pair<string, int> a, pair<string, int> b){
	if(a.S > b.S) return true;
	else if(a.S == b.S) return a.F < b.F;
	else return false;
}
int main(){
	string in;
	getline(cin, in);

	while(in != "0"){
		s.clear();
		qtd.clear();
		fanf.clear();
		ans.clear();
		v.clear();

		string nome = "";

		while(in != "1"){
			if(in[0] >= 'A' && in[0] <= 'Z'){ nome = in;
				ans[nome] = 0;
			}
			else s.insert(mp(in,nome));
			getline(cin, in);
		}

		for(auto i:s){
			if(qtd.find(i.F) != qtd.end()) qtd[i.F]++;
			else qtd[i.F] = 1;
		}

		for(auto i:qtd) if(i.S >1) fanf.insert(i.F);
		set<pair<string, string> >::iterator it = s.begin();
		while(it != s.end()){
			if(fanf.find((*it).F) != fanf.end()) it = s.erase(it);
			else it++;
		}
		for(auto a:s){
			if(ans.find(a.S) != ans.end()){
				ans[a.S]++;
			} else ans[a.S] = 1;
		}

		for(auto i:ans) v.pb({i.F, i.S});

		sort(v.begin(), v.end(), ord);
		for(auto i:v){
			cout << i.F << " " << i.S << "\n";
		}


		getline(cin, in);
	}


	return 0;
}