#ifndef __PIPREGDELAY_H_
#define __PIPREGDELAY_H_

#include <cstddef>
#include <cstdint>
#include <vector>

template <class T>
class PipRegDelay {

public:
  PipRegDelay() = default;
  ~PipRegDelay(){};
  PipRegDelay(PipRegDelay &pip)                  = delete;
  PipRegDelay &operator=(const PipRegDelay &pip) = delete;

  void init();
  void compulte(T *input);
  void update();

private:
  /**
   * @brief delay Queue and Output Reg
   *
   */
  size_t _delay_cycle;
  std::vector<T *> _delayQ;
  T               *outQpVal;
  size_t           _atQin;
  size_t           _atQout;
  size_t           _atQin_next;
  size_t           _atQout_next;
};

template <class T>
void PipRegDelay<T>::compulte(T *input) {
  _delayQ.at(_atQin);
  _atQin_next = () ?;
}

template <class T>
void PipRegDelay<T>::update() {
  _atQin = _atQin_next;
  _atQout = _atQout_next;
  
}

#endif