
int LED = 12;
double gcycleTime = 1;//sec
double cycleTime = 1;//sec

int longSignal = 0; // 0.06;
int shortSignal = 1; // 0.03;

int frameSequence = 0.03;
int current = 0;
 
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); // for pront data
  pinMode(LED, OUTPUT);

  while(gcycleTime > 0) {
   while(cycleTime > 0) {
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
    //Serial.println("cycleTime: ");
    //Serial.println(cycleTime, DEC);
}


void sendShortSignal() {
    Serial.println("sendShortSignal ");
    
    digitalWrite(LED, HIGH);
    double _delay = frameSequence;
    delay(_delay); 
    current = shortSignal;

    cycleTime -= _delay;
    //Serial.println("cycleTime: ");
    //Serial.println(cycleTime, DEC);
}

void sendBreakSignal() {
    Serial.println("sendBreakSignal ");
    
    digitalWrite(LED, LOW);
    double _delay = 0.1;
    delay(_delay);
    
    cycleTime -= _delay;
    //Serial.println("cycleTime: ");
    //Serial.println(cycleTime, DEC);
}

