// Filename: Particle.h
// Purpose: Declares base Particle class with mass and energy.
// Student ID: 
// Date: April 2025

#ifndef PARTICLE_H
#define PARTICLE_H

class Particle {
public:
  Particle(double rest_mass, double energy);
  virtual ~Particle() = default;

  virtual void print_data() const = 0;

  double get_rest_mass() const;
  double get_energy() const;
  void set_energy(double energy);

protected:
  double rest_mass_;
  double energy_;
};

#endif // PARTICLE_H
