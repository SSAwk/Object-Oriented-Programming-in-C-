/*The problem
Write a program that inputs two integers n and k, where n>=k. Your program should calculate the number of different ways that k bishops could be placed on an nXn chessboard. Structure your program using the backtracking scheme that we have used for the eight queens problem. What needs to be modified is the “OK” function. 
Input
Your main program should loop asking the user for values of n and k.
Output
Each time through the loop, output n, k and the number of configurations. Program Termination The program will terminate if the user enters a value of -1 for n.*/

#include <cstdlib>
#include <iostream>
using namespace std;

int n, k;

bool ok(int q[], int b, int size) {
  int row = q[b] / size, column = q[b] % size, crow, ccolumn;
  for (int i = 0; i < b; i++) {
    crow = q[i] / size;
    ccolumn = q[i] % size;
    if (abs(row - crow) == abs(column - ccolumn)) return false;
  }
  return true;
}

void backtrack(int &b, int c) {
  b--;
  if (b == -1) {
    cout << "Board size: " << n << " Bishops: " << k << " Configurations: " << c << endl << endl;
  }
}

int main() {
  while (true) {
    cout << "Enter the size of the board: ";
    cin >> n;
    cout << "Enter the number of bishops: ";
    cin >> k;
    if (n == -1) break;
    while (n < k) {
      cout << "Board size must be greater than number of bishops." << endl;
      cout << "Enter the size of the board: ";
      cin >> n;
      cout << "Enter the number of bishops: ";
      cin >> k;
    }
    int *q = new int[k];
    int c = 0, b = 0, t;
    q[b] = 0;
    while (true) {
      while (b < k) {
        while (q[b] < n * n) {
          if (ok(q, b, n)) break;
          else q[b]++;
        }
        if (q[b] == n * n) {
          backtrack(b, c);
          q[b]++;
          if (b == -1) break;
          continue;
        }
        else {
          t = q[b];
          b++;
          q[b] = t;
        }
      }
      if (b == -1) break;
      c++;
      backtrack(b, c);
      q[b]++;
    }
  }
  return 0;
}