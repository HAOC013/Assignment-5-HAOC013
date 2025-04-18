// Filename: Photon.cpp
// Purpose: Implements Photon class and Rule of 5.
// Student ID: 
// Date: April 2025

#include "photon.h"
#include <iostream>
#include <utility>
#include <cmath>  // Needed for cos()

Photon::Photon(double energy)
  : Particle(0.0, energy) {}

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

void Photon::print_data() const {
  std::cout << "Photon with energy: " << energy_ << " MeV\n";
}

void Photon::add_electron(const std::shared_ptr<Electron>& electron) {
  electrons_.push_back(electron);
}

const std::vector<std::shared_ptr<Electron>>& Photon::get_electrons() const {
  return electrons_;
}

// Friend function: returns full photon energy
double photoelectric_effect(Photon& photon) {
  return photon.get_energy();
}

// Friend function: Compton scattering modifies the photon's energy
double compton_scattering(Photon& photon) {
  double theta = M_PI / 4;  // 45 degrees
  double e = photon.get_energy();
  double me = 0.511;  // MeV
  double e_prime = e / (1 + (e / me) * (1 - cos(theta)));
  photon.set_energy(e_prime);
  return e_prime;
}

// Friend function: returns 2 electrons if photon has sufficient energy
std::vector<std::shared_ptr<Electron>> pair_production(Photon& photon) {
  if (photon.get_energy() < 1.022) {
    std::cout << "Error: Photon energy too low for pair production.\n";
    return {};
  }

  auto e1 = std::make_shared<Electron>(photon.get_energy() / 2);
  auto e2 = std::make_shared<Electron>(photon.get_energy() / 2);
  return {e1, e2};
}
