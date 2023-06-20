#pragma once
#include <iostream>
using namespace std;


class Name {
private:
	char* fName;
	char* lName;
public:
	Name();
	Name(char* fN, char* lN);
	Name(const Name& obj);
	~Name();
	char* getfName();
	char* getlName();
	void setfName(char* fN);
	void setlName(char* lN);
	friend ostream& operator<<(ostream& out, const Name& n);
};

class Date {
private:
	int day;
	int month;
	int year;
public:
	Date();
	Date(int day, int month, int year);
	Date(const Date& obj);
	int getday();
	int getmonth();
	int getyear();
	void setday(int day);
	void setmonth(int month);
	void setyear(int year);
	friend ostream& operator<<(ostream& out, const Date& d);
};

class mTime {
private:
	int hour;
	int min;
	int sec;
public:
	mTime();
	mTime(int hour, int min, int sec);
	mTime(const mTime& obj);
	int gethour();
	int getmin();
	int getsec();
	void sethour(int day);
	void setmin(int month);
	void setsec(int year);
	friend ostream& operator<<(ostream& out, const mTime& t);
};

class Service {
private:
	char* source;
	char* destination;
	float distance; //in km
	Date bookingDate;
	mTime bookingTime;
	bool status; // false for pending, true if complete
	float fuelrate;
	int cId; // Customer Id who booked the ride
	int dId; // Driver Id
	int vId; // vehicle Id
	//you can add more members here if required
	//add member functions
protected:
	virtual ostream& print(ostream& out) const;
public:
	Service();
	Service(char* sauce, char* dest, float dist, bool stat, float frate, int cid, int did, int vid, int hour, int min, int sec, int day, int month, int year);
	Service(const Service& s);
	~Service();
	char* getSource();
	void setSource(char* source);
	char* getDestination();
	void setDestination(char* destination);
	float getDistance();
	void setDistance(float distance);
	bool getStatus();
	void setStatus(bool status);
	float getFuelRate();
	void setFuelRate(float fuelrate);
	float getCID();
	void setCID(int cId);
	float getDID();
	void setDID(int dId);
	float getVID();
	void setVID(int vId);
	friend ostream& operator<< (ostream& out, const Service& s);
};

class Ride : public Service {
private:
	int noofPassengers; // false for pending, true if complete
	char* rideType; // intercity, intracity
	float DriverRanking; // 0 to 5 scale (worst to best)
	float VehicleRanking; // 0 to 5 scale (worst to best)
	//you can add more members here if required
	//add member functions
protected:
	virtual ostream& print(ostream& out) const;
public:
	Ride();
	Ride(int passengernum, char* type, float DRank, float VRank, char* source, char* destination, float distance, bool status, float fuelrate, int cId, int dId, int vId, int hour, int min, int sec, int day, int month, int year);
	Ride(const Ride& r);
	~Ride();
	int getPassengers();
	void setPassenger(int noofPassengers);
	char* getRideType();
	void setRideType(char* rideType);
	float getDriverRanking();
	void setDriverRanking(float DriverRanking);
	float getVehicleRanking();
	void setVehicleRanking(float VehicleRanking);
	friend ostream& operator<< (ostream& out, const Ride& r);
};

class Delivery : public Service {
private:
	float goodsWeight; // Weight of goods in Kg
	char* goodsType; //type of goods food, furniture, petroleum, chemicals, etc.
protected:
	ostream& print(ostream& out) const;
public:
	Delivery();
	Delivery(float goodsWeight, char* goodsType, char* source, char* destination, float distance, bool status, float fuelrate, int cId, int dId, int vId, int hour, int min, int sec, int day, int month, int year);
	Delivery(const Delivery& d);
	~Delivery();
	float getgoodsWeight();
	void setgoodsWeight(float goodsWeight);
	char* getgoodsType();
	void setgoodsType(char* goodsType);
	friend ostream& operator<< (ostream& out, const Delivery& d);
	//you can add more members here if required
	//add member functions
};

class Person {
private:
	Name pName;
	Date DOB;
	int Age;
	int Nid;
public:
	Person();
	Person(int age, int Nid, char* fN, char* lN, int day, int month, int year);
	Person(const Person& obj);
	~Person();
	int getAge();
	void setAge(int age);
	int getNid();
	void setNid(int nid);
	friend ostream& operator<< (ostream& out, const Person& p);
	//add following functions in this class //Getter, Setters
	//Destructor
};

class Customer : public Person {
private:
	int cId;
	// Unique and assigned first time when customer makes first service request
	Service** bookingHistory;
	//Maintain and Update history of customer for each service (ride or goods transportation order) by adding address of service in dynamic array.
	//you can add more members here if required
public:
	Customer();
	Customer(int cId, int age, int Nid, char* fN, char* lN, int day, int month, int year);
	Customer(const Customer& c);
	~Customer();
	int getcId();
	void setcId(int cid);
	void setRide(int passengernum, char* type, float DRank, float VRank, char* source, char* destination, float distance, bool status, float fuelrate, int cId, int dId, int vId, int hour, int min, int sec, int day, int month, int year);
	void setDelivery(float goodsWeight, char* goodsType, char* source, char* destination, float distance, bool status, float fuelrate, int cId, int dId, int vId, int hour, int min, int sec, int day, int month, int year);
	bool checkcustomeravailablity(int cid);
	friend ostream& operator<< (ostream& out, const Customer& c);
	//add following functions in this class //Getter, Setters
};

class Driver : public Person {
private:
	int dId;
	char** LicencesList;
	int noofLicences;
	float overallRanking;
	float salary;
	int experience;
	int status; // 1 for free, 2 if booked and 3 if canceled
	Service** serviceHistory;
	//Add services address in the array for tracking complete information of service.
public:
	Driver();
	Driver(int dId, char** LicencesList, int noofLicences, float overallRanking, float salary, int experience, int status, int age, int Nid, char* fN, char* lN, int day, int month, int year);
	Driver(const Driver& d);
	~Driver();
	int getdId();
	void setdId(int cid);
	int getnoofLicences();
	void setnoofLicences(int Lno);
	char** getLicencesList();
	void setLicencesList(char** LL);
	float getoverallRanking();
	void setoverallRanking(float rank);
	float getsalary();
	void setsalary(float salary);
	int getexperience();
	void setexperience(int exp);
	int getstatus();
	void setstatus(int status);
	void setRide(int passengernum, char* type, float DRank, float VRank, char* source, char* destination, float distance, bool status, float fuelrate, int cId, int dId, int vId, int hour, int min, int sec, int day, int month, int year);
	void setDelivery(float goodsWeight, char* goodsType, char* source, char* destination, float distance, bool status, float fuelrate, int cId, int dId, int vId, int hour, int min, int sec, int day, int month, int year);
	bool checkdriveravailablity(int did);
	void printMultipleLicenses(int did);
	void printTopDrivers(int did);
	friend ostream& operator<< (ostream& out, const Driver& d);
	//add following functions in this class
	//Getter, Setters
	//Destructor, Default and Parameterized Constructor, Copy Constructor, Output operator (prints complete information of Driver)
};

class Feature {
private:
	int fId;
	char* description;
	float cost;
	//you can add more members here if required
	//add member functions
public:
	Feature();
	Feature(int id, char* desc, float price);
	Feature(const Feature& f);
	~Feature();
	void setFID(int fId);
	int getFID();
	void setDescription(char* description);
	char* getDescription();
	void setCost(float cost);
	float getCost();
	friend ostream& operator<< (ostream& out, const Feature& f);
};

class Vehicle {
private:
	int vId;
	int registrationNo;
	float avgMileage;
	char* LicenceType; // License required for driving the vehicle
	bool status; // false for free, true if booked in a service already
	char* fueltype;
	float overallRanking;
	Date manufacturingDate;
	Feature* list;
	Service** serviceHistory;

	//Add services address in the array for tracking complete information of service.
	//you can add more members here if required
	//add member functions
public:
	Vehicle();
	Vehicle(int day, int month, int year, int fid, char* desc, float price, int vid, int reg, float mileage, char* Ltype, bool stat, char* ftype, float rank);
	Vehicle(const Vehicle& v);
	~Vehicle();
	void setVID(int vId);
	int getVID();
	void setRegNo(int registrationNo);
	int getRegNo();
	void setMileage(float avgMileage);
	float getMileage();
	void setLicenseType(char* LicenseType);
	char* getLicenseType();
	void setStatus(bool status);
	bool getStatus();
	void setFuelType(char* fueltype);
	char* getFuelType();
	void setRanking(float overallRanking);
	float getRanking();
	void setRide(int passengernum, char* type, float DRank, float VRank, char* source, char* destination, float distance, bool status, float fuelrate, int cId, int dId, int vId, int hour, int min, int sec, int day, int month, int year);
	void setDelivery(float goodsWeight, char* goodsType, char* source, char* destination, float distance, bool status, float fuelrate, int cId, int dId, int vId, int hour, int min, int sec, int day, int month, int year);
	bool checkvehicleavailablity(int vid);
	friend ostream& operator<< (ostream& out, const Vehicle& v);
};
