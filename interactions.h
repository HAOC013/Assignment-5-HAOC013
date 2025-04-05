// Filename: Interactions.h
// Purpose: Declares photon interaction functions.
// Student ID: 
// Date: April 2025

#ifndef INTERACTIONS_H
#define INTERACTIONS_H

#include <vector>
#include <memory>
#include "Photon.h"
#include "Electron.h"

double photoelectric_effect(const Photon& photon);
void compton_scatter(Photon& photon, double angle_radians);
std::vector<std::shared_ptr<Electron>> pair_production(const Photon& photon);

#endif // INTERACTIONS_H
