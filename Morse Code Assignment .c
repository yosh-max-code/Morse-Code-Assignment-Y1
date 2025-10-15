// Function declaration
  int charToPosition(char c);
  char Stak2Ascii(String stakCode);
  // Global variables
  bool FirstLetter = true;
  String currentSTAKformat = ""; //clears STAK string for next code everytime they are printed in output
  String commandBuffer = "";
  int yellowLED = 9;  // Yellow LED for ASCII to Stak transmission
  int redLED = 5; //Red LED for STAK to ASCII transmission
  #define potentiometer A0
  #define IR_Transmit A1
  #define IR_RECEIVER 2 
  bool isTIMode = false;
  String TIcommand = "";
  String lastTranslated = "";  // To keep track of recently translated characters







  // Lookup table for Stak Code values (A-Z and 0-9)
  const char* Ascii2Stak[] = {
      "@",      // A
      "!!@",    // B
      "!@^",    // C
      "@!",     // D
      "!",      // E
      "@@",     // F
      "!@@",    // G
      "!@!",    // H
      "!!",     // I
      "@!!",    // J
      "@^",     // K
      "!!^",    // L
      "!@",     // M
      "^@",     // N
      "^!",     // O
      "!^",     // P
      "@@@^",   // Q
      "!^@",    // R
      "!^!",    // S
      "^",      // T
      "^^",     // U
      "@@@",    // V
      "@!@",    // W
      "@!^",    // X
      "!^^",    // Y
      "@^!",    // Z
      "^!!!",    // 0
      "^!!@",   // 1
      "^!!^",   // 2
      "^!@!",   // 3
      "^!@@",   // 4
      "^!@^",   // 5
      "^!^!",   // 6
      "^!^@",   // 7
      "^!^^",   // 8
      "^@!!",   // 9
      "^!!",    // Full stop (.)
      "^!@",    // Comma (,)
      "^@!",    // Apostrophe (')
      "^@@",    // Question Mark (?)
      "^@^",    // Exclamation Mark (!)
      "^^!",    // Plus (+)
      "^^@",    // Minus (-)
      "^^^",    // Multiply (*)
      "^!^",    // Divide (/)
      "^@@@^"   // Equals (=)
  };
  int Pot2TIMEUNIT() {
      int MeterValue = analogRead(potentiometer); //read current 
      return map(MeterValue, 0, 1023, 15, 300);
  }
  void setup() {
      Serial.begin(9600);
      pinMode(yellowLED, OUTPUT); 
      pinMode(redLED, OUTPUT);
    pinMode(IR_Transmit, OUTPUT);
    pinMode(IR_RECEIVER, INPUT);  
  }
  void StakLED(String stakCode) {
      int timeUnit = Pot2TIMEUNIT();  // Get timing from potentiometer
      
      // Process first character
      if (stakCode[0] == '!') {
          digitalWrite(yellowLED, HIGH);
          delay(timeUnit);           // 1 unit
          digitalWrite(yellowLED, LOW);
          delay(timeUnit);           // 1 unit gap
      }
      else if (stakCode[0] == '@') {
          digitalWrite(yellowLED, HIGH);
          delay(timeUnit * 2);       // 2 units
          digitalWrite(yellowLED, LOW);
          delay(timeUnit);           // 1 unit gap
      }
      else if (stakCode[0] == '^') {
          digitalWrite(yellowLED, HIGH);
          delay(timeUnit * 4);       // 4 units
          digitalWrite(yellowLED, LOW);
          delay(timeUnit);           // 1 unit gap
      }
      // Process second character
      if (stakCode.length() > 1) {
          if (stakCode[1] == '!') {
              digitalWrite(yellowLED, HIGH);
              delay(timeUnit);
              digitalWrite(yellowLED, LOW);
              delay(timeUnit);
          }
          else if (stakCode[1] == '@') {
              digitalWrite(yellowLED, HIGH);
              delay(timeUnit * 2);
              digitalWrite(yellowLED, LOW);
              delay(timeUnit);
          }
          else if (stakCode[1] == '^') {
              digitalWrite(yellowLED, HIGH);
              delay(timeUnit * 4);
              digitalWrite(yellowLED, LOW);
              delay(timeUnit);
          }
      }
      // Process third character
      if (stakCode.length() > 2) {
          if (stakCode[2] == '!') {
              digitalWrite(yellowLED, HIGH);
              delay(timeUnit);
              digitalWrite(yellowLED, LOW);
              delay(timeUnit);
          }
          else if (stakCode[2] == '@') {
              digitalWrite(yellowLED, HIGH);
              delay(timeUnit * 2);
              digitalWrite(yellowLED, LOW);
              delay(timeUnit);
          }
          else if (stakCode[2] == '^') {
              digitalWrite(yellowLED, HIGH);
              delay(timeUnit * 4);
              digitalWrite(yellowLED, LOW);
              delay(timeUnit);
          }
      }
  }
  void AsciiLED(String stakCode) {
      int timeUnit = Pot2TIMEUNIT();  // Get timing from potentiometer
      
      // Process first character
      if (stakCode[0] == '!') {
          digitalWrite(redLED, HIGH);
          delay(timeUnit);           // 1 unit
          digitalWrite(redLED, LOW);
          delay(timeUnit);           // 1 unit gap
      }
      else if (stakCode[0] == '@') {
          digitalWrite(redLED, HIGH);
          delay(timeUnit * 2);       // 2 units
          digitalWrite(redLED, LOW);
          delay(timeUnit);           // 1 unit gap
      }
      else if (stakCode[0] == '^') {
          digitalWrite(redLED, HIGH);
          delay(timeUnit * 4);       // 4 units
          digitalWrite(redLED, LOW);
          delay(timeUnit);           // 1 unit gap
      }
      // Process second character
      if (stakCode.length() > 1) {
          if (stakCode[1] == '!') {
              digitalWrite(redLED, HIGH);
              delay(timeUnit);
              digitalWrite(redLED, LOW);
              delay(timeUnit);
          }
          else if (stakCode[1] == '@') {
              digitalWrite(redLED, HIGH);
              delay(timeUnit * 2);
              digitalWrite(redLED, LOW);
              delay(timeUnit);
          }
          else if (stakCode[1] == '^') {
              digitalWrite(redLED, HIGH);
              delay(timeUnit * 4);
              digitalWrite(redLED, LOW);
              delay(timeUnit);
          }
      }
      // Process third character
      if (stakCode.length() > 2) {
          if (stakCode[2] == '!') {
              digitalWrite(redLED, HIGH);
              delay(timeUnit);
              digitalWrite(redLED, LOW);
              delay(timeUnit);
          }
          else if (stakCode[2] == '@') {
              digitalWrite(redLED, HIGH);
              delay(timeUnit * 2);
              digitalWrite(redLED, LOW);
              delay(timeUnit);
          }
          else if (stakCode[2] == '^') {
              digitalWrite(redLED, HIGH);
              delay(timeUnit * 4);
              digitalWrite(redLED, LOW);
              delay(timeUnit);
          }
      }
  } 


 void sendIRPulse() {
    tone(IR_Transmit, 38000);    // Turn on IR LED at 38kHz
    delay(10);              // Keep it on for 10ms
    
    // Check if receiver detected the signal (receiver outputs LOW when IR detected)
    if (digitalRead(IR_RECEIVER) == LOW) {
        Serial.println("IR signal transmitted and received");
    } else {
        Serial.println("IR signal not detected");
    }
    
    noTone(IR_Transmit);         // Turn off IR LED
    delay(10);              // Wait 10ms
}

 void loop() {
    if (Serial.available() > 0) {
        char input = Serial.read();
        char inputAscii = toUpperCase(input);
        
        // Check if part of STAK code
        if (input == '@' || input == '^' || input == '!' || input == '=') {
            commandBuffer += input;
            
            // Check for PSV command in STAK format
            if (commandBuffer == "!^=!^!=@@@") {
                //immediately clear out 
                commandBuffer = "";
                currentSTAKformat = "";
                // Read potentiometer and convert to 4 digits
                int meterValue = analogRead(potentiometer);
                String fourDigits = String(meterValue);
                if (meterValue < 10) {
                    fourDigits = "000" + fourDigits;
                }
                else if (meterValue < 100) {
                    fourDigits = "00" + fourDigits;
                }
                else if (meterValue < 1000) {
                    fourDigits = "0" + fourDigits;
                }
                
                Serial.print("V: Potientometer Reading in STAK: ");
                // First digit
                String stakCode = Ascii2Stak[charToPosition(fourDigits[0])];
                Serial.print(stakCode);
                AsciiLED(stakCode);
                delay(Pot2TIMEUNIT());
                
                // Second digit
                stakCode = Ascii2Stak[charToPosition(fourDigits[1])];
                Serial.print("=");
                Serial.print(stakCode);
                AsciiLED(stakCode);
                delay(Pot2TIMEUNIT());
                
                // Third digit
                stakCode = Ascii2Stak[charToPosition(fourDigits[2])];
                Serial.print("=");
                Serial.print(stakCode);
                AsciiLED(stakCode);
                delay(Pot2TIMEUNIT());
                
                // Fourth digit
                stakCode = Ascii2Stak[charToPosition(fourDigits[3])];
                Serial.print("=");
                Serial.println(stakCode);
                AsciiLED(stakCode);
                
                // Clear buffers
                commandBuffer = "";
                currentSTAKformat = "";
                return;  // Exit immediately after PSV command
            }
            
            // Regular STAK processing
             if (input == '=') {
                // Process the accumulated STAK code before the separator
                if (currentSTAKformat.length() > 0) {
                    char ascii = Stak2Ascii(currentSTAKformat);
                    if (ascii != '\0') {
                        Serial.print(ascii);
                        AsciiLED(currentSTAKformat);
                        lastTranslated += ascii;
                        delay(Pot2TIMEUNIT() * 3);
                    }
                    currentSTAKformat = ""; // Clear for next character
                }
            } else {
                currentSTAKformat += input;
            }

            // If we've accumulated the full TI sequence (^=!!=) plus a number
         if (commandBuffer == "^=!!=") {
    // Let the normal translation continue, but prepare to check for number
    while(Serial.available() <= 0); // Wait for next input
    
    String stakDigit = "";
    while(Serial.available() > 0) {
        char digit = Serial.read();
        if(digit == '@' || digit == '^' || digit == '!') {
            stakDigit += digit;
        }
    }
    
    char translatedDigit = Stak2Ascii(stakDigit);
    if(isdigit(translatedDigit)) {
        int pulses = translatedDigit - '0';
        Serial.println("\nPulsing LED " + String(pulses) + " times");
        
        // New simpler loop implementation
        int count = 0;
        while(count < pulses) {
            sendIRPulse();
            delay(50);
            count = count + 1;
        }
    }
    
    // Clear the command buffer
    commandBuffer = "";
}
            return;
        }
        
        // Clear command Buffer for non-STAK characters
        commandBuffer = "";
        
        // Handle ASCII input
        if ((inputAscii >= 'A' && inputAscii <= 'Z') || 
            (inputAscii >= '0' && inputAscii <= '9') || inputAscii == '.' 
            || inputAscii == ',' || inputAscii == '\'' || inputAscii == '?'
            || inputAscii == '!' || inputAscii == '+' || inputAscii == '-'  
            || inputAscii == '*' || inputAscii == '/' || inputAscii == '=') {
            
            if (!FirstLetter) {
                Serial.print("=");
            }
            String stakCode = Ascii2Stak[charToPosition(inputAscii)];
            Serial.print(stakCode);
            StakLED(stakCode);
            digitalWrite(yellowLED, LOW);
            delay(Pot2TIMEUNIT() * 3);
            FirstLetter = false;
        }
        else if (inputAscii == '\n') {
            if (currentSTAKformat.length() > 0) {
                char ascii = Stak2Ascii(currentSTAKformat);
                if (ascii != '\0') {
                    Serial.print(ascii);
                    AsciiLED(currentSTAKformat);
                    delay(Pot2TIMEUNIT() * 3);
                }
                currentSTAKformat = "";
            }
            Serial.println();
            FirstLetter = true;
            lastTranslated = "";  // Clear the tracking string on newline
        }
        else if (inputAscii == ' ') {
            if (currentSTAKformat.length() > 0) {
                char ascii = Stak2Ascii(currentSTAKformat);
                if (ascii != '\0') {
                    Serial.print(ascii);
                    AsciiLED(currentSTAKformat);
                    delay(Pot2TIMEUNIT() * 3);
                }
                currentSTAKformat = "";
            }
            Serial.print(" ");
            FirstLetter = true;
            digitalWrite(yellowLED, LOW);
            delay(Pot2TIMEUNIT() * 6);
            lastTranslated = "";  // Clear the tracking string on space
        }
    }
}




  // Function that converts ASCII to position number
  int charToPosition(char c) {
      if (c == 'A') {
          return 0;
      }
      else if (c == 'B') {
          return 1;
      }
      else if (c == 'C') {
          return 2;
      }
      else if (c == 'D') {
          return 3;
      }
      else if (c == 'E') {
          return 4;
      }
      else if (c == 'F') {
          return 5;
      }
      else if (c == 'G') {
          return 6;
      }
      else if (c == 'H') {
          return 7;
      }
      else if (c == 'I') {
          return 8;
      }
      else if (c == 'J') {
          return 9;
      }
      else if (c == 'K') {
          return 10;
      }
      else if (c == 'L') {
          return 11;
      }
      else if (c == 'M') {
          return 12;
      }
      else if (c == 'N') {
          return 13;
      }
      else if (c == 'O') {
          return 14;
      }
      else if (c == 'P') {
          return 15;
      }
      else if (c == 'Q') {
          return 16;
      }
      else if (c == 'R') {
          return 17;
      }
      else if (c == 'S') {
          return 18;
      }
      else if (c == 'T') {
          return 19;
      }
      else if (c == 'U') {
          return 20;
      }
      else if (c == 'V') {
          return 21;
      }
      else if (c == 'W') {
          return 22;
      }
      else if (c == 'X') {
          return 23;
      }
      else if (c == 'Y') {
          return 24;
      }
      else if (c == 'Z') {
          return 25;
      }
      else if (c == '0') {
          return 26;
      }
      else if (c == '1') {
          return 27;
      }
      else if (c == '2') {
          return 28;
      }
      else if (c == '3') {
          return 29;
      }
      else if (c == '4') {
          return 30;
      }
      else if (c == '5') {
          return 31;
      }
      else if (c == '6') {
          return 32;
      }
      else if (c == '7') {
          return 33;
      }
      else if (c == '8') {
          return 34;
      }
      else if (c == '9') {
          return 35;
      }
      else if (c == '.') {
          return 36;
      }
      else if (c == ',') {
          return 37;
      }
      else if (c == '\'') {
          return 38;
      }
      else if (c == '?') {
          return 39;
      }
      else if (c == '!') {
          return 40;
      }
      else if (c == '+') {
          return 41;
      }
      else if (c == '-') {
          return 42;
      }
      else if (c == '*') {
          return 43;
      }
      else if (c == '/') {
          return 44;
      }
      else if (c == '=') {
          return 45;
      }
  }
  // Function that converts STAK code to ASCII
  char Stak2Ascii(String stakCode) {
      if (stakCode == "@") {
          return 'A';
      }
      else if (stakCode == "!!@") {
          return 'B';
      }
      else if (stakCode == "!@^") {
          return 'C';
      }
      else if (stakCode == "@!") {
          return 'D';
      }
      else if (stakCode == "!") {
          return 'E';
      }
      else if (stakCode == "@@") {
          return 'F';
      }
      else if (stakCode == "!@@") {
          return 'G';
      }
      else if (stakCode == "!@!") {
          return 'H';
      }
      else if (stakCode == "!!") {
          return 'I';
      }
      else if (stakCode == "@!!") {
          return 'J';
      }
      else if (stakCode == "@^") {
          return 'K';
      }
      else if (stakCode == "!!^") {
          return 'L';
      }
      else if (stakCode == "!@") {
          return 'M';
      }
      else if (stakCode == "^@") {
          return 'N';
      }
      else if (stakCode == "^!") {
          return 'O';
      }
      else if (stakCode == "!^") {
          return 'P';
      }
      else if (stakCode == "@@@^") {
          return 'Q';
      }
      else if (stakCode == "!^@") {
          return 'R';
      }
      else if (stakCode == "!^!") {
          return 'S';
      }
      else if (stakCode == "^") {
          return 'T';
      }
      else if (stakCode == "^^") {
          return 'U';
      }
      else if (stakCode == "@@@") {
          return 'V';
      }
      else if (stakCode == "@!@") {
          return 'W';
      }
      else if (stakCode == "@!^") {
          return 'X';
      }
      else if (stakCode == "!^^") {
          return 'Y';
      }
      else if (stakCode == "@^!") {
          return 'Z';
      }
      else if (stakCode == "^!!!") {
          return '0';
      }
      else if (stakCode == "^!!@") {
          return '1';
      }
      else if (stakCode == "^!!^") {
          return '2';
      }
      else if (stakCode == "^!@!") {
          return '3';
      }
      else if (stakCode == "^!@@") {
          return '4';
      }
      else if (stakCode == "^!@^") {
          return '5';
      }
      else if (stakCode == "^!^!") {
          return '6';
      }
      else if (stakCode == "^!^@") {
          return '7';
      }
      else if (stakCode == "^!^^") {
          return '8';
      }
      else if (stakCode == "^@!!") {
          return '9';
      }
      else if (stakCode == "^!!") {
          return '.';
      }
      else if (stakCode == "^!@") {
          return ',';
      }
      else if (stakCode == "^@!") {
          return '\'';
      }
      else if (stakCode == "^@@") {
          return '?';
      }
      else if (stakCode == "^@^") {
          return '!';
      }
      else if (stakCode == "^^!") {
          return '+';
      }
      else if (stakCode == "^^@") {
          return '-';
      }
      else if (stakCode == "^^^") {
          return '*';
      }
      else if (stakCode == "^!^") {
          return '/';
      }
      else if (stakCode == "^@@@^") {
          return '=';
      }
      return '\0';  // Return null character if no match found

  }
