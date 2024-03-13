//C++17
#include <iostream>
using namespace std;

template <typename... Args> 
auto fn_sum(Args... value) { 
    //Adds and returns the sum of parameters
    return (value + ...); 
}

template <typename... Args> 
void fn_Print(Args &&...value) {
  //Perfect forwarding of the parameter with std::forward
  (cout << ... << std::forward<Args>(value)) << '\n';
}

int main() {
  auto a{10}, b{15}; // Declaration of two Int
  auto c{10.5};      // Declaration of a double

  // Add up the numbers passed as parameters
  cout << "\nsum " << a << "+" << b << "+" << c << " = " << fn_sum(a, b, c)
       << endl;

  // Displaying a sequence of caracter strings
  fn_Print("Hello ", "World");

  return 0;
}

