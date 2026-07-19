#include <stdio.h>

int main(void) {
   int x = 2 * 3 + 8 / 2 - 1 * 3; //7 // 6 + 4 - 3 = 7
   int y = 2 * (3 + 8) / 2 - 1 * 3; //8 // 2 * 11 / 2 - 3 = 8
   int z = (2 * 3) + 8 / (2 - 1) * 3; //30 // 6 + 8 / 1 * 3 = 6 + 24 = 30

   printf("%d\n%d\n%d\n",x, y, z);
} 