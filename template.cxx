#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <typename vec, typename val>

void nb_occurence(const vec &list, val v) {
  int compteur{0}; // Initialisation du compteur
  for (const auto &ref_l : list) {
    if (v == ref_l) // Si correspondance : incrémenter le compteur
      compteur++;
  }
  cout << "Nous avons " << compteur << " occurrence(s) de " << v << " ." << endl;
}

int main() {
  //vecteur de int
  vector<int> myListe{2, 3, 1, 3, 5, 4, 1};
  nb_occurence(myListe, 1); //Compter le nombre d’occurrence de 1

  //chaine de caractère
  string text{"Hello everyone !"};
  nb_occurence(text, 'e'); // Compter le nombre d’occurrence de 'e'

  return 0;
}

// #C++ #vscode #clangd plugin
//[Fr] Fonction utilisant les Templates pour compter le nombre d’occurrences d’un élément dans une liste.
//[En] Template-based function for counting the number of occurrences of an element in a list.