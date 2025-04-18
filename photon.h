// C++ Assignment 5: Photon class header
// ID: 11010580
// Date: 19th April 2025
//
#ifndef PHOTON_H
#define PHOTON_H

#include "particle.h"
#include "electron.h"
#include <vector>
#include <memory>

class Photon : public Particle {
public:
  Photon(double energy);
  ~Photon();  // Rule of 5: Destructor

  Photon(const Photon& other);  // Rule of 5: Copy constructor
  Photon& operator=(const Photon& other);  // Rule of 5: Copy assignment

  Photon(Photon&& other) noexcept;  // Rule of 5: Move constructor
  Photon& operator=(Photon&& other) noexcept;  // Rule of 5: Move assignment

  void print_data() const override;

  void add_electron(const std::shared_ptr<Electron>& electron);
  const std::vector<std::shared_ptr<Electron>>& get_electrons() const;

  friend double photoelectric_effect(Photon& photon);
  friend double compton_scattering(Photon& photon);
  friend std::vector<std::shared_ptr<Electron>> pair_production(Photon& photon);

private:
  std::vector<std::shared_ptr<Electron>> electrons_;
};

#endif // PHOTON_H
