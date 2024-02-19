#include <algorithm>
#include <iostream>
using namespace std;

struct Friend {
  int x, y, id;
};

bool compare(Friend a, Friend b) { return a.x > b.x; }

int main() {
  int n;
  cin >> n;
  Friend ekipa[500];
  for (int i = 0; i < n; i++) {
    cin >> ekipa[i].x;
    ekipa[i].id = i;
  }

  for (int i = 0; i < n; i++) cin >> ekipa[i].y;

  sort(ekipa, ekipa + n, compare);

  int y, j;
  cin >> y >> j;

  int dp[500 + 1][500 + 1];

  for (int i = 0; i <= n; i++) dp[i][0] = 0;
  for (int j = 0; j <= y; j++) dp[0][j] = 0;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= y; j++) {
      if (j >= ekipa[i - 1].y) {
        dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - ekipa[i - 1].y] + ekipa[i - 1].x);
      } else {
        dp[i][j] = dp[i - 1][j];
      }
    }
  }
  cout << dp[n][y] + j;
  return 0;
}

/*
Ovaj zadatak se može riješiti primjenom algoritma za rješavanje problema knapsack (ruksak). Ideja algoritma je da se odluči koja će se pića
ponuditi na rođendanu kako bi se maksimizirala količina popijenog pića, ali u isto vrijeme izbjeglo prekoračenje Y kapaciteta kafića.

Prvo, treba stvoriti listu svih pozvanika i njihovih xi vrijednosti. Zatim treba sortirati listu prema vrijednosti xi u opadajućem redoslijedu.
To se radi kako bi se prvo pozvali oni pozvanici koji će popiti najviše pića.

Sljedeći korak je rješavanje problema knapsack. To se može učiniti primjenom dinamičkog programiranja. Napraviti ćemo tablicu veličine N x Y,
gdje ćemo u i-tom retku i-tog stupca spremiti maksimalnu količinu pića koju možemo ponuditi kada su već pozvani i prijatelji iz liste 
i kada je trenutačni Y kapacitet kafića j. 
Ako je maksimalna količina pića za i prijatelja i Y kapaciteta j jednaka vrijednosti u tablici iz (i-1) redka i stupca (j-yi), 
tada treba dodati piće koje će popiti i-ti prijatelj na trenutačnu količinu pića. Ako je maksimalna količina pića za i prijatelja i Y kapaciteta j jednaka vrijednosti 
u tablici iz (i-1) redka i stupca j, tada ne treba dodati piće koje će popiti i-ti prijatelj na trenutačnu količinu pića.

Kada se tablica popuni, na kraju treba ispisati element iz posljednjeg retka i posljednjeg stupca, što predstavlja maksimalnu količinu pića koja se može ponuditi na rođendanu.

Da, mogu nastaviti s pisanjem koda od mjesta gdje sam stao.

Kako sam već rekao, sljedeći korak je popunjavanje ostalih elemenata tablice. 
To se radi tako da se za svaki redak i stupac pogleda koliko je pića moguće ponuditi na rođendanu ako su već pozvani i prijatelji iz liste i ako je trenutačni Y kapacitet kafića j.

Ako je trenutačni Y kapacitet kafića veći ili jednak y-vrijednosti pridijeljenoj i-tom pozvaniku, tada se maksimalna količina pića koja se može ponuditi na rođendanu računa na sljedeći način:

ako se dodaje piće koje će popiti i-ti pozvanik na trenutačnu količinu pića, maksimalna količina pića na rođendanu će biti jednaka vrijednosti iz (i-1) redka i stupca (j-yi)
plus količina pića koju će popiti i-ti pozvanik.
ako se ne dodaje piće koje će popiti i-ti pozvanik na trenutačnu količinu pića, maksimalna količina pića na rođendanu će biti jednaka vrijednosti iz (i-1) redka i stupca j.
Ako je trenutačni Y kapacitet kafića manji od y-vrijednosti pridijeljenoj i-tom pozvaniku, tada se maksimalna količina pića koja se može ponuditi na rođendanu računa na sljedeći način:

maksimalna količina pića na rođendanu će biti jednaka vrijednosti iz (i-1) redka i stupca j.
Nakon popunjavanja ostalih elemenata tablice, na kraju treba ispisati element iz posljednjeg retka i posljednjeg stupca, što predstavlja maksimalnu količinu pića koja se može ponuditi na rođendanu.


Da bi se riješio ovaj problem, možemo koristiti dinamičko programiranje. Dinamičko programiranje je tehnika koja se koristi za rješavanje problema u kojima se sastoji od mnogih podproblema koji se međusobno povezuju.

U ovom slučaju, problem se sastoji od toga da odredimo koliko će pića biti popijeno na rođendanu. Da bi se to postiglo, moramo odlučiti koje će sve osobe biti pozvane na rođendan i koliko će pića svaka osoba popiti.

Da bi se riješio ovaj problem, možemo koristiti dvije matrice. Prva matrica će nam pomoći da odredimo koliko će pića biti popijeno ako pozovemo određen broj ljudi, a druga matrica će nam pomoći da odredimo koje sve osobe ćemo pozvati.

Korak 1:

Definirajte dvije matrice, dp i choose, dimenzije N x Y. Inicijalizirajte obje matrice na 0.

Korak 2:

Pokrenite petlju od 0 do N - 1.

Korak 3:

Pokrenite unutarnju petlju od 0 do Y.

Korak 4:

Ako je dp[i][j] veće od 0, to znači da smo već odlučili koliko će pića biti popijeno ako pozovemo i ljude. Dakle, trebamo samo dodati xi u dp[i][j] i promijeniti choose[i][j] u i + 1.

Korak 5:

Ako je dp[i][j] jednako 0, to znači da nismo odlučili koliko će pića biti popijeno ako pozovemo i ljude. Dakle, trebamo provjeriti sve moguće vrijednosti k od 0 do i i odlučiti koliko će pića biti popijeno ako po
*/
