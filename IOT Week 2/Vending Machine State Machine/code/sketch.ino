// Vending Machine State Machine

const int coinButton = 2;
const int buyButton = 3;
const int resetButton = 4;

const int redLED = 8;
const int greenLED = 9;

bool coinInserted = false;

void setup() {

  pinMode(coinButton, INPUT_PULLUP);
  pinMode(buyButton, INPUT_PULLUP);
  pinMode(resetButton, INPUT_PULLUP);

  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);

  Serial.begin(9600);

  digitalWrite(redLED, HIGH);
}

void loop() {

  // Insert Coin
  if (digitalRead(coinButton) == LOW && !coinInserted) {

    coinInserted = true;

    digitalWrite(redLED, LOW);
    digitalWrite(greenLED, HIGH);

    Serial.println("Coin Inserted");

    delay(300);
  }

  // Buy Item
  if (digitalRead(buyButton) == LOW && coinInserted) {

    Serial.println("Item Dispensed!");

    digitalWrite(greenLED, LOW);
    digitalWrite(redLED, HIGH);

    coinInserted = false;

    delay(300);
  }

  // Reset
  if (digitalRead(resetButton) == LOW) {

    coinInserted = false;

    digitalWrite(redLED, HIGH);
    digitalWrite(greenLED, LOW);

    Serial.println("Machine Reset");

    delay(300);
  }
}
