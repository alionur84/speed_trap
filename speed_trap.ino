// Sensörlerin bağlı olduğu pinler
const int sensor1Pin = 2; // İlk sensör pin
const int sensor2Pin = 3; // İkinci sensör pin

// Değişkenler
unsigned long sensor1Time = 0; // İlk sensörün geçiş zamanı
unsigned long sensor2Time = 0; // İkinci sensörün geçiş zamanı
unsigned long interval = 0; // İki sensör arasındaki zaman farkı
float distanceBetweenSensors = 10.0; // Sensörler arasındaki mesafe (örneğin, 10 cm)
float speed = 0.0; // Hesaplanan hız km/h cinsinden

void setup() {
  Serial.begin(9600); // Seri iletişimi başlat
  pinMode(sensor1Pin, INPUT); // Sensör pinlerini giriş olarak ayarla
  pinMode(sensor2Pin, INPUT);
}

void loop() {
  // İlk sensör algılandığında
  if (digitalRead(sensor1Pin) == HIGH) {
    sensor1Time = micros(); // İlk sensörün geçiş zamanını kaydet
  }

  // İkinci sensör algılandığında
  if (digitalRead(sensor2Pin) == HIGH) {
    sensor2Time = micros(); // İkinci sensörün geçiş zamanını kaydet
    interval = sensor2Time - sensor1Time; // İki sensör arasındaki zaman farkını hesapla
    speed = distanceBetweenSensors / (interval / 3600000000.0); // Hızı hesapla (km/s)
    speed *= 3600; // km/s cinsinden hızı km/h'ye çevir
    
    // Hızı seri monitöre yazdır
    Serial.print("Speed: ");
    Serial.print(speed);
    Serial.println(" km/h");
  }
}
