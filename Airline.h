#ifndef AIRLINE_H
#define AIRLINE_H

#include <iostream>
#include <string>
#include <sstream>
#include "Array.h"
#include "Aircraft.h"
#include "Part.h"
#include "defs.h"

using namespace std;

class Airline{
    friend ostream& operator<<(ostream&, Airline&);
    public:
        //constructor
        Airline(string);
        //Destructor
        ~Airline();

        //functions
        void addAircraft(const string&, const string&);
        void addPart(const string& part, int fh_inspect, int it_inspect);
        void takeFlight(string reg, int hours);
        void printAircraft();
        void printParts();
        void inspectionReport(string reg, Date&);
        bool install(string, string, Date&);
     
    private:
        //getter
        Aircraft* getAircraft(const string&);
        Part* getPart(const string&);

        string name;
        Array<Part*> part_array;
        Array<Aircraft*> airCraft_array;
};

#endif
