#include <iostream>


using namespace std;




int main()
{
    long nIters, st, in, ex, count;

    cin >> nIters;

    for (int i = 0; i < nIters; ++i)
    {
        cin >> st >> in >> ex;

        /*
          st + ec > in + (ex - ec)
          2ec > in - st + ex
          ec >  (in - st + ex) / 2
             >= ((in - st + ex) / 2) + 1
          
        */

        count = 0;
        if (st - in > ex)
        {
            count = ex;
        }
        else if (count == 0)
        {
            if (st > in) count = 1;
        }
        else
        {
            st = st + ex;
            while (st > in)
            {
                ++count;
                --st;
                ++in;
            }
        }
        
        cout << count;
    }
}
