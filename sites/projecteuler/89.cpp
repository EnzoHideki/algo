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
#define dbc(x) cerr << x << '\n'
#define dbn(x) cerr << #x << " == " << x << '\n'
#define m(v,x) memset(v,x,sizeof(v))
#define pb push_back
#define endl '\n'

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

//
string memo[5005][10][1005];

int symbol(char c) {
	switch (c) {
		case 'M':
			return 1000;
		case 'D':
			return 500;
		case 'C':
			return 100;
		case 'L':
			return 50;
		case 'X':
			return 10;
		case 'V':
			return 5;
		case 'I':
			return 1;
		default:
			return -1;
	}
}

int toDec(string s) {
	int n = 0;
	for (int i=0; i<(int)s.size()-1; i++) {
		if (symbol(s[i]) < symbol(s[i+1])) {
			n -= symbol(s[i]);
		} else {
			n += symbol(s[i]);
		}
	}

	return n + symbol(s[s.size()-1]);
}


int bitAt(int n, int pos) {
	return (n >> pos) & 1;
}

int flipBit(int n, int pos) {
	return n ^ (1 << pos);
}

int poss[] = {1,4,5,9,10,40,50,90,100,400,500,900,1000};
map<int, string> mp = {{1,"I"},{4,"IV"},{5,"V"},{9,"IX"},{10,"X"},{40,"XL"},
{50,"L"},{90,"XC"},{100,"C"},{400,"CD"},{500,"D"},{900,"CM"},{1000,"M"}};

string optimal(int n, int state, int prev) {
	if (n < 4) {
		string ret = "";
		while (n--) ret += 'I';
		return ret;
	}

	if (memo[n][state][prev] == "") {
		string cur = "";
		for (int i=0; i<n; i++) cur += 'I';

		int start = 0;

		if (n >= 1000) start = 12;
		else if (n >= 100) start = 8;
		else if (n >= 10) start = 4;

		for (int i=start; i<13; i++) {
			int x = poss[i];

			if (n >= x && prev >= x) {
				string ss = cur;
				if (x == 1 || x == 9 || x == 10 || x == 90 || x == 100 
					|| x == 900 || x == 1000) {
					ss = mp[x] + optimal(n-x,state,x);
				} else if ((x == 4 || x == 5) && bitAt(state, 0) == 0) {
					ss = mp[x] + optimal(n-x,flipBit(state,0),x);
				} else if ((x == 40 || x == 50) && bitAt(state, 1) == 0) {
					ss = mp[x] + optimal(n-x,flipBit(state,1),x);
				} else if ((x == 400 || x == 500) && bitAt(state, 2) == 0){
					ss = mp[x] + optimal(n-x,flipBit(state,2),x);
				}

				if ((int)ss.size() < (int)cur.size()) {
					cur = ss;
				}
			}
		}

		memo[n][state][prev] = cur;
	}

	return memo[n][state][prev];
}

int main(){
	ios::sync_with_stdio(false), cin.tie(0);

	string s;
	int ans = 0;
	while (cin >> s) {
		int n = toDec(s);
		string opt = optimal(n,0,1002);
		ans += s.size()-opt.size();
	}
	dbn(ans);
}