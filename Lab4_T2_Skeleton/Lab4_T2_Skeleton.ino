/*Change all the ? in the code to Control the direction of rotation based on whether your selected pin is touched.*/

#define IN1   32  // Replace the ? with the GPIO pin you selected to connect IN1
#define IN2   22   // Replace the ? with the GPIO pin you selected to connect IN2
#define A  18 // Replace the ? with the GPIO pin you selected to connect encoder A
#define B  35 // Replace the ? with the GPIO pin you selected to connect encoder B


int A_data;
int B_data;

String command;

void setup() {
  Serial.begin(115200); //Define baud

  pinMode( IN1, OUTPUT);  // Set IN1 as an output pin
  pinMode(IN2, OUTPUT);  // Set IN2 as an output pin

  pinMode(A, INPUT);  // Set A as an input pin
  pinMode(B, INPUT);  // Set B as an input pin

}

void loop() {
   
    if (Serial.available() > 0) {
        command = Serial.readStringUntil('\n'); // Read the incoming command
        command.trim(); // Remove any leading or trailing whitespace
        if (command == "C") {
            // clockwise rotation
            digitalWrite(IN1, HIGH);
            digitalWrite(IN2, LOW); 

        } 
        else if (command == "A") { 
            // anticlockwise rotation
            digitalWrite(IN1, LOW);
            digitalWrite(IN2, HIGH); 
        }
        }
    // Read values of A and B using digitalRead(Pin)
    A_data=digitalRead(A);
    B_data=digitalRead(B);
    // Plot A B in Serial Plotter
    Serial.print("A:");
    Serial.print(A_data);
    Serial.print(",");
    Serial.print("B:");
    Serial.print(B_data);
    Serial.println("\t"); 
}
}
