#include <bits/stdc++.h>
#define dbg(args...) fprintf(stderr, args)
#define F first
#define S second
#define m(x) memset((x),0,sizeof(x))
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int MAXN = 112;

map<string, string> mapa;
map<string, string> ans;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  int n; cin >> n;
  
  for(int i=0; i<n; i++){
     string a, b; cin >> a >> b;
     
     if(mapa.find(a) != mapa.end()){
       mapa[b] = mapa[a];
       mapa.erase(a);
     } else mapa[b] = a;
  }

  cout << mapa.size() << "\n";
  
  for(auto i:mapa) cout << i.S << " " << i.F << "\n";
  
  return 0;
}