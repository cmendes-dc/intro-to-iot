#include <LiquidCrystal.h>  // Include the LiquidCrystal library to control the LCD display

// Define the pin connected to the pushbutton
const int buttonPin = 3;

// Define the LCD pin connections: RS, Enable, Data4, Data5, Data6, Data7
const int rs = 7, en = 8, d4 = 9, d5 = 10, d6 = 11, d7 = 12;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);  // Create an LCD object with those pin assignments

void setup() {
  pinMode(buttonPin, INPUT);   // Set the button pin as INPUT (active HIGH when pressed)
  lcd.begin(16, 2);            // Initialize the LCD (16 columns, 2 rows)
  Serial.begin(9600);          // Start Serial Monitor for debugging output
  randomSeed(analogRead(0));   // Seed the random number generator using a floating analog pin
}

void loop() {
  lcd.clear();                 // Clear the LCD screen
  lcd.print("Press to Start"); // Display instruction to the player

  // Wait here until the player presses the button
  // Assumes the button is wired to be HIGH when pressed
  while (digitalRead(buttonPin) == HIGH) {
    // Just looping until the button is pressed
  }

  // Small delay to debounce the button press (remove mechanical bounce noise)
  delay(200);

  // Call the function that runs the reaction timer game
  reactionGame();
}

void reactionGame() {
  lcd.clear();                 // Clear the LCD screen
  lcd.print("Get Ready...");   // Inform the player to get ready

  // Generate a random delay between 3 to 6 seconds (3000-6000 ms)
  int randDelay = random(3000, 6000);
  delay(randDelay);            // Wait for the random period to make the start unpredictable

  lcd.clear();                 
  lcd.print("Press NOW!");     // Prompt the player to press the button as fast as possible

  unsigned long startTime = millis();  // Record the time right after showing "Press NOW!"

  // Wait here until the player presses the button
  // Assumes the button is wired HIGH when pressed
  while (digitalRead(buttonPin) == HIGH) {
    // Loop keeps running until the player reacts and presses the button
  }

  // Calculate the reaction time by subtracting the start time from the current time
  unsigned long reactionTime = millis() - startTime;

  // Display the reaction time on the LCD
  lcd.clear();
  lcd.print("Your time:");
  lcd.setCursor(0, 1);         // Move to the second row
  lcd.print(reactionTime);     // Show the reaction time in milliseconds
  lcd.print(" ms");

  // Print the same reaction time to the Serial Monitor for debugging or analysis
  Serial.print("Reaction Time: ");
  Serial.print(reactionTime);
  Serial.println(" ms");

  delay(3000);                 // Keep the result displayed for 3 seconds before returning
}