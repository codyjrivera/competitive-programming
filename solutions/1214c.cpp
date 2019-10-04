// Codeforces 1214c -- Cody Rivera


#include <iostream>


using namespace std;


int main(int argc, char** argv)
{
    long sLength;

    cin >> sLength;

    // Impossible to have odd balanced paren array
    if (sLength % 2 == 1)
    {
        cout << "No" << endl;
        return 0;
    }
    
    char A[sLength];

    for (int i = 0; i < sLength; ++i)
    {
        cin >> A[i];
    }


    long lCount = 0, rCount = 0;
    long dif;
    for (int i = 0; i < sLength; ++i)
    {
        if (A[i] == '(')
        {
            lCount++;
        }
        else
        {
            rCount++;
        }

        dif = lCount - rCount;
        // If the dif ever gets to less than -1, needs at least
        // 2 swaps to correct if correctible
        if (dif < -1)
        {
            cout << "No" << endl;
            return 0;
        }
    }

    // If there are an unequal amount of left and right parens
    if (lCount != rCount)
    {
        cout << "No" << endl;
    }
    else
    {
        cout << "Yes" << endl;
    }
    
}
