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

map<string, int> mapa;

bool isL(char a){
	if((a>='a' && a<='z') || (a>='A' && a<='Z')) return true;
	else return false;
}

char dow(char a){
	if(a>='A' && a<='Z') return (a-'A'+'a');
	return a;
}

int main(){
	int m, n; cin >> m >> n;
	
	for(int i=0; i<m; i++){
		string s; int sal; cin >> s >> sal;
		mapa[s] = sal;
	}
	
	for(int i=0; i<n; i++){
		int con = 0;
		string lin;
		while(cin >> lin && lin != "."){
			if(mapa.find(lin) != mapa.end())
				con += mapa[lin];
		}
		
		cout << con << endl; 
	}
}
