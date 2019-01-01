#include "header.h"
using namespace std;

int main (int argc, char *argv[])
{
    //storing the datafile information
    vector <Vehicle> vehicle;
    vector <Mechanic> mechanic;
    vector <Problem> problem;
    vector <Treatment> treatment;

    ifstream in;
    ifstream inData;
    ifstream inDa;
    ifstream five;
    ofstream six (argv[6], ofstream::out); //opens Output-file;

    string v; //stores vehicles
    string m; //stores mechanics
    string p; //stores problems
    string f; //stores fixes

    int num = atoi(argv[1]);
    in.open(argv[2]); //opening vehicles.txt
    inData.open(argv[3]); //opens Mechanics.txt
    inDa.open(argv[4]); //opens Problems.txt
    five.open(argv[5]);//opens fixes.txt

    if (num <1 || num > 20)
    {
        cerr << "Error: The number must be more than 0 and not over 20 " << endl;
    }

    //checking files and ignoring bad lines for vehicle
    if(in.fail())
    {
        cerr << "Error: Invalid Data in Vehicles Textfile" << endl;
        in.clear();
        in.ignore(100, '\n');
        return -1;
    }
    if(in.bad())
    {
        cerr << "Error: Hardware Failure in Vehicles Textfile" << endl;
        in.clear();
        in.ignore(100, '\n');
        return -2; // hardware failure
    }

    six << "================================" << endl;
    six << "Reading the Textfiles" << endl;
    six << endl;

    while (in >> v)
    {
        istringstream ss(v);
        string token;

        Vehicle one;

        getline(ss, token, ',');
        one.type = token;

        getline(ss, token, ',');
        one.colour = token;

        getline(ss, token, ',');
        one.plate = token;

        getline(ss, token, ',');
        one.problem = atoi(token.c_str());

        vehicle.push_back(one);
    }
    six << "The vehicles file has been read" << endl;
    six << endl;

    //checking files and ignoring bad lines for mechanics text file
    if(inData.fail())
    {
        cerr << "Error: Invalid Data in Mechanics Textfile" << endl;
        inData.clear();
        inData.ignore(100, '\n');
        return -1;
    }
    if(inData.bad())
    {
        cerr << "Error: Hardware Failure" << endl;
        inData.clear();
        inData.ignore(100, '\n');
        return -2;
    }

    //reading the mechanic textfile
    do
    {
        string token1;

        Mechanic one1;

        getline(inData, token1, ',');

        if (token1 == "\n") break;

        one1.name = token1;

        getline(inData, token1, ',');
        one1.gender = token1;

        getline(inData, token1, '.');
        one1.quality = atoi(token1.c_str());

        mechanic.push_back(one1);
    } while(!inData.eof());
    six << "The Mechanics file has been read" << endl;
    six << endl;

    //checking files and ignoring bad lines for vehicle
    if(inDa.fail())
    {
        cerr << "Error: Invalid Data in the Problems Textfile" << endl;
        inDa.clear();
        inDa.ignore(100, '\n');
        return -1;
    }
    if(inDa.bad())
    {
        cerr << "Error: Hardware Failiure in the Problems Textfile" << endl;
        inDa.clear();
        inDa.ignore(100, '\n');
        return -2; // hardware failure
    }

    //reading the problems textfile
    do
    {
        string token2;

        //creating a problem object
        Problem one2;

        getline(inDa, token2, ',');
        one2.name = token2;

        if (token2 == "\n") break;

        getline(inDa, token2, ',');
        one2.probDetermine = atoi(token2.c_str());

        getline(inDa, token2, ',');
        one2.problemTreat = atoi(token2.c_str());

        getline(inDa, token2, '.');
        one2.treatment = atoi(token2.c_str());

        problem.push_back(one2);
    }
    while (!inDa.eof());
    six << "The Problems file has been read" << endl;
    six << endl;

    //checking files and ignoring bad lines for the Fixes textfile
    if(five.fail())
    {
        cerr << "Error: Invalid Data in the Fixes Textfile" << endl;
        five.clear();
        five.ignore(100, '\n');
        return -1;
    }
    if(five.bad())
    {
        cerr << "Error: Hardware Failiure in the Fixes Textfile" << endl;
        five.clear();
        five.ignore(100, '\n');
        return -2; // hardware failure
    }
    //reading treatments file
    do
    {
        Treatment one3;

        string token;

        getline(five, token, '.');
        one3.name = token;

        //adding to the associated vector
        treatment.push_back(one3);
    }
    while (!five.eof());
    six << "The treatments file has been read" << endl;
    six << "================================" << endl;
    six << endl;

    //assign mechanic method
    assignedMechanic(vehicle, mechanic, six);

    six << "Diagnosing the vehicles and applying a fix" << endl;
    six << endl;

    //Diagnosing the vehicle
    diagnosis(mechanic, problem, treatment, six); //takes the vehicle and gets it problem and applies a fix

    six << "All Vehicles have left the Repair Centre" << endl;

    in.close();
    inData.close();
    inDa.close();
    five.close();
    six.close();

    return 0;
}
