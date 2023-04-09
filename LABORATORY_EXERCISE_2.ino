#include <SPI.h>
#include <SD.h>

File myFile;

void setup() {
  Serial.begin(9600);

  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  Serial.print("Initializing SD card...");

  if (!SD.begin(53)) {
    Serial.println("SD card initialization failed!");
    return;
  }

  Serial.println("SD card initialization done.");
  Serial.println("Enter 'write <filename>'");
  Serial.println("Enter 'delete <filename>'");
  Serial.println("Enter 'read <filename>'");
}

void loop() {
  // Wait for user input
  while (!Serial.available());
  // Read user input
  String inputString = Serial.readStringUntil('\n');
  inputString.trim();

  if (inputString.startsWith("write")) {
    // Get file name from user and open file for writing
    String fileName = inputString.substring(6);
    myFile = SD.open(fileName, FILE_WRITE);

    if (myFile) {
      Serial.print("Enter data to write: ");
      while (!Serial.available());
      String dataString = Serial.readStringUntil('\n');
      dataString.trim();
      myFile.println(dataString);
      myFile.close();
      Serial.println("Data written to file.");
    } else {
      Serial.println("Error opening file.");
    }
  } else if (inputString.startsWith("read")) {
    // Get file name from user and open file for reading
    String fileName = inputString.substring(5);
    myFile = SD.open(fileName);

    if (myFile) {
      // Read data from file and print to serial monitor
      while (myFile.available()) {
        Serial.write(myFile.read());
      }
      myFile.close();
    } else {
      Serial.println("Error opening file.");
    }
  } else if (inputString.startsWith("delete")) {
    // Get file name from user and delete the file
    String fileName = inputString.substring(7);
    if (SD.remove(fileName)) {
      Serial.println("File deleted.");
    } else {
      Serial.println("Error deleting file.");
    }
  } else {
    Serial.println("Invalid input. Enter 'write <filename>' to write data to a file, 'read <filename>' to read data from a file, or 'delete <filename>' to delete a file.");
  }
}
