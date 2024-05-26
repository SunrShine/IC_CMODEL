#ifndef __CHECKPOINT_H_
#define __CHECKPOINT_H_

#include <cstdint>

struct CheckPiont {
  CheckPiont(uint32_t wid, uint64_t val, uint32_t del) : _width(wid), _value(val), _delay(del) {
  }

  uint32_t _width;
  uint64_t _value;
  uint32_t _delay;
};

#endif