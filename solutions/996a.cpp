#include <iostream>
using namespace std;

int main() 
{
    long denoms[] = {100, 20, 10, 5, 1};
    long totalCash, totalBills = 0;
    long numBills;

    cin >> totalCash;
    
    for (int i = 0; i < 5; ++i)
    {
            numBills = totalCash / denoms[i];
            totalBills += numBills;
            if (totalCash % denoms[i] == 0)
            {
                break;
           }
            totalCash -= numBills * denoms[i];
    }
    
    cout << totalBills << endl;
    
    return 0;
}
