#include <bits/stdc++.h>
#define dbg(args...) //fprintf(stderr, args) 
using namespace std;

int main(){
	int n; cin >> n;

	for(int i=0; i<n; i++){
		string a, b; cin >> a >> b;

		reverse(a.begin(), a.end());
		reverse(b.begin(), b.end());

		int d = abs((int) a.size() - (int) b.size());
		string aux = "";
		for(int i=0; i<d; i++) aux += '0';

		if(a.size() > b.size()) b = aux + b;
		else a = aux + a;


		int ci = 0;

		string res = "";

		for(int i=(int) a.size()-1; i>=0 ; i--){
			int nn = ci + a[i]-'0' + b[i]-'0';

			if(i!=0 || nn!=0) res += to_string(nn%10);
			ci = nn/10;
		}

		if(ci) res += to_string(ci);

		res.erase(0, res.find_first_not_of('0'));

		cout << res << endl;
	}
}