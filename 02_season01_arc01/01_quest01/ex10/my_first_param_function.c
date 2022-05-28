#include <stdio.h>
// function will printf("detonation in... %d secondes.\n", seconds_left);
void detonation_in(int seconds_left) {
    printf("%s%d%s", "detonation in... ", seconds_left, " secondes.\n");
}

int main() {
  int timer = 10;

  while (timer >= 1) {
    detonation_in(timer);
    timer--;
  }
  return 0;
}