/* Reminder: Take care when using complex with integer data types, such as 
complex<int> or complex<long long>. Do not use abs() nor polar() with these 
types.*/
typedef complex<double> point;
#define X real
#define Y imag

double dot(const point &a, const point &b) { return real(conj(a) * b); }
double cross(const point &a, const point &b) { return imag(conj(a) * b); }

bool ccw (point a, point b, point c) { return cross((b-a),(c-a)) > 0; }

point a(3, 2), b(2, -7);
cout << a + b << endl;   // (5,-5)
cout << a - b << endl;   // (1,9)
cout << 3.0 * a << endl; // (9,6)
cout << a / 5.0 << endl; // (0.6,0.4)

point c = 2;
point d(3, 7);
cout << c << ' ' << d << endl; // (2, 0) (3, 7)

//Length
abs(point p);
/*Squared length (caution: 'norm' might be misleading here, because 'norm' in 
linear algebra means vector's length) */
norm(point p);
//Euclidean distance
abs(a - b);  //or abs(b - a)
//Squared distance
norm(a - b); //or norm(b - a)
//Angle of elevation
arg(b - a);  //attention: arg(b - a) != arg(a - b)
//Slope of line (a, b)
tan(arg(b - a));
//Polar to cartesian
polar(r, theta);
//Cartesian to polar
point(abs(p), arg(p));
//Rotation
point rotate_by(const point &p, const point &about, double radians) { 
    return (p - about) * exp(point(0, radians)) + about; 
	//or return (p - about) * polar(1.0, radians) + about;
}
//Angle ABC
abs(remainder(arg(a-b) - arg(c-b), 2.0 * PI));












inline int cmp(double x, double y = 0, double tol = eps) {
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

struct point {
	double x, y;
	point(double x = 0, double y = 0): x(x), y(y) {}
	point operator +(point q) { return point(x + q.x, y + q.y); }
	point operator -(point q) { return point(x - q.x, y - q.y); }
	point operator *(double t) { return point(x * t, y * t); }
	point operator /(double t) { return point(x / t, y / t); }
	double operator *(point q) {return x * q.x + y * q.y;}//a*b = |a||b|cos(ang)
	double operator %(point q) {return x * q.y - y * q.x;}//a%b = |a||b|sin(ang)
	double polar() { return ((y > -eps) ? atan2(y,x) : 2*Pi + atan2(y,x)); }
	double mod() { return sqrt(x * x + y * y); }
	double mod2() { return (x * x + y * y); }
	point rotate(double t) {return point(x*cos(t)-y*sin(t), x*sin(t)+y*cos(t));}
	int cmp(point q) const {
		if (int t = ::cmp(x, q.x)) return t;
		return ::cmp(y, q.y);
	}
	bool operator ==(point q) const { return cmp(q) == 0; }
	bool operator !=(point q) const { return cmp(q) != 0; }
	bool operator < (point q) const { return cmp(q) < 0; }
	static point pivot;
};
point point::pivot;
typedef vector<point> polygon;

double abs(point p) { return hypot(p.x, p.y); }
double arg(point p) { return atan2(p.y, p.x); }
inline int ccw(point p, point q, point r) {
	return cmp((p - r) % (q - r));
}
//Projeta o vetor v sobre o vetor u (cuidado precisao)
point proj(point v, point u) {
	return u*((u*v) / (u*u));
}
//\angle(p,q,r)| e o menor angulo entre os vetores u(p-q) e v(r-q)
// p->q->r virar pra esquerda => angle(p,q,r) < 0
inline double angle(point p, point q, point r) {
	point u = p - q, v = r - q;
	return atan2(u % v, u * v);
}
//Decide se q esta sobre o segmento fechado pr.
bool between(point p, point q, point r) {
	return ccw(p, q, r) == 0 && cmp((p - q) * (r - q)) <= 0;
}
//Decide se os segmentos fechados pq e rs tem pontos em comum
bool seg_intersect(point p, point q, point r, point s) {
	point A = q - p, B = s - r, C = r - p, D = s - q;
	int a = cmp(A % C) + 2 * cmp(A % D);
	int b = cmp(B % C) + 2 * cmp(B % D);
	if (a == 3 || a == -3 || b == 3 || b == -3) return false;
	if (a || b || p == r || p == s || q == r || q == s) return true;
	int t = (p < r) + (p < s) + (q < r) + (q < s);
	return t != 0 && t != 4;
}
// Calcula a distancia do ponto r ao segmento pq.
double seg_distance(point p, point q, point r) {
	point A = r - q, B = r - p, C = q - p;
	double a = A * A, b = B * B, c = C * C;
	if (cmp(b, a + c) >= 0) return sqrt(a);
	else if (cmp(a, b + c) >= 0) return sqrt(b);
	else return fabs(A % B) / sqrt(c);
}
// Classifica o ponto p em relacao ao poligono T.
// Retorna 0, -1 ou 1 dependendo se p esta no exterior, na fronteira
// ou no interior de T, respectivamente.
int in_poly(point p, polygon& T) {
	double a = 0; int N = T.size();
	for (int i = 0; i < N; i++) {
		if (between(T[i], p, T[(i+1) % N])) return -1;
		a += angle(T[i], p, T[(i+1) % N]);
	}
	return cmp(a) != 0;
}
//Encontra o ponto de intersecao das retas pq e rs.
point line_intersect(point p, point q, point r, point s) {
	point a = q - p, b = s - r, c = point(p % q, r % s);
	return point(point(a.x, b.x) % c, point(a.y, b.y) % c) / (a % b);
}

// Calcula a area orientada do poligono T.
// Se o poligono P estiver em setido anti-horario, poly_area(P) > 0,
// e <0 caso contrario
double poly_area(polygon& T) {
	double s = 0; int n = T.size();
	for (int i = 0; i < n; i++)
		s += T[i] % T[(i+1) % n];
	return s / 2;
}


//Calcula o incentro de um triangulo
point incenter(point p, point q, point r) {
	double a = (p-q).mod(), b = (p-r).mod(), c = (q-r).mod();
	return (r*a + q*b + p*c) / (a + b + c);
}

//Centro de massa de um poligono
point centro_massa(polygon p) {
	double x=0., y=0., area = poly_area(p);
	p.push_back(p[0]);
	for (int i = 0; i < p.size()-1; i++) {
		x += (p[i].x + p[i+1].x) * (p[i] % p[i+1]);
		y += (p[i].y + p[i+1].y) * (p[i] % p[i+1]);
	}
	return point(x/(6*area), y/(6*area));
}

// Determina o poligono intersecao dos dois poligonos convexos P e Q.
// Tanto P quanto Q devem estar orientados positivamente.(anti-horario)
// calcular complexidade
polygon poly_intersect(polygon& P, polygon& Q) {
	int m = Q.size(), n = P.size();
	int a = 0, b = 0, aa = 0, ba = 0, inflag = 0;
	polygon R;
	while ((aa < n || ba < m) && aa < 2*n && ba < 2*m) {
		point p1 = P[a], p2 = P[(a+1) % n], q1 = Q[b], q2 = Q[(b+1) % m];
		point A = p2 - p1, B = q2 - q1;
		int cross = cmp(A % B), ha = ccw(p2, q2, p1), hb = ccw(q2, p2, q1);
		if (cross == 0 && ccw(p1, q1, p2) == 0 && cmp(A * B) < 0) {
			if (between(p1, q1, p2)) R.push_back(q1);
			if (between(p1, q2, p2)) R.push_back(q2);
			if (between(q1, p1, q2)) R.push_back(p1);
			if (between(q1, p2, q2)) R.push_back(p2);
			if (R.size() < 2) return polygon();
			inflag = 1; break;
		} else if (cross != 0 && seg_intersect(p1, p2, q1, q2)) {
			if (inflag == 0) aa = ba = 0;
			R.push_back(line_intersect(p1, p2, q1, q2));
			inflag = (hb > 0) ? 1 : -1;
		}
		if (cross == 0 && hb < 0 && ha < 0) return R;
		bool t = cross == 0 && hb == 0 && ha == 0;
		if (t ? (inflag == 1) : (cross >= 0) ? (ha <= 0) : (hb > 0)) {
			if (inflag == -1) R.push_back(q2);
			ba++; b++; b %= m;
		} else {
			if (inflag == 1) R.push_back(p2);
			aa++; a++; a %= n;
		}
	}
	if (inflag == 0) {
		if (in_poly(P[0], Q)) return P;
		if (in_poly(Q[0], P)) return Q;
	}
	R.erase(unique(all(R)), R.end());
	if (R.size() > 1 && R.front() == R.back()) R.pop_back();
	return R;
}




//Polygon-Line intersection
//retorna tds trechos da reta que passa por s(s.a != s.b) coberta
//por p(simple polygon)
//tempo:O(n log n), memoria: O(n), onde n = p.size() TODO testar
vector <segment> cobertura(segment s, polygon p) {
	if (cmp(poly_area(p)) < 0) reverse(all(p)); //p deve esta no sentido anti-hr
	int n = (int)p.size();
	polygon q;
	p.pb(p[0]), p.pb(p[1]), p.pb(p[2]);
	for (int i = 1; i <= n; i++) {
		point u = p[i], v = p[i+1];
		int d0 = ccw(s.a,s.b,p[i-1]), d1 = ccw(s.a,s.b,p[i]);
		int d2 = ccw(s.a,s.b,p[i+1]), d3 = ccw(s.a,s.b,p[i+2]);
		if (d1 == d2) continue;
		if (d1 * d2 == -1)
			q.pb(line_intersect(s.a, s.b, u, v));
		else if (d1 == 0 && (d0*d2 == -1 || ccw(p[i-1], p[i], p[i+1]) > 0))
			q.pb(line_intersect(s.a, s.b, u, v));
		else if (d2 == 0 && ccw(p[i], p[i+1], p[i+2]) > 0 && d1*d3 >= 0)
			q.pb(line_intersect(s.a, s.b, u, v));
	}
	sort(all(q));
	vector <segment> seg;
	for (int i = 0; i < q.size(); i += 2) seg.pb( segment(q[i], q[i+1]));
	return seg;
}






//Polygon triangulation
#define N_VERTEX 10000
int orelha[N_VERTEX], prox[N_VERTEX], prev[N_VERTEX];
// verifica se p[prev[id]~p[id]~p[prox[id]] forma uma orelha p
bool eh_orelha(polygon &p, int id) {
	int n = p.size();
	point a = p[prev[id]], b = p[prox[id]];
	if (ccw(a, p[id], b) <= 0) return false;
	for (int i = 0; i < n; i++) {
		int j = ((i+1<n)?(i+1):(i+1-n)); //j = (i+1)%n
		if (i == prev[id] || i == prox[id] ||
		j == prev[id] || j == prox[id]) continue;
		if (seg_intersect(p[i], p[j], a, b))
			return false;
	}
	return true;
}
//Complexidade O(n^2)
//assume q o poligono eh simples com 3 ou mais vertices, sem pontos repetidos
void triangulacao(polygon &p) {
	int n = p.size(), id = 0;
	if (cmp(poly_area(p)) < 0) reverse(all(p)); //deixa p no sentido anti-hor
	for (int i = 0; i < n; i++) {
		prev[i] = ((i==0)?(n-1):(i-1));
		prox[i] = ((i+1<n)?(i+1):(i+1-n));
		orelha[i] = eh_orelha(p, i);
	}
	while (n > 3) {
		while (!orelha[id]) id = prox[id];
		//triangulo p[id], p[prev[id]], p[prox[id]]
		//diagonal inserida => prev[id] <-> prox[id]
		printf("%2d %2d %2d\n", id, prox[id], prev[id]);
		int ant = prev[id], next = prox[id];
		prox[ant] = next;
		prev[next] = ant;
		orelha[ant] = eh_orelha(p, ant);
		orelha[next] = eh_orelha(p, next);
		n--;
		id = prox[id];
	}
	//triangulo p[id], p[prox[id]], p[prox[prox[id]]]
	printf("%2d %2d %2d\n", id, prox[id], prox[prox[id]]);
}




//Closest Pair
#define inf 1e20
#define N_PTS 300010
#define LOG_PTS 25
point X[N_PTS], Y[N_PTS], Yrl[LOG_PTS][N_PTS];
inline bool cmpy(const point &a, const point &b) {
	return (cmp(a.y,b.y) < 0 || (cmp(a.y,b.y) == 0 && cmp(a.x,b.x) < 0));
}
//Retorna o quadrado da menor distancia
inline double divide_conquer(int n, int cont, point X[], point Y[]) {
	if (n <= 1) return inf;
	if (n == 2) return (X[0]-X[1]).mod2();
	int left = n/2; int right = n-left;
	int l = 0, r = left;
	point mid = (X[left-1] + X[left])/2;
	for (int i = 0; i < n; i++) {
		if (Y[i] < mid) Yrl[cont][l++] = Y[i];
		else Yrl[cont][r++] = Y[i];
	}
	double resp = inf;
	resp = min(resp, divide_conquer(left, cont+1, X, Yrl[cont]));
	resp = min(resp, divide_conquer(right, cont+1, X+left, Yrl[cont]+left));
	for (int i = 0; i < n; i++) {
		if (cmp(abs(Y[i].x-mid.x), resp) > 0) continue;
		for (int j = max(0, i-8); j < i; j++)
		resp = min(resp, (Y[i]-Y[j]).mod2());
	}
	return resp;
}
double closest_pair(vector <point> &p) {
	for (int i = p.size()-1; i >= 0; i--) X[i] = Y[i] = p[i];
	sort(X, X+p.size());
	sort(Y, Y+p.size(), cmpy);
	return sqrt(divide_conquer(p.size(), 0, &X[0], &Y[0]));
}



//Crosses Half-plane
// Retorna a interseccao de um poligono simples com um semiplano
// TODO cuidado qdo o poligono nao for convexo
// sumpoem q o semiplano eh o lado esquerdo, indo de p1 para p2
// p pode estar em qlqr direcao( poligono de retorno esta no msm sentido que p)
polygon halfplane(polygon& p, line& semiplano) {
	polygon q;
	point p1 = semiplano.first, p2 = semiplano.second;
	// Sequencia poligono convexo exaustiva, para determinar se o semiplano.
	int n = p.size();
	for (int i = 0; i < n; i++) {
		double c = (p2-p1) % (p[i]-p1);
		double d = (p2-p1) % (p[(i+1)%n]-p1);
		if (cmp(c) >= 0) q.push_back(p[i]);
		if (cmp(c * d) < 0)
		q.push_back(line_intersect(p1, p2, p[i], p[(i+1)%n]));
	}
	return q;
}



struct circle {
	point c; double r;
	circle(point c = point(0,0), double r=0.0):c(c), r(r) {}
	bool inside(point &e) { return cmp((e-c).mod(), r) <= 0; }
};



//assume que ha pelo menos 1 ponto de interseccao
//cuidado com circulos iguais, sem intersecao (um dentro do outro)
pair<point, point> interseccao(circle a, circle b) {
	if (cmp(a.r, b.r) < 0) swap(a, b);
	double R = a.r, r = b.r, d = (b.c-a.c).mod();
	double x1 = (R*R - r*r + d*d) / (2*d);
	double h = 0.0;
	if (cmp(R*R - x1*x1) > 0) h = sqrt(R*R - x1*x1);
	point v = ((b.c-a.c)/d) * R;
	return mp(a.c + v.rotate(h/R, x1/R), a.c + v.rotate(-h/R, x1/R));
}




void increment(double ini, double fim, double &Area, double &Perim, circle &q) {
	double teta = (cmp(fim,ini)>=0) ? (2*Pi-fim+ini) : (ini-fim);
	Perim += teta * q.r;
	Area += 0.5*teta*quad(q.r) - 0.5*sin(teta)*quad(q.r);
	point a = (point(cos(fim), sin(fim)) * q.r) + q.c;
	point b = (point(cos(ini), sin(ini)) * q.r) + q.c;
	Area += 0.5*(a % b);
}
//Calcula a area e o perimetro em O(n^2*logn)
//Consome memoria O(n)
double area_uniao_circle(vector <circle> &T) {
	vector <circle> p;
	vector < pair<double, double> > seg;
	point e, a, b;
	double Area = 0, Perim = 0, teta, ini, fim;
	//remove circles repitidos, com area nula, ou circle dentro de outro circle
	f (i, 0, T.size()) {
		bool check = cmp(T[i].r) > 0;
		for (int j = 0; j < T.size() && check; j++) {
			if (T[i]==T[j]) check = (i>=j);
			else if (cmp((T[i].c-T[j].c).mod()+T[i].r, T[j].r) <= 0)
			check = false;
		}
		if (check) p.pb(T[i]);
	}
	for (int i = 0; i < p.size(); i++) {
		seg.clear();
		for (int j = 0; j < p.size(); j++) if (i != j) {
			//p[i] e p[j] nao tem 2 pontos em comum
			if ((p[i].c-p[j].c).mod() > p[i].r + p[j].r -eps) continue;
			pair <point, point> inter = interseccao2(p[i], p[j]);
			teta = angle(inter.first, p[i].c, inter.second);
			if (teta > eps) {
				e = (inter.first - p[i].c).rotate(teta/2) + p[i].c;
				if (p[j].inside(e) == false) swap( inter.first, inter.second);
			} else {
				e = (inter.first - p[i].c).rotate((2*Pi+teta)/2) + p[i].c;
				if (p[j].inside(e) == false) swap( inter.first, inter.second);
			}
			ini = (inter.first - p[i].c).polar();
			fim = (inter.second - p[i].c).polar();
			a = (point(cos(ini), sin(ini)) * p[i].r) + p[i].c;
			b = (point(cos(fim), sin(fim)) * p[i].r) + p[i].c;
			if (ini > fim) {
				seg.pb( mp(ini, 2*Pi));
				seg.pb( mp(0, fim));
			}
			else seg.pb( mp(ini, fim));
		}
		sort(all(seg));
		if ((int) seg.size() == 0) {
			Perim += 2*Pi*p[i].r;
			Area += Pi*quad(p[i].r);
			continue;
		}
		fim = seg[0].second;
		for (int j = 1; j < seg.size(); j++) {
			if (cmp(fim, seg[j].first) < 0) {
				increment(seg[j].first, fim, Area, Perim, p[i]);
			}
			fim = max(fim, seg[j].second);
		}
		increment(seg[0].first, fim, Area, Perim, p[i]);
	}
	return Area;
}