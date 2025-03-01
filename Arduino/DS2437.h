#ifndef DS2437_h
#define DS2437_h

#ifndef HAVE_DS2480B
#define HAVE_DS2480B 0
#endif

#if HAVE_DS2480B
#include <DS2480B.h>
#else
#include <OneWire.h>
#endif

class DS2437 {
  private:
#if HAVE_DS2480B
    DS2480B *_ow;
#else
    OneWire *_ow;
#endif

  public:
#if HAVE_DS2480B
    DS2437(DS2480B *ow) {
#else
    DS2437(OneWire *ow) {
#endif
      _ow = ow;
    };

    int16_t temperature(uint8_t *addr) {
      uint8_t buf[9];
      _ow->reset();
      _ow->select(addr);
      _ow->write(0x44); // CONVERT T
      delay(2);
      while (!_ow->read_bit());
      _ow->reset();
      _ow->select(addr);
      _ow->write(0xbe); // READ SCRATCHPAD
      _ow->write(0x00);
      _ow->read_bytes(buf, 9);
      return _ow->crc8(buf, 9) ? 0x8000 : (((int16_t)buf[2] << 8) | buf[1]);
    };
    int16_t humidity(uint8_t *addr) {
      uint8_t buf[9];
      _ow->reset();
      _ow->select(addr);
      _ow->write(0x4e); // WRITE SCRATCHPAD
      _ow->write(0x00);
      _ow->write(0x0f);
      _ow->reset();
      _ow->select(addr);
      _ow->write(0xb4); // CONVERT V
      delay(20);
      while (!_ow->read_bit());
      _ow->reset();
      _ow->select(addr);
      _ow->write(0xbe); // READ SCRATCHPAD
      _ow->write(0x00);
      _ow->read_bytes(buf, 9);
      return _ow->crc8(buf, 9) ? 0x8000 : (((int16_t)buf[4] << 8) | buf[3]);
    };
    int16_t user(uint8_t *addr, uint8_t ref) {
      uint8_t buf[9];
      _ow->reset();
      _ow->select(addr);
      _ow->write(0x4e); // WRITE SCRATCHPAD
      _ow->write(0x00);
      _ow->write(0x06 | ((ref == DEFAULT) ? 0x00 : 0x01));
      _ow->reset();
      _ow->select(addr);
      _ow->write(0xb4); // CONVERT V
      delay(2);
      while (!_ow->read_bit());
      _ow->reset();
      _ow->select(addr);
      _ow->write(0xbe); // READ SCRATCHPAD
      _ow->write(0x00);
      _ow->read_bytes(buf, 9);
      return _ow->crc8(buf, 9) ? 0x8000 : (((int16_t)buf[4] << 8) | buf[3]);
    };
};

#endif
