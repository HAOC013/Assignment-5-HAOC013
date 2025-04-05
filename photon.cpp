// Filename: Photon.cpp
// Purpose: Implements Photon class behavior.
// Student ID: 
// Date: April 2025

#include "Photon.h"
#include "Electron.h"
#include <iostream>

Photon::Photon(double energy)
  : Particle(0.0, energy)
{
}

void Photon::print_data() const
{
  std::cout << "Photon with energy: " << energy_ << " keV\\n";
}

void Photon::add_electron(const std::shared_ptr<Electron>& electron)
{
  electrons_.push_back(electron);
}

const std::vector<std::shared_ptr<Electron>>& Photon::get_electrons() const
{
  return electrons_;
}
