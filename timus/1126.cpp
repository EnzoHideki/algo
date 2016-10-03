#include <algorithm>
#include <bitset>
#include <cmath>
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <ios>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <utility>
#include <vector>
#define dbg(args...) fprintf(stderr, args)
#define dbc(x) cerr << x << "\n"
#define dbn(x) //cerr << #x << " == " << x << "\n"
#define endl '\n'
#define m(x) memset((x),0,sizeof(x))
#define m1(x) memset((x),0,sizeof(x))
#define minf(x) memset((x),63,sizeof(x))
#define eb emplace_back
#define pb push_back
#define F first
#define S second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef set<int> si;

const int INF = 0x3f3f3f3f;

//

const int MAXN = 25123;

int v[MAXN];
multiset<int> ms;

int main(){
	int m; cin >> m;
	int i=0;
	while(cin >> v[i] && v[i] != -1){
		i++;
	}

	dbn(i);

	int j=0;
	for(; j<m; j++){
		ms.insert(v[j]);
		dbn(v[j]);
	}

	cout << *(ms.rbegin()) << endl;

	for(; j<i; j++){
		ms.insert(v[j]);
		dbn(v[j]);
		ms.erase(ms.find(v[j-m]));
		dbn(v[j-m]);
		cout << *(ms.rbegin()) << endl;
	}
}