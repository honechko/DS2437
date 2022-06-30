#include <DS2437.h>
OneWire ow(10); // DQ on pin 10, You also need 1k resistor between DQ and VCC
DS2437 mto(&ow);

void setup(void) {
  Serial.begin(9600);
}

void loop(void) {
  byte i, addr[8];

  if (!ow.search(addr)) {
    Serial.println("No more addresses.");
    ow.reset_search();
    delay(5000);
    return;
  }

  Serial.print("ROM =");
  for (i = 0; i < 8; i++) {
    Serial.write(' ');
    Serial.print(addr[i], HEX);
  }
  Serial.println();

  if (addr[0] == 0x1e) {
    Serial.print("  Temperature: ");
    Serial.println(mto.temperature(addr) / 256.0);
    Serial.print("  Relative Humidity: ");
    Serial.println(mto.humidity(addr) / 10.0);
    Serial.print("  User Sensor: ");
    Serial.println(mto.user(addr, DEFAULT));
  }
}

