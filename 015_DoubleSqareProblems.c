#include <stdio.h>
#include <assert.h>
#include <math.h>

int doubleSquare(unsigned int m) {
  int total = 0;
  int iUpper = sqrt((double)m / 2.0);
  for (int i = 0; i <= iUpper; i++) {
    unsigned int ii = i*i;
    for (int j = i; ; j++) {
      unsigned int sum = ii + j*j;
      if (sum == m)
        total++;
      else if (sum > m)
        break;
    }
  }
  return total;
}

int main(int argc, char *argv[]) {
	assert(2==doubleSquare(25));
}