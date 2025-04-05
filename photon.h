// Photon.h
// Purpose: Header file for the Photon class
// Student ID: 12345678
// Date: 2025-04-05

#ifndef PHOTON_H
#define PHOTON_H

#include <vector>
#include "Electron.h"  // Include the Electron class (as it's referenced in pair_production)

class Photon {
private:
    double energy;  // Energy of the photon in MeV

public:
    // Constructor with energy parameter
    Photon(double energy);

    // Destructor
    ~Photon();

    // Getter for energy
    double get_energy() const;

    // Setter for energy
    void set_energy(double energy);

    // Function to print photon data
    void print_data() const;

    // Friend function declarations
    friend double photoelectric_effect(Photon& photon);
    friend double compton_scattering(Photon& photon);
    friend std::vector<Electron> pair_production(Photon& photon);
};

#endif // PHOTON_H
