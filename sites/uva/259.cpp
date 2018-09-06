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
#include <sstream>
#include <unistd.h>
#include <utility>
#include <vector>
#define dbc(x) //cerr << x << '\n'
#define dbn(x) //cerr << #x << " == " << x << '\n'
#define pb push_back
#define endl '\n'

#define dbv(x, n) //cerr << #x << " == [ "; for (int i=0; i<int(n); i++) { cerr << x[i] << " "; } cerr << "]\n";
#define dbm(v, n, m) //cerr << #v << ":\n"; for (int i=0; i<n; i++) for (int j=0; j<m; j++) cerr << v[i][j] << " \n"[j == m-1];

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

//
const int MAXN = 112;
vector<int> adj[MAXN];
int capacity[MAXN][MAXN];
int parent[MAXN];
const int INF = 0x3f3f3f3f;
string ans;
int total;

void init() {
	memset(capacity, 0, sizeof capacity);
	ans = "__________";
	total = 0;

	for (int i=0; i<MAXN; i++) {
		adj[i].clear();
	}

	for (int i=30; i<40; i++) {
		adj[i].push_back(40);
		adj[40].push_back(i);

		capacity[i][40] = 1;
	}
}


int bfs(int s, int t) {
    memset(parent, -1, sizeof parent);
    parent[s] = -2;
    queue<pair<int, int>> q;
    q.push({s, INF});

    while (!q.empty()) {
        int cur = q.front().first;
        int flow = q.front().second;
        q.pop();

        for (int next : adj[cur]) {
            if (parent[next] == -1 && capacity[cur][next] > 0) {
                parent[next] = cur;
                int new_flow = min(flow, capacity[cur][next]);
                if (next == t) return new_flow;
                q.push({next, new_flow});
            }
        }
    }

    return 0;
}

int maxflow(int s, int t) {
    int flow = 0;

    int anspos = -1;

    while (int new_flow = bfs(s, t)) {
        flow += new_flow;
        int cur = t;

        while (cur != s) {
            int prev = parent[cur];

            if (prev >= 30 && prev <= 39) anspos = prev - 30;
            if (prev >= 1 && prev <= 26) ans[anspos] = 'A' + prev - 1;

            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] += new_flow;
            cur = prev;
        }
    }

    return flow;
}

vector<string> split(const string& s, const string& del) {
    vector<string> ret;
    char* cs = (char *) malloc(s.size() + 10);
    strcpy(cs, s.c_str());
    for (char* p = strtok(cs, del.c_str()); p; p = strtok(NULL, del.c_str()))
        ret.push_back(string(p));
    return ret;
}

int main(){
	ios::sync_with_stdio(false), cin.tie(0);

	string line;
	init();

	while (getline(cin, line)) {
		if (line == "") {
			if (maxflow(0, 40) == total) {
				cout << ans << endl;
			} else {
				cout << '!' << endl;
			}

			init();
			continue;
		}

		vector<string> vs = split(line, " ");
		string s = vs[0];
		string t = vs[1];

		int id = s[0] - 'A' + 1;

		adj[0].push_back(id);
		adj[id].push_back(0);

		capacity[0][id] = s[1] - '0';

		total += s[1] - '0';

		for (char c : t) {
			if (c != ';') {
				int num = 30 + c-'0';
				adj[id].push_back(num);
				adj[num].push_back(id);

				capacity[id][num] = 1;
			}
		}
	}

	if (maxflow(0, 40) == total) {
		cout << ans << endl;
	} else {
		cout << '!' << endl;
	}
}