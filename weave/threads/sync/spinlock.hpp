#pragma once

#include <weave/threads/thread.hpp>
#include <weave/threads/atomic.hpp>
#include <weave/threads/mem_ord.hpp>

namespace weave::threads::sync {

class SpinLock {
 public:
  inline void Lock() noexcept {
    while (!TryLock()) {
      while (state_.load(MemOrd::relaxed) == State::Locked) {
        // Back off
      }
    }
  }

  inline bool TryLock() noexcept {
    return state_.exchange(State::Locked, MemOrd::acquire) == State::Unlocked;
  }

  inline void Unlock() noexcept {
    state_.store(State::Unlocked, MemOrd::release);
  }

 private:
  enum class State : size_t {
    Unlocked,
    Locked
  };

  Atomic<State> state_{State::Unlocked};
};

}  // namespace weave::threads::sync
