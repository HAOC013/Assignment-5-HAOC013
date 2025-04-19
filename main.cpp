// C++ Assignment 5: main
// ID: 11010580
// Date: 19th April 2025
// This program simulates the behaviour of radioactive and stable nucli, the interactions
// of photons with matter and the radiation of photons from electons.
// It demonstrates inheritance (Nucleus/Particle hierarchies), smart pointers (dynamic particle management),
// and friend functions (for photon interactions and electron radiation).
// I use MeV not keV as the unit of energy thought the programa as i think it provides better context.


#include "radioactivenucleus.h"
#include "stablenucleus.h"
#include "photon.h"
#include "electron.h"
#include <iostream>
#include <memory>
#include <vector>
#include <iomanip> // required for std::fixed and std::setprecision

// Standard and class headers. Two base classes (Nucleus for RadioactiveNucleus and StableNucleus,
// Particle for Photon and Electron) are also included indirectly through derived class headers.

extern void print_simulation_summary();

int main() {
  std::cout << "\n===== Assignment 5: Radioactive Decay & Interactions =====\n"; 
  std::cout << "Press Enter to start..."; // I include this to improve UI
  std::cin.get();

  std::vector<std::shared_ptr<Nucleus>> nuclei; // Vector to store pointers to Nuclear and any class that inherits from it
  
  // Defining test nuclei and storing them in the vector
  nuclei.push_back(std::make_shared<RadioactiveNucleus>(
    137.0, 55, "Cs", 30.17, std::vector<double>{0.661}));
  nuclei.push_back(std::make_shared<RadioactiveNucleus>(
    22.0, 11, "Na", 2.6, std::vector<double>{1.2745}));
  nuclei.push_back(std::make_shared<RadioactiveNucleus>(
    60.0, 27, "Co", 5.27, std::vector<double>{1.173, 1.333}));
  nuclei.push_back(std::make_shared<StableNucleus>(
    56.0, 26, "Fe"));

// Loops through all test nuclei and uses polymorphism to simulate their decay
  for (const auto& nucleus : nuclei) {
    std::cout << "\n======= Simulating " << nucleus->get_nucleus_type() << " =======\n";
    nucleus->print_data();
    nucleus->decay();  
  }

// Manual test of electron radiate function see electron class for explanation on implementation
  std::cout << "\n=== Electron Radiation Tests ===\n";

  Electron test_electron1(0.888);
  std::vector<double> energies1 = {0.05, 0.12};
  for (double e : energies1) {
    test_electron1.add_photon(std::make_shared<Photon>(e));
  }

  std::cout << "Electron before radiation:\n";
  std::cout << "Electron | Energy: "
            << std::fixed << std::setprecision(3)
            << test_electron1.get_energy() * 1000 << " keV, Photons: "
            << energies1.size() << "\n";

  bool radiated1 = false;
  while (auto emitted = radiate(test_electron1)) {
    radiated1 = true;
    std::cout << "Radiated photon:\n";
    std::cout << "  Photon | Energy: " << std::fixed << std::setprecision(3)
              << emitted->get_energy() << " MeV\n";
  }
  if (!radiated1) {
    std::cout << "Electron has no photons to radiate.\n";
  }

  Electron test_electron2(0.777);
  std::vector<double> energies2 = {0.08, 0.14, 0.19};
  for (double e : energies2) {
    test_electron2.add_photon(std::make_shared<Photon>(e));
  }

  std::cout << "\nElectron before radiation:\n";
  std::cout << "Electron | Energy: "
            << std::fixed << std::setprecision(3)
            << test_electron2.get_energy() * 1000 << " keV, Photons: "
            << energies2.size() << "\n";

  bool radiated2 = false;
  while (auto emitted = radiate(test_electron2)) {
    radiated2 = true;
    std::cout << "Radiated photon:\n";
    std::cout << "  Photon | Energy: " << std::fixed << std::setprecision(3)
              << emitted->get_energy() << " MeV\n";
  }
  if (!radiated2) {
    std::cout << "Electron has no photons to radiate.\n";
  }

  print_simulation_summary();              

// End of output
  std::cout << "\n=== End of Assignment 5 Program ===\n";
  return 0;
}
