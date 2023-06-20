#include <iostream>
#include "TMS.H"
using namespace std;



int main() {

	char* fN = new char[10];
	char* lN = new char[10];
	char* type = new char[10];
	char* source = new char[10];
	char* destination = new char[10];
	char* goodsType = new char[10];
	char* desc = new char[10];
	char* Ltype = new char[10];
	char* ftype = new char[10];
	int passengernum, dId, vId, hour, min, sec, age, Nid, day, month, year, noofLicences, experience, fid, vid, reg;
	float goodsWeight, DRank, VRank, distancefuelrate, distance, fuelrate, salary, price, mileage;
	bool status;
	int istatus;
	int customerid = 0;
	int driverid = 0;
	int vehicleid = 0;
	char** LicencesList = new char* [6];
	for (int i = 0; i < 6; i++) {
		LicencesList[i] = new char[20];
	}

	int exit = 1;
	int choice;
	
	Customer** c = new Customer * [15];
	for (int i = 0; i < 15; i++) {
		c[i] = nullptr;
	}

	Driver** d = new Driver * [10];
	for (int i = 0; i < 10; i++) {
		d[i] = nullptr;
	}

	Vehicle** v = new Vehicle * [20];
	for (int i = 0; i < 20; i++) {
		v[i] = nullptr;
	}


	cout << "------------  Welcome to TMS Application  ------------" << endl;

	while (exit > 0) {
		cout << endl << "Press (1) to access Customers" << endl;
		cout << "Press (2) to access Drivers" << endl;
		cout << "Press (3) to access Vehicles" << endl;
		cout << "Press (4) to exit" << endl;
		cin >> choice;

		if (choice == 1) {
			while (1) {
				cout << "Enter your Customer ID: ";
				cin >> customerid;
				cout << endl;
				for (int i = 0; i < 15; i++) {
					if (c[i] != nullptr && c[i]->checkcustomeravailablity(customerid) == 1) {
						int customerchoice = 0;
						cout << "Welcome !" << endl << "Press (1) to book a ride " << endl << "Press (2) to book a delivery " << endl << "Press (3) to print list of all customers " << endl << "Press (4) to print complete record of customer " << endl << "Or Press any other key to exit " << endl;
						cin >> customerchoice;
						cout << endl;
						if (customerchoice == 1) {
							cout << "Enter source :";
							cin >> source;
							cout << endl;
							cout << "Enter destination :";
							cin >> destination;
							cout << endl;
							cout << "Enter distance :";
							cin >> distance;
							cout << endl;
							cout << "Enter Date and Time to schedule Ride: " << endl;
							cout << "Enter date :";
							cin >> day;
							cout << endl;
							cout << "Enter month :";
							cin >> month;
							cout << endl;
							cout << "Enter year :";
							cin >> year;
							cout << endl;
							cout << "Enter hour :";
							cin >> hour;
							cout << endl;
							cout << "Enter minute :";
							cin >> min;
							cout << endl;
							cout << "Enter second :";
							cin >> sec;
							cout << endl;
							cout << "Enter ride status(0 for pending, 1 if complete) :";
							cin >> status;
							cout << endl;
							cout << "Enter fuel rate :";
							cin >> fuelrate;
							cout << endl;
							cout << "Enter driver ID :";
							cin >> dId;
							cout << endl;
							cout << "Enter vehicle ID :";
							cin >> vId;
							cout << endl;
							cout << "Enter number of passengers for the ride :";
							cin >> passengernum;
							cout << endl;
							cout << "Enter ride type (intercity, intracity) :";
							cin >> type;
							cout << endl;
							cout << "Enter driver rank :";
							cin >> DRank;
							cout << endl;
							cout << "Enter vehicle rank :";
							cin >> VRank;
							cout << endl;
							c[i]->setRide(passengernum, type, DRank, VRank, source, destination, distance, status, fuelrate, customerid, dId, vId, hour, min, sec, day, month, year);
						}
						else if (customerchoice == 2) {
							cout << "Enter source :";
							cin >> source;
							cout << endl;
							cout << "Enter destination :";
							cin >> destination;
							cout << endl;
							cout << "Enter distance :";
							cin >> distance;
							cout << endl;
							cout << "Enter Date and Time to schedule Ride: " << endl;
							cout << "Enter date :";
							cin >> day;
							cout << endl;
							cout << "Enter month :";
							cin >> month;
							cout << endl;
							cout << "Enter year :";
							cin >> year;
							cout << endl;
							cout << "Enter hour :";
							cin >> hour;
							cout << endl;
							cout << "Enter minute :";
							cin >> min;
							cout << endl;
							cout << "Enter second :";
							cin >> sec;
							cout << endl;
							cout << "Enter ride status(0 for pending, 1 if complete) :";
							cin >> status;
							cout << endl;
							cout << "Enter fuel rate :";
							cin >> fuelrate;
							cout << endl;
							cout << "Enter driver ID :";
							cin >> dId;
							cout << endl;
							cout << "Enter vehicle ID :";
							cin >> vId;
							cout << endl;
							cout << "Enter goods weight :";
							cin >> goodsWeight;
							cout << endl;
							cout << "Enter goods type :";
							cin >> goodsType;
							cout << endl;
							c[i]->setDelivery(goodsWeight, goodsType, source, destination, distance, status, fuelrate, customerid, dId, vId, hour, min, sec, day, month, year);
						}
						else if (customerchoice == 3) {
							cout << endl;
							cout << "List of all Customers: " << endl;
							for (int i = 0; i < 15; i++) {
								if (c[i] != nullptr) {	
									cout << "Customer ID: " << c[i]->getcId() << endl;
								}
							}
						}
						else if (customerchoice == 4) {
							if (c[i] != nullptr) {
								cout << endl;
								cout << *c[i];
								cout << endl;
							}
						}
						break;
					}
					else if (i == 14) {
						cout << "Your information was not found in the record, You need to register first to use this application !" << endl;
						for (int j = 0; j < 15; j++) {
							if (c[j] == nullptr) {
								cout << "Enter your first Name: ";
								cin >> fN;
								cout << endl;
								cout << "Enter your last Name: ";
								cin >> lN;
								cout << endl;
								cout << "Enter National ID: ";
								cin >> Nid;
								cout << endl;
								cout << "Enter your age: ";
								cin >> age;
								cout << endl;
								cout << "Enter Date of Birth: " << endl;
								cout << "Enter date:";
								cin >> day;
								cout << endl;
								cout << "Enter month:";
								cin >> month;
								cout << endl;
								cout << "Enter year:";
								cin >> year;
								cout << endl;
								c[j] = new Customer(customerid, age, Nid, fN, lN, day, month, year);
								break;
							}
						}
						break;
					}
				}
				break;
			}
		}

		//-------------------------------------------------------------------------------------

		else if (choice == 2) {
			while (1) {
				cout << "Enter your Driver ID: ";
				cin >> driverid;
				cout << endl;
				for (int i = 0; i < 10; i++) {
					if (d[i] != nullptr && d[i]->checkdriveravailablity(driverid) == 1) {
						int driverchoice = 0;
						cout << "Welcome !" << endl << "Press (1) to enter a ride " << endl << "Press (2) to enter a delivery " << endl << "Press (3) to Print driver list with ranking above 4.5 " << endl << "Press (4) to Remove Driver " << endl << "Press (5) to print list of drivers with multiple licences " << endl << "Press (6) to print list of all drivers " << endl << "Press (7) to print complete record of driver " << endl << "Or Press any other key to exit " << endl;
						cin >> driverchoice;
						cout << endl;
						if (driverchoice == 1) {
							cout << "Enter source :";
							cin >> source;
							cout << endl;
							cout << "Enter destination :";
							cin >> destination;
							cout << endl;
							cout << "Enter distance :";
							cin >> distance;
							cout << endl;
							cout << "Enter Date and Time to schedule Ride: " << endl;
							cout << "Enter date :";
							cin >> day;
							cout << endl;
							cout << "Enter month :";
							cin >> month;
							cout << endl;
							cout << "Enter year :";
							cin >> year;
							cout << endl;
							cout << "Enter hour :";
							cin >> hour;
							cout << endl;
							cout << "Enter minute :";
							cin >> min;
							cout << endl;
							cout << "Enter second :";
							cin >> sec;
							cout << endl;
							cout << "Enter ride status(0 for pending, 1 if complete) :";
							cin >> status;
							cout << endl;
							cout << "Enter fuel rate :";
							cin >> fuelrate;
							cout << endl;
							cout << "Enter driver ID :";
							cin >> dId;
							cout << endl;
							cout << "Enter vehicle ID :";
							cin >> vId;
							cout << endl;
							cout << "Enter number of passengers for the ride :";
							cin >> passengernum;
							cout << endl;
							cout << "Enter ride type (intercity, intracity) :";
							cin >> type;
							cout << endl;
							cout << "Enter driver rank :";
							cin >> DRank;
							cout << endl;
							cout << "Enter vehicle rank :";
							cin >> VRank;
							cout << endl;
							d[i]->setRide(passengernum, type, DRank, VRank, source, destination, distance, status, fuelrate, customerid, dId, vId, hour, min, sec, day, month, year);
						}
						else if (driverchoice == 2) {
							cout << "Enter source :";
							cin >> source;
							cout << endl;
							cout << "Enter destination :";
							cin >> destination;
							cout << endl;
							cout << "Enter distance :";
							cin >> distance;
							cout << endl;
							cout << "Enter Date and Time to schedule Ride: " << endl;
							cout << "Enter date :";
							cin >> day;
							cout << endl;
							cout << "Enter month :";
							cin >> month;
							cout << endl;
							cout << "Enter year :";
							cin >> year;
							cout << endl;
							cout << "Enter hour :";
							cin >> hour;
							cout << endl;
							cout << "Enter minute :";
							cin >> min;
							cout << endl;
							cout << "Enter second :";
							cin >> sec;
							cout << endl;
							cout << "Enter ride status(0 for pending, 1 if complete) :";
							cin >> status;
							cout << endl;
							cout << "Enter fuel rate :";
							cin >> fuelrate;
							cout << endl;
							cout << "Enter driver ID :";
							cin >> dId;
							cout << endl;
							cout << "Enter vehicle ID :";
							cin >> vId;
							cout << endl;
							cout << "Enter goods weight :";
							cin >> goodsWeight;
							cout << endl;
							cout << "Enter goods type :";
							cin >> goodsType;
							cout << endl;
							d[i]->setDelivery(goodsWeight, goodsType, source, destination, distance, status, fuelrate, customerid, dId, vId, hour, min, sec, day, month, year);
						}
						else if (driverchoice == 3) {
							cout << endl;
							cout << "Top Drivers: " << endl;
							for (i = 0; i < 10; i++) {
								if (d[i] != nullptr) {
									d[i]->printTopDrivers(d[i]->getdId());
								}
							}
							cout << endl;
						}
						else if (driverchoice == 4) {
							delete d[i];
							d[i] = nullptr;
						}

						else if (driverchoice == 5) {
							cout << endl;
							cout << "Drivers with multiple licenses: " << endl;
							for (int i = 0; i < 10; i++)
							{
								if (d[i] != nullptr)
								{
									d[i]->printMultipleLicenses(d[i]->getdId());
								}
							}
						}
						else if (driverchoice == 6) {
							cout << endl;
							cout << "List of all Drivers: " << endl;
							for (int i = 0; i < 10; i++) {
								if (d[i] != nullptr) {
									cout << "Driver ID: " << d[i]->getdId() << endl;
								}
							}
						}
						else if (driverchoice == 7) {
							if (d[i] != nullptr) {
								cout << endl;
								cout << *d[i];
								cout << endl;
							}
						}
						break;
					}	
					else if (i == 9) {
						cout << "Your information was not found in the record, You need to register first to use this application !" << endl;
						for (int j = 0; j < 10; j++) {
							if (d[j] == nullptr) {
								cout << "Enter your first Name: ";
								cin >> fN;
								cout << endl;
								cout << "Enter your last Name: ";
								cin >> lN;
								cin.ignore();
								cout << endl;
								cout << "Enter No of Licences: ";
								cin >> noofLicences;
								cout << endl;
								cout << "Enter Licence List: " << endl;
								for (int i = 0; i < noofLicences; i++) {
									cin >> LicencesList[i];
								}
								cout << endl;
								cout << "Enter Driver Rank: ";
								cin >> DRank;
								cout << endl;
								cout << "Enter Salary: ";
								cin >> salary;
								cout << endl;
								cout << "Enter Experience: ";
								cin >> experience;
								cout << endl;
								cout << "Enter ride stage(1 for free, 2 if booked and 3 if canceled) : ";
								cin >> istatus;
								cout << endl;
								cout << "Enter National ID: ";
								cin >> Nid;
								cout << endl;
								cout << "Enter your age: ";
								cin >> age;
								cout << endl;
								cout << "Enter Date of Birth: " << endl;
								cout << "Enter date:";
								cin >> day;
								cout << endl;
								cout << "Enter month:";
								cin >> month;
								cout << endl;
								cout << "Enter year:";
								cin >> year;
								cout << endl;
								d[j] = new Driver(driverid, LicencesList, noofLicences, DRank, salary, experience, istatus, age, Nid, fN, lN, day, month, year);
								break;
							}
						}
						break;
					}
				}
				break;
			}
		}

		//=====================================================================================

		else if (choice == 3) {
			while (1) {
				cout << "Enter your Vehicle ID: ";
				cin >> vehicleid;
				cout << endl;
				for (int i = 0; i < 20; i++) {
					if (v[i] != nullptr && v[i]->checkvehicleavailablity(vehicleid) == 1) {
						int vehiclechoice = 0;
						cout << "Welcome !" << endl << "Press (1) to set a ride " << endl << "Press (2) to set a delivery " << endl << "Press (3) to Remove Vehicle " << endl << "Press (4) to print complete record of vehicle " << endl << "Or Press any other key to exit " << endl;
						cin >> vehiclechoice;
						cout << endl;
						if (vehiclechoice == 1) {
							cout << "Enter source :";
							cin >> source;
							cout << endl;
							cout << "Enter destination :";
							cin >> destination;
							cout << endl;
							cout << "Enter distance :";
							cin >> distance;
							cout << endl;
							cout << "Enter Date and Time to schedule Ride: " << endl;
							cout << "Enter date :";
							cin >> day;
							cout << endl;
							cout << "Enter month :";
							cin >> month;
							cout << endl;
							cout << "Enter year :";
							cin >> year;
							cout << endl;
							cout << "Enter hour :";
							cin >> hour;
							cout << endl;
							cout << "Enter minute :";
							cin >> min;
							cout << endl;
							cout << "Enter second :";
							cin >> sec;
							cout << endl;
							cout << "Enter ride status(Press(0) for pending, Press(1) if complete) :";
							cin >> status;
							cout << endl;
							cout << "Enter fuel rate :";
							cin >> fuelrate;
							cout << endl;
							cout << "Enter driver ID :";
							cin >> dId;
							cout << endl;
							cout << "Enter vehicle ID :";
							cin >> vId;
							cout << endl;
							cout << "Enter number of passengers for the ride :";
							cin >> passengernum;
							cout << endl;
							cout << "Enter ride type (intercity, intracity) :";
							cin >> type;
							cout << endl;
							cout << "Enter driver rank :";
							cin >> DRank;
							cout << endl;
							cout << "Enter vehicle rank :";
							cin >> VRank;
							cout << endl;
							v[i]->setRide(passengernum, type, DRank, VRank, source, destination, distance, status, fuelrate, customerid, dId, vId, hour, min, sec, day, month, year);
						}
						else if (vehiclechoice == 2) {
							cout << "Enter source :";
							cin >> source;
							cout << endl;
							cout << "Enter destination :";
							cin >> destination;
							cout << endl;
							cout << "Enter distance :";
							cin >> distance;
							cout << endl;
							cout << "Enter Date and Time to schedule Ride: " << endl;
							cout << "Enter date :";
							cin >> day;
							cout << endl;
							cout << "Enter month :";
							cin >> month;
							cout << endl;
							cout << "Enter year :";
							cin >> year;
							cout << endl;
							cout << "Enter hour :";
							cin >> hour;
							cout << endl;
							cout << "Enter minute :";
							cin >> min;
							cout << endl;
							cout << "Enter second :";
							cin >> sec;
							cout << endl;
							cout << "Enter ride status(0 for pending, 1 if complete) :";
							cin >> status;
							cout << endl;
							cout << "Enter fuel rate :";
							cin >> fuelrate;
							cout << endl;
							cout << "Enter driver ID :";
							cin >> dId;
							cout << endl;
							cout << "Enter vehicle ID :";
							cin >> vId;
							cout << endl;
							cout << "Enter goods weight :";
							cin >> goodsWeight;
							cout << endl;
							cout << "Enter goods type :";
							cin >> goodsType;
							cout << endl;
							v[i]->setDelivery(goodsWeight, goodsType, source, destination, distance, status, fuelrate, customerid, dId, vId, hour, min, sec, day, month, year);
						}
						if (vehiclechoice == 3) {
							delete v[i];
							v[i] = nullptr;
						}
						if (vehiclechoice == 4) {
							if (v[i] != nullptr) {
								cout << endl;
								cout << *v[i];
								cout << endl;
							}
						}
						break;
					}
					else if (i == 19) {
						cout << "Your information was not found in the record, You need to register first to use this application !" << endl;
						for (int j = 0; j < 20; j++) {
							if (v[j] == nullptr) {
								cout << "Enter vehicle registeration number: ";
								cin >> reg;
								cout << endl;
								cout << "Enter mileage : ";
								cin >> mileage;
								cout << endl;
								cout << "Enter Licence type required for the vehicle: ";
								cin >> Ltype;
								cout << endl;
								cout << "Enter status of vehicle(Press(0) for free, Press(1) if booked in a service already): ";
								cin >> status;
								cout << endl;
								cout << "Enter fuel type for vehicle: ";
								cin >> ftype;
								cout << endl;
								cout << "Enter vehicle rank: ";
								cin >> VRank;
								cout << endl;
								cout << "Enter extra feature for vehicle: " << endl;
								cout << "Enter feature ID: ";
								cin >> fid;
								cout << endl;
								cout << "Enter feature Desciption: ";
								cin >> desc;
								cout << endl;
								cout << "Enter feature price: ";
								cin >> price;
								cout << endl;
								cout << "Enter Date of Manufacturing: " << endl;
								cout << "Enter date: ";
								cin >> day;
								cout << endl;
								cout << "Enter month: ";
								cin >> month;
								cout << endl;
								cout << "Enter year: ";
								cin >> year;
								cout << endl;
								v[j] = new Vehicle(day, month, year, fid, desc, price, vehicleid, reg, mileage, Ltype, status, ftype, VRank);
								break;
							}
						}
						break;
					}
				}
				break;
			}
		}
		else if (choice == 4) {
			break;
		}
	}

	cout << "------------  BYE  ------------" << endl;

	/*delete[] fN;
	fN = nullptr;
	delete[] lN;
	lN = nullptr;
	delete[] type;
	type = nullptr;
	delete[] source;
	source = nullptr;
	delete[] destination;
	destination = nullptr;
	delete[] goodsType;
	goodsType = nullptr;
	delete[] desc;
	desc = nullptr;
	delete[] Ltype;
	Ltype = nullptr;
	delete[] ftype;
	ftype = nullptr;*/

}