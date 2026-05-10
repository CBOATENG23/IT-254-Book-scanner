#define BUTTON_PIN 2
#define LED1 8
#define LED2 9
#define LED3 10
#define BUZZER 5
#define POT_PIN A0

// #define TRIG_PIN 7
// #define ECHO_PIN 6

int buttonState = 0;
int potValue = 0;
int moodLevel = 0;
int recommendations = 0;
int sensorValue = 0;

long duration;
int distance;

void setup() {
  Serial.begin(9600);

  pinMode(BUTTON_PIN, INPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(BUZZER, OUTPUT);

  // pinMode(TRIG_PIN, OUTPUT);
  // pinMode(ECHO_PIN, INPUT);
}

void loop() {

  // Read potentiometer (0–1023)
  potValue = analogRead(POT_PIN);

  // Set mood level
  if (potValue < 341) {
    moodLevel = 0;
  }
  else if (potValue < 682) {
    moodLevel = 1;
  }
  else {
    moodLevel = 2;
  }

  // Ultrasonic sensor code (optional)
  /*
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);

  digitalWrite(TRIG_PIN, LOW);

  duration = pulseIn(ECHO_PIN, HIGH);
  distance = duration * 0.034 / 2;
  */

  // Read button
  buttonState = digitalRead(BUTTON_PIN);

  // Trigger scan
  if (buttonState == HIGH) {

    Serial.print("SCAN:");
    Serial.println(moodLevel);

    // Short buzzer beep
    tone(BUZZER, 1000, 200);

    // Prevent spam clicks
    delay(1000);
  }

  // Receive result from Python
  if (Serial.available() > 0) {

    recommendations = Serial.parseInt();

    // Turn all LEDs off first
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);

    // Turn LEDs on based on recommendation count
    if (recommendations >= 1) {
      digitalWrite(LED1, HIGH);
    }

    if (recommendations >= 2) {
      digitalWrite(LED2, HIGH);
    }

    if (recommendations >= 3) {
      digitalWrite(LED3, HIGH);
    }

    // Success sound
    tone(BUZZER, 2000, 300);
  }
}