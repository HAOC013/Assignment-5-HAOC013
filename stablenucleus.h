// Filename: StableNucleus.h
// Purpose: Declares StableNucleus class with Rule of 5.
// Student ID: 
// Date: April 2025

#ifndef STABLE_NUCLEUS_H
#define STABLE_NUCLEUS_H

#include "nucleus.h"

class StableNucleus : public Nucleus {
public:
  StableNucleus(double atomic_mass, int atomic_number, const std::string& nucleus_type);
  ~StableNucleus();  // Rule of 5: Destructor

  StableNucleus(const StableNucleus& other);  // Rule of 5: Copy constructor
  StableNucleus& operator=(const StableNucleus& other);  // Copy assignment

  StableNucleus(StableNucleus&& other) noexcept;  // Move constructor
  StableNucleus& operator=(StableNucleus&& other) noexcept;  // Move assignment

  void decay() override;
  void print_data() const override;
};

#endif // STABLE_NUCLEUS_H
