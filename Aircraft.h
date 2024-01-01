#ifndef AIRCRAFT_H
#define AIRCRAFT_H

#include <iostream>
#include <string>
#include <sstream>
#include "Array.h"
#include "Part.h"
#include "defs.h"

using namespace std;

class Aircraft{
    friend ostream& operator<<(ostream&, Aircraft&);
    public:
        //constructor
        Aircraft(string, string);
        //Destructor
        ~Aircraft();

        //getter
        string getRegistration();

        //functions
        void install(Part*, Date&);
        void takeFlight(int hours);
        void inspectionReport(Date&, Array<Part*>&);

     
    private:
        string type;
        string registration;
        int flighthours;
        Array<Part*> part_array;
};

#endif
