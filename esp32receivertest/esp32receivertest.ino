#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEScan.h>

BLEScan *scanner;

void setup() {
  Serial.begin(115200);

  BLEDevice::init("");

  scanner = BLEDevice::getScan();
  scanner->setActiveScan(true);

  Serial.println("BLE receiver start:");
}

void loop() {
  Serial.println("Scanning...");

  BLEScanResults *results = scanner->start(5, false);

  bool foundTarget = false;

  for (int i = 0; i < results->getCount(); i++) {
    BLEAdvertisedDevice device = results->getDevice(i);

    if (device.haveName() && device.getName() == "ESP32_Target") {
      foundTarget = true;

      Serial.println("Target found");
      Serial.print("Device: ");
      Serial.println(device.getName().c_str());

      Serial.print("RSSI: ");
      Serial.print(device.getRSSI());
      Serial.println(" dBm");

    }
  }

  if (!foundTarget) {
    Serial.println("ESP32_Target not found");
  }

  scanner->clearResults();

  delay(5000);
}