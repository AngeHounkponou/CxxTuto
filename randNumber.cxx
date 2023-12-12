#include <iostream>
#include <random>

using namespace std;

int main() {

  int m_score{0}, m_choice{0}, m_trigger{0}, m_next{0}, m_min{1}, m_max{6};

  // Product of integer values uniformly distributed over an interval from m_min to m_max
  uniform_int_distribution<int> distribution(m_min, m_max);

  // Generate non-deterministic random number for the default_random_engine 
  random_device rd;
  default_random_engine generator(rd());  

  do {
    if (system("clear")) system("cls"); // Clean screen
    
    // Get a random number between m_min and m_max
    m_trigger = distribution(generator);

    do { // Choose a number between m_min and m_max
      cout << "Choose a number between " << m_min << " and " << m_max << " => ";
      cin >> m_choice;
    } while (m_choice < m_min || m_choice > m_max);

    if (m_trigger == m_choice) {//If you have chosen the same number as the machine, the game ends.
      m_next = 0;
      cout << "PAN !!! End of the game... Final score = " << m_score << endl;
    } else {
      m_score++;
      cout << "Trigger [" << m_trigger << "] - Congratulations, your score is "
           << m_score <<"."<< endl;
      cout << "Would you like to continue? 1=YES / 0=NO ";
      cin >> m_next;
    }

  } while (m_next > 0 && (m_choice != m_trigger));

  cout << endl;

  return 0;
}

/*

[En] A little console game in C++ that highlights random number generation.
At each turn, the user must choose a number between 1 and 6, but different from the number chosen by the machine.
If you have chosen the same number as the machine, the game ends.
If not, you can quit the game or choose another number to increase your score.

[Fr] Petit jeu console en C++ qui met en évidence la génération de nombres aléatoires.
À chaque tour, l’utilisateur doit choisir un numéro compris entre 1 et 6, mais différent du numéro choisi par la machine.
Si vous avez choisi le même numéro que la machine, le jeu se termine.
Dans le cas contraire, vous pouvez quitter le jeu ou choisir un autre numéro pour augmenter votre score.

*/