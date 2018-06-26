#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <functional>
#include <iomanip>
#include <ios>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <unistd.h>
#include <utility>
#include <vector>
#define dbg(args...) fprintf(stderr, args)
#define dbc(x) cerr << x << '\n'
#define dbn(x) cerr << setprecision(20) << #x << " == " << x << '\n'
#define m(v,x) memset(v,x,sizeof(v))
#define pb push_back
#define endl '\n'
#define F first
#define S second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int INF = 0x3f3f3f3f;

//
const int MAXN = 1123;

int r,c;

int tab[MAXN][MAXN];
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

bool seen[MAXN*MAXN];
int dist[MAXN*MAXN];

bool val(pii p) {
	return p.F >= 0 && p.F < c && p.S >= 0 && p.S < r;
}

int conv(pii p) {
	return p.S*c + p.F;
}

void bfs(pii p) {
	m(seen, false);
	m(dist, 63);

	queue<pii> fila;

	fila.push(p);
	dist[conv(p)] = 0;
	seen[conv(p)] = true;
	while (!fila.empty()) {
		pii x = fila.front();
		fila.pop();

		for (int i=0; i<4; i++) {
			pii cur = {x.F+dx[i], x.S+dy[i]};
			if (val(cur) && tab[cur.S][cur.F] != -1 && seen[conv(cur)] == false) {
				seen[conv(cur)] = true;
				fila.push(cur);
				dist[conv(cur)] = dist[conv(x)] + 1;
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(false), cin.tie(0);

	while (cin >> r >> c && r != 0 && c != 0) {
		m(tab,1);

		int rows; cin >> rows;

		for (int i=0; i<rows; i++) {
			int row; cin >> row;
			int bombs; cin >> bombs;

			for (int j=0; j<bombs; j++) {
				int col; cin >> col;

				tab[row][col] = -1;
			}
		}

		int startx, starty, destx, desty;
		cin >> starty >> startx >> desty >> destx;

		bfs({startx, starty});

		cout << dist[conv({destx,desty})] << endl;
	}
}