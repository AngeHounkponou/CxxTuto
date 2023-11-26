#include <chrono>
#include <iostream>
#include <thread>

using namespace std;

int main() {  
  if (system("clear")) system("cls"); // 1 - Clean screen 

  // 2 - Get the current point in time (for the start).
  const auto m_debut {chrono::high_resolution_clock::now()};  
  // 3 - Get another point in time that will be updated
  auto m_fin {chrono::high_resolution_clock::now()};
  // 4 - computes interval between m_fin and m_debut (m_interval will be updated)
  auto m_interval {chrono::duration_cast<chrono::milliseconds>(m_fin - m_debut).count()};

  auto timeToRun{7000}; // 5 - Program running time in milliseconds

  do {
    // 6 - Pause the program for one second
    this_thread::sleep_for(chrono::seconds(1));

    // 7 - Update m_fin to get current point in time
    m_fin = chrono::high_resolution_clock::now();

    // 8 - Update m_interval with the new value of m_fin 
    m_interval = chrono::duration_cast<chrono::milliseconds>(m_fin - m_debut).count();    
    if (system("clear")) system("cls"); // 9 - Clean screen 
    
    // 10 - Display number of seconds since program start 
    cout <<"Has been running since "<<(m_interval / 1000)<<" second(s)" << endl;
  } while (m_interval < timeToRun);
  
  cout <<"End of run ...\n"<< endl;
  return 0;
}

//#C++ #vscode #clangd add-on
//[Fr]Petit code en C++ qui permet de créer un chronomètre ou un minuteur (avec quelques modifications).
//[En]Small C++ code to create a stopwatch or timer (with a few modifications).