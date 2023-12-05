#include <iostream>
#include <vector>

using namespace std;

int main() {

  int lng_suite{0};  // Variable to store number of iterations
  vector<int> v_fib{1, 0, 0}; // Vector for manipulating results

  // Loop to control number of iterations
  do {
    cout << "Enter the length N of the Fibonacci sequence ( N>0 et N<15): ";
    cin >> lng_suite;
  } while (lng_suite <= 0 || lng_suite >= 15);

  for (auto i{0}; i < lng_suite; i++) {
    // v_fib[2] = v_fib[0] + v_fib[1]
    v_fib.at(2) = v_fib.at(0) + v_fib.at(1);

    // Display the result contained in v_fib[2]
    cout << v_fib.at(2) << " -> ";

    // Swap vector values for next iteration
    v_fib.at(1) = v_fib.at(0); // v_fib[1] = v_fib[0]
    v_fib.at(0) = v_fib.at(2); // v_fib[0] = v_fib[2]
  }

  return 0;
}

