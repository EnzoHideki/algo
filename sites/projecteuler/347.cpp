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
#include <sstream>
#include <unistd.h>
#include <utility>
#include <vector>
#define dbc(x) cerr << x << '\n'
#define dbn(x) cerr << #x << " == " << x << '\n'
#define m(v,x) memset(v,x,sizeof(v))
#define pb push_back
#define endl '\n'

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

//
const int MAX_SIZE = 50000010;

vector<int> prime;
vector<int> SPF(MAX_SIZE);

map<pii, int> mp;

void linear_sieve(int N) { 
    for (ll i=2; i<N; i++) {
        if (SPF[i] == 0) {
            prime.push_back(i);
            SPF[i] = i;
        }

        for (ll j=0; j < (int) prime.size() && i*prime[j] < N 
        	&& prime[j] <= SPF[i]; j++) {
            SPF[i*prime[j]] = prime[j] ;
        }
    }
}

int main(){
	ios::sync_with_stdio(false), cin.tie(0);

	linear_sieve(10000010);

	ll ans = 0;
	for (int i=1; i<=10000000; i++) {
		int tmp = i;
		set<int> s;
		while (tmp != 1 && s.size() <= 2) {
			s.insert(SPF[tmp]);
			tmp /= SPF[tmp];
		}

		if (s.size() == 2) {
			mp[{*s.begin(), *(--s.end())}] = i;
		}		
	}

	for (auto p : mp) {
		ans += p.second;
	}

	dbn(ans);
}