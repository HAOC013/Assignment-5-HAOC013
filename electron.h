// Filename: Electron.h
// Purpose: Declares Electron class with radiation method.
// Student ID: 
// Date: April 2025

#ifndef ELECTRON_H
#define ELECTRON_H

#include "Particle.h"
#include <vector>
#include <memory>

class Photon;

class Electron : public Particle
{
public:
  Electron(double energy);

  void print_data() const override;

  void add_photon(const std::shared_ptr<Photon>& photon);
  std::shared_ptr<Photon> radiate();

private:
  std::vector<std::shared_ptr<Photon>> photons_;
};

#endif // ELECTRON_H
