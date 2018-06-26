#include <cstdio>
#include <iostream>
#include <algorithm>
#include <set>
#include <utility>
#include <vector>
#include <map>
#include <queue>
#define dbg(args...) fprintf(stderr, args)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int MAXN = 212;

map<string, string> dic;

int main(){
	int t; cin >> t;

	for(int i=0; i<t; i++){
		int m, n; cin >> m >> n;

		dic.clear();

		string pal,sig;

		getline(cin, pal);

		for(int j=0; j<m; j++){
			getline(cin, pal);
			getline(cin, sig);

			dic[pal] = sig;
		}
		
		for(int j=0; j<n; j++){
			string frase; getline(cin, frase);
			string pal1 = "";

			for(int k=0; frase[k]; k++){
				if(frase[k] == ' ') {
					if(dic.find(pal1) != dic.end()){
						cout << dic[pal1];
					} else {
						cout << pal1;
					}

					cout << " ";

					pal1 = "";
				} else if(k==(int)(frase.size())-1){
					pal1 += frase[k];

					if(dic.find(pal1) != dic.end()){
						cout << dic[pal1];
					} else {
						cout << pal1;
					}

					cout << "\n";

					pal1 = "";
				} else {
					pal1 += frase[k];
				}
			}
		}

		cout << endl;

	}
}
