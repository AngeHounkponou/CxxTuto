#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Function to split text based on a separator
vector<string> fn_spleat(string s_line, string separator = ",") {
  size_t st_found{};       // To gets the position of the separator
  string s_value{};        // To get cell value
  vector<string> v_line{}; // To get all values of a line

  // As long as we have a valid match
  while ((st_found = s_line.find(separator)) != string::npos) {

    // Get cell value for this position
    s_value = s_line.substr(0, st_found);

    // Add the cell value to v_line vector
    v_line.push_back(s_value + " | ");

    // Delete found value from original string
    s_line.erase(0, st_found + separator.length());
  }

  // Add the last value of the vector and return
  v_line.push_back(s_line);
  return v_line;
}

// Function to read the csv file
vector<vector<string>> read_csv(string fileName = "my_file.csv",
                                string separator = ",") {
  ifstream file;                        // Stream to read the file
  string line{};                        // Variable to store a line of the file
  vector<vector<string>> vec_csvLine{}; // Vector to store all file records

  file.open(fileName); // Opening the file

  if (file.is_open()) { // Make sure the file is open

    cout << "Reading the file header..." << endl;
    // Retrieve column names with the first line
    getline(file, line);
    vec_csvLine.push_back(fn_spleat(line, separator));

    // Read the rest of the files (Limited to 10 records for example)
    unsigned char ln_num{};
    while (getline(file, line) && ln_num < 10) {
      vec_csvLine.push_back(fn_spleat(line, separator));
      ln_num++; // Counts the number of lines read
    }
    file.close(); // Close file
  }

  // Display the rest of the file
  for (auto &&i : vec_csvLine) {
    for (auto &&j : i) {
      cout << j << " ";
    }
    cout << endl;
  }

  return vec_csvLine;
}

int main() {
  // Initialization of a vector of X from a read csv file
  vector<vector<string>> vec_csv{read_csv("my_file.csv")};

  cout << endl << "Reading the second recording ." << endl;
  // Display only the second record in the file
  for (auto &&i : vec_csv.at(2)) {
    cout << i;
  }

  cout << endl;

  return 0;
}
