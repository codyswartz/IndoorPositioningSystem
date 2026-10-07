#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>

void setup() {
  Serial.begin(115200);

  BLEDevice::init("ESP32_Target");

  BLEServer *server = BLEDevice::createServer();

  BLEAdvertising *advertising = BLEDevice::getAdvertising();
  advertising->start();

  Serial.println("Bluetooth Test Transmission.");
  Serial.println("Device name: ESP32_Target");
}

void loop() {
  Serial.println("Transmitting signal");
  delay(2000);
}