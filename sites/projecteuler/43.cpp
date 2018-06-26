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
#include <unistd.h>
#include <utility>
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

ll sum;

char v[10] = {'0','1','2','3','4','5','6','7','8','9'};
vector<int> p = {2,3,5,7,11,13,17};

int main(){
	int fat = 10*9*8*7*6*5*4*3*2;

	for(int i=0; i<fat; i++){
		int ok = 1;
		for(int j=1; j<8; j++){
			if((100*(v[j]-'0') + 10*(v[j+1]-'0') + (v[j+2]-'0')) % p[j-1]){
				ok = 0;
				break;	
			}
		}

		if (!ok) {
			next_permutation(v, v+10);
			continue;	
		} else {
			ll a = atoll(v);
			sum += a;
			printf("%lld\n", a);
			sleep(1);
			next_permutation(v, v+10);
		}		
	}

	printf("Answer: %lld\n", sum);
}