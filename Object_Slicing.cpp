/*Abstraction: giving different views of an object (ex. Our behaviors with diff persons)
	- Has a relation.
	- When one obj uses other obj, it should know the essential behaviors.
	- Build from end user point of view. Ex: car, upi simple steps and complex steps hidden which is not necessary.

Object Slicing: essential behaviors that particular context demands by hiding the remaining behaviors

Base class pointer can store address of derived class obj but it is not allowed to access all the members of a derived class but only members of base class objects.
*/

// OBJECT SLICING
class IEmployee {
    public:                          //c++ doesn't have a interface, we need to synthesise so we use "virtual"
        virtual void professional() = 0;     //virtual -> class that contains pure virtual() (method whose body = 0) is called Interface
};
class IFamilyMember {
    public:                          //c++ doesn't have a interface, we need to synthesise so we use "virtual"
        virtual void casual() = 0;     //virtual -> class that contains pure virtual() (method whose body = 0) is called Interface
        virtual void cranky() = 0;
};

// Person agress / fulfils the contracts(implements)
class Person : public IEmployee, IFamilyMember {
    public:
        void casualBehavior(){      //In a class, if members are declared in public, these are default interface of that class
        }
        void professional(){
        }
        void cranky(){
        }
};

class OfficeContext {               // so here casual and cranky will be "fat behavior"
    public:
        void Enter(IEmployee* obj){     //Person has entered office context, so casual and cranky behaviors must be hidden.
            //obj->casualBehavior();    // Person* obj = contract knows the address of the person obj but has all behaviors, so use IEmployee* obj
            obj->professional(); 
            //obj->cranky();                   
        }
};
                                    
class homeContext {                 // so here professional and cranky will be "fat behavior"
    public:
        void Enter(Person* obj){     //Person has entered office context, so professional and cranky behaviors must be hidden.
            obj->casualBehavior();
            obj->cranky();             
        }
};
// so obj of officecontext/homecontext and person obj needs "contract"
// The "contracts" are termed as "INTERFACES" 
// Every view is a base class. So need 2 context here, 2 view and so 2 base class needed.
// So (I=object) IEmployee and IFamily is created. And its behavior is added as a method

int main(){
    Person tom;
    homeContext fContext;
    OfficeContext oContext;
    fContext.Enter(obj:&tom);
    oContext.Enter(obj:&tom);

    Person harry;
    fContext.Enter(obj:&harry);
    oContext.Enter(obj:&harry);
    return 0;
}
