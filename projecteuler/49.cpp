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
#include <vector>
#define dbg(args...) //fprintf(stderr, args)
#define dbc(x) //cerr << x << "\n"
#define dbn(x) cerr << #x << " == " << x << "\n"
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

const int MAXN = 11234;

int sie[MAXN];

set<int> primes;

bool somePerm(int a, int n){
	string as = to_string(n);

	string aa = to_string(a);

	while(next_permutation(aa.begin(), aa.end()))
		if(aa == as)
			return true;

	return false;
}

int main(){
	ios::sync_with_stdio(false);

	sie[0] = 1;
	sie[1] = 1;
	for (int i=2; i<MAXN; i++) for (int j=2*i; j<MAXN; j+=i) sie[j] = 1;

	for(int i=0; i<MAXN; i++) if(!sie[i]) primes.insert(i);

	set<int>::iterator it = primes.begin();

	while(*it < 1000) it++;

	while(true){
		dbn(*it);
		if(*it > 9999) break;

		string s = to_string(*it);

		for(int i=0; i<23; i++){
			next_permutation(s.begin(), s.end());

			int sk = stoi(s);

			if(sk < *it) break;

			int third = sk + sk - *it;
			if(primes.find(third) != primes.end())
				if(primes.find(sk) != primes.end())
					if(*it != 1487 && somePerm(*it, third)) {
						cout << *it << sk << third << endl;
						return 0;
					}
		}

		it++;
	}
}
