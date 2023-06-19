#include "Keyboard.h"
#include "Mouse.h"

int dir_choose = 0;
int press_rand = 0;
int wait_rand = 0;

void setup() {
  pinMode(12, INPUT_PULLUP);
}

void loop() {
  dir_choose = random(0,4);
  press_rand = random(20);
  wait_rand = random(3000);
  if (digitalRead(12) == LOW) {
    if (dir_choose == 0){
      Keyboard.press('w');
      delay(press_rand + 20);
      Keyboard.release('w');
    }
    else if (dir_choose == 1){
      Keyboard.press('a');
      delay(press_rand + 20);
      Keyboard.release('a');
    }
    else if (dir_choose == 2){
      Keyboard.press('s');
      delay(press_rand + 20);
      Keyboard.release('s');
    }
    else if (dir_choose == 3){
      Keyboard.press('d');
      delay(press_rand + 20);
      Keyboard.release('d');
    }
    delay(6000 + wait_rand);
  }


}
