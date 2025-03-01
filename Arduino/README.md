# DS2437 Library for Arduino

[DS2437.zip](https://github.com/honechko/DS2437/raw/main/Arduino/download/DS2437.zip)

## Dependencies

* [OneWire](https://www.pjrc.com/teensy/td_libs_OneWire.html), version with weak pullup [OneWire-2.3.7wp.zip](https://github.com/honechko/DS2437/raw/main/Arduino/download/OneWire-2.3.7wp.zip)
* [AltSoftSerial](https://www.pjrc.com/teensy/td_libs_AltSoftSerial.html), [AltSoftSerial.zip](https://github.com/honechko/DS2480/raw/main/Arduino/download/AltSoftSerial.zip)
* [DS2480B](https://github.com/collin80/DS2480B), fixed version [DS2480B_fixed.zip](https://github.com/honechko/DS2480/raw/main/Arduino/download/DS2480B_fixed.zip)

## Usage

```
#include <DS2437.h>
OneWire ow(10);
DS2437 mto(&ow);

byte addr[] = {0x1E,0x41,0x42,0x0F,0x48,0x4E,0x59,0x22};

void setup(void) {
  Serial.begin(9600);
}

void loop(void) {
  Serial.print("t = ");
  Serial.println(mto.temperature(addr) / 256.0);
  Serial.print("h = ");
  Serial.println(mto.humidity(addr) / 10.0);
  Serial.print("u = ");
  Serial.println(mto.user(addr, DEFAULT));
  delay(1000);
}
```

Look examples subdir for more examples.

## Library functions

* ```int16_t temperature(uint8_t *addr)```  
  return value: themperature in Celsius multiplied by 256 on success, -32768 on error  
* ```int16_t humidity(uint8_t *addr)```  
  return value: relative humidity in percents multiplied by 10 on success, -32768 on error  
* ```int16_t user(uint8_t *addr, uint8_t ref)```  
  return value: value from user's sensor on success, -32768 on error  
  ref: DEFAULT | INTERNAL  
  ADC reference, DEFAULT corresponds to VCC, INTERNAL corresponds to 1.1V  

