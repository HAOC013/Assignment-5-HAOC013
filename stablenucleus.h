// C++ Assignment 5: stablenucleus.h
// ID: 11010580
// Date: 19th April 2025
// Header file for the StableNucleus class, which inherits from the Nucleus class and represents stable nuclei.

#ifndef STABLE_NUCLEUS_H
#define STABLE_NUCLEUS_H

#include "nucleus.h"

class StableNucleus : public Nucleus {
public:
  StableNucleus(double atomic_mass, int atomic_number, const std::string& nucleus_type);
  ~StableNucleus();

  StableNucleus(const StableNucleus& other);
  StableNucleus& operator=(const StableNucleus& other);
  StableNucleus(StableNucleus&& other) noexcept;
  StableNucleus& operator=(StableNucleus&& other) noexcept;

// Overriding nucleus base class to allow different nucleus types to implement their own specific behaviors.
// these functions in the base class are just there as placeholders
  void decay() override;
  void print_data() const override;
};

#endif // STABLE_NUCLEUS_H
