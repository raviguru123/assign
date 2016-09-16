#include<iostream>
using namespace std;

bool isEven(int number){
    return (number&1)==0;
}

int generateSeries(int number){
    return (isEven(number)==true?number/2:3*number+1);
}

int main(){
    cout<<"please enter the number=>";
    int number,count=0;
    cin>>number;
    cout<<number;

    do{
        count++;
        number=generateSeries(number);
        cout<<"->"<<number;
    }while(number!=1&&count<1000000);

    string str=number==1?"Not Collatz Problem":"Collatz Problem";
    cout<<endl;
    cout<<str;
return 0;
}

