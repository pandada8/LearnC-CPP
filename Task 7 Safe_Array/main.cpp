#include "safe_array.h"
#include <iostream>
using namespace std;

int main(){
	Array array(100);
	array[10] = 10;
    if (10 == array[10]){
		cout << "Normal Value:" << array[10];
	}else{
		cout << "Error: " << array[10];
	}
}
