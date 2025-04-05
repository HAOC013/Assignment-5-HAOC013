// main.cpp
// Purpose: Simulate the behavior of radioactive nuclei, photons, and particles.
// Student ID: 12345678
// Date: 2025-04-05

#include "RadioactiveNucleus.h"
#include "StableNucleus.h"
#include "Photon.h"
#include "Electron.h"
#include <iostream>
#include <vector>

int main() {
  // Create some sample nuclei
  RadioactiveNucleus co60(27, 60, 5.27, "Co-60");
  RadioactiveNucleus na22(11, 22, 2.6, "Na-22");
  StableNucleus fe56(26, 56, "Fe-56");

  // Vector to store different nuclei for polymorphism
  std::vector<Nucleus*> nuclei = { &co60, &na22, &fe56 };

  // Decay the radioactive nuclei
  std::cout << "\n--- Decay Simulation ---\n";
  for (auto& nucleus : nuclei) {
    std::cout << "\nProcessing " << nucleus->get_name() << " nucleus:\n";
    nucleus->print_data();
    if (dynamic_cast<RadioactiveNucleus*>(nucleus)) {
      std::cout << "This is a radioactive nucleus. Decaying...\n";
      nucleus->decay();
    } else {
      std::cout << "Stable nucleus, no decay.\n";
    }
  }

  // Simulate photon interaction with matter
  std::cout << "\n--- Photon Interaction Simulation ---\n";
  Photon photon(1274.5); // Energy of Na-22 photon
  std::cout << "Photon energy: " << photon.get_energy() << " keV\n";
  photon.print_data();

  std::cout << "\nAttempting pair production:\n";
  std::vector<std::shared_ptr<Electron>> electrons = pair_production(photon);
  if (!electrons.empty()) {
    std::cout << "Pair production successful. Electrons created:\n";
    for (auto& e : electrons) {
      e->print_data();
    }
  } else {
    std::cout << "Pair production failed. Photon energy insufficient.\n";
  }

  // Simulate electron radiating photons
  std::cout << "\n--- Electron Radiation Simulation ---\n";
  Electron electron(0.511);
  std::cout << "Electron initial state:\n";
  electron.print_data();
  
  std::cout << "Electron is radiating a photon...\n";
  electron.radiate();  // Emit a photon
  electron.print_data();

  std::cout << "\n--- Simulation Ended ---\n";

  return 0;
}
