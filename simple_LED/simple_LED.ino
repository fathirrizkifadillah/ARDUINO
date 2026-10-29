// Pin LED
const int ledPutih = 8;
const int ledMerah = 9;
const int ledKuning = 10;

void setup() {
    pinMode(ledPutih, OUTPUT);
    pinMode(ledMerah, OUTPUT);
    pinMode(ledKuning, OUTPUT);
}

void loop() {
    // LED putih menyala
    digitalWrite(ledPutih, HIGH);
    digitalWrite(ledMerah, LOW);
    digitalWrite(ledKuning, LOW);
    delay(1000);

    // LED merah menyala
    digitalWrite(ledPutih, LOW);
    digitalWrite(ledMerah, HIGH);
    digitalWrite(ledKuning, LOW);
    delay(1000);

    // LED kuning menyala
    digitalWrite(ledPutih, LOW);
    digitalWrite(ledMerah, LOW);
    digitalWrite(ledKuning, HIGH);
    delay(1000);

    // Semua LED mati sebentar
    digitalWrite(ledPutih, LOW);
    digitalWrite(ledMerah, LOW);
    digitalWrite(ledKuning, LOW);
    delay(500);
}