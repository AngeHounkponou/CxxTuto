#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> v_numbers = {3, 5, 8, 4, 2};

  // Lambda function with explicit capture that multiplies each element of the
  // vector by factor.
  int factor = 2;
  transform(v_numbers.begin(), v_numbers.end(), v_numbers.begin(),
            [factor](int num) { return num * factor; });

  cout << endl << "Vector elements : ";
  for (auto num : v_numbers) {
    cout << num << " "; // Display result
  }
  cout << endl;

  // Lambda function with implicit capture
  auto is_Even = [](int num) { return num % 2 == 0; };

  // Use the lambda function in an algorithm to find the first even number.
  auto it = find_if(v_numbers.begin(), v_numbers.end(), is_Even);

  // Display result
  if (it != v_numbers.end()) {
    cout << "The first even element found = " << (*it) << endl;
  } else {
    cout << "No even elements found " << endl;
  }

  return 0;
}
