#include <iostream>
#include <string.h>
using namespace std;
typedef struct tokenstring test;
void stmt(test token[], int start);
void exp(test token[] , int start);
void primary(test token[] , int start);
void primarytail(test token[] , int start);
void semicolon(test token[] , int start);
struct tokenstring{
    string type = "";
    string value = "";
};
int where = 0;
string answer = "";
bool correct = true;
int main()
{
    string a;

    while(cin >> a)
    {
        answer = "";
        correct = true;
        string valid = "true";
        where = 0;
        test token[50];
        int i = 0 , j = 0;
        while( i < a.length())
        {

            if((a[i]<= 'z' and a[i] >= 'a') or (a[i] <='Z' and a[i]>= 'A'))
            {
                token[j].type = "ID";
                token[j].value = a[i];
                i++;
                while((a[i]<= 'z' and a[i] >= 'a') or (a[i] <='Z' and a[i]>= 'A') or (a[i]<= '9' and a[i] >= '0') or (a[i] == '_'))
                {
                    token[j].value += a[i];
                    i++;
                }
                j++;
            }
            else if(a[i] == '"')
            {
                token[j].type = "STRLIT";
                i++;
                while(a[i]!= '"' and i < a.length())
                {
                    token[j].value += a[i];
                    i++;
                }
                i++;
                j++;
            }
            else if(a[i] == '(')
            {
                token[j].type = "LBR";
                token[j].value = a[i];
                j++;
                i++;
            }
            else if(a[i] == ')')
            {
                token[j].type = "RBR";
                token[j].value = a[i];
                j++;
                i++;
            }
            else if(a[i] == '.')
            {
                token[j].type ="DOT";
                token[j].value = a[i];
                j++;
                i++;
            }
            else if (a[i] == ';')
            {

                token[j].type = "SEMICOLON";
                token[j].value = a[i];
                j++;
                i++;
            }
            else if(a[i] == ' '){

                i++;
            }
            else{
                token[j].type = "invalid";
                valid = "invalid input";
                break;
            }

        }

        if(valid != "invalid input")
        {
            stmt(token , 0);
            if(correct == true)
            {
                cout << answer;
            }
            else{
                cout << "invalid input" << endl;
            }
        }
        else{
            cout << "invalid input" << endl;
        }
        //cout<< valid;
    }
    return 0;
}
void stmt(test token[], int start)
{
   exp(token , where);
   semicolon(token, where);
}
void exp(test token[] , int start)
{
     if(token[where].type == "STRLIT")
    {
        answer = answer+ "STRLIT" + ' ' + '"' +token[where].value + '"'+'\n';
        where++;
    }
    else if(token[where].type == "ID")
    {
        primary(token , start);
    }
    else if(token[where].type == "SEMICOLON" and token[where+1].type == "" )
    {

    }
    else if(token[where].type == "RBR")
    {

    }
    else{
        correct = false;
    }
}
void primary(test token[] , int start)
{
    answer = answer + "ID" + ' ' + token[where].value + '\n';
    where++;
    primarytail(token , start);
}
void primarytail(test token[] , int start)
{
    if(token[where].type == "DOT")
    {
        answer = answer+ "DOT" + ' ' + token[where].value + '\n';
        where++;
        if(token[where].type == "ID")
        {
            answer = answer + "ID" + ' ' + token[where].value + '\n';
            where++;
            primarytail(token , start);
        }
        else{
            correct = false;
        }
    }
    else if (token[where].type == "LBR")
    {
        answer = answer + "LBR" + ' ' + token[where].value + '\n';
        where++;
        exp(token , start);
        if(token[where].type == "RBR")
        {
            answer = answer + "RBR" + ' ' + token[where].value + '\n';
            where++;
        }
        primarytail(token , start);
    }
    else if (token[where].type == "SEMICOLON" and token[where+1].type == "")
    {

    }
    else{
        correct = false;
    }
}
void semicolon(test token[] , int start)
{
    if (token[where].type == "SEMICOLON")
    {
        answer = answer + "SEMICOLON" + ' ' + token[where].value + '\n';

    }
    else{
        correct = false;
    }
}
