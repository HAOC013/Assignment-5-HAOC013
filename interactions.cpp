// Filename: Interactions.cpp
// Purpose: Implements photon interaction functions.
// Student ID: 
// Date: April 2025

#include "Interactions.h"
#include <iostream>
#include <cmath>

double photoelectric_effect(const Photon& photon)
{
  return photon.get_energy();
}

void compton_scatter(Photon& photon, double angle_radians)
{
  double initial_energy = photon.get_energy();
  double scattered_energy = initial_energy / (1.0 + (initial_energy / 511.0) * (1.0 - std::cos(angle_radians)));
  photon.set_energy(scattered_energy);
}

std::vector<std::shared_ptr<Electron>> pair_production(const Photon& photon)
{
  if (photon.get_energy() <= 2 * 0.511) {
    std::cout << "Insufficient energy for pair production.\\n";
    return {};
  }

  auto e1 = std::make_shared<Electron>(photon.get_energy() / 2.0);
  auto e2 = std::make_shared<Electron>(photon.get_energy() / 2.0);
  return {e1, e2};
}
