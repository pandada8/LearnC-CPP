#include <string>
#include <iostream>
#include <map>
#include <sstream>
#include <fstream>

using namespace std;

class Storage{
    map<string, int> repo;
    public:
        void reduce(string name, int number){
            if(exist(name) && number <= repo[name]){
                repo[name] -= number;
            }
        };
        inline bool exist(string name){
            return repo.count(name) == 1;
        }
        int getAvaiable(string name){
            if (exist(name)){
                return repo[name];
            }else{
                return 0;
                // TODO: Raise a Exception here,
            }
        }
        void add(string name, int number){
            if ( exist(name) ){
                repo[name] = number;
            }else{
                repo[name] += number;
            }
        };
        void print(){
            if(repo.empty()){
                cout << "No Avaliable :/" << endl;
                return;
            }
            for(map<string, int>::iterator ic=repo.begin(); ic != repo.end(); ++ic){
                // TODO: Using getAvaliable rather than operate the raw data
                cout << "Brand: " << ic -> first << "\t Avaliable: " << ic -> second << endl;
            }
        };
        string serialize(){
            ostringstream out;
            for(map<string, int>::iterator it=repo.begin(); it!= repo.end(); ++it){
                out << it -> first << "\t" << it -> second << "\n";
            }
            return out.str();
        };
        void load(void){
            ifstream ifile ("data.dat");
            if (ifile.is_open()){
                string brand;
                int number;
                while (ifile >> brand >> number){
                    add(brand, number);
                }
                cout << "Loading data from file..." << endl << repo.size() <<" loaded" << endl;
            }else{
                cout << "Not found the data file, init a empty database." << endl;
            }
            ifile.close();
        }
        void save(void){
            ofstream ofile ("data.dat");
            if (ofile.is_open()){
                ofile << serialize();
                cout << "Data dumped" << endl;
                ofile.close();
            }else{
                cerr << "Oops, we can't open the file..." << endl << "Saving failed...." << endl;
            }
        }
};

void sayHello(){
    cout << "   _____ _             _    \n";
    cout << "  / ____| |           | |   \n";
    cout << " | (___ | |_ __ _  ___| | __\n";
    cout << "  \\___ \\| __/ _` |/ __| |/ /\n";
    cout << "  ____) | || (_| | (__|   < \n";
    cout << " |_____/ \\__\\__,_|\\___|_|\\_\\\n";
    cout << "\n";
}

void showHelp(){
    cout << "Usage:" << endl;
    cout << "  help   : to get this help message" << endl;
    cout << "  show   : print all goods in the repo" << endl;
    cout << "  add    : add goods quantity" << endl;
    cout << "  reduce : reduce goods quantity" << endl;
    cout << "  exit   : exit" << endl;
    cout << "  You can use ^D (Control + D) to exit too" << endl;
}

int main(){
    // the hello world
    sayHello();
    Storage store;
    
    store.load();
    // Starting the main loop
    cout << "input help to get help info...." << endl;
    cout << "Your must save before quiting or the data will lost!" << endl;

    string action;
    while (cout << "> ",cin >> action){
        // produce a friendly prompt
        if (action == "help"){
            showHelp();
        }else if (action == "exit"){
            return 0;
        }else if (action == "save"){
            store.save();
        }else if (action == "show"){
            store.print();
        }else if (action == "add"){
            string name;
            int number;
            cout << "(+) Input the name:";
            cin >> name;
            cout << "(+) Input the number:";
            cin >> number;
            store.add(name, number);
        }else if (action == "reduce"){
            string name;
            int number;
            cout << "(-) Input the name:";
            cin >> name;
            cout << "(-) Input the number:";
            cin >> number;
            store.reduce(name, number);
        }
    }
    cout << "Goodbye" << endl;
    
    // check if there is a data file and load it
    return 0;
}

