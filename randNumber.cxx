#include <iostream>
#include <random>

using namespace std;

int main() {
  //
  int m_score{0}, m_choice{0}, m_trigger{0}, m_next{0}, m_min{1}, m_max{6};

  //Product of integer values uniformly distributed over an interval from m_min to m_max
  uniform_int_distribution<int> distribution(m_min, m_max);

  //Use random_device to generate non-deterministic random number
  random_device rd;
  default_random_engine generator(rd());

  do {
    if (system("clear")) system("cls"); // Clean screen

    do {
      //
      cout << "Choisir un nombre compris entre " << m_min << " et " << m_max<< " > ";
      cin >> m_choice;
    } while (m_choice < m_min || m_choice > m_max);

    m_trigger = distribution(generator);

    if (m_trigger == m_choice) {
      m_next = 0;
      cout << "PAN !!! Fin de la partie... Score final : "<<m_score << endl;
    } else {
      m_score++;
      cout << m_trigger << " Bravos votre score est = " << m_score << endl;
      cout << "Voulez vous continuer ? 1 = OUI / 0 = NON ";
      cin >> m_next;
    }

  } while (m_next > 0 && (m_choice != m_trigger));

  return 0;
}