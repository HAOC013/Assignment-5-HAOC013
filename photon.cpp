// C++ Assignment 5: Photon class implementation
// ID: 11010580
// Date: 19th April 2025
// Implements the Photon class, which inherits from the Particle class and simulates photon interactions
// with matter through pair production, Compton scattering, and the photoelectric effect.

#include "photon.h"
#include <iostream>
#include <utility>
#include <cmath>  // Needed for cos() which is used in Compton scattering

// Defining all 5 special member functions (Rule of 5) for the Photon class
Photon::Photon(double energy)
  : Particle(0.0, energy) {}

// Destructor for photon class (default destructor, stated for completeness)
Photon::~Photon() = default;

Photon::Photon(const Photon& other)
  : Particle(0.0, other.energy_), electrons_(other.electrons_) {}

Photon& Photon::operator=(const Photon& other) {
  if (this != &other) {
    energy_ = other.energy_;
    electrons_ = other.electrons_;
  }
  return *this;
}

Photon::Photon(Photon&& other) noexcept
  : Particle(0.0, other.energy_), electrons_(std::move(other.electrons_)) {}

Photon& Photon::operator=(Photon&& other) noexcept {
  if (this != &other) {
    energy_ = other.energy_;
    electrons_ = std::move(other.electrons_);
  }
  return *this;
}

// Print photon energy
void Photon::print_data() const {
  std::cout << "Photon with energy: " << energy_ << " MeV\n";
}
// Adds an electron to the photon's vector of electrons
void Photon::add_electron(const std::shared_ptr<Electron>& electron) {
  electrons_.push_back(electron);
}
// Returns the vector of electrons associated with the photon
const std::vector<std::shared_ptr<Electron>>& Photon::get_electrons() const {
  return electrons_;
}

// Friend function: returns photon energy for photoelectric effect (as outlined in brief)
double photoelectric_effect(Photon& photon) {
  return photon.get_energy();
}

// Friend function: returns photon energy after Compton scattering (as outlined in brief)
double compton_scattering(Photon& photon) {
  double theta = M_PI / 4;  // 45 degrees
  double e = photon.get_energy();
  double me = 0.511;  // MeV
  double e_prime = e / (1 + (e / me) * (1 - cos(theta))); // Equatuion for Compton scattering energy loss
  photon.set_energy(e_prime);
  return e_prime;
}

// Friend function: Simulates pair production returns 2 electrons (one electron one positron) if photon has sufficient energy
std::vector<std::shared_ptr<Electron>> pair_production(Photon& photon) {
  if (photon.get_energy() < 1.022) {
    //std::cout << "Error: Photon energy too low for pair production.\n";
    return {};
  }
// Models pair production
  auto e1 = std::make_shared<Electron>(photon.get_energy() / 2);
  auto e2 = std::make_shared<Electron>(photon.get_energy() / 2);
  return {e1, e2};
}
