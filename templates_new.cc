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

//////////////////////////////
// PRZEJDŹ OD RAZU DO MAINA //
//////////////////////////////

int licznik = 0;

int zwykla_funkcja() {
    ++licznik;
    return 2 + 2;
}

struct Obiekt_z_operatorem {
    int niepotrzebna_zmienna_xd = 69;
    void operator()() {
        ++licznik;
    }
} obiekt_z_operatorem; // można tak od razu fajnie tworzyć obiekty jakiejś klasy

struct Obiekt_do_wypisania {
    int fajna_zmienna = 42;
    void operator()(Debug &d) {
        d << "[(<" << fajna_zmienna << ">)].";
    }
} obiekt_do_wypisania;

void funkcja_wypisujaca(Debug &d) {
    d << "hohoho.";
}

auto zwykla_lambda = [] {
    return ceil2(49); // ceil2(x) zwraca najmniejszą potęgę dwójki >= x. Dobre przy ustawianiu liczby liści/wierzchołków w drzewie
}; // w porównaniu do pow2(x) co było w poprzednich wersjach, zwraca >= x, a nie > x

auto lambda_wypisujaca = [](Debug &d) {
    d << "pozycja najbardziej na prawo/najważniejszego bitu liczby 49 (110001) = " << first_bit(49) << '!';
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int int4 = 4;
    double double314 = 3.14;
    D << int4;
    D << int4 << " jest równe " << ceil(double314);
    D << "Tak jak widać, automatycznie wstawia nl (endl).";

    string str = "Wypisywanie stringów jako zmienne też działa jbc xd.";
    D << str;

    int &int_ref = int4, *int_pointer = &int4;
    D << int4 << " " << int_ref << " " << int_pointer << " (nie tylko działa dla pointerów, działa też dla iteratorów, które są w pewnym sensie pointerami).";

    vector<int> vec_int = { 3, 4, 5 };
    D << nl << "Sposób stworzenia tego vectora nazywa się 'lista inicjalizacją'/'initializer list', a zawartość vectora = " << vec_int;

    vector< vector<int> > vec_vec_int = {
        {1, 2, 3},
        {4, 5},
        {},
        {6, 7, 8, 9}
    };
    D << "Wypisanie vectora vectorów jest jeszcze fajniejsze: " << vec_vec_int;

    D << "Tak jak widać, debug jest sprytny, bo te wewnętrzne vectory wypisuje w zwięzłej, jednolinijkowej postaci.";
    D << "Można otrzymać taki efekt dla zwykłego vectora, gdy się wypisze vector poprzez funkcję O, czyli O(vec_int): " << O(vec_int);
    D << "Wypisanie >2-wymiarowych kontenerów też działa ok, ale nie jest jakoś bardzo ładne (bo zresztą jak by to miało wyglądać?).";

    D << nl << "Gdy się ma bardzo duże ilości zmiennych do zdebuggowania, ciężkie jest podpisywanie każdej zmiennej (np. wypisanie D << 'int4: ' << int4).";
    D << "Więc istnieje specjalne narzędzie do tego: funkcja I. Przykład: D << I(int4) wypisuje " << I(int4) << '.';
    D << "Tak jak widać, automatycznie też potem wstawia spacje.";

    D << nl << "Teraz pora przejść do nowości, czyli rzeczy których nie było w poprzednich nagłówkach.";
    D << "Jedną z nich to wypisywanie pointerów, które było widać wcześniej.";
    D << "Inną - wypisywanie funkcji. Dokładniej:" << nl << "- funkcji" << nl << "- obiektów z operator()" << nl << "- lambd.";
    D << "w opisie będę te trzy przypadki po prostu nazywać 'funkcjami' (niepoprawnie, ale tak dla wygody).";

    D << nl << "Debug przyjmuje dwa typy funkcji " << nl << "- bez argumentu" << nl << "- z jednym argumentem, który przyjmuje referencję do obiektu Debug.";
    D << "Jedna oczywiście służy do tego, by wykonać jakieś operacje tylko na swoim kompie, druga - by ułatwić wypisywanie w debugu.";
    D << "Dobrym przykładem jest podczas tworzenia klasy. Często chce się wtedy napisać coś, co debug będzie ją wyświetlać.";
    D << "Można wtedy po prostu napisać void operator()(Debug &d), i korzystać z d zamiast D.";
    D << "Fajne jest to, że można teraz tworzyć klasy wewnątrz klas/funkcji. Po prostu się dopisuje odpowiedni operator() wewnątrz klasy.";
    D << "Daje to oczywiście wtedy wsparcie do wypisywania vectorów z tym obiektem, itd.";

    D << nl << "Przykłady:";
    D << I(zwykla_lambda) << I(zwykla_lambda());
    D << I(zwykla_funkcja) << I(funkcja_wypisujaca) << I(obiekt_z_operatorem) << I(obiekt_do_wypisania) << I(zwykla_lambda) << I(lambda_wypisujaca);
    D << I(licznik);
    D << [&](Debug &d) {
        d << "I takie używanie lambd mi się podoba :P.";
    };

    D << nl << "Wracając do kontenerów - oczywiście działa wypisywanie jakichkolwiek kontenerów z std.";
    D << "Np. vector/array/deque/set/multiset/unordered_set/map/itd. działa, i bez problemu można tworzyć kontenery kontenerów, itd.";
    D << "Oczywiście, jest też wsparcie dla std::pair. Wypisywanie kontenerów par czy pary kontenerów też działa bezproblemowo:";
    D << pair<double, vector<int> >(double314, vec_int);

    D << nl << "Czasem, przy debuggowaniu BST/drzew przedział-przedział, często się przydaje wypisanie pewną ilość spacji przed wiadomością.";
    D << "Oczywiście, Debug też to ma, a dokładniej w formie operator()(int = 1). Wypisuje tyle dwuspacji, ile wysłano do operator() (licząc od 1).";
    D << "a";
    D() << "b";
    D(0) << "c";
    D(1) << "d";
    D(2) << "e";
    D(3) << "f";

    D << nl << "Podsumowując, Debug potrafi wypisać:";
    D << "- wszelkie obiekty dostępne w c++, oraz obiekty z std, jak np. bitset, string, complex.";
    D << "- referencje do obiektów oraz pointery do obiektów.";
    D << "- kontenery z std (rozszerzona & zwięzła postać wypisania).";
    D << "- pary.";
    D << "- funkcje/lambdy/obiekty z operator() bez argumentów, oraz z argumentem Debug& (tak jakby funkcje debuggowe).";
    D << "- pewną liczbę dwuspacji przed wiadomościami dla wygody.";
    D << "- 'podpisywać' zmienne za pomocą funkcji I().";

    D << nl << "Kwestie techniczne:";
    D << "Debug korzysta z flagi -DDEBUG by go włączyć. Gdy nie będzie tej flagi, Debug nic nie wypisze, ani nie odpali żadnej funkcji.";
    D << "Będzie w skrócie sie zachowywał tak, jakby go nie było - tzn, można zostawić linie z debugiem, zostaną one po prostu zignorowane przez kompilator, nic nie spowolnią.";
    D << "Debug wypisuje wszystko do stderr. Da się prosto wyłączyć debuga (nie wyłączając flagi) przekierowując stderr do np. /dev/null: czyli ./m 2>/dev/null.";

    D << nl << "Poza Debugiem, jest FOR, FORD, REP, REPD, definy dla par (X, Y), dla szybkiego tworzenia kontenerów (V dla vector, A dla array).";
    D << "Zamiast endl należy używać nl (także dla cout).";
    D << "Istnieje trochę ułatwiaczy życia - PII, L, VI, VVI, itd, - czyli skrócone nazwy pewnych typów danych.";
    D << "Użycie first_bit oraz ceil2 widać w funkcjach (pow2 już nie istnieje w tej wersji debugu).";
    D << "Funkcje maxi/mini(a, b) robią a = max/min(a, b). Działa też, gdy a nie jest lvalue - wtedy po prostu zwraca maksa.";
    D << "Można też użyć po prostu D; do zrobienia newlina.";
    D << "inf wynosi 1061109567 (trochę większe od 1e9). Można spokojnie pomnożyć inf przez 2 i dodać jeszcze 25264512 (>2e7) i nie przekroczy inta.";
    D << "Podobnie inf_l wynosi lekko ponad 4.5e18, a limit long longa = 2^63-1, czyli lekko ponad 9.2e18.";
    D << "Dodatkowo, jak Debug spotka przy wypisywaniu jakiegoś inf, to wypisze zamiast tego odpowiednio znaki +∞ lub -∞ (nie sprawdzone czy działa na Windowsie):";
    D << I(inf) << I(-inf) << I(inf_l) << I(-inf_l);

    cout << licznik << nl;
    D << nl << "Tomasz Nowak, 13.05.2018";
}
