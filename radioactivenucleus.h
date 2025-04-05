// Filename: RadioactiveNucleus.h
// Purpose: Declares RadioactiveNucleus class with decay behavior.
// Student ID: 
// Date: April 2025

#ifndef RADIOACTIVE_NUCLEUS_H
#define RADIOACTIVE_NUCLEUS_H

#include "Nucleus.h"

class RadioactiveNucleus : public Nucleus
{
public:
  RadioactiveNucleus(double atomic_mass, int atomic_number, const std::string& nucleus_type,
                     double half_life, const std::vector<double>& photon_energies);

  void decay() override;
  void print_data() const override;

private:
  double half_life_;
  std::vector<double> photon_energies_;
};

#endif // RADIOACTIVE_NUCLEUS_H
