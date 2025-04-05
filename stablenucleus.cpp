// Filename: StableNucleus.cpp
// Purpose: Implements StableNucleus methods.
// Student ID: 
// Date: April 2025

#include "StableNucleus.h"
#include <iostream>

StableNucleus::StableNucleus(double atomic_mass, int atomic_number, const std::string& nucleus_type)
  : Nucleus(atomic_mass, atomic_number, nucleus_type)
{
}

void StableNucleus::decay()
{
  std::cout << "Stable nucleus cannot decay.\\n";
}

void StableNucleus::print_data() const
{
  std::cout << "Stable Nucleus: " << nucleus_type_
            << " (Z=" << atomic_number_ << ", A=" << atomic_mass_ << ")\\n";
}
