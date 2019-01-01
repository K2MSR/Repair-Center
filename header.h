#ifndef ASSI1_HEADER_H
#define ASSI1_HEADER_H

#endif //ASSI1_HEADER_H

#include <string>
#include <vector>
#include <iostream>
#include <iterator>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <sstream>

struct Vehicle
{
    std::string type;
    std::string colour;
    std::string plate;
    int problem;
};

struct Mechanic
{
    std::string name;
    std::string gender;
    int quality;
    std::vector <Vehicle> vehiclesAssigned; //vehicles to be worked on stored here
};

struct Problem
{
    std::string name;
    int probDetermine; //determination complexity
    int problemTreat; //treatment complexity
    int treatment;
};

struct Treatment
{
    std::string name;
};

//assigning a random mechanic
void assignedMechanic(std::vector<Vehicle> vehicle, std::vector <Mechanic>& mechanic,std::ofstream& six);

void diagnosis
        (std::vector<Mechanic> mechanic,
         std::vector<Problem> problem,
         std::vector<Treatment> treatment,
         std::ofstream& six);

float chance(int quality, int probDetermine);

void vehicleRepair (Vehicle &vehicle, Treatment &treatment, int quality, int treatmentComplexity, std::ofstream& six);
