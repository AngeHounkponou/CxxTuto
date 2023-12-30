#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void f(string s_line, string separator = ",") {
  size_t s_found = 0;
  string s_value;
  vector<string> v_line{};
 
  while ((s_found = s_line.find(separator)) != string::npos) {
    s_value = s_line.substr(0, s_found);
    v_line.push_back(s_value);
    s_line.erase(0, s_found + separator.length());
  }
  v_line.push_back(s_line);

  for (auto i : v_line) {
    cout << i << endl;
  }
}

void read_csv(string fileName = "my_file.csv", string separator = ",") {
  ifstream file;
  string line{};

  file.open(fileName);
  if (file.is_open()) {
    getline(file, line);

    cout << line << endl;

    file.close();
  }
}

int main() {

  f("For your giving of the blessing is certainly well done", " ");
  return 0;
}