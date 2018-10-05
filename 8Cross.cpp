/*Sets up 8 numbers in a cross formation using backtrack.*/

#include <iostream>
#include <cmath>
using namespace std;

bool check(int a[], int x) {
  int c[8][4] = {
    {-1, -1, -1, -1},
    {0, -1, -1, -1},
    {1, -1, -1, -1,},
    {0, 1, 2, -1},
    {1, 2, 3, -1},
    {0, 3, 4, -1},
    {3, 4, 5, -1},
    {2, 4, 6, -1}
  };
  for (int i = 0; i < x; i++) {
    if (a[i] == a[x]) return false;
  }
  for (int i = 0; c[x][i] > -1; i++) {
    if (abs(a[x] - a[c[x][i]]) == 1) return false;
  }
  return true;
}

void print(int c[]) {
  cout << "  " << c[1] << " " << c[2] << endl
  << c[0] << " " << c[3] << " " << c[4] << " " << c[7] << endl
  << "  " << c[5] << " " << c[6] << endl << endl;
}

void backtrack(int &col) {
  col--;
  if (col == -1) exit(0);
}

int main() {
  int c[8] = {0}, col = 0;
  bool f = false;
  while (true) {
    while (col < 8) {
      if (!f) c[col] = 0;
      while (c[col] <= 8) {
        c[col]++;
        if (c[col] == 9) {
          backtrack(col);
          continue;
        }
        if (check(c, col)) break;
      }
      col++;
      f = false;
    }
    print(c);
    backtrack(col);
    f = true;
  }
}