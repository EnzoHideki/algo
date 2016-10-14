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

int main(){
	ll l1, r1, l2, r2, k; cin >> l1 >> r1 >> l2 >> r2 >> k;

	ll t = 0;

	if(l2 < l1 && r2 < l1){
		cout << 0 << endl; //
	} else if(l2 < l1 && r2 >= l1 && r2 <= r1){
		t = r2 - l1 + 1;
		if(k >= l1 && k <= r2) t--;
		cout << t << endl;
	} else if(r2 >= l1 && r2 <= r1 && l2 >= l1 && l2 <= r1){
		t = r2 - l2 + 1;
		if(k >= l2 && k <= r2) t--;
		cout << t << endl;
	} else if(l2 >= l1 && l2 <= r1 && r2 > r1){
		t = r1 - l2 + 1;
		if(k >= l2 && k <= r1) t--;
		cout << t << endl;
	} else if(l2 > r1 && r2 > r1){
		cout << 0 << endl; //
	} else if(l2 <= l1 && r2 >= r1){
		t = r1 - l1 + 1;
		if(k >= l1 && k <= r1) t--;
		cout << t << endl;
	}

	return 0;
}