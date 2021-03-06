#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
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
#define dbc(x) cerr << x << "\n"
#define dbn(x) cerr << #x << " == " << x << "\n"
#define m(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,-1,sizeof(x))
#define minf(x) memset(x,63,sizeof(x))
#define pb push_back
#define eb emplace_back
#define F first
#define S second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int INF = 0x3f3f3f3f;

//
int phi(int n) {
    int result = n;
    for(int i = 2; i * i <= n; ++i)
        if(n % i == 0) {
            while(n % i == 0) n /= i;
            result -= result / i;
        }
    if (n > 1) result -= result / n;
    return result;
}

int main(){
	ios::sync_with_stdio(false);

	int ans = -1;

	double mn = (double) INF;
	
	for (int i=2; i<1e7; i++) {
		if (i % 200000 == 0) dbn(i);

		int pp = phi(i);

		string ii = to_string(i);
		string phii = to_string(pp);

		if (is_permutation(ii.begin(), ii.end(), phii.begin()) &&
			((double) i / (double) pp) < mn) {
			ans = i;
			mn = ((double) i / (double) pp);
		}
	}

	cout << ans << endl;
}