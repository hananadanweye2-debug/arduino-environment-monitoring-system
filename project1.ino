#include <LiquidCrystal.h>
#include <Servo.h>

// Pin Definitions
int buzzerPin = 9;
int servoPin = 10;
int temperaturePin = A0;
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);
Servo myServo;
char receivedChar;

void setup() {
 pinMode(buzzerPin, OUTPUT);
 myServo.attach(servoPin);
 lcd.begin(16, 2); 
 lcd.setCursor(0, 0);
 lcd.print("Weather Monitor");
 Serial.begin(9600);
 delay(2000); // Display the message for 2 seconds
 lcd.clear(); // Clear the screen
 // Send an initial message to Serial Monitor
 Serial.println("Weather Monitoring Started");
}

void loop() {
 // Check if data is available from Bluetooth (HC-05 module)
 if (Serial.available()) {
 receivedChar = Serial.read(); // Read the incoming character
 if (receivedChar == 'B') { // Turn buzzer on (command 'B')
 digitalWrite(buzzerPin, HIGH);
 }
 if (receivedChar == 'b') { // Turn buzzer off (command 'b')
 digitalWrite(buzzerPin, LOW);
   }
 if (receivedChar == 'S') { // Turn servo to 90 degrees (command 'S')
 myServo.write(90);
 }
 if (receivedChar == 's') { // Turn servo back to 0 degrees (command 's')
 myServo.write(0);
 }
 }
  
  // Read temperature sensor (using analog pin A0)
 int temperatureReading = analogRead(temperaturePin);
 float voltage = temperatureReading * (5.0 / 1023.0);
 float temperature = (voltage - 0.5) * 100; // TMP36 gives 500mV at 0°C
 
   // Display temperature on the LCD
 lcd.setCursor(0, 0);
 lcd.print("Temp: ");
 lcd.print(temperature);
 lcd.print(" C");
 Serial.print("Temperature: ");
 Serial.print(temperature);
 Serial.println(" C");

  // Control servo motor based on temperature
 if (temperature > 30) {
 myServo.write(90); // Move servo to 90 degrees if temp > 30°C
 } else {
 myServo.write(0); // Move servo to 0 degrees if temp <= 30°C
 }
  // Generate different buzzing sounds based on temperature
 if (temperature < 20) {
 // Low temperature (< 20°C): Low-frequency buzzer sound
 tone(buzzerPin, 500); // 500 Hz sound
 }
   else if (temperature >= 20 && temperature <= 30) {
  // Medium temperature (20°C - 30°C): Medium-frequency buzzer sound
 tone(buzzerPin, 1000); // 1000 Hz sound
 }
  else if (temperature > 30) {
 tone(buzzerPin, 1500);
 }
   delay(2000);
   }