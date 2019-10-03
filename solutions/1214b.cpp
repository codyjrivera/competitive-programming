#include <iostream>

using namespace std;


int main()
{
    int b, g, n;

    cin >> b >> g >> n;


    if (n > b && n > g)
    {
        cout << b + g + 1 - n << endl;
    }
    else
    {
        int max;
        if (n > g)
        {
            if (n > b)
            {
                max = n;
            }
            else
            {
                max = b;
            }
        }
        else
        {
            if (g > b)
            {
                max = g;
            }
            else
            {
                max = b;
            }
        }

        cout << max + 1 << endl;
    }
}
