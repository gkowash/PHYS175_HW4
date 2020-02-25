#include <iostream>

using namespace std;

int getNthPrime(int n) {
  int i = 1; //hardcoding in the prime "2" to make the loop below cleaner
  int val = 1; //(this way we only have to loop through odds)
  bool prime;
  
  //loop through odd numbers searching for a prime
  while (i < n) {
    val += 2;
    prime = true;
    //search for a divisor (only considering odds)
    for (int j = val-2; j > 2; j -= 2) {
      if (val % j == 0) {
	prime = false;
	break;
      }
    }
    if (prime) {
      i++;
    }
  }
  
  return val; //returns Nth prime number
}

int main() {
  cout << "3rd prime: " << getNthPrime(3) << endl;
  cout << "5th prime: " << getNthPrime(5) << endl;
  cout << "12th prime: " << getNthPrime(12) << endl;
  cout << "10001st prime: " << getNthPrime(10001) << endl;
  return 1;
}
