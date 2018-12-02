# competitive

Moje rzeczy związane z competitive programming: nagłówki, techniki, skrypty

## Instalacja skryptów do kodzenia (src)

Wymagane jest clang++ oraz zsh (być może też oh-my-zsh, wszystko jest na szkolnych kompach). Tworzy folder ~/src (zrób kopię zapasową tego folderu przed instalacją). Jednolinijkowiec:

```
wget -O - https://raw.githubusercontent.com/tonowak/competitive/master/install.sh | zsh && source ~/src/aliases.sh
```

## Wyjaśnienie folderu ~/src

### Komenda task

Komenda task przyjmuje jeden argument (nazwa folderu do stworzenia). Wpisanie `task zad` stworzy folder `~/src/zad` jeżeli jeszcze nie istnieje, przejdzie do niego oraz skopiuje wszystkie pliki z `~/src/template` do tego folderu.

Komenda ma na celu szybkie tworzenie i przechodzenie do nowego folderu do kodzenia zadanka. Gdy zapisanych zadań jest dużo, dobrym pomysłem jest je porozdzielać na foldery (`task oi/zad` stworzy (jak jeszcze nie istnieje) folder zad w folderze ~/src/oi/ (jak folder oi nie istnieje to go też tworzy), a następnie przejdzie do folderu zad). Jeżeli korzystasz z Sublime-Text, kolejnym dobrym pomysłem jest otworzenie folderu ~/src, by mieć pasek z wszystkimi zadaniami i plikami.

Rozkład plików w folderach stworzonych komendą task:
* main.cpp - wzorcówka (domyślnie pliki .cpp zostaną stworzone na podstawie najnowszych nagłówków)
* brute.cpp - brute
* gen.cpp - generatorka (w tym pliku czeka też funkcja rd())
* spr.sh - odpala po kolei testy (pliki .in oraz .out) z folderu tests/ na wzorcówce aż znajdzie WA, a potem wypisuje błędny test
* gen.sh - generuje testy za pomocą generatorki aż out'y wzorcówki i bruta nie będą się zgadzać. Generatorka pobiera argumenty z tests/config.gen i zapisuje wygenerowany test w tests/gen.gen. Out'y wzorcówki i bruta są w tests/main.gen oraz tests/brute.gen
* tests/config.gen - plik konfiguracyjny generatorki. Skrypt gen.sh przekierowuje zawartość tests/config.gen do inputu generatorki
* tests/gen.gen - wygenerowany test przez skrypt gen.sh
* tests/main.gen - wygenerowane wyjście wzorcówki na teście tests/gen.gen
* tests/brute.gen - wygenerowane wyjście bruta na teście tests/gen.gen
* tests/\*.in oraz tests/\*.out - testy dla skryptu spr.sh. Gdy istnieje plik x.in, to musi też istnieć plik x.out. Domyślnie nie ma takich plików w folderze. Można stworzyć dowolną ilość takich plików.

### Kompilacja

Komenda `compile plik -a -b -c...` kompiluje plik.cpp pod nazwą plik z flagami -std=c++11 -a -b -c... Argument plik może mieć lub nie mieć rozszerzenia .cpp. W przypadku błędu kompilacji, error zostanie wyświetlony w specjalnym okienku (komenda less). By wyjść z okienka, wystarczy nacisnąć q. Naciśnięcje g lub G przenosi odpowiednio na górę lub dół okienka. Można się poruszać strzałeczkami (włącznie z vim-owymi).

Komenda `dc plik` kompiluje plik tak jak compile, ale z dodatkowymi flagami do debugu (wszystkie, jakie mogłem wymyśleć). Dodatkowo istnieje komenda `dc_gdb plik` do odpalania dużych inputów dla valgrinda'gdb.

Komenda `nc plik` kompiluje plik tak jak na OIu (O3 i static).

### Skrypty spr.sh oraz gen.sh

Skrypt `gen.sh` generuje testy, aż out'y bruta i wzorcówki będą różne. W przypadku WA, wygenerowane wejście (plik tests/config.gen jest inputem generatorki) zostanie zapisane w tests/gen.gen, oraz outy bruta i wzorcówki w tests/brute.gen i tests/main.gen. Automatycznie te pliki zostaną wyświetlone (w przypadku zbyt dużego rozmiaru pliku, wyświetlanie jest pomijane). Wszelkie komunikaty mają fajne kolorki.

Skrypt `spr.sh` kompiluje `main.cpp` i porównuje out'y wzorcówki z testami w postaci tests/x.in i tests/x.out, gdzie x to nazwa testu. Dodatkowo informuje o czasie wykonania wzorcówki (według oitime'a!) i zużytej pamięci (tylko jak przekroczą pewną minimalną wartość). W przypadku WA, skrypt wypisuje test tak jak w gen.sh oraz zapisuje test w plikach tests/gen.gen, tests/brute.gen, tests/main.gen (odpowiednio: input, oczekiwany output, output wzorcówki). W przypadku RE, skrypt wypisuje numer błędu.

By liczenie czasu tak jak na OI'u działało, niezbędne może się okazać wpisanie komendy `sudo sysctl kernel.perf_event_paranoid=-1`

### Komenda add\_test

Będąc w folderze jakiegoś taska, komenda add\_test stworzy kolejny test (w sensie, jak w tests/ są pliki 1.in oraz 2.in, stworzy 3.in). Poprosi najpierw o wpisanie zawartości pliku .in, potem pliku .out. Przestaje wczytywać zawartość pliku, gdy spotka pustą linię.

### Aliasy

Będąc w folderze zadania, istnieje wiele komend skrótowych:

* dm - kompiluje z flagami do debugu i uruchamia plik main.cpp na teście tests/gen.gen
* db - kompiluje z flagami do debugu i uruchamia plik brute.cpp na teście tests/gen.gen
* dg - kompiluje z flagami do debugu plik gen.cpp
* nm - kompiluje z flagami OI'a i uruchamia plik main.cpp na teście tests/gen.gen
* nb - kompiluje z flagami OI'a i uruchamia plik brute.cpp na teście tests/gen.gen
* ng - kompiluje z flagami OI'a plik gen.cpp
* s - odpala skrypt spr.sh (sprawdzarka wzorcówki na testach tests/\*.in)
* g - odpala skrypt gen.sh (generatorka testów do uwalenia wzorcówki)

Aliasy do edytowania/wyświetlania plików (raczej mało ważne gdy się używa Sublime-Text):

* v - alias na edytor tekstu (domyślnie vim, można zmienić na subl by odpalało w Sublime-Text)
* vm - edytuje plik main.cpp
* vb - edytuje plik gen.cpp
* vg - edytuje plik brute.cpp
* vtg - edytuje plik tests/gen.gen
* vtc - edytuje plik tests/config.gen
* vtm - edytuje plik tests/main.gen
* vtb - edytuje plik tests/brute.gen
* cm - wyświetla plik main.cpp (oraz istnieją analogicznie cb, cg, ctg, ctc, ctm, ctb)

Oraz poprzednie komendy:

* task
* compile
* dc (i dodatkowy dc\_gdb)
* nc
* add\_test

## Nagłówki i inne OI-owe kody

Znajdują się w folderze src/.github/ (prev_versions albo techniques)



