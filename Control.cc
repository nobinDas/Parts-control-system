
#include "Control.h"

const string Control::ac_type[AC_NUM] = {"Twin Otter","Turbo Otter", "Cessna"};
const string Control::ac_reg[AC_NUM] = {"CF-123A", "CG-999","CF-AXEL"};
const string Control::parts[PART_NUM]={"Propeller1", "Avionics1","Avionics2","Landing Gear1", "Strut1", "Strut2","Strut3", "Windshield1", "Aileron1", "Elevator1"};

const int Control::fh[PART_NUM] = {100, 200, 150, 250, 150, 150,150, 0, 0, 0};
const int Control::it[PART_NUM] = {0, 0, 0, 0, 30, 60, 45, 50, 100, 90};

void Control::launch(){

    Airline al("My Airline");
    initAirline(al);


    int choice = 6;


    while (choice!= 0){
        view.showMenu(choice);
        switch(choice){
            case 1: al.printAircraft(); break;
            case 2: al.printParts(); break;
            case 3: takeFlights(al); break;
            case 4: inspectionReport(al); break;
        }
    }
    cout<<"exiting program"<<endl;
}

void Control::inspectionReport(Airline& al){
    Date d(2022,12,25);
    for (int i = 0; i < AC_NUM; ++i){
        al.inspectionReport(ac_reg[i], d);
    }
}

void Control::takeFlights(Airline& al){
    for (int i = 0; i < AC_NUM; ++i){
        al.takeFlight(ac_reg[i], 100);
    }
}

void Control::initAirline(Airline& al){
    for (int i = 0; i < AC_NUM; ++i){
        al.addAircraft(ac_type[i],ac_reg[i]);
    }

    for (int i = 0; i < PART_NUM; ++i){
        al.addPart(parts[i], fh[i], it[i]);
    }

    Date d(2021,9,17);

    al.install(ac_reg[0],parts[0], d);
    al.install(ac_reg[0],parts[1], d);
    al.install(ac_reg[0],parts[3], d);
    al.install(ac_reg[1],parts[2], d);
    al.install(ac_reg[1],parts[4], d);
    al.install(ac_reg[2],parts[5], d);
    al.install(ac_reg[2],parts[8], d);
    al.install(ac_reg[2],parts[9], d);


}

