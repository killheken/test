#include <iostream>
#include <string.h>
#include <sstream>
using namespace std;
struct tokenstring{
        string type = "";
        int value;
    };
string yes = "TA is handsome.";
void pro(struct tokenstring[] , int start , int peeknumber);
void ass(struct tokenstring[] , int start , int peeknumer);
void inum(struct tokenstring[] , int start , int peeknumer);

int main()
{
    char a[50];
    while(cin.getline(a , 50))
    {
    yes = "TA is handsome.";
    struct tokenstring answer[50];

    string token="" ;
    int i = 0 , start = 0;
    //cin.getline(a , 50);
    //cout << a;
    while (i < strlen(a))
    {
        token = "";
        if (a[i] == ' ')
        {
            i++;
        }
        else
        {
            if ((a[i] <= '9' and a[i] >= '0')or a[i] == '-')
            {

                token = "inum";
                i++;
                while ((a[i] <= '9') and (a[i] >= '0') and (i < strlen(a)))
                {
                    i++;

                }
                if((a[i] <= 'z' and a[i]>= 'a')or (a[i] <= 'Z' and a[i] >= 'A'))
                    {
                        yes = "Token mismatch.";
                        break;
                    }
                answer[start].type = token;
                start++;
                //cout << answer;
            }
            else if((a[i] <= 'z' and a[i]>= 'a')or (a[i] <= 'Z' and a[i] >= 'A'))
            {
                token = "id";
                i++;
                while((a[i] <= 'z' and a[i]>= 'a')or (a[i] <= 'Z' and a[i] >= 'A'))
                {
                    i++;
                }
                if ((a[i] <= '9' and a[i] >= '0')or a[i] == '-')
                    {
                        yes = "Token mismatch.";
                        break;
                    }
                answer[start].type = token;
                start++;
                //i++;
            }
            else if(a[i] == '=')
            {
                token = "assign";
                answer[start].type= token ;
                start ++;
                i++;
            }
            else{
                yes = "Token mismatch.";
                break;
            }
        }

    }
    if(yes != "Token mismatch.")
    {
        pro(answer ,start , 0);
    }
    cout << yes << endl;

    //cout << answer;
    }
}
void pro(struct tokenstring a[] , int start , int peeknumber)
{
    if(peeknumber == start)
    {
        cout << "end";
    }
    else if (a[peeknumber].type == "id")
    {

        ass(a,start,peeknumber+1);
        pro(a,start , peeknumber+2);
    }
    else if (a[peeknumber].type == "inum")
    {
        inum(a ,start , peeknumber);
    }
    else{
        yes = "Grammar mismatch.";
    }
}
void ass(struct tokenstring a[] , int start , int peeknumber)
{
    if(a[peeknumber].type == "assign")
    {

    }
    else{
        yes = "Grammar mismatch.";
    }
}
void inum(struct tokenstring a[] , int start , int peeknumber)
{
    if(a[peeknumber].type == "inum")
    {
        if (a[peeknumber+1].type != "")
        {
            yes = "Grammar mismatch.";
        }
    }
    else{
        yes = "Grammar mismatch.";
    }
}
