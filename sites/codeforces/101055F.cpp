#include <bits/stdc++.h>

#define dbg(args...) fprintf(stderr, args)
#define F first
#define S second
#define m(x) memset((x),0,sizeof(x))

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int MAXN = 112;

int main(){
	int q; cin >> q;
	
	for(int i=0; i<q; i++){
		int k = 0;
		string in; cin >> in;
		
		string num = "";
		
		
		for(int j=0; j<in.size(); j++){
			if(in[j] >= '0' && in[j] <= '9'){
				num += in[j];
			} else {
				k++;
			}
		}
				
		int nn = stoi(num);

		int aux = nn;
	
		ll prod = 1;
		while(aux >= 1){
			prod *= aux;
			aux -= k;
		}
		
		cout << prod << "\n";
	}
	
	return 0;
}
