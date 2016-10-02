#include <bits/stdc++.h>
#define F first
#define S second
#define dbn(x) cerr << #x << " == " << x << endl

using namespace std;

typedef pair<int,int> pii;
typedef set< pair<pii, string> > siis;
typedef long long ll;
typedef set<pii> sii;

const int INF = 0x3f3f3f3f;

sii rei;
map<string, pii> mapa;

//Reindeer Games

int main(){
	ios::sync_with_stdio(false);

	int m; cin >> m;

	ll prod = 0;
	
	rei.insert({INF,0});
	rei.insert({0,0});
	
	while(m--){
		char a; cin >> a;
		string nome; cin >> nome;

		int s, p;
				
		if(a == 'A'){
			cin >> s >> p;

			rei.insert({s,p});
			mapa[nome] = {s,p};
			
			sii::iterator it = rei.lower_bound({s,p});
			sii::iterator it1 = --it;
			sii::iterator it2 = (++(++it))--;
			
			prod -= (ll) (*it1).S * (*it2).S;
			prod += (ll) (*it1).S * (*it).S + (ll) (*it).S * (*it2).S;
		} else {			
			s = mapa[nome].F;
			p = mapa[nome].S;
						
			sii::iterator it = rei.lower_bound({s,p});
			sii::iterator it1 = --it;
			sii::iterator it2 = (++(++it))--;
			
			prod -= (ll) (*it1).S * (*it).S + (ll) (*it).S * (*it2).S;
			prod += (ll) (*it1).S * (*it2).S;
			
			rei.erase(it);
		}
		
		cout << prod << endl;
	}
}