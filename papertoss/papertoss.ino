#define UD1 A3
#define LR1 A2
#define UD2 A0
#define LR2 A1
int received;
char buffer[10];      // input buffer
int N;                // how many measurements to make
boolean done = false;
// this constant won't change:
const int  buttonPin = 5; // the pin that the pushbutton is attached to

// Variables will change:
int buttonState = 0;         // current state of the button
int lastButtonState = 0;     // previous state of the button


void setup() {
  // Initialize the button pin as an input:
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
}

void loop() {
      received = 0;
      buffer[received] = '\0';
      done = false;
    
      // Check input on serial line.
      while (!done) {
        if (Serial.available()) { // Something is in the buffer
          N = Serial.read();  // so get the number byte
          done = true;
        }
      }
      // Read the pushbutton input pin:
      buttonState = digitalRead(buttonPin);

      if (buttonState == HIGH) {
      // If the current state is HIGH then the button
      // Send to serial that the engine has started:   
      //  Serial.print(1);
      //  Serial.print('\t');
        lastButtonState = 1;
        delay (100);  
      }
  // Save the current state as the last state,
  // for next time through the loop
  lastButtonState = buttonState;
      int LRval1 = analogRead(LR1);
      int UDval1 = analogRead(UD1);
      int LRval2 = analogRead(LR2);
      int UDval2 = analogRead(UD2);
      Serial.print(lastButtonState, DEC);
      Serial.print('\t');
      Serial.print(LRval1, DEC);
      Serial.print('\t');
      Serial.print(UDval1, DEC);
      Serial.print('\t');
      Serial.print(LRval2, DEC);
      Serial.print('\t');
      Serial.print(UDval2, DEC);
      Serial.print('\n');
      delay(10);
      
}
