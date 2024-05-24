#include <TinyGPS++.h>
#include <SoftwareSerial.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>
Adafruit_MPU6050 mpu;
// GPS modülü için RX ve TX pinleri
static const int RXPin = 4, TXPin = 3;
static const uint32_t GPSBaud = 9600;

// SoftwareSerial nesnesi
SoftwareSerial gpsSerial(RXPin, TXPin);

// TinyGPS++ nesnesi
TinyGPSPlus gps;

void setup() {
  Serial.begin(115200); // Bilgisayar ile seri haberleşme başlatılıyor
  gpsSerial.begin(GPSBaud); // GPS modülü için seri haberleşme başlatılıyor
  while (!Serial)
    delay(10);
  Serial.println("GPS modülü verileri okunuyor...");
  Serial.println("Adafruit MPU6050 test!");
  if (!mpu.begin()) {
    Serial.println("Failed to find MPU6050 chip");
    while (1) {
      delay(10);
    }
}

Serial.println("MPU6050 Found!");
  Serial.println("MPU6050 Found!");

  //setupt motion detection
  mpu.setHighPassFilter(MPU6050_HIGHPASS_0_63_HZ);
  mpu.setMotionDetectionThreshold(1);
  mpu.setMotionDetectionDuration(20);
  mpu.setInterruptPinLatch(true);	// Keep it latched.  Will turn off when reinitialized.
  mpu.setInterruptPinPolarity(true);
  mpu.setMotionInterrupt(true);

  Serial.println("");
  delay(100);
}

void loop() {
  // GPS modülünden veri oku
  while (gpsSerial.available() > 0) {
    char c = gpsSerial.read();
    gps.encode(c); // Alınan her karakteri TinyGPS++'a gönder
  }

  // Konum verisi güncellendiğinde
  if (gps.location.isUpdated()) {
    // Enlem, boylam ve hız bilgilerini yazdır
    Serial.print("Latitude: "); Serial.println(gps.location.lat(), 6);
    Serial.print("Longitude: "); Serial.println(gps.location.lng(), 6);
    Serial.print("Speed (km/s): "); Serial.println(gps.speed.kmph());
  }
  if(mpu.getMotionInterruptStatus()) {
    /* Get new sensor events with the readings */
    sensors_event_t a, g, temp;
    mpu.getEvent(&a, &g, &temp);

    /* Print out the values */
    Serial.print("AccelX:");
    Serial.print(a.acceleration.x);
    Serial.print(",");
    Serial.print("AccelY:");
    Serial.print(a.acceleration.y);
    Serial.print(",");
    Serial.print("AccelZ:");
    Serial.print(a.acceleration.z);
    Serial.print(", ");
    Serial.print("GyroX:");
    Serial.print(g.gyro.x);
    Serial.print(",");
    Serial.print("GyroY:");
    Serial.print(g.gyro.y);
    Serial.print(",");
    Serial.print("GyroZ:");
    Serial.print(g.gyro.z);
    Serial.println("");
  }

  delay(10);
}