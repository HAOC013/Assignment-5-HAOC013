// C++ Assignment 5: Particle class implementation
// ID: 11010580
// Date: 19th April 2025
//
#include "particle.h"

Particle::Particle(double rest_mass, double energy)
  : rest_mass_(rest_mass), energy_(energy) {}

double Particle::get_rest_mass() const {
  return rest_mass_;
}

double Particle::get_energy() const {
  return energy_;
}

void Particle::set_energy(double energy) {
  energy_ = energy;
}
