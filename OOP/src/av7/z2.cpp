#include <iostream>
using namespace std;
class Vehicle {
public:
	Vehicle() {
		cout << "Vehicle Constructor" << endl;
	}
	virtual ~Vehicle() {
		cout << "Vehicle Destructor" << endl;
	}
	virtual void accelerate() {
		cout << "Vehicle Accelerating" << endl;
	}
	void setAcceleration(double a) {
		acceleration = a;
	}
	double getAcceleration() {
		return acceleration;
	}
protected:
	double acceleration;
};
class Car: public Vehicle {
public:
	Car() {
		cout << "Car Constructor" << endl;
	}
	virtual ~Car() {
		cout << "Car Destructor" << endl;
	}
	virtual void accelerate() {
		cout << "Car Accelerating" << endl;
	}
	virtual void drive() {
		cout << "Car Driving" << endl;
	}
};
class Jet: public Vehicle {
public:
	Jet() {
		cout << "Jet Constructor" << endl;
	}
	virtual ~Jet() {
		cout << "Jet Destructor" << endl;
	}
	virtual void fly() const {
		cout << "Jet flying" << endl;
	}
};
class JetCar: public Car, public Jet {
public:
	JetCar() {
		cout << "JetCar Constructor" << endl;
	}
	virtual ~JetCar() {
		cout << "JetCar Destructor" << endl;
	}
	virtual void drive() {
		cout << "JetCar driving" << endl;
	}
	virtual void fly() {
		cout << "JetCar flying" << endl;
	}
};
void analyzeCarPerformance(Car *testVehicle) {
	testVehicle->drive();
	//drive() exists for both base and sub class
}
void analyzeJetPerformance(Jet *testVehicle) {
	testVehicle->fly();
	//fly() exists for both base and sub class
}
int main() {
	Car myCar;
	Jet myJet;
	JetCar myJetCar;
	cout << endl << endl;
	cout << "Car testing in progress" << endl;
	analyzeCarPerformance(&myCar);
	analyzeCarPerformance(&myJetCar);
	cout << "Jet testing in progress" << endl;
	analyzeJetPerformance(&myJet);
	analyzeJetPerformance(&myJetCar);
	cout << endl << endl;
	return 0;
}
