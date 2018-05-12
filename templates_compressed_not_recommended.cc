#include <bits/stdc++.h> // Tomasz Nowak
using namespace std;     // XIII LO Szczecin
#define FOR(i,a,n) for (auto i = (a), i##__ = (n); i <= i##__; ++i)
#define REP(i,n) FOR(i,0,(n)-1)
#define FORD(i,a,n) for (auto i = (a), i##__ = (n); i >= i##__; --i)
#define REPD(i,n) FORD(i,(n)-1,0)
#define ALL(x) x.begin(), x.end()
#define SZ(x) ((int) x.size())
#define X first
#define Y second
#define V vector
#define A array
constexpr char nl = '\n';
template<class A, class B> A&& mini(A &&a, B &&b) { if (b < a) a = b; return a; }
template<class A, class B> A&& maxi(A &&a, B &&b) { if (b > a) a = b; return a; }
int first_bit(int x) { return x == 0 ? 0 : sizeof(x) * 8 - __builtin_clz(x); }
int ceil2(int x) { return x < 2 ? x : 1 << first_bit(x - 1); }
#define _enable_if(a...) typename enable_if<a, int>::type()
#define _func(func, a...) template<class T> auto func(T &&x) -> decltype(a)
template<class Iter> struct Off { Iter _a, _b; };
#define _create_trait(name, a...) _func(_##name, a, true_type{});  false_type _##name(...); \
	template<class T> struct name : decltype(_##name(declval<T>())) {};
_create_trait(is_string, string(x))  _create_trait(is_container, x.begin(), _enable_if(is_string<T>() == false))
_create_trait(is_func, x())
struct Debug;  _create_trait(is_debug_func, x(declval<add_lvalue_reference<Debug>::type>()));
_create_trait(is_point, *x, _enable_if(is_string<T>() == false));
_func(O, _enable_if(is_container<T>() == true), Off<decltype(x.begin())>()) { return { ALL(x) }; }
_func(O, _enable_if(is_container<T>() == false), x) { return x; }
#define _operator(a...) _func(operator<<, a, *this)
struct Debug {
	~Debug() { cerr << nl; }
	Debug& operator()(int x = 1) { REP(_, x) *this << "  "; return *this; }
	_operator(cerr << x, _enable_if(is_func<T>() == false && is_point<T>() == false)) { cerr << O(x); return *this; }
	_operator(_enable_if(is_container<T>() == true)) {
		*this <<  "{\n";
		for (auto a = x.begin(); a != x.end(); ++a)
			*this << "  " << distance(x.begin(), a) << ": " << O(*a) << '\n';
		return *this << "}";
	}
	_operator(x.first) { return *this << "(" << O(x.first) << ", " << O(x.second) << ")"; }
	_operator(x._a) {
		*this << "{";
		for (auto a = x._a, b = x._b; a != b; ++a)
			*this << O(*a) << (next(a) == b ? "" : ", ");
		return *this << "}";
	}
	_operator(_enable_if(is_func<T>() == true)) { x(); return *this; }
	_operator(_enable_if(is_debug_func<T>() == true)) { x(*this); return *this; }
	_operator(_enable_if(is_point<T>() == true && is_func<T>() == false && is_debug_func<T>() == false)) { return *this << *x; }
};
struct DebugOff { 
	template<class T> DebugOff& operator<<(T&&) { return *this; }
	DebugOff& operator()(int = 0) { return *this; }
};
#ifdef DEBUG
# define D Debug()
#else
# define D DebugOff()
#endif
#define I(a...) #a ": " << a << "   "
using VI	= V<int>;
using VVI	= V<VI>;
using LL	= long long;
using VL	= V<LL>;
using II	= pair<int, int>;
using VVII	= V<PII>;
using VVII 	= V<VPII>;
using VB	= V<bool>;
// End of templates v8 by Tomasz Nowak
