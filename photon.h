// C++ Assignment 5: Photon class header
// ID: 11010580
// Date: 19th April 2025
// Header file for the Photon class, which inherits from the Particle class and simulates photon interactions
#ifndef PHOTON_H
#define PHOTON_H

#include "particle.h"
#include "electron.h"
#include <vector>
#include <memory>

class Photon : public Particle {
public:
  Photon(double energy);
  ~Photon();  // Rule of 5: Destructor

  Photon(const Photon& other);  // Rule of 5: Copy constructor
  Photon& operator=(const Photon& other);  // Rule of 5: Copy assignment

  Photon(Photon&& other) noexcept;  // Rule of 5: Move constructor
  Photon& operator=(Photon&& other) noexcept;  // Rule of 5: Move assignment

  void print_data() const override;

  void add_electron(const std::shared_ptr<Electron>& electron);
  const std::vector<std::shared_ptr<Electron>>& get_electrons() const;

// Friend functions for photon interactions as outlined in brief. Friend functions are used to access private members of the Photon class.
  friend double photoelectric_effect(Photon& photon);
  friend double compton_scattering(Photon& photon);
  friend std::vector<std::shared_ptr<Electron>> pair_production(Photon& photon);

// friend function to simulate photon radiation from an electron
private:
  std::vector<std::shared_ptr<Electron>> electrons_;
};

#endif // PHOTON_H
