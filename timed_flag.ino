#include <Servo.h>

#define SERVO_PIN       10
#define WAVE_DELAY_SECS 270 // 4.5 mins

Servo servo;

int pos_arr [2] = {10, 170};
bool pos = 0;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  servo.attach(SERVO_PIN);
}

void blink(int duration_secs = 60) {
  for (int i = 0; i < duration_secs; ++i) {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(500);
    digitalWrite(LED_BUILTIN, LOW);
    delay(500);
  }
}

void wave_flag() {
    servo.write(pos_arr[pos^=1]);
}

void loop() {
  wave_flag();
  blink(WAVE_DELAY_SECS);
}
