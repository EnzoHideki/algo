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
#define dbg(args...) //fprintf(stderr, args)
#define dbc(x) cerr << x << '\n'
#define dbn(x) cerr << #x << " == " << x << '\n'
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

typedef complex<double> point;
#define X real
#define Y imag

const double PI = acos(-1.0);
const double EPS = 1e-9;

vector<string> split(string s, string del) {
	vector<string> v;
	char* cstr = (char*) malloc(s.size() + 10);
	strcpy(cstr, s.c_str());
	for (char *p = strtok(cstr,del.c_str()); p; p = strtok(NULL,del.c_str())) {
		v.pb(string(p));
	}
	return v;
}

int ccw(point a, point b, point c) {
	point first = b-a;
	point second = c-a;

	return first.X()*second.Y() - first.Y()*second.X();
}

double angle(point a, point b, point c) {
	return abs(remainder(arg(a-b) - arg(c-b), 2*PI));
}

bool inPolygon(point pt, const vector<point> &P) {
	if ((int)P.size() == 0) return false;
	double sum = 0;
	for (int i = 0; i < (int)P.size()-1; i++) {
		if (ccw(pt, P[i], P[i+1])) sum += angle(P[i], pt, P[i+1]);
		else sum -= angle(P[i], pt, P[i+1]); 
	}
	return fabs(fabs(sum) - 2*PI) < EPS; 
}

int main(){
	ios::sync_with_stdio(false), cin.tie(0);

	string s;
	int count = 0;
	while (cin >> s) {
		vector<string> in = split(s,",");
		vector<point> pol;

		if (in.size() != 6) assert(0);

		int x,y;

		for (int i=0; i<6; i++) {
			if (i % 2 == 0) {
				x = stoi(in[i]);
			} else {
				y = stoi(in[i]);
				pol.pb(point(x,y));
			}
		}

		pol.pb(point(pol[0].X(), pol[0].Y()));

		if (inPolygon(point(0,0), pol)) count++;
	}

	cout << count << endl;
}