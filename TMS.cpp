#include <iostream>
#include "TMS.H"
using namespace std;

Name::Name() {
	fName = nullptr;
	lName = nullptr;
}

Name::Name(char* fN, char* lN) {
	fName = new char[strlen(fN) + 1];
	for (int i = 0; i < strlen(fN); i++) {
		fName[i] = fN[i];
	}
	fName[strlen(fN)] = '\0';

	lName = new char[strlen(lN) + 1];
	for (int i = 0; i < strlen(lN); i++) {
		lName[i] = lN[i];
	}
	lName[strlen(lN)] = '\0';
}

Name::Name(const Name& obj) {
	fName = new char[strlen(obj.fName) + 1];
	for (int i = 0; i < strlen(obj.fName); i++) {
		fName[i] = obj.fName[i];
	}
	fName[strlen(obj.fName)] = '\0';

	lName = new char[strlen(obj.lName) + 1];
	for (int i = 0; i < strlen(obj.lName); i++) {
		lName[i] = obj.lName[i];
	}
	lName[strlen(obj.lName)] = '\0';
}

Name::~Name() {
	if (fName != nullptr) {
		/*delete[] fName;*/
		fName = nullptr;
	}
	if (lName != nullptr) {
		/*delete[] lName;*/
		lName = nullptr;
	}
}

char* Name::getfName() {
	return fName;
}

char* Name::getlName() {
	return lName;
}

void Name::setfName(char* fN) {
	if (fName != nullptr) {
		delete[] fName;
		fName = nullptr;

		fName = new char[strlen(fN) + 1];
		for (int i = 0; i < strlen(fN); i++) {
			fName[i] = fN[i];
		}
		fName[strlen(fN)] = '\0';
	}
	else {
		fName = new char[strlen(fN) + 1];
		for (int i = 0; i < strlen(fN); i++) {
			fName[i] = fN[i];
		}
		fName[strlen(fN)] = '\0';
	}
}

void Name::setlName(char* lN) {
	if (lName != nullptr) {
		delete[] lName;
		lName = nullptr;

		lName = new char[strlen(lN) + 1];
		for (int i = 0; i < strlen(lN); i++) {
			lName[i] = lN[i];
		}
		lName[strlen(lN)] = '\0';
	}
	else {
		lName = new char[strlen(lN) + 1];
		for (int i = 0; i < strlen(lN); i++) {
			lName[i] = lN[i];
		}
		lName[strlen(lN)] = '\0';
	}
}

ostream& operator<<(ostream& out, const Name& n) {
	out << n.fName << " " << n.lName << endl;
	return out;
}

Date::Date() {
	day = 0;
	month = 0;
	year = 0;
}

Date::Date(int day, int month, int year) {
	this->day = day;
	this->month = month;
	this->year = year;
}

Date::Date(const Date& obj) {
	day = obj.day;
	month = obj.month;
	year = obj.year;
}

int Date::getday() {
	return day;
}

int Date::getmonth() {
	return month;
}

int Date::getyear() {
	return year;
}

void Date::setday(int day) {
	this->day = day;
}

void Date::setmonth(int month) {
	this->month = month;
}

void Date::setyear(int year) {
	this->year = year;
}

ostream& operator<<(ostream& out, const Date& d) {
	out << d.day << " / " << d.month << " / " << d.year << endl;
	return out;
}

mTime::mTime() {
	hour = 0;
	min = 0;
	sec = 0;
}

mTime::mTime(int hour, int min, int sec) {
	this->hour = hour;
	this->min = min;
	this->sec = sec;
}

mTime::mTime(const mTime& obj) {
	hour = obj.hour;
	min = obj.min;
	sec = obj.sec;
}

int mTime::gethour() {
	return hour;
}

int mTime::getmin() {
	return min;
}

int mTime::getsec() {
	return sec;
}

void mTime::sethour(int hour) {
	this->hour = hour;
}

void mTime::setmin(int min) {
	this->min = min;
}

void mTime::setsec(int sec) {
	this->sec = sec;
}

ostream& operator<<(ostream& out, const mTime& t) {
	out << t.hour << " : " << t.min << " : " << t.sec << endl;
	return out;
}

ostream& Service::print(ostream& out) const {
	return out;
}

Service::Service() :bookingDate(), bookingTime() {
	source = nullptr;
	destination = nullptr;
	distance = 0;
	status = false; // false for pending, true if complete
	fuelrate = 0;
	cId = 0;
	dId = 0;
	vId = 0;
}

Service::Service(char* sauce, char* dest, float dist, bool stat, float frate, int cid, int did, int vid, int hour, int min, int sec, int day, int month, int year) :bookingDate(day, month, year), bookingTime(hour, min, sec) {

	source = new char[strlen(sauce) + 1];
	for (int i = 0; i < strlen(sauce); i++) {
		source[i] = sauce[i];
	}
	source[strlen(sauce)] = '\0';

	destination = new char[strlen(dest) + 1];
	for (int i = 0; i < strlen(dest); i++) {
		destination[i] = dest[i];
	}
	destination[strlen(dest)] = '\0';


	distance = dist;
	status = stat;
	fuelrate = frate;
	cId = cid;
	dId = did;
	vId = vid;
}

Service::Service(const Service& s) {

	this->source = new char[strlen(s.source) + 1];
	for (int i = 0; i < strlen(s.source); i++) {
		this->source[i] = s.source[i];
	}
	this->source[strlen(s.source)] = '\0';

	this->destination = new char[strlen(s.destination) + 1];
	for (int i = 0; i < strlen(s.destination); i++) {
		this->destination[i] = s.destination[i];
	}
	this->destination[strlen(s.destination)] = '\0';

	this->distance = s.distance;
	this->bookingDate = s.bookingDate;
	this->bookingTime = s.bookingTime;
	this->status = s.status;
	this->fuelrate = s.fuelrate;
	this->cId = s.cId;
	this->dId = s.dId;
	this->vId = s.vId;
}

Service::~Service() {

}

char* Service::getSource() {
	return source;
}

void Service::setSource(char* source) {
	if (this->source != nullptr) {
		delete[] this->source;
		this->source = nullptr;

		this->source = new char[strlen(source) + 1];
		for (int i = 0; i < strlen(source); i++) {
			this->source[i] = source[i];
		}
		this->source[strlen(source)] = '\0';
	}
	else {
		this->source = new char[strlen(source) + 1];
		for (int i = 0; i < strlen(source); i++) {
			this->source[i] = source[i];
		}
		this->source[strlen(source)] = '\0';
	}
}

char* Service::getDestination() {
	return destination;
}

void Service::setDestination(char* destination) {
	if (this->destination != nullptr) {
		delete[] this->destination;
		this->destination = nullptr;

		this->destination = new char[strlen(destination) + 1];
		for (int i = 0; i < strlen(destination); i++) {
			this->destination[i] = destination[i];
		}
		this->destination[strlen(destination)] = '\0';
	}
	else {
		this->destination = new char[strlen(destination) + 1];
		for (int i = 0; i < strlen(destination); i++) {
			this->destination[i] = destination[i];
		}
		this->destination[strlen(destination)] = '\0';
	}
}

float Service::getDistance() {
	return distance;
}

void Service::setDistance(float distance) {
	this->distance = distance;
}

bool Service::getStatus() {
	return status;
}

void Service::setStatus(bool status) {
	this->status = status;
}

float Service::getFuelRate() {
	return fuelrate;
}

void Service::setFuelRate(float fuelrate) {
	this->fuelrate = fuelrate;
}

float Service::getCID() {
	return cId;
}

void Service::setCID(int cId) {
	this->cId = cId;
}

float Service::getDID() {
	return dId;
}

void Service::setDID(int dId) {
	this->dId = dId;
}

float Service::getVID() {
	return vId;
}

void Service::setVID(int vId) {
	this->vId = vId;
}

ostream& operator<< (ostream& out, const Service& s) {
	out << "Source: " << s.source << endl;
	out << "Destination: " << s.destination << endl;
	out << "Distance: " << s.distance << " km" << endl;
	out << "Booking Date: " << endl << s.bookingDate << endl;
	out << "Booking Time: " << endl << s.bookingTime << endl;
	out << "Ride Status: ";
	if (s.status == 1) {
		cout << "Complete " << endl;
	}
	else if (s.status == 0) {
		cout << "Cancel " << endl;
	}
	out << "Fual Rate: " << s.fuelrate << endl;
	out << "Customer ID: " << s.cId << endl;
	out << "Driver ID: " << s.dId << endl;
	out << "Vehicle ID: " << s.vId << endl;
	s.print(out);
	return out;
}

ostream& Ride::print(ostream& out) const {
	cout << "Ride Details: " << endl;
	cout << "Number of Passengers: " << noofPassengers << endl;
	cout << "Ride Type: " << rideType << endl;
	cout << "Driver Ranking: " << DriverRanking << endl;
	cout << "Vehicle Ranking: " << VehicleRanking << endl;
	return out;
}

Ride::Ride() :Service() {
	noofPassengers = 0;
	rideType = nullptr;
	DriverRanking = 0;
	VehicleRanking = 0;
}

Ride::Ride(int passengernum, char* type, float DRank, float VRank, char* source, char* destination, float distance, bool status, float fuelrate, int cId, int dId, int vId, int hour, int min, int sec, int day, int month, int year) : Service(source, destination, distance, status, fuelrate, cId, dId, vId, hour, min, sec, day, month, year) {
	rideType = new char[strlen(type) + 1];
	for (int i = 0; i < strlen(type); i++) {
		rideType[i] = type[i];
	}
	rideType[strlen(type)] = '\0';

	noofPassengers = passengernum;
	DriverRanking = DRank;
	VehicleRanking = VRank;
}

Ride::Ride(const Ride& r) : Service(r) {
	rideType = new char[strlen(r.rideType) + 1];
	for (int i = 0; i < strlen(r.rideType); i++) {
		this->rideType[i] = r.rideType[i];
	}
	rideType[strlen(r.rideType)] = '\0';

	noofPassengers = r.noofPassengers;
	DriverRanking = r.DriverRanking;
	VehicleRanking = r.VehicleRanking;
}

//have to make destructor
Ride::~Ride() {

}

int Ride::getPassengers() {
	return noofPassengers;
}

void Ride::setPassenger(int noofPassengers) {
	this->noofPassengers = noofPassengers;
}

char* Ride::getRideType() {
	return rideType;
}
void Ride::setRideType(char* rideType) {
	if (this->rideType != nullptr) {
		delete[] this->rideType;
		this->rideType = nullptr;

		this->rideType = new char[strlen(rideType) + 1];
		for (int i = 0; i < strlen(rideType); i++) {
			this->rideType[i] = rideType[i];
		}
		this->rideType[strlen(rideType)] = '\0';
	}
	else {
		this->rideType = new char[strlen(rideType) + 1];
		for (int i = 0; i < strlen(rideType); i++) {
			this->rideType[i] = rideType[i];
		}
		this->rideType[strlen(rideType)] = '\0';
	}
}

float Ride::getDriverRanking() {
	return DriverRanking;
}

void Ride::setDriverRanking(float DriverRanking) {
	this->DriverRanking = DriverRanking;
}

float Ride::getVehicleRanking() {
	return VehicleRanking;
}

void Ride::setVehicleRanking(float VehicleRanking) {
	this->VehicleRanking = VehicleRanking;
}

ostream& operator<< (ostream& out, const Ride& r) {
	out << static_cast<Service>(r);
	out << "Number of Passengers: " << r.noofPassengers << endl;
	out << "Ride Type: " << r.rideType << endl;
	out << "Driver Ranking: " << r.DriverRanking << endl;
	out << "Vehicle Ranking: " << r.VehicleRanking << endl;
	return out;
}

ostream& Delivery::print(ostream& out) const {
	out << "Delivery Details: " << endl;
	out << "Goods Weight: " << goodsWeight << " kg" << endl;
	out << "Goods Type: " << goodsType << endl;
	return out;
}

Delivery::Delivery() : Service() {
	this->goodsWeight = 0;
	this->goodsType = nullptr;
}

Delivery::Delivery(float goodsWeight, char* goodsType, char* source, char* destination, float distance, bool status, float fuelrate, int cId, int dId, int vId, int hour, int min, int sec, int day, int month, int year) : Service(source, destination, distance, status, fuelrate, cId, dId, vId, hour, min, sec, day, month, year) {
	this->goodsWeight = goodsWeight;
	this->goodsType = new char[strlen(goodsType) + 1];
	for (int i = 0; i < strlen(goodsType); i++) {
		this->goodsType[i] = goodsType[i];
	}
	this->goodsType[strlen(goodsType)] = '\0';
}

Delivery::Delivery(const Delivery& d) : Service(d) {
	goodsWeight = d.goodsWeight;
	goodsType = new char[strlen(d.goodsType) + 1];
	for (int i = 0; i < strlen(d.goodsType); i++) {
		goodsType[i] = d.goodsType[i];
	}
	goodsType[strlen(d.goodsType)] = '\0';
}

Delivery::~Delivery() {

}

float Delivery::getgoodsWeight() {
	return goodsWeight;
}

void Delivery::setgoodsWeight(float goodsWeight) {
	this->goodsWeight = goodsWeight;
}

char* Delivery::getgoodsType() {
	return goodsType;
}

void Delivery::setgoodsType(char* goodsType) {
	if (this->goodsType != nullptr) {
		delete[] this->goodsType;
		this->goodsType = nullptr;

		this->goodsType = new char[strlen(goodsType) + 1];
		for (int i = 0; i < strlen(goodsType); i++) {
			this->goodsType[i] = goodsType[i];
		}
		this->goodsType[strlen(goodsType)] = '\0';
	}
	else {
		this->goodsType = new char[strlen(goodsType) + 1];
		for (int i = 0; i < strlen(goodsType); i++) {
			this->goodsType[i] = goodsType[i];
		}
		this->goodsType[strlen(goodsType)] = '\0';
	}
}

ostream& operator<< (ostream& out, const Delivery& d) {
	out << static_cast<Service>(d);
	out << "Goods Weight: " << d.goodsWeight << " kg" << endl;
	out << "Goods Type: " << d.goodsType << endl;
	return out;
}

Person::Person() :pName(), DOB() {
	Age = 0;
	Nid = 0;
}

Person::Person(int age, int Nid, char* fN, char* lN, int day, int month, int year) : pName(fN, lN), DOB(day, month, year) {
	this->Age = age;
	this->Nid = Nid;
}

Person::Person(const Person& p) {
	this->pName = p.pName;
	this->DOB = p.DOB;
	this->Age = p.Age;
	this->Nid = p.Nid;
}

Person::~Person() {

}

int Person::getAge() {
	return Age;
}

void Person::setAge(int age) {
	this->Age = age;
}

int Person::getNid() {
	return Nid;
}

void Person::setNid(int nid) {
	this->Nid = nid;
}

ostream& operator<< (ostream& out, const Person& p) {
	out << "Name: " << p.pName;
	out << "Date of Birth: " << p.DOB;
	out << "Age: " << p.Age << endl;
	out << "Number ID: " << p.Nid << endl;
	return out;
}

Customer::Customer() :Person(), bookingHistory() {
	cId = 0;
}

Customer::Customer(int cId, int age, int Nid, char* fN, char* lN, int day, int month, int year) : Person(age, Nid, fN, lN, day, month, year) {
	this->cId = cId;
	this->bookingHistory = new Service * [10];
	for (int i = 0; i < 10; i++) {
		this->bookingHistory[i] = nullptr;
	}
	cout << "Customer registeration successfull !" << endl;
}

Customer::Customer(const Customer& c) : Person(c) {
	cId = c.cId;
	bookingHistory = new Service * [10];
	for (int i = 0; i < 10; i++) {
		bookingHistory[i] = c.bookingHistory[i];
	}
}

Customer::~Customer() {

}

int Customer::getcId() {
	return cId;
}

void Customer::setcId(int cid) {
	this->cId = cid;
}

void Customer::setRide(int passengernum, char* type, float DRank, float VRank, char* source, char* destination, float distance, bool status, float fuelrate, int cId, int dId, int vId, int hour, int min, int sec, int day, int month, int year) {
	for (int i = 0; i < 10; i++) {
		if (bookingHistory[i] == nullptr) {
			bookingHistory[i] = new Ride(passengernum, type, DRank, VRank, source, destination, distance, status, fuelrate, cId, dId, vId, hour, min, sec, day, month, year);
			i = 9;
		}
		else if (i == 9) {
			cout << "List is Full !" << endl;
		}
	}
	cout << "Ride booked successfully !" << endl;
}

void Customer::setDelivery(float goodsWeight, char* goodsType, char* source, char* destination, float distance, bool status, float fuelrate, int cId, int dId, int vId, int hour, int min, int sec, int day, int month, int year) {
	for (int i = 0; i < 10; i++) {
		if (bookingHistory[i] == nullptr) {
			bookingHistory[i] = new Delivery(goodsWeight, goodsType, source, destination, distance, status, fuelrate, cId, dId, vId, hour, min, sec, day, month, year);
			i = 9;
		}
		else if (i == 9) {
			cout << "List is Full !" << endl;
		}
	}
	cout << "Delivery booked successfully !" << endl;
}

bool Customer::checkcustomeravailablity(int cid) {
	if (this->cId == cid) {
		return true;
	}
	return false;
}

ostream& operator<< (ostream& out, const Customer& c) {
	out << static_cast<Person>(c);
	out << "Customer ID: " << c.cId << endl;
	out << "-------Customer Record-------" << endl;
	for (int i = 0; i < 10; i++) {
		if (c.bookingHistory[i] != nullptr) {
			out << *c.bookingHistory[i] << endl;
			out << "--------------------" << endl;
		}
	}
	return out;
}

void Driver::printMultipleLicenses(int did) {
	if (noofLicences > 1) {
		cout << "Driver ID: " << did << endl;
	}
}

Driver::Driver() :Person(), serviceHistory() {
	dId = 0;
	LicencesList = nullptr;
	noofLicences = 0;
	overallRanking = 0;
	salary = 0;
	experience = 0;
	status = 0;
}

Driver::Driver(int dId, char** LicencesList, int noofLicences, float overallRanking, float salary, int experience, int status, int age, int Nid, char* fN, char* lN, int day, int month, int year) : Person(age, Nid, fN, lN, day, month, year) {
	this->dId = dId;
	this->noofLicences = noofLicences;
	this->LicencesList = new char* [this->noofLicences];
	for (int i = 0; i < noofLicences; i++) {
		this->LicencesList[i] = new char[strlen(LicencesList[i]) + 1];
	}
	for (int i = 0; i < noofLicences; i++) {
		for (int j = 0; j < strlen(LicencesList[i]); j++) {
			this->LicencesList[i][j] = LicencesList[i][j];
		}
		this->LicencesList[i][strlen(LicencesList[i])] = '\0';
	}
	this->overallRanking = overallRanking;
	this->salary = salary;
	this->experience = experience;
	this->status = status;

	this->serviceHistory = new Service * [10];
	for (int i = 0; i < 10; i++) {
		this->serviceHistory[i] = nullptr;
	}
	cout << "Driver registeration successfull !" << endl;
}

Driver::Driver(const Driver& d) : Person(d) {
	dId = d.dId;
	noofLicences = d.noofLicences;
	LicencesList = new char* [noofLicences];
	for (int i = 0; i < noofLicences; i++) {
		LicencesList[i] = new char[strlen(d.LicencesList[i]) + 1];
	}
	for (int i = 0; i < noofLicences; i++) {
		for (int j = 0; j < strlen(d.LicencesList[i]); j++) {
			LicencesList[i][j] = d.LicencesList[i][j];
		}
		LicencesList[i][strlen(d.LicencesList[i])] = '\0';
	}
	noofLicences = d.noofLicences;
	overallRanking = d.overallRanking;
	salary = d.salary;
	experience = d.experience;
	status = d.status;

	serviceHistory = new Service * [10];
	for (int i = 0; i < 10; i++) {
		serviceHistory[i] = d.serviceHistory[i];
	}
}

Driver::~Driver() {

}

int Driver::getdId() {
	return dId;
}

void Driver::setdId(int cid) {
	this->dId = cid;
}

int Driver::getnoofLicences() {
	return noofLicences;
}

void Driver::setnoofLicences(int Lno) {
	this->noofLicences = Lno;
}

char** Driver::getLicencesList() {
	return LicencesList;
}

void Driver::setLicencesList(char** LL) {
	if (LicencesList != nullptr) {
		for (int i = 0; i < noofLicences; i++) {
			delete LicencesList[i];
		}
		delete[] LicencesList;
		LicencesList = nullptr;

		LicencesList = new char* [noofLicences];
		for (int i = 0; i < noofLicences; i++) {
			LicencesList[i] = new char[strlen(LL[i]) + 1];
		}
		for (int i = 0; i < noofLicences; i++) {
			for (int j = 0; j < strlen(LL[i]); j++) {
				LicencesList[i][j] = LL[i][j];
			}
			LicencesList[i][strlen(LL[i])] = '\0';
		}
	}
	else {
		LicencesList = new char* [noofLicences];
		for (int i = 0; i < noofLicences; i++) {
			LicencesList[i] = new char[strlen(LL[i]) + 1];
		}
		for (int i = 0; i < noofLicences; i++) {
			for (int j = 0; j < strlen(LL[i]); j++) {
				LicencesList[i][j] = LL[i][j];
			}
			LicencesList[i][strlen(LL[i])] = '\0';
		}
	}
}

float Driver::getoverallRanking() {
	return overallRanking;
}

void Driver::setoverallRanking(float rank) {
	this->overallRanking = rank;
}

float Driver::getsalary() {
	return salary;
}

void Driver::setsalary(float salary) {
	this->salary = salary;
}

int Driver::getexperience() {
	return experience;
}

void Driver::setexperience(int exp) {
	this->experience = exp;
}

int Driver::getstatus() {
	return status;
}

void Driver::setstatus(int status) {
	this->status = status;
}

void Driver::setRide(int passengernum, char* type, float DRank, float VRank, char* source, char* destination, float distance, bool status, float fuelrate, int cId, int dId, int vId, int hour, int min, int sec, int day, int month, int year) {
	for (int i = 0; i < 10; i++) {
		if (serviceHistory[i] == nullptr) {
			serviceHistory[i] = new Ride(passengernum, type, DRank, VRank, source, destination, distance, status, fuelrate, cId, dId, vId, hour, min, sec, day, month, year);
			i = 9;
		}
		else if (i == 9) {
			cout << "List is Full !" << endl;
		}
	}
	cout << "Ride booked successfully !" << endl;
}

void Driver::setDelivery(float goodsWeight, char* goodsType, char* source, char* destination, float distance, bool status, float fuelrate, int cId, int dId, int vId, int hour, int min, int sec, int day, int month, int year) {
	for (int i = 0; i < 10; i++) {
		if (serviceHistory[i] == nullptr) {
			serviceHistory[i] = new Delivery(goodsWeight, goodsType, source, destination, distance, status, fuelrate, cId, dId, vId, hour, min, sec, day, month, year);
			i = 9;
		}
		else if (i == 9) {
			cout << "List is Full !" << endl;
		}
	}
	cout << "Delivery booked successfully !" << endl;
}

bool Driver::checkdriveravailablity(int did) {
	if (this->dId == did) {
		return true;
	}
	return false;
}

void Driver::printTopDrivers(int did) {
	if (overallRanking >= 4.5)
	{
		cout << "Driver ID: " << did << endl;
		cout << "Ranking: " << getoverallRanking() << endl;
	}
}

ostream& operator<< (ostream& out, const Driver& d) {
	out << static_cast<Person>(d);
	out << "Driver ID: " << d.dId << endl;
	out << "No of Licences: " << d.noofLicences << endl;
	out << "Licences List: " << endl;
	for (int i = 0; i < d.noofLicences; i++) {
		out << d.LicencesList[i] << endl;
	}
	out << "Overall Ranking: " << d.overallRanking << endl;
	out << "Salary: " << d.salary << endl;
	out << "Experience: " << d.experience << endl;
	out << "Ride Status: ";
	if (d.status == 1) {
		out << "Free " << endl;
	}
	else if (d.status == 2) {
		out << "Booked " << endl;
	}
	else if (d.status == 3) {
		out << "Pending " << endl;
	}
	out << "-------Driver Record-------" << endl;
	for (int i = 0; i < 10; i++) {
		if (d.serviceHistory[i] != nullptr) {
			out << *d.serviceHistory[i] << endl;
			out << "--------------------" << endl;
		}
	}
	return out;
}

Feature::Feature() {
	fId = 0;
	description = nullptr;
	cost = 0;
}

Feature::Feature(int id, char* desc, float price) {
	fId = id;
	cost = price;
	this->description = new char[strlen(desc) + 1];
	for (int i = 0; i < strlen(desc); i++) {
		this->description[i] = desc[i];
	}
	this->description[strlen(desc)] = '\0';
}

Feature::Feature(const Feature& f) {
	fId = f.fId;
	cost = f.cost;
	description = new char[strlen(f.description) + 1];
	for (int i = 0; i < strlen(f.description); i++) {
		this->description[i] = f.description[i];
	}
	this->description[strlen(f.description)] = '\0';
}

Feature::~Feature() {

}

void Feature::setFID(int fId) {
	this->fId = fId;
}

int Feature::getFID() {
	return fId;
}

void Feature::setDescription(char* description) {
	if (this->description != nullptr) {
		delete[] this->description;
		this->description = nullptr;

		this->description = new char[strlen(description) + 1];
		for (int i = 0; i < strlen(description); i++) {
			this->description[i] = description[i];
		}
		this->description[strlen(description)] = '\0';
	}
	else {
		this->description = new char[strlen(description) + 1];
		for (int i = 0; i < strlen(description); i++) {
			this->description[i] = description[i];
		}
		this->description[strlen(description)] = '\0';
	}
}

char* Feature::getDescription() {
	return description;
}

void Feature::setCost(float cost) {
	this->cost = cost;
}

float Feature::getCost() {
	return cost;
}

ostream& operator<< (ostream& out, const Feature& f) {
	out << "Faeture ID: " << f.fId << endl;
	out << "Feature Description: " << f.description << endl;
	out << "Feature Cost: " << f.cost << endl;
	return out;
}

Vehicle::Vehicle() :manufacturingDate(), list(), serviceHistory() {
	vId = 0;
	registrationNo = 0;
	avgMileage = 0;
	LicenceType = nullptr;
	status = false; //vehicle is free
	fueltype = nullptr;
	overallRanking = 0;
}

Vehicle::Vehicle(int day, int month, int year, int fid, char* desc, float price, int vid, int reg, float mileage, char* Ltype, bool stat, char* ftype, float rank) :manufacturingDate(day, month, year) {
	list = new Feature(fid, desc, price);
	this->vId = vid;
	this->registrationNo = reg;
	this->avgMileage = mileage;
	this->LicenceType = new char[strlen(Ltype) + 1];
	for (int i = 0; i < strlen(Ltype); i++) {
		this->LicenceType[i] = Ltype[i];
	}
	this->LicenceType[strlen(Ltype)] = '\0';
	this->status = stat; //vehicle is free when false and in use when trues
	this->fueltype = new char[strlen(ftype) + 1];
	for (int i = 0; i < strlen(ftype); i++) {
		this->fueltype[i] = ftype[i];
	}
	this->fueltype[strlen(ftype)] = '\0';
	this->overallRanking = rank;

	this->serviceHistory = new Service * [10];
	for (int i = 0; i < 10; i++) {
		this->serviceHistory[i] = nullptr;
	}
	cout << "Vehicle registeration successfull !" << endl;
}

Vehicle::Vehicle(const Vehicle& v) {
	vId = v.vId;
	registrationNo = v.registrationNo;
	avgMileage = v.avgMileage;
	LicenceType = new char[strlen(v.LicenceType) + 1];
	for (int i = 0; i < strlen(v.LicenceType); i++) {
		LicenceType[i] = v.LicenceType[i];
	}
	LicenceType[strlen(v.LicenceType)] = '\0';
	status = v.status;
	fueltype = new char[strlen(v.fueltype) + 1];
	for (int i = 0; i < strlen(v.fueltype); i++) {
		fueltype[i] = v.fueltype[i];
	}
	fueltype[strlen(v.fueltype)] = '\0';
	overallRanking = v.overallRanking;
	manufacturingDate = v.manufacturingDate;
	list = v.list;
	serviceHistory = new Service * [10];
	for (int i = 0; i < 10; i++) {
		serviceHistory[i] = v.serviceHistory[i];
	}
}

Vehicle::~Vehicle() {

}

void Vehicle::setVID(int vId) {
	this->vId = vId;
}

int Vehicle::getVID() {
	return vId;
}

void Vehicle::setRegNo(int registrationNo) {
	this->registrationNo = registrationNo;
}

int Vehicle::getRegNo() {
	return registrationNo;
}

void Vehicle::setMileage(float avgMileage) {
	this->avgMileage = avgMileage;
}

float Vehicle::getMileage() {
	return avgMileage;
}

void Vehicle::setLicenseType(char* LicenseType) {
	if (this->LicenceType != nullptr) {
		delete[] this->LicenceType;
		this->LicenceType = nullptr;

		this->LicenceType = new char[strlen(LicenseType) + 1];
		for (int i = 0; i < strlen(LicenseType); i++) {
			this->LicenceType[i] = LicenceType[i];
		}
		this->LicenceType[strlen(LicenceType)] = '\0';
	}
	else {
		this->LicenceType = new char[strlen(LicenseType) + 1];
		for (int i = 0; i < strlen(LicenseType); i++) {
			this->LicenceType[i] = LicenceType[i];
		}
		this->LicenceType[strlen(LicenceType)] = '\0';
	}
}

char* Vehicle::getLicenseType() {
	return LicenceType;
}

void Vehicle::setStatus(bool status) {
	this->status = status;
}

bool Vehicle::getStatus() {
	return status;
}

void Vehicle::setFuelType(char* fueltype) {
	if (this->fueltype != nullptr) {
		delete[] this->fueltype;
		this->fueltype = nullptr;

		this->fueltype = new char[strlen(fueltype) + 1];
		for (int i = 0; i < strlen(fueltype); i++) {
			this->fueltype[i] = fueltype[i];
		}
		this->fueltype[strlen(fueltype)] = '\0';
	}
	else {
		this->fueltype = new char[strlen(fueltype) + 1];
		for (int i = 0; i < strlen(fueltype); i++) {
			this->fueltype[i] = fueltype[i];
		}
		this->fueltype[strlen(fueltype)] = '\0';
	}
}

char* Vehicle::getFuelType() {
	return fueltype;
}

void Vehicle::setRanking(float overallRanking) {
	this->overallRanking = overallRanking;
}

float Vehicle::getRanking() {
	return overallRanking;
}

void Vehicle::setRide(int passengernum, char* type, float DRank, float VRank, char* source, char* destination, float distance, bool status, float fuelrate, int cId, int dId, int vId, int hour, int min, int sec, int day, int month, int year) {
	for (int i = 0; i < 10; i++) {
		if (serviceHistory[i] == nullptr) {
			serviceHistory[i] = new Ride(passengernum, type, DRank, VRank, source, destination, distance, status, fuelrate, cId, dId, vId, hour, min, sec, day, month, year);
			i = 9;
		}
		else if (i == 9) {
			cout << "List is Full !" << endl;
		}
	}
	cout << "Ride booked successfully !" << endl;
}

void Vehicle::setDelivery(float goodsWeight, char* goodsType, char* source, char* destination, float distance, bool status, float fuelrate, int cId, int dId, int vId, int hour, int min, int sec, int day, int month, int year) {
	for (int i = 0; i < 10; i++) {
		if (serviceHistory[i] == nullptr) {
			serviceHistory[i] = new Delivery(goodsWeight, goodsType, source, destination, distance, status, fuelrate, cId, dId, vId, hour, min, sec, day, month, year);
			i = 9;
		}
		else if (i == 9) {
			cout << "List is Full !" << endl;
		}
	}
	cout << "Delivery booked successfully !" << endl;
}

bool Vehicle::checkvehicleavailablity(int vid) {
	if (this->vId == vid) {
		return true;
	}
	return false;
}

ostream& operator<< (ostream& out, const Vehicle& v) {
	out << "Vehicle ID: " << v.vId << endl;
	out << "Registration No: " << v.registrationNo << endl;
	out << "Average Mileage: " << v.avgMileage << endl;
	out << "Licence Type: " << v.LicenceType << endl;
	out << "Availability Status: ";
	if (v.status == 1) {
		out << "Booked" << endl;
	}
	else if (v.status == 0) {
		out << "Free" << endl;
	}
	out << "Fuel Type: " << v.fueltype << endl;
	out << "Overall Ranking: " << v.overallRanking << endl;
	out << "Manufacturing Date: " << v.manufacturingDate << endl;
	out << "Features: " << endl << *(v.list) << endl;
	out << "-------Vehicle Record-------" << endl;
	for (int i = 0; i < 10; i++) {
		if (v.serviceHistory[i] != nullptr) {
			out << *v.serviceHistory[i] << endl;
			out << "--------------------" << endl;
		}
	}
	return out;
}