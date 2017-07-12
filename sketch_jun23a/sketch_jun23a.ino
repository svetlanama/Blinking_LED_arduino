
int LED = 12;

void setup() {

  Serial.begin(9600); // for print log data
  pinMode(LED, OUTPUT);

  //TEST
  //   sendOneSignal();
  //   sendBreakSignal();
  //   sendZeroSignal();
  //   sendBreakSignal();
  //   sendOneSignal();
  //   sendBreakSignal();
  //   sendZeroSignal();
  //   sendBreakSignal();

  sendText();
}

void loop() {
}

void sendOneSignal() {
  digitalWrite(LED, HIGH);
  double _delay = 500; 
  delay(_delay);
}

void sendZeroSignal() {
  digitalWrite(LED, HIGH);
  double _delay = 250;
  delay(_delay);
}

void sendBreakSignal() {
  digitalWrite(LED, LOW);
  double _delay = 250;
  delay(_delay);
}

void sendText() {

  String myText = "s";//"shins";
  Serial.println(myText);
  //sendStartSignal();
  //sendBreakSignal();

  for (int i = 0; i < myText.length(); i++) {
    char myChar = myText.charAt(i);
    //Serial.println(myChar);
    
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
    
    Serial.print(" ");
  }
}


