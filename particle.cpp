// Filename: Particle.cpp
// Purpose: Implements the Particle base class.
// Student ID: 
// Date: April 2025

#include "Particle.h"

Particle::Particle(double rest_mass, double energy)
  : rest_mass_(rest_mass), energy_(energy)
{
}

double Particle::get_rest_mass() const
{
  return rest_mass_;
}

double Particle::get_energy() const
{
  return energy_;
}

void Particle::set_energy(double energy)
{
  energy_ = energy;
}
