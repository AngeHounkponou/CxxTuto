#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void write_csv(vector<vector<string>> &dico, string fileName = "my_file.csv",
               string separator = ",") {

  // Création du flux d'écriture du fichier.
  ofstream file;

  // Ouverture du flux d'écriture.
  file.open(fileName);

  // Variable pour stocker les enregistrements.
  string line{};

  for (auto i : dico) { // Parcourir les enregistrements.

    line = ""; // Vider la ligne au début de chaque itération.

    for (auto j : i) { // Parcourir les colonnes.
      // Ajoutez le contenu de la colonne et le séparateur de colonnes.
      line.append(j + separator);
    }

    line.pop_back(); // Supprimer le séparateur de colonnes en fin de ligne.

    file << line << endl; // Ajouter la ligne au fichier.
  }

  file.close(); // Refermer le fichier.

  cout << "Writing completed" << endl; // Afficher un message.
}

int main() {
  // Entête du fichier
  vector<string> v_title{"Id", "Gender", "Nickname", "Favourite game"};

  // Création de 3 enregistrements
  vector<string> v_row01{"1", "M", "Black_Arrow", "World of Warcraft"};
  vector<string> v_row02{"2", "M", "Malibu92", "God of War"};
  vector<string> v_row03{"3", "F", "Nadia-RTX", "Tomb Raider"};

  // Ajout des enregistrements au dictionnaire.
  vector<vector<string>> v_dico{v_title, v_row01, v_row02, v_row03};

  // Écrire le fichier CSV
  write_csv(v_dico);

  return 0;
}

