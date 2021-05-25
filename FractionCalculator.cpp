#include "FractionCalculator.h"

FractionCalculator::FractionCalculator() //Default Consstractor
{
}

void FractionCalculator::Calculator()
{
    int c, counter = 0;
    Fraction f1, f2, f3;
    do {
        cout << "Welcome to FCI Calculator " << endl;
        cout << "----------------------------------------" << endl;
        cout << "1-Perform Fraction Addition\n" 
             << "2-Perform Fraction Subtraction\n" 
             << "3-Perform Fraction Multiplication\n"
             << "4-Perform Fraction Division\n"
             << "5-Exit" << endl;
        counter++;
        cin >> c;
        if (c != 5) 
        {
            if (counter == 1)
            {
                cin >> f1;
                f3 = f1;
                cin >> f2;

            }
            else
            {
                cin >> f2;
            }
        }
        
        
        switch(c)
        {
        case 1:
        {
            f3 = f3 + f2;
            cout << f3 << endl;
            break;
        }
        case 2:
        {
            f3 = f3 - f2;
            cout << f3 << endl;
            break;
        }
        case 3:
        {
            f3 = f3 * f2;
            cout << f3 << endl;
            break;
        }
        case 4:
        {
            f3 = f3 / f2;
            cout << f3 << endl;
            break;
        }
        case 5:
        {
            break;
        }
        default: cout << "Invalid input \n";
        };
    } while (c != 5);
}
