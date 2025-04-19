// C++ Assignment 5: radioactivenucleus.h
// ID: 11010580
// Date: 19th April 2025
// Header file for the RadioactiveNucleus class, which inherits from the Nucleus class and models radioactive decay.

#ifndef RADIOACTIVE_NUCLEUS_H
#define RADIOACTIVE_NUCLEUS_H

#include "nucleus.h"

class RadioactiveNucleus : public Nucleus {
public:
  // Constructor
  RadioactiveNucleus(double atomic_mass, int atomic_number,
                     const std::string& nucleus_type,
                     double half_life, const std::vector<double>& photon_energies);

  // Destructor
  ~RadioactiveNucleus();
  RadioactiveNucleus(const RadioactiveNucleus& other);
  RadioactiveNucleus& operator=(const RadioactiveNucleus& other);
  RadioactiveNucleus(RadioactiveNucleus&& other) noexcept;
  RadioactiveNucleus& operator=(RadioactiveNucleus&& other) noexcept;

  // Overriding nucleus base class to allow different nucleus types to implement their own specific behaviors.
  // these functions in the base class are just there as placeholders
  void decay() override;
  void print_data() const override;

private: // sets half life and photon energies as private members so they can be used in the decay function
  double half_life_;
  std::vector<double> photon_energies_;
};

#endif // RADIOACTIVE_NUCLEUS_H
