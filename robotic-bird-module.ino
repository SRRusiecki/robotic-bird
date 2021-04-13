
// Program for the robotic bird control module.
// The operation is controlled by the remote controller using XBee WiFi module.
// Higher level functions are NOT closed in loops for the most intuitive movement time setting.


#include <Servo.h>

int readXBee;

//Assign numbers of output pins soldered with external song player.
int songPin0 = 11;
int songPin1 = 10;
int songPin2 = 9;
int songPin3 = 8;
int songPin4 = 7;
int songPin5 = 6;

int activeSongPlayerPin = 2;    // Pin for the external audio player: has HIGH state when player is playing.

Servo servoL;   // Servo that moves the left wing.
Servo servoR;   // Servo that moves the right wing.

void setup()
{
  // Set port at 9600 baud, the same value as in remote controller.
  // Necessary for XBee modules to communicate properly.
  Serial1.begin(9600);
 
  pinMode(activeSongPlayerPin, INPUT);
  pinMode(songPin0, OUTPUT);
  pinMode(songPin1, OUTPUT);
  pinMode(songPin2, OUTPUT);
  pinMode(songPin3, OUTPUT);
  pinMode(songPin4, OUTPUT);
  pinMode(songPin5, OUTPUT);

  // Position both servos symmetrically.   
  servoL.attach(3);
  servoL.write(14);
  servoR.attach(13);
  servoR.write(34);
}

void loop()
{  
  unsigned long time =millis();   // Start counting time to measure the exact execution time.
  Serial1.begin(9600);
  if(Serial1.available() > 0)
  {
    readXBee = Serial1.read();    // Read the number sent through XBee by the remote controller.
    delay(200);

    switch(readXBee)
    {
      case 49:    // Pressed 1. button on the remote controller.
                  // Start 1. audio-visual displays.
                  
        playbackSynchro(songPin1, 1576, 800, 661, 771, 847, 1188, 2864);
        delay(4500);
        playbackSynchro(songPin1, 1576, 800, 661, 771, 847, 1188, 1268);
        delay(3000);
        playbackSynchro(songPin1, 1576, 800, 661, 771, 847, 1188, 1268);
        delay(4500);
        playbackSynchro(songPin1, 1576, 800, 661, 771, 847, 1188, 1268);
        delay(3000);
        playbackSynchro(songPin1, 1576, 800, 661, 771, 847, 1188, 1268);
        delay(5000);
       break;

      case 50:    // Pressed 2. button on the remote controller.
                  // Start 2. audio-visual displays.
                  
        playbackSynchro(songPin2, 1887, 1115, 964, 838, 708, 1028, 468);
        delay(3500);
        playbackSynchro(songPin2, 1887, 1115, 964, 838, 708, 1028, 468);
        delay(3000);
        playbackSynchro(songPin2, 1887, 1115, 964, 838, 708, 1028, 468);
        delay(2500);
        playbackSynchro(songPin2, 1887, 1115, 964, 838, 708, 1028, 468);
        delay(4000);
        playbackSynchro(songPin2, 1887, 1115, 964, 838, 708, 1028, 468);
        delay(5000);
        break;
      
      case 51:    // Pressed 3. button on the remote controller.
                  // Start purely acoustic display, no movements.
                  // Sum of 5 delay(12000) == execution time of this display.
                  
        playTrack(songPin3);
        delay(12000);         // Time counts from sending a signal to song player.
        playTrack(songPin3);
        delay(12000);
        playTrack(songPin3);
        delay(12000);
        playTrack(songPin3);
        delay(12000);
        playTrack(songPin3);
        delay(12000);
        break;
          
      case 52:    // Pressed 4. button on the remote controller.
                  // Start purely visual display, no song played.
                  
        playbackSynchro(0, 1887, 1115, 964, 838, 708, 1028, 468);
        delay(3000);
        playbackSynchro(0, 1887, 1115, 964, 838, 708, 1028, 468);
        delay(4000);
        playbackSynchro(0, 1887, 1115, 964, 838, 708, 1028, 468);
        delay(4500);
        playbackSynchro(0, 1887, 1115, 964, 838, 708, 1028, 468);
        delay(2500);
        playbackSynchro(0, 1887, 1115, 964, 838, 708, 1028, 468);
        delay(5000);    
        break;
            
      default:
        Serial.println(readXBee);
    } 
  }
  
  else if (!Serial1.available() > 0)
  {
    digitalWrite(songPin0, HIGH);
    digitalWrite(songPin1, HIGH);
    digitalWrite(songPin2, HIGH);
    digitalWrite(songPin3, HIGH);
    digitalWrite(songPin4, HIGH);
    digitalWrite(songPin5, HIGH);
  }
}
void playTrack (int track)

// Activate corresponding SongPin of the player.
{
  Serial.println(Serial1.read());
  digitalWrite(track, LOW);
  delay(200);
  digitalWrite(track, HIGH);
  Serial1.end();
}

void playbackSynchro (int track, int delay1, int delay2, int delay3, int delay4, int delay5, int delay6, int delay7)

// Function sets the exact timing of 6 wing movements during specified song playback.

  {
    playTrack(track);
    Serial.println(millis());     // Print exact time (only when conncted to computer).
    servoL.write(14);
    servoR.write(34);
    delay(1);
    Serial.println(millis());
    delay(delay1);                // Time counts from sending a signal to song player.
    Serial.println(millis());
    wingsUp(14, 34, 5, 1);        // Takes 66 miliseconds.
    wingsDown(14, 34, 5, 1);      // Takes 66 miliseconds.
    Serial.println(millis());
    delay(delay2);
    Serial.println(millis());
    wingsUp(14, 34, 5, 1);
    wingsDown(14, 34, 5, 1);    
    Serial.println(millis());
    delay(delay3); 
    Serial.println(millis());
    wingsUp(14, 34, 5, 1);
    wingsDown(14, 34, 5, 1);    
    Serial.println(millis());
    delay(delay4);
    Serial.println(millis());
    wingsUp(14, 34, 5, 1);
    wingsDown(14, 34, 5, 1);    
    Serial.println(millis());
    delay(delay5);
    Serial.println(millis());
    wingsUp(14, 34, 5, 1);
    wingsDown(14, 34, 5, 1);    
    Serial.println(millis());
    delay(delay6);
    Serial.println(millis());
    wingsUp(14, 34, 5, 1);
    wingsDown(14, 34, 5, 1);    
    Serial.println(millis());
    delay(delay7);
    Serial.println(millis());
  }

void wingsDown(int lowestWingPosition, int highestWingPosition, int delay1, int delay2)
 {
  int internalMovementRange = highestWingPosition - lowestWingPosition - 8;
 
 // Accelerate smoothly at the beginning of the movement.
 for (int z = 0; z <= 4; z += 1) {    //
    servoL.write(highestWingPosition - z);
    servoR.write(lowestWingPosition + z);
    delay(delay1-z);
 }
 
 // Move with the full speed.
 for (int z = 0; z <= internalMovementRange; z += 1) {
    servoL.write(highestWingPosition - 4 - z);
    servoR.write(lowestWingPosition +4 + z);
    delay(delay2);
  }

 // Decelerate smoothly at the end of the movement.
 for (int z = 0; z <= 4; z += 1) {
    servoL.write(highestWingPosition - 4 - internalMovementRange - z);
    servoR.write(lowestWingPosition + 4 + internalMovementRange + z);
    delay(delay1+z);
  }
 }

void wingsUp (int lowestWingPosition, int highestWingPosition, int delay1, int delay2)
 {
  int internalMovementRange = highestWingPosition - lowestWingPosition - 8;
  
 // Accelerate smoothly at the beggining of the movement.
 for (int z = 0; z <= 4; z += 1) {
    servoL.write(lowestWingPosition + z);
    servoR.write(highestWingPosition - z);
    delay(delay1-z);
  }
         
 // Move with the full speed.
 for (int z = 0; z <= internalMovementRange; z += 1) {
    servoL.write(lowestWingPosition + 4 + z);
    servoR.write(highestWingPosition - 4 -z);
    delay(delay2);          
  }

 // Decelerate smoothly at the end of the movement.
 for (int z = 0; z <= 4; z += 1) {
    servoL.write(lowestWingPosition + 4 + internalMovementRange + z);
    servoR.write(highestWingPosition - 4 - internalMovementRange - z);
    delay(delay1+z);
  }
}
