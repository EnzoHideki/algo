#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <ios>
#include <iomanip>
#include <queue>
#include <utility>
#include <set>
#include <map>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <climits>
#define dbg(args...) fprintf(stderr, args)
#define dbc(x) cerr << x << "\n"
#define dbn(x) cerr << #x << " == " << x << "\n"
#define endl '\n'
#define m(x) memset((x),0,sizeof(x))
#define minf(x) memset((x),63,sizeof(x))
#define eb emplace_back
#define pb push_back
#define F first
#define S second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef set<int> si;
typedef set<pii> sii;

const int MAXM = 1e4 + 10;
const int MAXN = 1e2 + 10;
const int INF = 0x3f3f3f3f;
const double DINF = 999999.0;

// Telecom Company

struct antenna{
	int id, x, y, r;

	antenna(int a, int b, int c, int d){
		id = a;
		x = b;
		y = c;
		r = d;
	};

	antenna(){
	};
};


double pit(antenna a, antenna b){
	return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

antenna ant[MAXN];

double dist[MAXN][MAXN];

int main(){
	int n;

	while(cin >> n && n!=0){
		//fill(dist, dist+sizeof(dist), -1.0);
		for(int i=1; i<=n; i++){
			for(int j=1; j<=n; j++){
				dist[i][j] = DINF;
			}
		}

		/*for(int i=1; i<=n; i++){
			for(int j=1; j<=n; j++){
				dbg("dist[%d][%d] = %lf\n", i,j, dist[i][j]);
			}
		}
*/

		m(ant);
		/*for(int i=0; i<MAXN; i++)
		for(int j=0; j<MAXN; j++)
			dist[i][j] = DINF;
*/
		for(int i=1; i<=n; i++){
			int x,y,r; cin >> x >> y >> r;

			ant[i] = antenna(i,x,y,r);
		}

		for(int i=1; i<=n; i++){
			for(int j=1; j<=n; j++){
				double d = pit(ant[i],ant[j]);
				if(i != j && d <= ant[i].r){
					dist[i][j] = d;
				} else if(i == j) dist[i][j] = 0;
			}
		}

		/*for(int i=1; i<=n; i++){
			for(int j=1; j<=n; j++){
				dbg("dist[%d][%d] = %lf\n", i,j, dist[i][j]);
			}
		}
*/

		for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
		for(int k=1; k<=n; k++)
			dist[j][k] = min(dist[j][k], dist[j][i]+dist[i][k]); 

		int c; cin >> c;

		while(c--){
			int a1, a2; cin >> a1 >> a2;

			if(dist[a1][a2] != DINF) cout << floor(dist[a1][a2]) << endl;
			else cout << -1 << endl;
		}
	}

}