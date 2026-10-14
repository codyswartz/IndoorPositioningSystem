#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>

void setup() {
  Serial.begin(115200);

  BLEDevice::init("ESP32_Anchor_2");

  BLEServer *server = BLEDevice::createServer();

  BLEAdvertising *advertising = BLEDevice::getAdvertising();
  advertising->start();

  Serial.println("transmitter started.");
  Serial.println("Device name: ESP32_Anchor_2");
}

void loop() {
  Serial.println("Transmitting BLE signal: ESP32_Anchor_2");
  delay(2000);
}
