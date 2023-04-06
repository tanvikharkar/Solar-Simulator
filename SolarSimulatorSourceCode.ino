// Solar Simulator LED Intensity Code
// Tanvi Kharkar, Mitchel Hutcheson, Jake Meyers EE 461/462 'Design of an LED Based Solar Simulator'


// LED color and corresponding Arduino pin
const int RED = 3;
const int GREEN = 4;
const int WHITE = 5;
const int FAR_RED = 6;
const int BLUE = 7;
const int AMBER = 8;
const int UV = 9;
const int CYAN = 10;
const int VIOLET = 11;
const int A_HIGH = 255;

float LED_output;

char key;
String press_key;
int num_key;

void setup() {
  Serial.begin(9600);
  
  pinMode(FAR_RED, OUTPUT);
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(UV, OUTPUT);
  pinMode(VIOLET, OUTPUT);
  pinMode(WHITE, OUTPUT);
  pinMode(BLUE, OUTPUT);
  pinMode(AMBER, OUTPUT);
  pinMode(CYAN, OUTPUT);
  
  Serial.print("Enter an intensity value from 0 to 100: ");

  while (!Serial){
    // Wait until a user input is entered from the computer keyboard
  }
}

void loop() {
  if (Serial.available() > 0){  // If a key is pressed
    key = Serial.read();  // Reads key press

    // LED INTENSITY CONTROL      
    // Key press '0' = 0% intensity, '1' = 10% intensity, ... , '9' = 90% intensity
    // '$' = 100% intensity. LED intensity can be changed in increments of 10%
    if (key == '0' || key == '1' || key == '2' || key == '3' || key == '4' || key == '5'
        || key == '6' || key == '7' || key == '8' || key == '9' || key == '$'){
          
      if (key == '$'){
        String press_key = "10";
        Serial.print(press_key.toInt() * 10);
        Serial.print("%");
        num_key = press_key.toInt();
      }
      
      else{
        String press_key = String(key);
        Serial.print(press_key.toInt() * 10);
        Serial.print("%");
        num_key = press_key.toInt();
      }
      LED_output = (1 - (float(num_key) / 10)) * A_HIGH; // Formula for controlling LED intensity based on user input
      Serial.print("\nLED Color: ");
    }

    // LED COLOR CONTROL
    // Far Red
    else if (key == 'f' || key == 'F'){
      Serial.print("Far Red");
      analogWrite(FAR_RED, LED_output);
      Serial.print("\n\nEnter an intensity value from 0% to 100%: ");      
    }
    
    // Red
    else if (key == 'r' || key == 'R'){
      Serial.print("Red");
      analogWrite(RED, LED_output);
      Serial.print("\n\nEnter an intensity value from 0% to 100%: ");
    }

    // Green
    else if (key == 'g' || key == 'G'){
      Serial.print("Green");
      analogWrite(GREEN, LED_output);
      Serial.print("\n\nEnter an intensity value from 0% to 100%: ");
    }

    // UV
    else if (key == 'u' || key == 'U'){
      Serial.print("UV");
      analogWrite(UV, LED_output);
      Serial.print("\n\nEnter an intensity value from 0% to 100%: ");
    }
    
    // Violet
    else if (key == 'v' || key == 'V'){
      Serial.print("Violet");
      analogWrite(VIOLET, LED_output);
      Serial.print("\n\nEnter an intensity value from 0% to 100%: ");
    }

    // White
    else if (key == 'w' || key == 'W'){
      Serial.print("White");
      analogWrite(WHITE, LED_output);
      Serial.print("\n\nEnter an intensity value from 0% to 100%: ");
    }

    // Blue
    else if (key == 'b' || key == 'B'){
      Serial.print("Blue");
      analogWrite(BLUE, LED_output);
      Serial.print("\n\nEnter an intensity value from 0% to 100%: ");
    }

    // Amber
    else if (key == 'a' || key == 'A'){
      Serial.print("Amber");
      analogWrite(AMBER, LED_output);
      Serial.print("\n\nEnter an intensity value from 0% to 100%: ");
    }

    // Cyan
    else if (key == 'c' || key == 'C'){
      Serial.print("Cyan");
      analogWrite(CYAN, LED_output);
      Serial.print("\n\nEnter an intensity value from 0% to 100%: ");
    }

    // Everything
    else if (key == 'e' || key == 'E'){
      Serial.print("Everything");
      analogWrite(FAR_RED, LED_output);
      analogWrite(RED, LED_output);
      analogWrite(GREEN, LED_output);
      analogWrite(UV, LED_output);
      analogWrite(VIOLET, LED_output);
      analogWrite(WHITE, LED_output);
      analogWrite(BLUE, LED_output);
      analogWrite(AMBER, LED_output);
      analogWrite(CYAN, LED_output);
      Serial.print("\n\nEnter an intensity value from 0% to 100%: ");
    }
    
    // Adjusted Spectrum
    else if (key == 's' || key == 'S'){
      Serial.print("Adjusted Spectrum");
      analogWrite(FAR_RED, (1 - 0.8) * A_HIGH);
      analogWrite(RED, (1 - 0.3) * A_HIGH);
      analogWrite(AMBER, (1 - 1.0) * A_HIGH);
      analogWrite(GREEN, (1 - 0.1) * A_HIGH);
      analogWrite(CYAN, (1 - 0.9) * A_HIGH);
      analogWrite(BLUE, (1 - 1.0) * A_HIGH);
      analogWrite(VIOLET, (1 - 0.3) * A_HIGH);
      analogWrite(UV, (1 - 0.2) * A_HIGH);
      analogWrite(WHITE, (1 - 1.0) * A_HIGH);
      Serial.print("\n\nEnter an intensity value from 0% to 100%: ");
    }
  }
  // If a valid key is not pressed, program will wait for a valid user input to perform an action
}
