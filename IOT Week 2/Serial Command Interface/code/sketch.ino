// Serial Command Interface

char command;

void setup() {
  Serial.begin(9600);

  pinMode(13, OUTPUT);

  Serial.println("=== Serial Command Interface ===");
  Serial.println("Commands:");
  Serial.println("ON    -> Turn LED ON");
  Serial.println("OFF   -> Turn LED OFF");
  Serial.println("HELLO -> Print Greeting");
  Serial.println("STATUS-> LED Status");
  Serial.println("-----------------------------");
}

void loop() {

  if (Serial.available()) {

    String command = Serial.readStringUntil('\n');
    command.trim();
    command.toUpperCase();

    if (command == "ON") {
      digitalWrite(13, HIGH);
      Serial.println("LED Turned ON");
    }

    else if (command == "OFF") {
      digitalWrite(13, LOW);
      Serial.println("LED Turned OFF");
    }

    else if (command == "HELLO") {
      Serial.println("Hello! Welcome to Arduino.");
    }

    else if (command == "STATUS") {
      if (digitalRead(13))
        Serial.println("LED is ON");
      else
        Serial.println("LED is OFF");
    }

    else {
      Serial.println("Invalid Command!");
    }
  }
}
