#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
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
#include <unistd.h>
#include <vector>
#define dbg(args...) //fprintf(stderr, args)
#define dbc(x) //cerr << x << "\n"
#define dbn(x) //cerr << #x << " == " << x << "\n"
#define m(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,1,sizeof(x))
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

//

map<char,int> alpha;

int main(){
	ios::sync_with_stdio(false);

	for (char i = 'a'; i <= 'z'; i++) {
		alpha[i] = 0;
	}

	int n;
	string s;

	cin >> n >> s;

	if(n>26){
		cout << -1 << endl;
		return 0;	
	} 

	for(int i=0; i<n; i++){
		alpha[s[i]]++;
	}

	int ans = 0;
	for (char i = 'a'; i <= 'z'; i++) {
		if(alpha[i] > 0) {
			ans += alpha[i]-1;
		}
	}

	cout << ans << endl;
}