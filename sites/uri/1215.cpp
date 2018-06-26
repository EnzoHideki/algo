#include <cstdio>
#include <iostream>
#include <algorithm>
#include <set>
#include <utility>
#include <vector>
#include <map>
#define dbg(args...) fprintf(stderr, args)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int MAXN = 12;

set<string> disc;

bool isL(char a){
	if((a>='a' && a<='z') || (a>='A' && a<='Z')) return true;
	else return false;
}

char dow(char a){
	if(a>='A' && a<='Z') return (a-'A'+'a');
	return a;
}

int main(){
	while(!cin.eof()){
		string s; cin >> s;
		
		//cout << "string: " << s << endl;
		string aux = "";
		
		for(int i=0; i<s.size(); i++){
			if(isL(s[i])) aux += dow(s[i]);
			else if(aux.size()){
				//cout << "aux: " << aux << endl;
				disc.insert(aux);
				aux = "";
			}
		}
		
		if(aux.size()){
			//cout << "aux: " << aux << endl;
			disc.insert(aux);
			aux = "";
		}
	}
	
	for(auto v : disc){
		cout << v << endl;
	}
}
