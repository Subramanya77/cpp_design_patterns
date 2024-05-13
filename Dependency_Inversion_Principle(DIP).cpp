// DIP - Dependency Inversion Principle. DIP is a Strategy Design Pattern
// code/object is losely coupled -> 1 obj doen't know anything about other object other than the Interfaces.
//Car used Engine -> Car depends on Engine. (has-a relation has dependency).

//abstraction
class IEngine {
    public:
        virtual void start() = 0;
        virtual void stop() = 0;
};

//low level module
class MPFIEngine : public IEngine{
    void start(){
    }
    void stop(){
    }
};
class GDIEngine : public IEngine{
    void start(){
    }
    void stop(){
    }
};
class StallinEngine {

};

//high level module
class XUV3X0 {
    //MPFIEngine engine;    //tightly coupled. If for the same car class, if new engine class needed this is not possible.
                            // here high level module is depended on low level module. Not correct. 
                            // need to move from tightly coupled to losely coupled using abstraction.
    IEngine* engine;        // using abstraction (dependency)
                            //XUV3X0 depends on IEngine
    public:
        //constructor Dependency Injection - Dependancy is must and it is not changed until last. Here XUV is dependent on Engine
        XUV3X0(IEngine* engineArg) : engine {enginrArg} {}
        void drive(){
            this->engine->start();
        }
        void halt(){
            this->engine->stop();
        }
        ~XUV3X0(){
            delete engine;
        }
};

int main() {
    MPFIEngine napEngine;
    GDIEngine turboEngine;
    XUV3X0 car{&napEngine};
    car.drive();
    XUV3X0 car{&turboEngine};   //pointer can point into nap or turbo engine. And pointer will get the address in runtime. 
                                //So it is called Run time Polymorphism
    car.drive();
    return 0;
}
