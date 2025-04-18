// C++ Assignment 5: main
// ID: 11010580
// Date: 19th April 2025
// This program simulates the behaviour of radioactive and stable nucli, the interactions
// of photons with matter and the radiation of photons from electons.
// It demonstrates inheritance (Nucleus/Particle hierarchies), smart pointers (dynamic particle management),
// and friend functions (for photon interactions and electron radiation).



#include "radioactivenucleus.h"
#include "stablenucleus.h"
#include "photon.h"
#include "electron.h"
#include <iostream>
#include <memory>
#include <vector>
// Standard and class headers. Two base classes (Nucleus for RadioactiveNucleus and StableNucleus,
// Particle for Photon and Electron) are also included indirectly through derived class headers.


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
    std::cout << "\n=== Simulating " << nucleus->get_nucleus_type() << " ===\n";
    nucleus->print_data();
    nucleus->decay();  
  }

// Manual test of electron radiate function
  std::cout << "\n=== Manual Electron Test ===\n";
  Electron test_electron(1.0);
  test_electron.print_data();
  test_electron.add_photon(std::make_shared<Photon>(0.25));

  auto test_radiation = radiate(test_electron);
  if (test_radiation) {
    std::cout << "  Electron radiated photon with energy: " << test_radiation->get_energy() << " MeV\n";
  }

// End of output
  std::cout << "\n=== End of Assignment 5 Program ===\n";
  return 0;
}
