// Filename: StableNucleus.h
// Purpose: Declares StableNucleus class derived from Nucleus.
// Student ID: 
// Date: April 2025

#ifndef STABLE_NUCLEUS_H
#define STABLE_NUCLEUS_H

#include "Nucleus.h"

class StableNucleus : public Nucleus
{
public:
  StableNucleus(double atomic_mass, int atomic_number, const std::string& nucleus_type);
  void decay() override;
  void print_data() const override;
};

#endif // STABLE_NUCLEUS_H
