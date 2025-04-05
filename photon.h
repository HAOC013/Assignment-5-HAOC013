// Filename: Photon.h
// Purpose: Declares Photon class derived from Particle.
// Student ID: 
// Date: April 2025

#ifndef PHOTON_H
#define PHOTON_H

#include "Particle.h"
#include <vector>
#include <memory>

class Electron;

class Photon : public Particle
{
public:
  Photon(double energy);

  void print_data() const override;

  void add_electron(const std::shared_ptr<Electron>& electron);
  const std::vector<std::shared_ptr<Electron>>& get_electrons() const;

private:
  std::vector<std::shared_ptr<Electron>> electrons_;
};

#endif // PHOTON_H
