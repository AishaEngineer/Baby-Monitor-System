/*
  Baby Monitor System
  Monitors infant temperature and sends SMS alert when temperature >= 38°C
  Components: Arduino Mega, MAX6675 Sensor, SIM900A GSM Module
*/

#include <MAX6675_Thermocouple.h>

// MAX6675 Pin Definitions
#define SCK_PIN 23
#define CS_PIN  25
#define SO_PIN  27

// GSM Module Serial (Serial2 on Arduino Mega)
#define GSM_SERIAL Serial2

// Temperature threshold
const float TEMP_THRESHOLD = 38.0;

// Timing variables
unsigned long lastSMSTime = 0;
unsigned long callStartTime = 0;
int alertState = 0;  // 0: normal, 1: SMS sent, 2: calling

MAX6675_Thermocouple* thermocouple = NULL;

void setup() {
  Serial.begin(9600);
  GSM_SERIAL.begin(9600);
  
  // Initialize MAX6675 sensor
  thermocouple = new MAX6675_Thermocouple(SCK_PIN, CS_PIN, SO_PIN);
  
  // Initialize GSM module
  GSM_SERIAL.println("AT");
  delay(1000);
  GSM_SERIAL.println("AT+CMGF=1");  // Set SMS to text mode
  delay(100);
  GSM_SERIAL.println("AT+CNMI=2,2,0,0,0");  // Set SMS indication
  delay(5);
  
  Serial.println("Baby Monitor System Ready");
}

void loop() {
  // Read temperature from sensor
  double celsius = thermocouple->readCelsius();
  
  Serial.print("Temperature: ");
  Serial.print(celsius);
  Serial.println(" °C");
  
  // Check if temperature exceeds threshold
  if (celsius >= TEMP_THRESHOLD) {
    handleHighTemperature(celsius);
  } else {
    // Reset alert state when temperature normalizes
    alertState = 0;
  }
  
  // Handle GSM responses
  if (GSM_SERIAL.available() > 0) {
    String response = GSM_SERIAL.readString();
    Serial.println("GSM Response: " + response);
    
    // Check for OK response after commands
    if (response.indexOf("OK") != -1) {
      Serial.println("Command executed successfully");
    }
  }
  
  delay(1000);  // Read every second
}

void handleHighTemperature(float temp) {
  Serial.println("⚠️ HIGH TEMPERATURE DETECTED!");
  
  switch(alertState) {
    case 0:  // Send SMS alert
      sendSMSAlert(temp);
      alertState = 1;
      lastSMSTime = millis();
      break;
      
    case 1:  // Wait 60 seconds then make call
      if (millis() >= lastSMSTime + 60000) {
        makePhoneCall();
        alertState = 2;
        callStartTime = millis();
      }
      break;
      
    case 2:  // Wait 60 seconds then hang up
      if (millis() >= callStartTime + 60000) {
        hangUpCall();
        alertState = 0;  // Reset to start
      }
      break;
  }
}

void sendSMSAlert(float temp) {
  GSM_SERIAL.println("AT+CMGF=1");  // Text mode
  delay(500);
  GSM_SERIAL.println("AT+CMGS=\"+967XXXXXXXXX\"");  // Replace with actual number
  delay(500);
  GSM_SERIAL.print("⚠️ BABY ALERT! Temperature is: ");
  GSM_SERIAL.print(temp);
  GSM_SERIAL.println(" °C");
  delay(500);
  GSM_SERIAL.write(26);  // Ctrl+Z to send SMS
  delay(5000);
  
  Serial.println("SMS Alert Sent");
}

void makePhoneCall() {
  GSM_SERIAL.println("ATD+967XXXXXXXXX;");  // Replace with actual number
  delay(1000);
  Serial.println("Making phone call...");
}

void hangUpCall() {
  GSM_SERIAL.println("ATH");  // Hang up
  delay(1000);
  Serial.println("Call ended");
}
