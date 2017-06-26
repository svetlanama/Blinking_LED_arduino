
int LED = 12;
double gcycleTime = 4; //times
double cycleTime = 1; //1 sec duration

int longSignal = 0;  // 0.06;
int shortSignal = 1; // 0.03;

int frameSequence = 0.03;
int current = 0;

void setup() {
 
  Serial.begin(9600); // for pront data
  pinMode(LED, OUTPUT);

  while (gcycleTime > 0) {
    while (cycleTime > 0) {
      if (cycleTime > 0) {
        if (current == 0) {
          sendShortSignal();
        } else {
          sendLongSignal();
        }
        sendBreakSignal();
      } else {
        digitalWrite(LED, LOW);
      }
    }
    gcycleTime --;
    cycleTime = 1;
    digitalWrite(LED, LOW);
    delay(1000);
  }

}

void loop() {
}

void sendLongSignal() {
  Serial.println("sendLongSignal ");

  digitalWrite(LED, HIGH);
  double _delay = frameSequence * 2;
  delay(_delay);
  current = longSignal;

  cycleTime -= _delay;
}


void sendShortSignal() {
  Serial.println("sendShortSignal ");

  digitalWrite(LED, HIGH);
  double _delay = frameSequence;
  delay(_delay);
  current = shortSignal;

  cycleTime -= _delay;
}

void sendBreakSignal() {
  Serial.println("sendBreakSignal ");

  digitalWrite(LED, LOW);
  double _delay = 0.1;
  delay(_delay);

  cycleTime -= _delay;
}

