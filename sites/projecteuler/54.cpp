#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
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
#define dbc(x) cerr << x << "\n"
#define dbn(x) cerr << #x << " == " << x << "\n"
#define m(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,-1,sizeof(x))
#define minf(x) memset(x,63,sizeof(x))
#define pb push_back
#define eb emplace_back
#define F first
#define S second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int INF = 0x3f3f3f3f;

//

string seq = "23456789TJQKA";
vector<int> draw;

bool comp(int a, int b) { return a > b;}

int ten(string s) {
	set<char> suit = {s[1], s[4], s[7], s[10], s[13]};
	set<char> ss = {s[0], s[3], s[6], s[9], s[12]};

	if (suit.size() == 1) {
		for (int i=0; i<5; i++) {
			if (*ss.begin() != "AJKQT"[i]) return 0;
		}

		return 1;
	} else return 0;
}

int nine(string s) {
	set<char> suit = {s[1], s[4], s[7], s[10], s[13]};
	vector<int> v;

	if (suit.size() == 1) {
		for (int i=0; i<5; i++) {
			v.pb(seq.find(string()+s[3*i]));
			draw.pb(seq.find(string()+s[3*i]));
		}

		sort(v.begin(), v.end());
		sort(draw.begin(), draw.end(), comp);

		for (int i=1; i<5; i++) {
			if (v[i] != v[i-1]+1) return 0;
		}

		return 1;
	} else return 0;
}

int eight(string s) {
	map<char, int> mp;

	for (int i=0; i<5; i++) {
		mp[s[3*i]]++;
	}

	int ind = 0;
	for (auto i:mp) {
		if (i.S == 4) {
			draw.pb(seq.find(i.F));
			if (ind == 0) draw.pb(seq.find((*--mp.end()).F));
			if (ind == 1) draw.pb(seq.find((*mp.begin()).F));
			return 1;
		}

		ind++;
	}

	return 0;
}

int seven(string s) {
	map<char, int> mp;

	for (int i=0; i<5; i++) {
		mp[s[3*i]]++;
	}

	if (mp.size() == 2) {
		if ((*mp.begin()).S == 2 && (*--mp.end()).S == 3) {
			draw.pb(seq.find((*--mp.end()).F));
			draw.pb(seq.find((*mp.begin()).F));
			return 1;
		} 
		
		if ((*mp.begin()).S == 3 && (*--mp.end()).S == 2) {
			draw.pb(seq.find((*mp.begin()).F));
			draw.pb(seq.find((*--mp.end()).F));
			return 1;	
		}  
	}

	return 0;
}

int six(string s) {
	set<char> suit = {s[1], s[4], s[7], s[10], s[13]};

	for (int i=0; i<5; i++) draw.pb(seq.find(s[3*i]));
	sort(draw.begin(), draw.end(), comp);

	if (suit.size() == 1) return 1;
	else return 0;
}

int five(string s) {
	vector<int> v;

	for (int i=0; i<5; i++) {
		v.pb(seq.find(string()+s[3*i]));
		draw.pb(seq.find(string()+s[3*i]));
	}

	sort(v.begin(), v.end());
	sort(draw.begin(), draw.end());

	for (int i=1; i<5; i++) {
		if (v[i] != v[i-1]+1) return 0;
	}

	return 1;
}

int four(string s) {
	map<char, int> mp;

	for (int i=0; i<5; i++) mp[s[3*i]]++;

	int ok = 0;
	for (auto i:mp) {
		if (i.S == 3) {
			draw.pb(seq.find(i.F));
			ok = 1;
		}
	}

	vector<int> v;
	for (auto i:mp) if (i.S != 3) v.pb(seq.find(i.F));
	sort(v.begin(), v.end(), comp);
	
	for (auto i:v) draw.pb(i);

	return ok;
}

int three(string s) {
	map<char, int> mp;

	for (int i=0; i<5; i++) mp[s[3*i]]++;

	int ok = 0;
	for (auto i:mp) {
		if (i.S == 2) {
			draw.pb(seq.find(i.F));
			ok++;
		}
	}

	sort(draw.begin(), draw.end(), comp);

	for (auto i:mp) {
		if (i.S == 1) draw.pb(seq.find(i.F));
	}

	if (ok == 2) return 1;
	else return 0;
}

int two(string s) {
	map<char, int> mp;

	vector<int> v;

	for (int i=0; i<5; i++) mp[s[3*i]]++;

	int ok = 0;
	for (auto i:mp) {
		if (i.S == 2) {
			draw.pb(seq.find(i.F));
			ok++;
		} else {
			v.pb(seq.find(i.F));
		}
	}

	sort(v.begin(), v.end(), comp);

	for (auto i:v) {
		draw.pb(i);
	}

	if (ok == 1) return 1;
	else return 0;
}

int one(string s) {
	for (int i=0; i<5; i++) {
		draw.pb(seq.find(s[3*i]));
	}

	sort(draw.begin(), draw.end(), comp);

	return 1;
}


int which(string s) {
	draw.clear();
	if (ten(s)) return 10;
	draw.clear();
	if (nine(s)) return 9;
	draw.clear();
	if (eight(s)) return 8;
	draw.clear();
	if (seven(s)) return 7;
	draw.clear();
	if (six(s)) return 6;
	draw.clear();
	if (five(s)) return 5;
	draw.clear();
	if (four(s)) return 4;
	draw.clear();
	if (three(s)) return 3;
	draw.clear();
	if (two(s)) return 2;
	draw.clear();
	if (one(s)) return 1;

	assert(0);
}


int main() {
	int first = 0;

	freopen("in.txt", "r", stdin);

	for (int i=0; i<1000; i++) {
		string s; getline(cin, s);

		string p1 = s.substr(0,14);
		string p2 = s.substr(15);

		int pone = which(p1);
		vector<int> t1 = draw;

		int ptwo = which(p2);
		vector<int> t2 = draw;

		if (pone > ptwo) {
			first++;
		} else if (pone == ptwo) {
			for (int j=0; j<t1.size(); j++) {
				if (t1[j] > t2[j]) {
					first++;
					break;
				} else if (t1[j] < t2[j]) {
					break;
				}
			}
 		}
 		
	}

	cout << first << endl;
}	