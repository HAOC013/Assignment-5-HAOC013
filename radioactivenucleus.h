// Filename: RadioactiveNucleus.h
// Purpose: Declares RadioactiveNucleus class with decay behavior and Rule of 5.
// Student ID: 
// Date: April 2025

#ifndef RADIOACTIVE_NUCLEUS_H
#define RADIOACTIVE_NUCLEUS_H

#include "nucleus.h"

class RadioactiveNucleus : public Nucleus {
public:
  RadioactiveNucleus(double atomic_mass, int atomic_number, const std::string& nucleus_type,
                     double half_life, const std::vector<double>& photon_energies);
  ~RadioactiveNucleus();  // Rule of 5: Destructor

  RadioactiveNucleus(const RadioactiveNucleus& other);  // Rule of 5: Copy constructor
  RadioactiveNucleus& operator=(const RadioactiveNucleus& other);  // Copy assignment

  RadioactiveNucleus(RadioactiveNucleus&& other) noexcept;  // Move constructor
  RadioactiveNucleus& operator=(RadioactiveNucleus&& other) noexcept;  // Move assignment

  void decay() override;
  void print_data() const override;

private:
  double half_life_;
  std::vector<double> photon_energies_;
};

#endif // RADIOACTIVE_NUCLEUS_H
