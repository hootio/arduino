#include <Servo.h>

Servo myservo;

int pos = 0;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  myservo.attach(10);
}

int SERVO_DELAY_SECS = 3 * 60;

void blink(int duration_secs = 60) {
  for (uint32_t i = 0; i < duration_secs; ++i) {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(500);
    digitalWrite(LED_BUILTIN, LOW);
    delay(500);
  }
}

void wave_flag(int times = 5) {
  for (int i = 0; i < times; ++i) {
    myservo.write(170);
    delay(500);
    myservo.write(10);
    delay(500);
  }
}

void loop() {
  wave_flag();
  blink(SERVO_DELAY_SECS);
}
