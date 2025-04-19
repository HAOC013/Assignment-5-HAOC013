// C++ Assignment 5: Electron class header
// ID: 11010580
// Date: 19th April 2025
// Declarations necessary for Electron class that inherits from Particle class and simulates photon radiation.

#ifndef ELECTRON_H
#define ELECTRON_H

// Standard headers and inheritance from particle class
#include "particle.h"
#include <vector>
#include <memory>

class Photon;

class Electron : public Particle {
public:
  Electron(double energy);
  ~Electron();  // Rule of 5: Destructor

  Electron(const Electron& other);  // Rule of 5: Copy constructor
  Electron& operator=(const Electron& other);  // Rule of 5: Copy assignment

  Electron(Electron&& other) noexcept;  // Rule of 5: Move constructor
  Electron& operator=(Electron&& other) noexcept;  // Rule of 5: Move assignment

  void print_data() const override;

  void add_photon(const std::shared_ptr<Photon>& photon);

// ==== Electron radiation function: Explaining my implementation (as discussed in lab) ====
// Electron class stores a vector of photons it can emit.
// The radiate() function returns and removes the most recently added photon.
// Cannot radiate indefinitely and only emit a photon if available.
// The number and energy of photons are controlled externally by the simulation logic,
// One photon per electron added manually for testing.
  friend std::shared_ptr<Photon> radiate(Electron& electron);

private:
  std::vector<std::shared_ptr<Photon>> photons_;
};

#endif // ELECTRON_H
