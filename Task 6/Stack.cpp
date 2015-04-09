#include <vector>
#include <iostream>

using namespace std;

class vecStack{
    private:
        vector<int> data;
    public:
        void push(int d){
            data.push_back(d);
        };
        bool empty(){
            return data.empty();
        };
        int pop(){
            if (!data.empty()){
                int ret = data.back();
                data.pop_back();
                return ret;
            }else{
                return 0;
                // should raise exception
            }
        };
        void debug(){
            cout << "Print Debug information";
            for (vector<int>::iterator ic=data.begin(); ic != data.end();++ic){
                cout << *ic << " ";
            }
            cout << endl;
        }
};

int main(){
    vecStack v;
    v.push(4);
    v.push(5);
    v.push(6);
    v.debug();
    cout << v.pop();
    cout << v.pop();
    cout << v.pop();
    return 0;
}
