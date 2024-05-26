#ifndef __PIPREGDELAY_H_
#define __PIPREGDELAY_H_

#include <cstddef>
#include <cstdint>
#include <vector>

template <class T> class PipRegDelay {

public:
  PipRegDelay() = default;
  ~PipRegDelay(){};
  PipRegDelay(PipRegDelay &pip) = delete;
  PipRegDelay &operator=(const PipRegDelay &pip) = delete;

  void init();
  void compulte(T *input);
  void update();

private:
  /**
   * @brief delay Queue and Output Reg
   *
   */
  size_t _delay_cycle = 1;
  std::vector<T *> _delayQ;
  T *_outQVal = nullptr;
  T *_inQVal = nullptr;
  size_t _atQin = 0;
  size_t _atQout = 1;
  size_t _atQin_next = 1;
  size_t _atQout_next = 2;
};

template <class T> void PipRegDelay<T>::compulte(T *input) {
  _inQVal = input;
  _atQin_next = (_atQin + 1) % _delay_cycle;
  _atQout_next = (_atQin_next + 1) % _delay_cycle;
}

template <class T> void PipRegDelay<T>::update() {
  _delayQ.at(_atQin) = _inQVal;
  _outQVal = _delayQ.at(_atQin);
  _atQin = _atQin_next;
  _atQout = _atQout_next;
}

#endif