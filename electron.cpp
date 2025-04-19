// C++ Assignment 5: Electron class implementation
// ID: 11010580
// Date: 19th April 2025
// Creates an Electron class that inherits from Particle class and simulates photon radiation.

// Standard and class headers
#include "electron.h"
#include "photon.h"
#include <iostream>
#include <utility>

// Defining all 5 special member functions (Rule of 5) for the Electron class

// Constructor to initialise electron rest mass/energy
Electron::Electron(double energy)
  : Particle(0.511, energy) {}

// Destructor for electron class (default destructor, stated for compleatness)
Electron::~Electron() = default;

// Copy constructor
Electron::Electron(const Electron& other)
  : Particle(0.511, other.energy_), photons_(other.photons_) {}

// Copy assignment operator
Electron& Electron::operator=(const Electron& other) {
  if (this != &other) {
    energy_ = other.energy_;
    photons_ = other.photons_;
  }
  return *this;
}
// Move constructor
Electron::Electron(Electron&& other) noexcept
  : Particle(0.511, other.energy_), photons_(std::move(other.photons_)) {}

// Move assignment opertor 
Electron& Electron::operator=(Electron&& other) noexcept {
  if (this != &other) {
    energy_ = other.energy_;
    photons_ = std::move(other.photons_);
  }
  return *this;
}

// Displays electron energy

void Electron::print_data() const {
  std::cout << "Electron with energy: " << energy_ << " MeV\n";
}

// Adds a photon to the electron's vector of photons (See radiate function bellow)
void Electron::add_photon(const std::shared_ptr<Photon>& photon) {
  photons_.push_back(photon);
}

// ==== Electron radiation function: Explaining my implementation (as discussed in lab) ====
// Electron class stores a vector of photons it can emit.
// The radiate() function returns and removes the most recently added photon.
// Cannot radiate indefinitely and only emit a photon if available.
// The number and energy of photons are controlled externally by the simulation logic,
// One photon per electron added manually for testing.

std::shared_ptr<Photon> radiate(Electron& electron) {
  if (electron.photons_.empty()) {
    std::cout << "Electron has no photons to radiate.\n";
    return nullptr;
  }

  std::shared_ptr<Photon> emitted = electron.photons_.back();
  electron.photons_.pop_back();
  return emitted;
}
