#include <iostream>
#include <string>
using namespace std;

class Device {
    private:
        string name;
        string model;
        string version;
    protected:
        Device(string nameArg, string modelArg, string versionArg) : name{nameArg}, model{modelArg}, version{versionArg} {
            cout << "Device Instantiated" << endl;
        }
        ~Device(){
            cout << "Device Destructed" << endl;
        }
};
class Printer : virtual public Device {
    public:
        Printer():Device("","",""){
            cout << "Printer Instantiated" << endl;
        }
        ~Printer(){
            cout << "Printer Destructed" << endl;
        }
        void print( string content ) {
            cout << "Print" << content << endl;
        };
};
class Scanner : virtual public Device {
    public:
        Scanner():Device("","",""){
            cout << "Scanner Instantiated" << endl;
        }
        ~Scanner(){
            cout << "Scanner Destructed" << endl;
        }
        void scan( string content ) {
            cout << "Scan" << content << endl;
        };
};

class PrintScanner : public Printer, public Scanner {           //This is MULTIPLE INHERITENCE. In c++ DON'T USE MULTIPLE INHERITENCE
        Printer printerObj;
        Scanner scannerObj;
    public:
        void print(string content) {
            this->printerObj.print(content);        //delegating calls to its nieghbours
        }
        void scan(string content) {                 //delegating calls to its nieghbours
            this->scannerObj.scan(content);
        }
        PrintScanner(string n, string m, string v) : Device {n, m, v}{  //Diamond problem, so PS is calling Device directly
            cout << "PrintScanner Instantiated" << endl;
        }
        ~PrintScanner(){
            cout << "PrintScanner Destructed" << endl;
        }
};

class TaskManager {                                                             //Printer and Scanner is a Neighbour of TaskMangaer
    public:                                                                    
        void invokePrintTask(Printer* printerPtr, string content ) {
            printerPtr->print(content);
        };
         void invokeScanTask(Scanner* scannerPtr, string content ) {
            scannerPtr->scan(content);
        };
};

int main(){
    // Printer hpPrinter;
    // Scanner hpScanner;
    PrintScanner hpPrintScanner ("", "", "");
    TaskManager taskMgr;
    // taskMgr.invokePrintTask(prinerPtr:&hpPrinter, content:"doc.pdf";);
    // taskMgr.invokeScanTask(scannerPtr:&hpScanner, content:"doc.pdf";);
    taskMgr.invokePrintTask(&hpPrintScanner, "doc.pdf");
    taskMgr.invokeScanTask(&hpPrintScanner, "doc.pdf");
}

/*
  output:
Device Instantiated
Printer Instantiated
Scanner Instantiated
Device Instantiated
Printer Instantiated
Device Instantiated
Scanner Instantiated
PrintScanner Instantiated
Printdoc.pdf
Scandoc.pdf
PrintScanner Destructed
Scanner Destructed
Device Destructed
Printer Destructed
Device Destructed
Scanner Destructed
Printer Destructed
Device Destructed
*/
