#include <bits/stdc++.h> // Tomasz Nowak
using namespace std;     // XIII LO Szczecin

#define FOR(i, a, n) for (auto i = (a), i##__ = (n); i <= i##__; ++i)
#define REP(i, n) FOR(i, 0, (n) - 1)
#define FORD(i, a, n) for (auto i = (a), i##__ = (n); i >= i##__; --i)
#define REPD(i, n) FORD(i, (n) - 1, 0)
#define ALL(x) x.begin(), x.end()
#define SZ(x) int(x.size())
#define X first
#define Y second
#define V vector
#define A array
constexpr char nl = '\n';

template<class A, class B> A& mini(A &a, B &&b) { if (b < a) a = b; return a; }
template<class A, class B> A& maxi(A &a, B &&b) { if (b > a) a = b; return a; }
int first_bit(int x) { return x == 0 ? 0 : sizeof(x) * 8 - __builtin_clz(x); }
int ceil2(int x) { return x < 2 ? x : 1 << first_bit(x - 1); }

template<class A, class B> ostream& operator<<(ostream &os, pair<A, B> &x);
template<class T> auto operator<<(ostream &os, T &&x) -> decltype(x.begin(), os) {
	os << '{';
	for(auto a = x.begin(); a != x.end(); ++a)
		os << *a << (a == prev(x.end()) ? "" : " ");
	return os << '}';
}
template<class T> void _dump(T &&x) {
	cerr << "{\n";
	for(auto a = x.begin(); a != x.end(); ++a)
		cerr << "  " << distance(x.begin(), a) << ": " << *a << nl;
	cerr << '}';
}
template<class A, class B> ostream& operator<<(ostream &os, pair<A, B> &x) {
	return os << '(' << x.X << ", " << x.Y << ')';
}

#ifdef DEBUG
# define DD(a...) a
#else
# define DD(a...)
#endif
#define LG(a...) DD(cerr << #a ": " << a << "  ");
#define LN(a...) DD(cerr << #a ": " << a << nl);
#define D(a...) DD(cerr << #a ": ", _dump(a), cerr << nl);

using VI    = V<int>;
using VVI   = V<VI>;
using L     = long long;
using VL    = V<L>;
using VB    = V<bool>;
using II    = pair<int, int>;
using VII   = V<II>;
using VVII  = V<VII>;

// end of templates v9 ('mini' version) by Tomasz Nowak

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int i = -123;
	II p = {6, 9};
	VI v = {1, 2, 3, 4};
	VVI vv = {
		{1, 2, 3},
		{4, 5},
		{}
	};
	LG(i) LN(p) LG(v) D(vv)
}
