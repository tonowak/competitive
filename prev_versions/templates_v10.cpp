#include <bits/stdc++.h>
using namespace std;
using L = long long;

// wtedy, gdy mam przynajmniej 5 for'ów w kodzie:
#define FOR(i, l, r) for(int i = l; i <= r; ++i)
#define REP(i, n) FOR(i, 0, n - 1)

template<class T> int size(T &x) { // wtedy, gdy przynajmniej 2x użyję int(vec.size())
	return int(x.size());
}
template<class A, class B> ostream& operator<<(ostream &os, pair<A, B> p) { // wtedy, gdy chcę wypisać pary lub mapy
	return os << '(' << p.first << ", " << p.second << ')';
}
template<class T> auto operator<<(ostream &os, T v) -> decltype(v.begin(), os) { // wtedy, gdy chcę wypisać vectory lub inne kontenery
	os << "{ ";
	for(auto &x : v)
		os << x << ' ';
	return os << '}';
}
template<class T> void dump(T v) { // wtedy, gdy chcę wypisać vectory vectorów
#ifdef DEBUG
	cerr << "{\n";
	for(auto it = v.begin(); it != v.end(); ++it)
		cerr << "  " << distance(v.begin(), it) << ": " << *it << '\n';
	cerr << "}\n";
#endif
}

// wtedy, gdy mam przynajmniej 5 cerr'ów w kodzie:
#ifdef DEBUG
# define LOG(a...) cerr << a << '\n';
# define LG(a...) LOG(#a ": " << a)
#else
# define LOG(...)
# define LG(...)
#endif

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	LOG("vec: " << vector<int>{1, 2, 3});
	dump(vector<vector<int>>{
		{1, 2, 3},
		{4, 2},
		{},
		{11, 12, 13}
	});
}
