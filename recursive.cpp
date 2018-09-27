#include <iostream>
#include <string.h>
#include <sstream>
using namespace std;
int main()
{

    char a[50];
    string token="" , answer;
    int i = 0;
    cin.getline(a , 50);
    //cout << a;

    while (i < strlen(a))
    {
        //cout << i;
        if (a[i] == ' ')
        {
            i++;
        }
        else
        {
            if (a[i] <= '9' and a[i] >= '0')
            {

                token += a[i];
                i++;
                while ((a[i] <= '9') and (a[i] >= '0') and (i < strlen(a)))
                {
                    token += a[i];
                    i++;
                    cout << 't';
                }
                answer = answer + token + ' ';
                //cout << answer;
            }
            else
            {
                cout << "test";
                switch (a[i])
                {
                case 'i':
                    answer = answer + "interger ";
                }
                //i++;
            }
        }

    }

    //cout << answer;
}
