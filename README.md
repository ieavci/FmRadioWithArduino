tr- TEA5767 radyo modülü kullanarak kendi radyomuzu yapıyoruz. <br>
en- We make our own radio using the TEA5767 radio module.

<hr>
<h2>Electronic circuit parts</h2>
<ul>
  <li>Arduino UNO</li>
  <li>TEA5767 radio module</li>
  <li>Breadbord</li>
  <li>Jumper</li>
</ul>


<h2>Breadboard Schematic Circuit</h2>
<img src="https://github.com/ieavci/FmRadioWithArduino/blob/main/schematic%20circuit/radyotinker.jpg" alt="Proje Resmi" style="max-width:100%; height:auto;">



<h2>Libraries</h2>
<ul>
  <li>SPI.h</li>
  <li>TEA5767.h</li>
  <li>Wire.h</li>  
</ul>


<h2>Code</h2>
<bold>Example to run on serial monitor: FREQ:88.2</bold>

```html
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


