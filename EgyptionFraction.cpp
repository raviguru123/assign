#include <iostream>
using namespace std;

void generateEgyptianSeries(int numerator, int denominator)
{
    if (denominator== 0||numerator==0)
        return;
    if (denominator%numerator==0)
    {
        cout<<"1/"<< denominator/numerator;
        return;
    }

    if (numerator%denominator==0)
    {
        cout <<numerator/denominator;
        return;
    }
    if (numerator>denominator)
    {
        cout << numerator/denominator<<"+";
        generateEgyptianSeries(numerator%denominator,denominator);
        return;
    }

    int number=denominator/numerator+1;
    cout << "1/"<<number << "+";
    generateEgyptianSeries(numerator*number-denominator,denominator*number);
 }
int main()
{
    int numerator,denominator;
    cout<<"Please Enter Numerator=";
    cin>>numerator;
    cout<<"Please Enter Denominator=";
    cin>>denominator;
    cout << "Egyptian Fraction is=>"<<endl;
    generateEgyptianSeries(numerator, denominator);
    return 0;
}

