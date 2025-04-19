// Filename: stablenucleus.h
// Purpose: Declares the StableNucleus class.
// Student ID: 11010580
// Date: 19th April 2025

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

  void decay() override;
  void print_data() const override;
};

#endif // STABLE_NUCLEUS_H
