#include <bits/stdc++.h>

#define dbg(args...) //fprintf(stderr, args)
#define dbc(x) //cerr << x << "\n"
#define dbn(x) //cerr << #x << " == " << x << "\n"
#define m(x) memset(x,0,sizeof(x))
#define bits(x) __builtin_popcount(x)
#define pb push_back
#define mp make_pair
#define F first
#define S second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int MAXN = 112;

struct ponto{
	int x,y,z;
	
	ponto(int a, int b, int c){
		x = a;
		y = b;
		z = c;
	};
	
	ponto(){};
};

ponto cross(ponto a, ponto b){
	ponto ret;
	
	ret.x = (a.y*b.z) - (b.y*a.z);
	ret.y = (a.z*b.x) - (b.z*a.x);
	ret.z = (a.x*b.y) - (b.x*a.y);
	
	return ret;
}

bool nulo(ponto p){
	return (p.x==0 && p.y==0 && p.z==0);
}

ponto ps[MAXN];

int dot(ponto normal, ponto p){
	return (normal.x*p.x + normal.y*p.y + normal.z*p.z);
}

int main(){
	int n; cin >> n;
	
	for(int i=0; i<n; i++){
		int x,y,z;
		cin >> x >> y >> z;
		ps[i] = ponto(x,y,z);
	}
	
	int resp = min(3,n);
	
	//se tem menos de tres pontos
	if(n < 4){
		cout << resp << "\n";
		return 0;
	}
	
	//pega todas as combinacoes de tres pontos
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(i==j) continue;
			for(int k=0; k<n; k++){
				if(k==i || k==j) continue;
				
				ponto p1 = ponto(ps[j].x-ps[i].x, ps[j].y-ps[i].y, ps[j].z-ps[i].z);
				ponto p2 = ponto(ps[k].x-ps[i].x, ps[k].y-ps[i].y, ps[k].z-ps[i].z);
				
				int atual = 3;
				ponto s = cross(p1,p2);

				dbn(i);
				dbn(j);
				dbn(k);
				dbn(s.x);
				dbn(s.y);
				dbn(s.z);
				//se o vetor normal for nulo, entao os tres pontos sao colineares
				if(s.x == 0 && s.y == 0 && s.z == 0){
					//p1 nulo p2 nulo
					//p1 n nulo p2 nulo
					//p1 nulo p2 n nulo
					//p1 n nulo p2 n nulo

					dbc("caso1");
					for(int l=0; l<n; l++){
						if(l==k || l==i || l==j) continue;			
						ponto g = ponto(ps[l].x-ps[i].x, ps[l].y-ps[i].y, ps[l].z-ps[i].z);
						ponto t = cross(p1,g);

						//se o vetor normal for nulo e p1 n for nulo, entao o quarto ponto ta colinear tbm
						if(nulo(t) && !nulo(p1)) atual ++;
						
						if(nulo(t) && nulo(p1) && nulo(p2)) atual++;
					}
					atual++;
				}

				//se nao, sao nao-colineares
				else {
					dbc("caso2");
					for(int l=0; l<n; l++){
						if(l==k || l==i || l==j) continue;
						ponto g = ponto(ps[l].x-ps[i].x, ps[l].y-ps[i].y, ps[l].z-ps[i].z);
						//se o quarto ponto tá no plano
						dbn(l);
					 	dbn(dot(cross(p1,p2), g));
					 	if(dot(cross(p1,p2), g) == 0){
							atual ++;
						}
					}
				}

				dbn(atual);
				dbc("");
				resp = max(resp, atual);
			}						
		}
	}
	resp = min(resp,n);
	cout << resp << "\n";
	
	return 0;
}
