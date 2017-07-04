
int LED = 12;
double gcycleTime = 4; //times
double cycleTime = 2000; //1 sec duration

int longSignal = 0;  // 0.06;
int shortSignal = 1; // 0.03;

int frameSequence = 1000 / 30;
int breakSignal = 1;
int current = 0;

void setup() {

  Serial.begin(9600); // for pront data
  pinMode(LED, OUTPUT);

  /*while (gcycleTime > 0) {
    while (cycleTime > 0) {
      if (cycleTime > 0) {
        if (current == 0) {
          sendOneSignal();
        } else {
          sendZeroSignal();
        }
        sendBreakSignal();
      } else {
        digitalWrite(LED, LOW);
      }
      Serial.println(cycleTime);
    }
    gcycleTime --;
    cycleTime = 1;

    digitalWrite(LED, LOW);
    delay(1000);
    //} */

  printText();
}

void loop() {
}


void ledOn() {
  digitalWrite(LED, HIGH);
  delay(5000);
}

void sendStartSignal() {
  Serial.println(" = StartSignal ");

  digitalWrite(LED, HIGH);
  double _delay = frameSequence * 3;
  delay(_delay);
  current = longSignal;

  cycleTime -= _delay;
}


void sendOneSignal() {
  Serial.println(" = OneSignal ");

  digitalWrite(LED, HIGH);
  double _delay = 1000; //frameSequence * 2;
  delay(_delay);
  current = longSignal;

  cycleTime -= _delay;
}


void sendZeroSignal() {
  Serial.println(" = ZeroSignal ");

  digitalWrite(LED, HIGH);
  double _delay = 500;
  delay(_delay);
  current = shortSignal;

  cycleTime -= _delay;
}

void sendBreakSignal() {
  Serial.println(" = BreakSignal ");

  digitalWrite(LED, LOW);
  double _delay = 1000;
  delay(_delay);

  cycleTime -= _delay;
}


void printText() {
  String myText = "h"; //"shins";
  sendStartSignal();
  sendBreakSignal();

  for (int i = 0; i < myText.length(); i++) {
    char myChar = myText.charAt(i);
    Serial.println(myChar);
    for (int i = 7; i >= 0; i--) {

      byte bytes = bitRead(myChar, i);
      Serial.print(bytes, BIN);
      if (bytes == 1) {
        sendOneSignal();
        sendBreakSignal();
      } else {
        sendZeroSignal();
        sendBreakSignal();
      }
    }

    //Serial.println(cycleTime);
    Serial.println("");

  }

  Serial.println("end");
}


