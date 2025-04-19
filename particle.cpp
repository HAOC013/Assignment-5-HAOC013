// C++ Assignment 5: Particle class implementation
// ID: 11010580
// Date: 19th April 2025
// Implements the Particle class, which serves as a base class for Photon and Electron classes.

#include "particle.h"

// Constructor to initialize particle properties
Particle::Particle(double rest_mass, double energy)
  : rest_mass_(rest_mass), energy_(energy) {}

// Destructor for Particle class (default destructor, stated for completeness)
double Particle::get_rest_mass() const {
  return rest_mass_;
}

// Returns the rest mass of the particle
double Particle::get_energy() const {
  return energy_;
}

// Returns the energy of the particle
void Particle::set_energy(double energy) {
  energy_ = energy;
}
