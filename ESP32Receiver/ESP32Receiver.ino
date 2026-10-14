#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEScan.h>

BLEScan *scanner;

void setup() {
  Serial.begin(115200);

  BLEDevice::init("");

  scanner = BLEDevice::getScan();
  scanner->setActiveScan(true);

  Serial.println("Bluetooth receiver started");
}

void loop() {
  Serial.println("Scanning for anchors");

  BLEScanResults *results = scanner->start(5, false);

  for (int i = 0; i < results->getCount(); i++) {
    BLEAdvertisedDevice device = results->getDevice(i);

    if (device.haveName()) {
      String name = device.getName().c_str();

      if (name == "ESP32_Anchor_1" ||
          name == "ESP32_Anchor_2" ||
          name == "ESP32_Anchor_3") {

        Serial.print(name);
        Serial.print(" RSSI: ");
        Serial.print(device.getRSSI());
        Serial.println(" dBm");
      }
    }
  }

  scanner->clearResults();
  delay(2000);
}
