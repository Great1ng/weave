#pragma once

#include <atomic>

namespace weave::threads {

template <typename T>
using Atomic = std::atomic<T>;

}