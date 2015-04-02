#include <string>
#include <iostream>
#include <map>
#include <sstream>

using namespace std;

class Storage{
    map<string, int> repo;
    public:
        void reduce(string name, int number){
            
        };
        void add(string name, int number){
            if (!repo[name]){
                repo[name] = number;
            }
        };
        void print(){
            for(map<string, int>::iterator ic=repo.begin(); ic != repo.end(); ++ic){
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

int main(){
    // the hello world
    sayHello();
    Storage store;
    store.add("Test", 4);
    store.print();
    cout << store.serialize();
    // check if there is a data file and load it
    return 0;
}

