#include <iostream>
#include <cstring>
using namespace std;
int main ()
{
    int i = 0;
    int j = 0;
    int k = 0;

    char arr[2][3];
    char arrayChuoi[9];
    for (i = 0; i < 8; ++i)
    {
        cin >> arrayChuoi[i];
        if (arrayChuoi[i] != ';')
        {
            arr[j][k] = arrayChuoi[i];
            k++;
        }
        else
        {
            j++;
            k = 0;
        }
    }



    j = 0;
    i = 0;
    k = 0;
    for (i = 0; i < 2; ++i)
    {
        for (j = 0; j < 3; ++j)
        {
        	cout << arr[i][j];
        }
        cout << endl;
    }
    return 0;
}
