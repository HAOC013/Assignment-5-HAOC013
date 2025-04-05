// Filename: RadioactiveNucleus.cpp
// Purpose: Implements decay logic for radioactive nuclei.
// Student ID: 
// Date: April 2025

#include "RadioactiveNucleus.h"
#include <iostream>

RadioactiveNucleus::RadioactiveNucleus(double atomic_mass, int atomic_number,
                                       const std::string& nucleus_type,
                                       double half_life, const std::vector<double>& photon_energies)
  : Nucleus(atomic_mass, atomic_number, nucleus_type),
    half_life_(half_life),
    photon_energies_(photon_energies)
{
}

void RadioactiveNucleus::decay()
{
  if (decayed_) return;

  std::cout << "Decaying " << nucleus_type_ << "...\n";

for (double energy : photon_energies_) {
  auto photon = std::make_shared<Photon>(energy);
  std::cout << "  Emitted photon:\n    ";
  photon->print_data();
  emitted_photons_.push_back(photon);
}

// Challenge: positron emission for Na
if (nucleus_type_ == "Na") {
  std::cout << "  Positron emitted (β⁺ decay)\n";
}


  decayed_ = true;
}

void RadioactiveNucleus::print_data() const
{
  std::cout << "Radioactive Nucleus: " << nucleus_type_
            << " (Z=" << atomic_number_ << ", A=" << atomic_mass_
            << ", Half-life=" << half_life_ << ")\\n";
}
