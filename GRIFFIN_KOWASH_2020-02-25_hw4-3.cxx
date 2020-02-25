#include <iostream>

using namespace std;

int main() {
  int total = 0;
  int sqTotal = 0;
  int difference;
  
  for (int i=1; i <= 100; i++) {
    total += i;
    sqTotal += i*i;
  }
  
  difference = sqTotal - total;
  cout << "Difference between sum and sum of squares of first 100 natural numbers: " << difference << endl;
}
