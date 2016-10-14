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
#define minf(x) memset(x,63,sizeof(x))
#define bits(x) __builtin_popcount(x)
#define pb push_back
#define eb emplace_back
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
const int MAXN = 112345;

//string takeTrail(string a){

//}

string remTr(string a){
	int t = a.size();

	dbn(a);
	bool tp = false;
	for(int i=0; i<(int) a.size(); i++){
		if(a[i]=='.'){ 
			tp = true;
			break;
		}
	}

	dbn(tp);

	for(int i= (int) a.size()-1; i>=0; i--){
		if(tp){
			dbn(a[i]);
			if(a[i] == '0'){
				t--;
			} else if(a[i] == '.'){
				t--;
				break;
			} else break;
		}
	}

	dbn(t);

	string ret = "";
	for(int i=0; i<t; i++){
		ret+=a[i];
	}

	return ret;
}

string remLe(string a){
	int ind = 0;
	for(int i=0; i<(int)a.size(); i++){
		if(i != '0'){
			ind = i;
			break;
		}
	}
	string ret = "";
	for(int i=ind; i<(int) a.size(); i++){
		ret += a[i];
	}

	return ret;
}

int main(){
	ios::sync_with_stdio(false);

	string in; cin >> in;
	string aux = in;

	int ind = 0;

	int inddot = 0;

	for(int i=0; i<(int) in.size(); i++){
		if(in[i] == '.'){
			inddot = i;
		} if(in[i] == 'e'){
			ind = i;
			break;
		} 
	}

	int n = 0;

	for(int i=ind+1; i<(int) in.size(); i++){
		n = 10*n + (in[i] - '0');
	}

	string novo;

	for(int i=0; i<ind; i++){
		novo += in[i];
	}

	for(int i=0; i<100; i++){
		novo += '0';
	}


	string res = "";

	for(int i=0; i<inddot; i++){
		res += novo[i];
	}

	for(int i=inddot+1; i<=inddot+n; i++){
		res += novo[i];
	}

	res += '.';

	for(int i=inddot+n+1; i<(int) novo.size(); i++){
		res += novo[i];
	}

	cout << remTr(remLe(res)) << endl;
}