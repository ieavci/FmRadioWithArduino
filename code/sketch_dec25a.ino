#include <SPI.h>
#include <TEA5767.h>
#include <Wire.h>

TEA5767 Radio;

void setup() {
  Wire.begin();
  Radio.init();
  Serial.begin(9600); // Seri bağlantıyı başlat
}

void loop() {
  if (Serial.available() > 0) {
    String input = Serial.readStringUntil('\n'); // Seri porttan giriş al

    if (input.startsWith("FREQ:")) { // Gelen veri "FREQ:" ile başlıyorsa
      double newFreq = input.substring(5).toFloat(); // Frekans değerini al
      Radio.set_frequency(newFreq); // Yeni frekansı ayarla

      Serial.print("New frequency: ");
      Serial.println(newFreq);
    }
  }

  // Radyo durumunu oku ve seri monitöre yazdır
  unsigned char buf[5];
  if (Radio.read_status(buf) == 1) {
    double currentFreq = floor(Radio.frequency_available(buf) / 100000 + 0.5) / 10;

    Serial.print("Current frequency: ");
    Serial.println(currentFreq);
  }
  
  delay(500);
}
