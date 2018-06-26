#include <cstdio>
#include <iostream>
#include <cmath>
#include <math.h>
#include <cstdlib>
#include <algorithm>
#include <set>
#include <utility>
#include <vector>
#include <map>
#include <cstring>
#include <queue>
#include <ios>
#include <iomanip>
#include <bitset>
#define dbg(args...) //fprintf(stderr, args)
#define dbc(x) //cerr << x << "\n"
#define dbn(x) //cerr << #x << " == " << x << "\n"
#define m(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,1,sizeof(x))
#define minf(x) memset(x,63,sizeof(x))
#define pb push_back
#define eb emplace_back
#define F first
#define S second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int MAXN = 12;

string ta[8];

bool isVal(char a){
	return (a <= 7) && (a >= 0);
}

bool pawn(string c){
	int pos1 = c[0]-'a'-1;
	int pos2 = c[0]-'a'+1;
	int pos3 = c[1]-'0'-1-1;

	if(isVal(pos3)){
		if((isVal(pos1) && ta[pos3][pos1] == 'p') || (isVal(pos2) && ta[pos3][pos2] == 'p'))  return true;
		else return false;
	} else return false;
}

bool rook(string c, char p){
	int inil = c[0];
	int inin = c[1];

	while(isVal(inil - 'a') && isVal(inin-'0'-1)){
		if(ta[inin-'0'-1][inil-'a'] == p) return true;
		
		else if(ta[inin-'0'-1][inil-'a'] != '.' && (inin-'0'-1 != c[1]-'0'-1 || inil-'a' != c[0]-'a')) break;

		inil++;
	}

	inil = c[0];
	inin = c[1];

	while(isVal(inil - 'a') && isVal(inin-'0'-1)){
		if(ta[inin-'0'-1][inil-'a'] == p) return true;
		else if(ta[inin-'0'-1][inil-'a'] != '.' && (inin-'0'-1 != c[1]-'0'-1 || inil-'a' != c[0]-'a')) break;

		inil--;
	}

	inil = c[0];
	inin = c[1];

	while(isVal(inil - 'a') && isVal(inin-'0'-1)){
		if(ta[inin-'0'-1][inil-'a'] == p) return true;
		else if(ta[inin-'0'-1][inil-'a'] != '.' && (inin-'0'-1 != c[1]-'0'-1 || inil-'a' != c[0]-'a')) break;

		inin++;
	}

	inil = c[0];
	inin = c[1];

	while(isVal(inil - 'a') && isVal(inin-'0'-1)){
		if(ta[inin-'0'-1][inil-'a'] == p) return true;
		else if(ta[inin-'0'-1][inil-'a'] != '.' && (inin-'0'-1 != c[1]-'0'-1 || inil-'a' != c[0]-'a')) break;

		inin--;
	}

	return false;
}

bool knight(string c){
	if(isVal(c[1]-'0'-1+2)){
		if(isVal(c[0]-'a'+1) && ta[c[1]-'0'-1+2][c[0]-'a'+1] == 'c') return true;
		else if(isVal(c[0]-'a'-1) && ta[c[1]-'0'-1+2][c[0]-'a'-1] == 'c') return true;
		else if(isVal(c[0]-'a'+2) && ta[c[1]-'0'-1+1][c[0]-'a'+2] == 'c') return true;
		else if(isVal(c[0]-'a'-2) && ta[c[1]-'0'-1+1][c[0]-'a'-2] == 'c') return true;
	}

	if(isVal(c[1]-'0'-1-2)){
		if(isVal(c[0]-'a'+1) 		&& ta[c[1]-'0'-1-2][c[0]-'a'+1] == 'c') return true;
		else if(isVal(c[0]-'a'-1) 	&& ta[c[1]-'0'-1-2][c[0]-'a'-1] == 'c') return true;
		else if(isVal(c[0]-'a'+2) 	&& ta[c[1]-'0'-1-1][c[0]-'a'+2] == 'c') return true;
		else if(isVal(c[0]-'a'-2) 	&& ta[c[1]-'0'-1-1][c[0]-'a'-2] == 'c') return true;
	}

	return false;
}

bool bishop(string c, char p){
	int inil = c[0];
	int inin = c[1];
	while(isVal(inil-'a') && isVal(inin-'0'-1)){
		if(ta[inin-'0'-1][inil-'a'] == p) return true;
		else if(ta[inin-'0'-1][inil-'a'] != '.' && (inin-'0'-1 != c[1]-'0'-1 || inil-'a' != c[0]-'a')) break;

		inil++;
		inin--;
	}

	inil = c[0];
	inin = c[1];
	while(isVal(inil-'a') && isVal(inin-'0'-1)){
		if(ta[inin-'0'-1][inil-'a'] == p) return true;
		else if(ta[inin-'0'-1][inil-'a'] != '.' && (inin-'0'-1 != c[1]-'0'-1 || inil-'a' != c[0]-'a')) break;

		inil--;
		inin++;
	}

	inil = c[0];
	inin = c[1];
	while(isVal(inil-'a') && isVal(inin-'0'-1)){
		if(ta[inin-'0'-1][inil-'a'] == p) return true;
		else if(ta[inin-'0'-1][inil-'a'] != '.'  && (inin-'0'-1 != c[1]-'0'-1 || inil-'a' != c[0]-'a')) break;

		inil++;
		inin++;
	}

	inil = c[0];
	inin = c[1];
	while(isVal(inil-'a') && isVal(inin-'0'-1)){
		if(ta[inin-'0'-1][inil-'a'] == p) return true;
		else if(ta[inin-'0'-1][inil-'a'] != '.'  && (inin-'0'-1 != c[1]-'0'-1 || inil-'a' != c[0]-'a')) break;

		
		inil--;
		inin--;
	}

	return false;
}

int dirx[8] = {-1,0,1,-1,1,-1,0,1};
int diry[8] = {1,1,1,0,0,-1,-1,-1};

bool king(string c){
	for(int i=0; i<8; i++){
		if(isVal(c[0]-'a'+dirx[i]) && isVal(c[1]-'0'-1+diry[i]) && ta[c[1]-'0'-1+diry[i]][c[0]-'a'+dirx[i]] == 'k') return true;
	}

	return false;
}

bool queen(string c){
	return bishop(c, 'r')||rook(c, 'r');
}

int main(){
	ios_base::sync_with_stdio(false);

	for(int i=7; i>=0; i--) getline(cin, ta[i]);

	string cap; cin >> cap;

	if(pawn(cap) || rook(cap, 't') || knight(cap) || bishop(cap, 'b') || king(cap) || queen(cap)) cout << "Sim" << endl;
	else cout << "Nao" << endl;
}
