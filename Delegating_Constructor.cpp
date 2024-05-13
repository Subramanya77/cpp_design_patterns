// Delegation Constructors:
class A{
    private:
    int x;
    float y;                    
    string z;

    public:
    A(int xArg){
        this->x=xArg;       
    }
    A(int xArg, float yArg) :A {xArg}{                          //calling A constuctor instead of repeating x
        this->y=yArg;
    }
    A(int xArg, float yArg, string zArg) :A {xArg, yArg}{       //calling A constuctor instead of repeating x & y
        this->z=zArg;
    }
}
