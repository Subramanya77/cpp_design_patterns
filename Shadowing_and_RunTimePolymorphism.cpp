// shadowing and run time polymorphism

class Vehicle {                         //base class
    private:
        string regNumber;
        string name;
};

class Car : public Vehicle {

};

class Truck : public Vehicle {

};

class VehicleSimulator {
    Vehicle *v;

    public:
        VehicleSimulator(Vehicle* vArg) : v{vArg} {}
        void start() {       //here addr of car and truck can be passed. Since we know base class obj can store 
                                        //the addr of derived class
            v->start();
        }
        void stop() {
            v->stop();
        }
        void drive() {
            v->drive();
        }
};

//from vehicle si,ulator POV, it can select car/truck at run time, so it is run time poly so it is strtegy pattern.
// drive() is different for car and truck, it is template method pattern.

int main() {
    Car vehicle;
    VehicleSimulator simulator (&vehicle);
    simulator.start();
    simulator.drive();
    simulator.stop();
}

// --------------------------------------------------------
// since start and stop is same for all vehicle
class Vehicle {                         //base class
    private:
        string regNumber;
        string name;
    public:
    void start() {
            cout << "key start" << endl;
        }
    void stop() {
            cout << "key stop" << endl;
        }
    virtual void drive() = 0;               //non implemented in vehicle class, it should be handled in sub classes car and truck.

};

class Car : public Vehicle {
    public:
        void drive() {
            cout << "car drive" << endl;
        }
};

class Truck : public Vehicle {
    public:
        void drive() {
            cout << "truck drive" << endl;
        }
};

class VehicleSimulator {
    Vehicle *v;

    public:
        VehicleSimulator(Vehicle* vArg) : v{vArg} {}
        void start() {       //here addr of car and truck can be passed. Since we know base class obj can store 
                                        //the addr of derived class
            v->start();
        }
        void stop() {
            v->stop();
        }
        void drive() {
            v->drive();
        }
};

int main() {
    Car vehicle;
    Truck vehicle;
    VehicleSimulator simulator (&vehicle);
    simulator.start();
    simulator.drive();
    simulator.stop();
}
