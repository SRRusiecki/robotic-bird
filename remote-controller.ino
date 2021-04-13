// Program for the 4 button XBee WiFi remote controller.

int buttonPin1 = 13;
int buttonState1 = 0;
int buttonPin2 = 4;
int buttonState2 = 0;
int buttonPin3 = 2;
int buttonState3 = 0;
int buttonPin4 = 3;
int buttonState4 = 0; 

void setup()
{
  // Set port at 9600 baud, the same value as in remote controller.
  // Necessary for XBee modules to communicate properly.
  Serial1.begin(9600);  //XBee/UART1/pins 0 and 1
  Serial.begin(9600);   //USB
  pinMode(buttonPin1, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);
  pinMode(buttonPin3, INPUT_PULLUP);
  pinMode(buttonPin4, INPUT_PULLUP);

}

void loop()
{
  Serial1.begin(9600);
  buttonState1 = digitalRead(buttonPin1);
  buttonState2 = digitalRead(buttonPin2);
  buttonState3 = digitalRead(buttonPin3);
  buttonState4 = digitalRead(buttonPin4);
    
  if (buttonState1 == LOW)
      {
      Serial1.begin(9600);
      Serial1.print(1);
      delay(20);
      }
  else if (buttonState2 == LOW)
      {
      Serial1.begin(9600);
      Serial1.print(2);
      delay(20);
      }
  else if (buttonState3 == LOW)
      {
      Serial1.begin(9600);
      Serial1.print(3);
      delay(20);
      }
  else if (buttonState4 == LOW)
      {
      Serial1.begin(9600);
      Serial1.print(4);
      delay(20);
      }
  else
    {
      Serial1.end();
    }
}
