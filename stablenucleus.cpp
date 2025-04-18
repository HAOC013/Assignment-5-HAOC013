// C++ Assignment 5: StableNucleus class implmentation
// ID: 11010580
// Date: 19th April 2025
//

#include "stablenucleus.h"
#include <iostream>

StableNucleus::StableNucleus(double atomic_mass, int atomic_number, const std::string& nucleus_type)
  : Nucleus(atomic_mass, atomic_number, nucleus_type) {}

StableNucleus::~StableNucleus() = default;

StableNucleus::StableNucleus(const StableNucleus& other)
  : Nucleus(other) {}

StableNucleus& StableNucleus::operator=(const StableNucleus& other) {
  if (this != &other) {
    Nucleus::operator=(other);
  }
  return *this;
}

StableNucleus::StableNucleus(StableNucleus&& other) noexcept
  : Nucleus(std::move(other)) {}

StableNucleus& StableNucleus::operator=(StableNucleus&& other) noexcept {
  if (this != &other) {
    Nucleus::operator=(std::move(other));
  }
  return *this;
}

void StableNucleus::decay() {
  std::cout << "Stable nucleus cannot decay.\n";
}

void StableNucleus::print_data() const {
  std::cout << "Stable Nucleus: " << nucleus_type_
            << " (Z=" << atomic_number_ << ", A=" << atomic_mass_ << ")\n";
}
