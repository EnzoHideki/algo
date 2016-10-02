#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef set<int> si;
typedef set<long long> sll;
typedef long long ll;

sll fibs;

int main(){
	fibs.insert(1);
	fibs.insert(2);

	sll::iterator it = fibs.begin();
	ll n = 0;
	while((n = (*it + *(++it))) && n <= 2000000000){
		fibs.insert(n);
	}

	fibs.insert(n);

	int t; cin >> t;

	for(int j=1; j<=t; j++){
		ll n; cin >> n;

		ll res = 1;
		for(ll i=1; i<=n; i++){
			ll a; cin >> a;

			ll ans = 0;
			while(true){
				it = fibs.lower_bound(a);
				if(*it > a){
					it--;
				}

				if(*it == a){
					ans++;
					break;
				} else if(*it < a){
					ans++;
					a-=*it;
				}
			}

			res *= ans;
		}

		cout << "Case " << j << ": " << res << endl; 
	}
}