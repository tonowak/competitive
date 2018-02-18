#include <bits/stdc++.h> // Tomasz Nowak
using namespace std;

#define FOR(i,a,n) for (auto i = (a), i##__ = (n); i <= i##__; ++i)
#define REP(i,n) FOR(i,0,(n)-1)
#define FORD(i,a,n) for (auto i = (a), i##__ = (n); i >= i##__; --i)
#define REPD(i,n) FORD(i,(n)-1,0)
#define ALL(x) x.begin(), x.end()
#define EB emplace_back
#define ST first
#define ND second
#define SZ(x) ((int)x.size())
#define RS resize
#define V vector
constexpr char nl = '\n';
template<class T, class B> void mini(T &&a, B &&b) { if (b < a) a = b; }
template<class T, class B> void maxi(T &&a, B &&b) { if (b > a) a = b; }
int pow2(int x) { return x < 2 ? 0 : sizeof(x) * 8 - __builtin_clz(x - 1); }

#define _S(zn, a...) typename enable_if<is_same<a, typename remove_reference<T>::type>::value zn 1, int>::type()
#define _F(func, a...) template<class T> auto func(T &&x) -> decltype(a)
template<class T> struct Off { T __a, __b; };
_F(O, _S(!=, string), Off<decltype(x.begin())>()) { return {x.begin(), x.end()}; }
_F(O, cerr << x, x) { return x; }
_F(O, x.first, x) { return x; }
#define _OP(a...) _F(operator<<, a, *this)
#define RTH return *this
struct Debug {
	~Debug() { cerr << nl; }
	Debug& operator()(int x = 0) { REP(a, x+1) cout << "  "; RTH; }
	_OP(cerr << x) { cerr << O(x); RTH; }
	_OP(x.begin(), _S(!=, string)) {
		cerr <<  "{\n";
		for (auto a = x.begin(); a != x.end(); ++a)
	*this << "  " << distance(x.begin(), a) << ": " << O(*a) << '\n';
		RTH << "}";
	}
	_OP(x.first) { RTH << "(" << O(x.first) << ", " << O(x.second) << ")"; }
	_OP(x.__a) {
		cerr << "{";
		for (auto a = x.__a, b = x.__b; a != b; ++a)
	*this << O(*a) << (next(a) == b ? "" : ", ");
		RTH << "}";
	}
};
struct DebugOff { 
	template<class T> DebugOff& operator<<(T&&) { RTH; }
	DebugOff& operator()(int = 0) { RTH; }
};
#ifdef DEBUG
# define D Debug()
# define DD(a...) a
#else
# define D DebugOff()
# define DD(...)
#endif
#define I(a...) #a ": " << a << "   "
#define TD(C, a...) _F(O, _S(==, C), x) { return x; } Debug& operator<<(Debug &d, C &x) { a; return d; }

using VI	= V<int>;
using VVI	= V<VI>;
using LL	= long long;
using VLL	= V<LL>;
using PII	= pair<int, int>;
using VPII  = V<PII>;
using VVPII = V<VPII>;
using VB	= V<bool>;

//end of templates v7

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	
}
