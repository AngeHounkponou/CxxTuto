#include <iostream>
#include <memory> //For smart pointer

using namespace std;

class Rectangle {
  int heigh;
  int width;

public:
  // Constructor
  explicit Rectangle(int h, int w) : heigh(h), width(w) {}

  void showInfos() {
    cout << "heigh = " << heigh << " & width = " << width
         << " -> Area = " << (heigh * width) << endl;
  }
};

int main() {
  Rectangle *raw_ptr{new Rectangle{5, 15}}; // Create Raw Pointer

  auto smart_ptr{make_unique<Rectangle>(4, 2)}; // Create Smart Pointer

  raw_ptr->showInfos();   // Print infos with raw pointer
  smart_ptr->showInfos(); // Print infos with  smart pointer

  delete raw_ptr;    // free memory
  raw_ptr = nullptr; // For safe, set raw pointer to nullptr

  /** For smart pointers, there's nothing more to do. Memory release will be
   * automatically.*/
  return 0;
}

// Smart pointer vs raw pointer