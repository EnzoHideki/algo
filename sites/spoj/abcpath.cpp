#include <bits/stdc++.h>
#define m(x) memset((x), 0, sizeof(x))
#define minf(x) memset((x), 63, sizeof(x))
#define m1(x) memset((x),-1,sizeof(x))
#define pb push_back
#define dbg(args...) fprintf(stderr, args)
#define dbc(x) cerr << x << endl
#define dbn(x) cerr << #x << " == " << x << endl
using namespace std;

typedef vector<int> vi;
typedef set<int> si;
typedef set<long long> sll;
typedef long long ll;

const int MAXH = 5e1 + 10;

// ABC Path

char tab[MAXH][MAXH];
queue<int> fila;
vi adj[MAXH*MAXH];
int dist[MAXH*MAXH];
int ans,h,w;

int dx[8] = {1,0,-1,0,1,-1,-1,1};
int dy[8] = {0,1,0,-1,1,1,-1,-1};

void bfs(int v){
	m1(dist);
	fila.push(v);
	dist[v] = 0;

	while (!fila.empty()){
		int p = fila.front();
		fila.pop();

		for(int i : adj[p]){
			if(dist[i] == -1){
				dist[i] = dist[p]+1;
				fila.push(i);	
			}
		}
	}
}

bool val(int x, int y){ return (x >= 0 && x<w && y>=0 && y<h); }
int conv(int x, int y){ return y*w + x; }

int main(){
	int t = 1;
	while(cin >> h >> w && h!=0 && w!=0){
		m(tab);

		ans = 0;

		for(int i=0; i<MAXH*MAXH; i++) adj[i].clear();

		for(int i=0; i<h; i++) cin >> tab[i];

		for(int i=0; i<h; i++)
		for(int j=0; j<w; j++)
		for(int k=0; k<8; k++) if(val(j+dx[k], i+dy[k]) && tab[i][j]+1 == tab[i+dy[k]][j+dx[k]]) adj[conv(j,i)].pb(conv(j+dx[k], i+dy[k]));

		for(int i=0; i<h; i++)
		for(int j=0; j<w; j++)
			if(tab[i][j] == 'A'){
				bfs(conv(j,i));
				ans = max(ans, *max_element(dist, dist+(MAXH*MAXH))+1);	
			}

		cout << "Case " << t++ << ": " << ans << endl;
	}
}