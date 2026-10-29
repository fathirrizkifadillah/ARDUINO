// ============================================
// SISTEM DETEKSI BENDA
// Arduino + HC-SR04 + 3 LED + Buzzer
// ============================================

// Pin LED
const int ledPutih = 8;
const int ledKuning = 9;
const int ledMerah = 10;

// Pin sensor ultrasonik HC-SR04
const int trigPin = 11;
const int echoPin = 12;

// Pin buzzer
const int buzzer = 7;

// Batas jarak (cm)
const int jarakWaspada = 20;
const int jarakBahaya = 10;

void setup() {
    pinMode(ledPutih, OUTPUT);
    pinMode(ledKuning, OUTPUT);
    pinMode(ledMerah, OUTPUT);

    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);

    pinMode(buzzer, OUTPUT);

    digitalWrite(ledPutih, LOW);
    digitalWrite(ledKuning, LOW);
    digitalWrite(ledMerah, LOW);

    noTone(buzzer);

    Serial.begin(9600);
}

void loop() {
    // Membaca sensor ultrasonik
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);

    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    unsigned long durasi = pulseIn(echoPin, HIGH, 30000);

    // Jika sensor gagal membaca
    if (durasi == 0) {
        Serial.println("Sensor gagal membaca jarak");

        digitalWrite(ledPutih, LOW);
        digitalWrite(ledKuning, LOW);
        digitalWrite(ledMerah, LOW);

        noTone(buzzer);
    } else {
        // Menghitung jarak dalam centimeter
        float jarak = durasi * 0.0343 / 2;

        Serial.print("Jarak benda: ");
        Serial.print(jarak);
        Serial.println(" cm");

        // Kondisi 1: Benda jauh (> 20 cm)
        // LED putih menyala
        if (jarak > jarakWaspada) {
            digitalWrite(ledPutih, HIGH);
            digitalWrite(ledKuning, LOW);
            digitalWrite(ledMerah, LOW);

            noTone(buzzer);

            Serial.println("Status: NORMAL");
        }

        // Kondisi 2: Benda mulai mendekat (> 10-20 cm)
        // LED kuning menyala
        else if (jarak > jarakBahaya) {
            digitalWrite(ledPutih, LOW);
            digitalWrite(ledKuning, HIGH);
            digitalWrite(ledMerah, LOW);

            noTone(buzzer);

            Serial.println("Status: WASPADA");
        }

        // Kondisi 3: Benda sangat dekat (<= 10 cm)
        // LED merah dan buzzer aktif
        else {
            digitalWrite(ledPutih, LOW);
            digitalWrite(ledKuning, LOW);
            digitalWrite(ledMerah, HIGH);

            tone(buzzer, 1000);

            Serial.println("Status: BAHAYA!");
        }
    }

    delay(100);
}