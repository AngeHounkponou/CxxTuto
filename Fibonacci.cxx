#include <iostream>
#include <vector>

using namespace std;

int main() {

  int lng_suite{0};  // Variable pour stocker le nombre d'itérations
  vector<int> v_fib{1, 0, 0}; // Vecteur pour manipuler les résultats

  // Boucle de contrôle du nombre d'itérations
  do {
    cout << "Entrer la longeur N de la suite Fibonacci (N>0 et N<15): ";
    cin >> lng_suite;
  } while (lng_suite <= 0 || lng_suite >= 15);

  for (auto i{0}; i < lng_suite; i++) {
    // v_fib[2] = v_fib[0] + v_fib[1]
    v_fib.at(2) = v_fib.at(0) + v_fib.at(1);

    // Afficher le résultat contenu dans v_fib[2]
    cout << v_fib.at(2) << " -> ";

    // Permuter les valeurs du vecteur pour la prochaine itération 
    v_fib.at(1) = v_fib.at(0); // v_fib[1] = v_fib[0]
    v_fib.at(0) = v_fib.at(2); // v_fib[0] = v_fib[2]
  }

  return 0;
}

