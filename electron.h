// Filename: Electron.h
// Purpose: Declares Electron class with radiation method as friend function and Rule of 5.
// Student ID: 
// Date: April 2025

#ifndef ELECTRON_H
#define ELECTRON_H

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

  // Radiate function:
  // In a realistic simulation, an electron radiates only if it has energy stored as photons.
  // This function emits the last photon added and removes it from the electron’s photon list.
  // The number and energy of stored photons are determined externally by the simulation logic.
  friend std::shared_ptr<Photon> radiate(Electron& electron);

private:
  std::vector<std::shared_ptr<Photon>> photons_;
};

#endif // ELECTRON_H
