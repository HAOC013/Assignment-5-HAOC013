// Filename: radioactivenucleus.h
// Purpose: Declares RadioactiveNucleus class with decay behavior and Rule of 5.
// Student ID: 11010580
// Date: 19th April 2025

#ifndef RADIOACTIVE_NUCLEUS_H
#define RADIOACTIVE_NUCLEUS_H

#include "nucleus.h"

class RadioactiveNucleus : public Nucleus {
public:
  // Constructor
  RadioactiveNucleus(double atomic_mass, int atomic_number,
                     const std::string& nucleus_type,
                     double half_life, const std::vector<double>& photon_energies);

  // Rule of 5
  ~RadioactiveNucleus();
  RadioactiveNucleus(const RadioactiveNucleus& other);
  RadioactiveNucleus& operator=(const RadioactiveNucleus& other);
  RadioactiveNucleus(RadioactiveNucleus&& other) noexcept;
  RadioactiveNucleus& operator=(RadioactiveNucleus&& other) noexcept;

  // Overridden base class methods
  void decay() override;
  void print_data() const override;

private:
  double half_life_;
  std::vector<double> photon_energies_;
};

#endif // RADIOACTIVE_NUCLEUS_H
