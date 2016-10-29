#include <bits/stdc++.h>
#define dbg(args...) //fprintf(stderr, args) 
#define m(x) memset((x),0,sizeof(x))
#define m1(x) memset((x),-1,sizeof(x))
#define pb push_back
using namespace std;

const int MAXN = 2123;

vector<int> adj[80];
int dx[8] = {1,2,2,1,-1,-2,-2,-1};
int dy[8] = {2,1,-1,-2,-2,-1,1,2};
queue<int> fila;

int dist[80];

int conv(int x, int y){
	return y*8 + x;
}

bool val(int x, int y){
	return (x >= 0 && x<8 && y>=0 && y<8);
}

void bfs(int v){
	m1(dist);

	fila.push(v);
	dist[v]= 0;

	while(!fila.empty()){
		int x = fila.front();
		fila.pop();

		for(auto i:adj[x]){
			if(dist[i] == -1){
				dist[i] = dist[x]+1;
				fila.push(i);
			}
		}
	}
}

int main(){
	for(int i=0; i<8; i++){
		for(int j=0; j<=7; j++){
			for(int k=0; k<8; k++){
				if(val(j+dx[k], i+dy[k])){
					adj[conv(j, i)].pb(conv(j+dx[k], i+dy[k]));
				}
			}
		}
	}

	int t; cin >> t;

	while(t--){
		string in, des; cin >> in >> des;
		bfs(conv(in[0]-'a', in[1]-'1'));

		cout << dist[conv(des[0]-'a', des[1]-'1')] << endl;
	}
}