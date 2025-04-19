// C++ Assignment 5: StableNucleus.cpp
// ID: 11010580
// Date: 19th April 2025
// Implements the StableNucleus class, which inherits from the Nucleus class and represents stable nuclei.

#include "stablenucleus.h"
#include <iostream>
#include <iomanip>


StableNucleus::StableNucleus(double atomic_mass, int atomic_number, const std::string& nucleus_type)
  : Nucleus(atomic_mass, atomic_number, nucleus_type) {}
// Destructor for stable nucleus class (default destructor, stated for completeness)
StableNucleus::~StableNucleus() = default;
// Copy constructor
StableNucleus::StableNucleus(const StableNucleus& other)
  : Nucleus(other) {}
// Copy assignment operator
StableNucleus& StableNucleus::operator=(const StableNucleus& other) {
  if (this != &other) {
    Nucleus::operator=(other);
  }
  return *this;
}
// Move constructor
StableNucleus::StableNucleus(StableNucleus&& other) noexcept
  : Nucleus(std::move(other)) {}
// Move assignment operator
StableNucleus& StableNucleus::operator=(StableNucleus&& other) noexcept {
  if (this != &other) {
    Nucleus::operator=(std::move(other));
  }
  return *this;
}

// Prints stable nucleus data in same style as radioactive nucleus
void StableNucleus::print_data() const {
  std::cout << "=== Nucleus data ===\n";
  std::cout << "Stable Nucleus: " << nucleus_type_
            << " (Z=" << atomic_number_
            << ", A=" << std::fixed << std::setprecision(3) << atomic_mass_ << ")\n";
  std::cout << "Status: Stable nucleus\n";
}

// Stable nuclei do not decay, so the decay function is overridden to do nothing
void StableNucleus::decay() {
  std::cout << "\n==== Decaying " << nucleus_type_ << "...====\n";
  std::cout << "Error: stable nucleus cannot decay.\n";
}

