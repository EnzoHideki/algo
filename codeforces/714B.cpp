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

const int INF = 0x3f3f3f3f;

//

si nu;

int main(){
	int n; cin >> n;

	for(int i=0; i<n; i++){
		int a; cin >> a;
		nu.insert(a);
	}

	dbn(nu.size());
	if(nu.size() <= 3){
		if(nu.size() == 1){
			cout << "YES" << endl;
			return 0;
		}

		if(nu.size() == 2){
			cout << "YES" << endl;
			return 0;
		}

		if(nu.size() == 3){
			si::iterator it = nu.begin();
			si::iterator it1 = ++it;
			si::iterator it2 = ++it1;
			it--;
			it1--;
			dbn(*it1);
			dbn(*it2);
			dbc("aqui2");
			dbn(*it1 - *it);
			dbn(*it2 - *it1);
			if(*it1 - *it == *it2 - *it1){
				dbc("aqui");
				cout << "YES" << endl;
				return 0;
			}
		}
	}

	cout << "NO" << endl;

	return 0;
}
