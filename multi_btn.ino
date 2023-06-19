#include "Keyboard.h"
#include "Mouse.h"
#define KEY_SPACE 0xB4
#define hw 600
#define btn_test_flag 0
#define sensor_test_flag 1

#define captcha_right A2
#define captcha_left A5
#define b6_btn A1
#define b7_btn A0
#define right_sensor A3
#define left_sensor A4

#define left_sensor_fish_high 550
#define sensor_active 450
#define sensor_no_click_dif 20
#define sensor_click_dif 40
#define sensor_night_mode 300

#define captcha_left_low 640
#define captcha_left_high 680
#define captcha_right_low 470
#define captcha_right_high 520


#define mod 3200

int dir_choose = 0;
int press_rand = 0;
int wait_rand = 0;


// set pin numbers for the five buttons:

const int fish_btn = 13;
const int bp_btn = 12;
const int c1_btn = 11;
const int c2_btn = 10;
const int c3_btn = 9;

const int b1_btn = 8;
const int b2_btn = 7;
const int b3_btn = 6;
const int em_btn = 5;
const int b4_btn = 4;

const int buzz = 3;
const int b5_btn = 2;

int move_x = 0;
int move_y = 0;
int offset_x = 0;
int offset_y = 0;
int offset_dir = 0;
const int click_and_move_max = 37;

int backpack = 0;
int bp_max = 27;
int bp_flag = 0;

int rode_flag = 0;
int sterlyad_count = 0;



void setup() { // initialize the buttons' inputs:
  pinMode(fish_btn, INPUT_PULLUP);
  pinMode(em_btn, INPUT_PULLUP);
  pinMode(bp_btn, INPUT_PULLUP);
  pinMode(buzz, OUTPUT);
  pinMode(captcha_right, INPUT);
  pinMode(captcha_left, INPUT);
  pinMode(right_sensor, INPUT);
  pinMode(left_sensor, INPUT);

  pinMode(c1_btn, INPUT_PULLUP);
  pinMode(c2_btn, INPUT_PULLUP);
  pinMode(c3_btn, INPUT_PULLUP);

  pinMode(b1_btn, INPUT_PULLUP);
  pinMode(b2_btn, INPUT_PULLUP);
  pinMode(b3_btn, INPUT_PULLUP);
  pinMode(b4_btn, INPUT_PULLUP);
  pinMode(b5_btn, INPUT_PULLUP);
  pinMode(b6_btn, INPUT_PULLUP);
  pinMode(b7_btn, INPUT_PULLUP);

  Serial.begin(9600);
  // initialize mouse control:
  Mouse.begin();
  Keyboard.begin();
}

void anti_afk(){
  if (digitalRead(b3_btn) == LOW) {
    dir_choose = random(0,4);
    press_rand = random(20);
    wait_rand = random(3000);    
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

void swim_xp_gain(){
  if (digitalRead(b1_btn) == LOW) {
    Keyboard.press(KEY_SPACE);
    delay(50);
    Keyboard.release(KEY_SPACE);
    delay(50);
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.press('w');
    delay(6*mod);
    Keyboard.release('w');
    Keyboard.press('s');
    delay(10*mod);
    Keyboard.release('s');
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.press('w');
    delay(1500);
    Keyboard.release('w');
    //Keyboard.release(KEY_LEFT_SHIFT);
    //delay(300);
  }
  if (digitalRead(b1_btn) == HIGH) {
    Keyboard.releaseAll();
  }
  emergency();
}

void sterlyad_cook(){
  if (digitalRead(b2_btn) == LOW) {
    Mouse.click(MOUSE_RIGHT);
    for (int i = 0; i <= 525; i++) {
      Mouse.move(0, -1,0);
      delay(1);
    }
    delay(20);
    for (int i = 0; i <= 360; i++) {
      Mouse.move(1, 0 ,0);
      delay(1);
    }
    delay(20);
    Mouse.click(MOUSE_RIGHT);
    for (int i = 0; i <= 715; i++) {
      Mouse.move(0, 1,0);
      delay(1);
    }
    delay(20);
    for (int i = 0; i <= 360; i++) {
      Mouse.move(-1, 0 ,0);
      delay(1);
    }
    delay(20);
    Mouse.click();
    for (int i = 0; i <= 188; i++) {
      Mouse.move(0, -1,0);
      delay(1);
    }
    delay(6000); 
    sterlyad_count = sterlyad_count + 1;
    sterlyad_full();
  }
  else{
    sterlyad_count = 0;
  }
  emergency();
}


void skelet(){
  if (digitalRead(b2_btn) == LOW) {
    Mouse.press(MOUSE_RIGHT);
  }
  else{
    Mouse.release(MOUSE_RIGHT);
  }
  emergency();
}

void run(){
  if (digitalRead(b2_btn) == LOW) {
      Keyboard.press('w');
      Keyboard.press(KEY_LEFT_SHIFT);
      delay(20000);
    }
    
    Keyboard.release('w');
    Keyboard.release(KEY_LEFT_SHIFT);
    delay(10000);
}
void valheim(){
  //skelet();
  run();
}
void sterlyad_cook2(){
  if (digitalRead(b2_btn) == LOW) {
    Mouse.click(MOUSE_RIGHT);
    for (int i = 0; i <= 84; i++) {
      Mouse.move(3, -4,0);
      delay(1);
    }
    delay(50);
    Mouse.click(MOUSE_RIGHT);
    delay(50);
    for (int i = 0; i <= 84; i++) {
      Mouse.move(-3, 5,0);
      delay(1);
    }
    Mouse.click();
    for (int i = 0; i <= 45; i++) {
      Mouse.move(1, -3,0);
      delay(1);
    }
    for (int i = 0; i <= 27; i++) {
      Mouse.move(-1, 0,0);
      delay(1);
    }
    for (int i = 0; i <= 2; i++) {
      Mouse.move(0, -1,0);
      delay(1);
    }
    delay(5500);
    sterlyad_count = sterlyad_count + 1;
    sterlyad_full();
  }
  else{
    sterlyad_count = 0;
  }
  emergency();
}

void smoothie_cook(){
  if (digitalRead(b2_btn) == LOW) {
    Mouse.click(MOUSE_RIGHT);
    for (int i = 0; i <= 78; i++) {
      Mouse.move(4, -4,0);
      delay(1);
    }
    delay(50);
    Mouse.click(MOUSE_RIGHT);
    delay(50);
    for (int i = 0; i <= 23; i++) {
      Mouse.move(4, 0,0);
      delay(1);
    }    
    delay(50);
    Mouse.click(MOUSE_RIGHT);
    for (int i = 0; i <= 78; i++) {
      Mouse.move(-4, 4,0);
      delay(1);
    }
    delay(50);
    
    delay(50);
    for (int i = 0; i <= 23; i++) {
      Mouse.move(-4, 0,0);
      delay(1);
    }    
    for (int i = 0; i <= 32; i++) {
      Mouse.move(0, 4,0);
      delay(1);
    }    
    delay(50);
    Mouse.click();
    delay(50);
    for (int i = 0; i <= 32; i++) {
      Mouse.move(0, -4,0);
      delay(1);
    }    
    delay(50);
    delay(5500);
    //Mouse.click(MOUSE_RIGHT);
    //delay(50);
    
    //sterlyad_count = sterlyad_count + 1;
    //sterlyad_full();
  }
  else{
    sterlyad_count = 0;
  }
  emergency();
}

void button_test(){
  if (btn_test_flag == 1){
    Serial.print(digitalRead(bp_btn));
    Serial.print(' ');
    Serial.print(digitalRead(c1_btn));
    Serial.print(' ');
    Serial.print(digitalRead(c2_btn));
    Serial.print(' ');
    Serial.print(digitalRead(c3_btn));
    Serial.print(' ');

  
    Serial.print(digitalRead(b1_btn));
    Serial.print(' ');
    Serial.print(digitalRead(b2_btn));
    Serial.print(' ');
    Serial.print(digitalRead(b3_btn));
    Serial.print(' ');
    Serial.print(digitalRead(em_btn));
    Serial.print(' ');

    Serial.print(digitalRead(b4_btn));
    Serial.print(' ');
    Serial.print(digitalRead(b5_btn));
    Serial.print(' ');
    Serial.print(digitalRead(b6_btn));
    Serial.print(' ');
    Serial.print(digitalRead(b7_btn));
    
    if (sensor_test_flag == 0){
      Serial.println(' ');
    }
    else{
      Serial.print(' ');
    }
  }
}

void sensor_test(){
  if (sensor_test_flag == 1){
    Serial.print(analogRead(left_sensor));
    Serial.print(' ');
    Serial.print(analogRead(right_sensor));
    Serial.print(' ');
    Serial.print(analogRead(left_sensor) - analogRead(right_sensor));
    Serial.print(' ');
    Serial.print(' ');
    Serial.print(backpack);    
    Serial.print(' ');
    Serial.print(' ');
    Serial.print(analogRead(captcha_left));
    Serial.print(' ');
    Serial.println(analogRead(captcha_right));
  }
}

void test(){
  button_test();
  sensor_test();
}

int nsign(int x){
  if (x < 0){
    return 1;
  }
  else {
    return -1;
  }
}

void emergency(){
  if (digitalRead(em_btn) == LOW) {
    while (digitalRead(em_btn) == LOW) { 
      test();
    }
  }   
}

void mouse_move_down(){
  move_y = random(40,60);
  for (int i = 0; i <= 95; i++) {
    Mouse.move(0, move_y/20,0);
    delay(2);
  }
  if (offset_dir == 1){
    for (int i = 0; i <= click_and_move_max; i++) {
      Mouse.move(move_x/20, 0,0);
      delay(2);
    }
    
    offset_x = offset_x + (move_x/10)*20;
  }
  else {
    for (int i = 0; i <= click_and_move_max; i++) {
      Mouse.move(-move_x/20, 0,0);
      delay(2);
    }
    offset_x = offset_x - (move_x/10)*20;
  }
}

void drop_fr(){
  delay(500);
  emergency();
  Keyboard.press(234);
  delay(40);
  Keyboard.release(234);
  delay(40);
  mouse_move_down();
}

void click_and_move(){
  move_x = random(80,100);
  move_y = random(20,40)*nsign(offset_y);
  if (offset_dir == 0){
    if (analogRead(left_sensor) > sensor_active and analogRead(left_sensor) < left_sensor_fish_high and abs(analogRead(left_sensor) - analogRead(right_sensor)) > sensor_click_dif){
      Mouse.click();
    }
    for (int i = 0; i <= click_and_move_max; i++) {
      Mouse.move(move_x/20, move_y/20,0);
      delay(2);
    }
    
    offset_x = offset_x + (move_x/10)*20;
    offset_y = offset_y + (move_y/10)*20;
    if (offset_x > hw) {
      offset_dir = 1;
    }
  }
  else {
    if (analogRead(left_sensor) > sensor_active and analogRead(left_sensor) < left_sensor_fish_high and abs(analogRead(left_sensor) - analogRead(right_sensor)) > sensor_click_dif){
      Mouse.click();
    }
    for (int i = 0; i <= click_and_move_max; i++) {
      Mouse.move(-move_x/20, move_y/20,0);
      delay(2);
    }
    
    offset_x = offset_x - (move_x/10)*20;
    offset_y = offset_y + (move_y/10)*20;
    if (offset_x < - hw) {
      offset_dir = 0;
    }
  }
}

void bp_melody(){
  tone(buzz, 1100, 500);
  delay(500);
  tone(buzz, 1200, 500);
  delay(500);
  tone(buzz, 1300, 500);
  delay(500);
}

void captcha_melody(){
  tone(buzz, 1000, 500);
  delay(500);
}

void sterlyad_full(){
  if (sterlyad_count == 33){
    while (sterlyad_count == 33){
      cooking_melody();
      delay(1000);
      if (digitalRead(b2_btn) == HIGH) {
        sterlyad_count = 0;
      }
    }
  }
}

void cooking_melody(){
  tone(buzz, 1000, 500);
  delay(500);
  tone(buzz, 900, 500);
  delay(500);
  tone(buzz, 800, 500);
  delay(500);
}

void bp_full(){
  if (backpack == bp_max) {
    while (digitalRead(bp_btn) != LOW) { 
      emergency();
      bp_melody();
      delay(500);
    }
    backpack = 0;
  }   
}

void bp_zero(){
  if (digitalRead(bp_btn) == LOW) { 
    backpack = 0;
  }
}

void captcha_alarm(){
  if ((analogRead(captcha_left) > captcha_left_low and analogRead(captcha_left) < captcha_left_high) and (analogRead(captcha_right) > captcha_right_low and analogRead(captcha_right) < captcha_right_high)) {
    while ((analogRead(captcha_left) > captcha_left_low and analogRead(captcha_left) < captcha_left_high) and (analogRead(captcha_right) > captcha_right_low and analogRead(captcha_right) < captcha_right_high)) { 
      emergency();
      captcha_melody();
      delay(100);
    }
  }   
}

void fishing_main(){
  if (digitalRead(fish_btn) == LOW) {       
    emergency();
    
    bp_zero();
    bp_full();
    if (analogRead(left_sensor) > sensor_active and analogRead(left_sensor) < left_sensor_fish_high and abs(analogRead(left_sensor) - analogRead(right_sensor)) > sensor_click_dif){
      click_and_move();
      bp_flag = 1;
      rode_flag = 1;
    }
    else if (abs(analogRead(left_sensor) - analogRead(right_sensor))<sensor_no_click_dif and analogRead(left_sensor) > sensor_active){
      bp_flag = 0;
    }
    else {
      if (rode_flag == 1 and ((analogRead(left_sensor) - analogRead(right_sensor))>0 or analogRead(left_sensor) <sensor_night_mode)){
        if (bp_flag == 1){
          backpack = backpack+1;
          bp_flag = 0;
        }
        bp_full();
        drop_fr();
        rode_flag = 0;
      }
      captcha_alarm();
    }
    
  }
}

void car_enter_exit(){
  if (digitalRead(c1_btn) == LOW) { 
    Keyboard.write('j');
    delay(100);
    Keyboard.write('l');
    delay(100);
    Keyboard.write('2');
    delay(100);
  }
  if (digitalRead(c2_btn) == LOW) {
    Keyboard.write('f');
  }
}

void wsca(){
  if (digitalRead(fish_btn) == HIGH) {
    if (digitalRead(b4_btn) == LOW) {
      Keyboard.press('w');
      delay(20);
    }
    else {
      Keyboard.release('w');
    }
    if (digitalRead(b5_btn) == LOW) {
      Keyboard.press(KEY_LEFT_SHIFT);
      delay(20);
    }
    else {
      Keyboard.release(KEY_LEFT_SHIFT);
    }
    if (digitalRead(b6_btn) == LOW) {
      Keyboard.press(KEY_LEFT_CTRL);
      delay(20);
    }
    else {
      Keyboard.release(KEY_LEFT_CTRL);
    }
    if (digitalRead(b7_btn) == LOW) {
      Keyboard.press(KEY_LEFT_ALT);
      delay(20);
    }
    else {
      Keyboard.release(KEY_LEFT_ALT);
    }
  }
}

void loop() {
  test();
  swim_xp_gain();  
  fishing_main();
  //sterlyad_cook2();
  //smoothie_cook();
  valheim();
  car_enter_exit();
  anti_afk();
  wsca();
}

void yield() {
  emergency();
}