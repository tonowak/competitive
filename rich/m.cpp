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
constexpr int inf = 0x3f3f3f3f; 
constexpr long long inf_l = 0x3f3f3f3f3f3f3f3f;

#define _eif(a...) typename enable_if<a, int>::type()
#define _func(func, a...) template<class T> auto func(T &&x) -> decltype(a)
#define _rref(a...) typename remove_reference<a>::type
#define _create_trait(name, a...) \
    _func(_##name, a, true_type{}); \
    false_type _##name(...); \
    template<class T> struct name : decltype(_##name(declval<T>())) {};
struct Debug;
_create_trait(is_debug_func, x(declval<add_lvalue_reference<Debug>::type>()));
_create_trait(is_func, x())
_create_trait(is_string, string(x))
_create_trait(is_ptr, *x, _eif(is_string<T>() == false));
_create_trait(is_container, x.begin(), _eif(is_string<T>() == false))

template<class Iter> struct Off { Iter _a, _b; };
_func(O, _eif(is_container<T>() == true), Off<decltype(x.begin())>()) { return { ALL(x) }; }
_func(O, _eif(is_container<T>() == false), x) { return x; }

#define _operator(a...) _func(operator<<, a, *this)
struct Debug {
    Debug() {  cerr << boolalpha; }
    ~Debug() { cerr << nl; }
    Debug& operator()(int x = 1) { REP(_, x) *this << "  "; return *this; }
    _operator(cerr << x, _eif(is_func<T>() == false && is_ptr<T>() == false && is_integral<_rref(T)>() == true)) { 
        using L = long long;
        if(abs(int(x)) == inf || abs(L(x)) == inf_l)
            cerr << ((int(x) == inf || L(x) == inf_l) ? "+∞" : (int(x) == -inf || L(x) == -inf_l) ? "-∞" : "?");
        else
            cerr << x;
        return *this; 
    }
    _operator(cerr << x, _eif(is_func<T>() == false && is_ptr<T>() == false && is_integral<_rref(T)>() == false)) {
        cerr << x;
        return *this;
    }
    _operator(x.first) { 
        return *this << "(" << O(x.first) << ", " << O(x.second) << ")"; }
    _operator(_eif(is_container<T>() == true)) {
        *this << "{\n";
        for (auto a = x.begin(); a != x.end(); ++a)
            *this << "  " << distance(x.begin(), a) << ": " << O(*a) << '\n';
        return *this << "}";
    }
    _operator(x._a) {
        *this << "{";
        for (auto a = x._a, b = x._b; a != b; ++a)
            *this << O(*a) << (next(a) == b ? "" : ", ");
        return *this << "}";
    }
    _operator(_eif(is_func<T>() == true)) { x(); return *this; }
    _operator(_eif(is_debug_func<T>() == true)) { x(*this); return *this; }
    _operator(_eif(is_ptr<T>() == true && is_func<T>() == false && is_debug_func<T>() == false)) {
        return *this << *x;
    }
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

using VI    = V<int>;
using VVI   = V<VI>;
using L     = long long;
using VL    = V<L>;
using VB    = V<bool>;
using II    = pair<int, int>;
using VII   = V<II>;
using VVII  = V<VII>;

// end of templates v8 by Tomasz Nowak

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

}

