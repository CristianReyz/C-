#include <iostream>
using namespace std;
int n;

int factorial(int n){
	if(n == 0){
		return 1;
	}
	else{
		return (n*factorial(n-1));
	}	
}

int main(){
	cout<<"ingresa numero"<<endl; cin>>n;
	cout<<"el factorial es: "<<factorial(n)<<endl;
	
}

