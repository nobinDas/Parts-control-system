#ifndef PART_H
#define PART_H

#include <iostream>
#include <string>
#include <sstream>
#include "Date.h"

using namespace std;



class Part{
    friend ostream& operator<<(ostream& ost, Part& p);
    // friend ostream& operator<<(ostream& ost, Part& p){
    //     p.print(ost);
    //     return ost;
    // }
    public:
        //constructor
        Part(string name);
        //destructor
        virtual ~Part();

        //getter
        string getName();

        //member function
        void addFlightHours(int);
        void install(Date&);
        // virtual void print(ostream& os);

        //virtual function
        virtual bool inspection(const Date& date)=0;
     
    protected:
        string name;
        Date installationDate;
        int flighthours;
};

class FH_Part: virtual public Part{
    public:
        //constructor
        FH_Part(string name, int fhInspect);
        // FH_Part(int fhInspect);
        //destructor
        virtual ~FH_Part();  

        //virtual function
        virtual bool inspection(const Date& date);

    protected:
        int fh_inspect;
};

class IT_Part: virtual public Part{
    public:
        //constructor
        IT_Part(string name, int itInspect);
        //destructor
        virtual ~IT_Part();  

        //virtual function
        virtual bool inspection(const Date& date);

    protected:
        int it_inspect;
};

class FHIT_Part: public FH_Part, public IT_Part{
    public:
        //constructor
        FHIT_Part(string name, int fhInspect, int itInspect);
        //destructor
        virtual ~FHIT_Part();  

        //virtual function
        virtual bool inspection(const Date& date);
};
#endif
