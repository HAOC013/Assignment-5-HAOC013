// Filename: Electron.cpp
// Purpose: Implements Electron class including photon emission.
// Student ID: 
// Date: April 2025

#include "Electron.h"
#include "Photon.h"
#include <iostream>

Electron::Electron(double energy)
  : Particle(0.511, energy)
{
}

void Electron::print_data() const
{
  std::cout << "Electron with energy: " << energy_ << " MeV\\n";
}

void Electron::add_photon(const std::shared_ptr<Photon>& photon)
{
  photons_.push_back(photon);
}

std::shared_ptr<Photon> Electron::radiate()
{
  if (photons_.empty()) {
    std::cout << "Electron has no photons to radiate.\\n";
    return nullptr;
  }

  std::shared_ptr<Photon> emitted = photons_.back();
  photons_.pop_back();
  return emitted;
}
