#include "header.h"
using namespace std;

//assigning a random mechanic to a vehicle
void assignedMechanic(std::vector<Vehicle> vehicle, std::vector<Mechanic>& mechanic, std::ofstream& six) {
    int mechNum = mechanic.size(); //stores the size of the mechanic vector
    int vehicleNum = vehicle.size(); //stores the size of the vehicle vector
    int result; //stores the result of the random
    int count = 0; //counts the vehicles

    six << "Assigning a vehicle to a mechanic" << std::endl;


    for (vector<Vehicle>::iterator it = vehicle.begin(); it != vehicle.end(); ++it) {
        count++;

        result = rand() % (mechNum); //between 0 and a maximum of 4
        Mechanic m = mechanic[result];

        six << "================================" << endl;
        six << "Mechanic number " << result << endl;
        six << "Details: ";
        six << m.name << std::endl;
        six << "Will be assigned with Vehicle: " << count << std::endl;

         mechanic[result].vehiclesAssigned.push_back(*it);
    }
    six << "================================" << endl;
    six << endl;
}

//gets the chance
float chance(int quality, int probDetermine)
{
    int result = quality - probDetermine;
    return (50 + result) / 100.f; //gets the baseline
}

//diagnoses the vehicle and applies a fix
void diagnosis
        (std::vector<Mechanic> mechanic,
         std::vector<Problem> problem,
         std::vector<Treatment> treatment,
         std::ofstream& six)
{
    for (std::vector<Mechanic>::iterator in = mechanic.begin(); in != mechanic.end(); ++in) {
        std::vector<Vehicle> vehicle = (*in).vehiclesAssigned; //gets the assigned vehicles in mechanic

        for (std::vector<Vehicle>::iterator it = vehicle.begin(); it != vehicle.end(); ++it) {

            int problemIndex = (*it).problem; //getting the the incorrect problem index

            int probDet = problem[problemIndex].probDetermine; //getting the problem determine index

            int treatmentComplexity = problem[problemIndex].problemTreat; //gets the problem treatment index

            int treatIndex = problem[problemIndex].treatment - 1; //getting the treatment index only for the correct problem

            float chances = chance((*in).quality, probDet); //calculates the percentages

            //checking for correctness
            if ((10 * chances) <= (rand() % 200)) //takes the worst possible outcome
            {
                int index = rand() % problem.size();
                if (index != problemIndex)
                {
                    treatmentComplexity = treatmentComplexity * 0.25f; //assigning the 25% chance of working for wrong fix
                    treatIndex = problem[index].treatment -1;

                    six << "The Mechanic found a different problem: ";
                    six << problem[(*it).problem].name << std::endl;
                }
            }
            vehicleRepair(*it, treatment[treatIndex], (*in).quality , treatmentComplexity ,six);
        }
    }
}

//applies the treatment to the vehicle
void vehicleRepair (Vehicle &vehicle, Treatment &treatment, int quality, int treatmentComplexity, std::ofstream& six)
{
    six << "The treatment:";
    six << treatment.name << " is applied." << std::endl;

    float result  =  chance(quality, treatmentComplexity);

    if ((100 * result) <= (rand() % 200)) //takes the worst outcome
    {
        six << "The fix failed." << std::endl;
        six << "The vehicle has left the Repair Centre." << std::endl;
        six << "================================" << endl;
    }
    else
    {
        six << "The fix is successful." << std::endl;
        six << "The vehicle has left the Repair Centre." << std::endl;
        six << "================================" << endl;
    }
}
