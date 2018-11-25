#include <iostream>
#include <string>
#include <ctype.h>
#include <map>
#include <sstream>
#include <algorithm>

using namespace std;
string first(char);
struct test{
    char nont;
    string rhs;
}context[50];
map<char, string> m;
map<char, string> fin;
map<char, bool>nullable;
int main()
{
    string a;
    int j = 0;
    while(getline(cin , a))
    {

        for(int i = 0; i < a.size(); i++)
        {
            if(isupper(a[i])&&i==0)
            {
                context[j].nont = a[i];
                nullable[context[j].nont] = false;
            }
            else if(a[i] != ' '){
                context[j].rhs+=a[i];
                if(a[i] == ';')
                {
                    nullable[context[j].nont] = true;
                }
            }

        }
        //m[context[j].nont] += context[j].rhs;
        j++;
    }

    for(int i = 0 ; i< j; i++)
    {
        first(context[i].nont);
        string output , result;
        result = m[context[i].nont];
        bool *ptr = new bool[result.size()];
        for(int x = 0 ; x < result.size() ; x++)
        {
            *(ptr+x) = true;
        }
        for(int a= 0 ; a < result.size()-1; a++)
        {
            for(int b = a+1 ; b < result.size(); b++)
            {
                if(result[a] == result[b])
                {
                    *(ptr+b) = false;
                }
            }
        }
        for(int a= 0 ; a < result.size() ; a++)
        {
            if(*(ptr+a))
            {
                output+=result[a];
            }
        }
        //cout << context[i].nont <<": "<<output<<endl;
        sort(output.begin(), output.end());
        fin[context[i].nont] = output;
        map<char,string>::iterator it;
        for(it=m.begin();it!=m.end();it++)
            (*it).second = "";
    }
    map<char,string>::iterator it;
        for(it=fin.begin();it!=fin.end();it++)
            cout << (*it).first << " " << (*it).second << '\n';
    return 0;
}

string first(char target)
{
    for(int i =0; i< 50 ; i++)
    {
        if(target == context[i].nont)
        {
            for(int x =0; x < context[i].rhs.size() ; x++)
            {
                string result = first(context[i].rhs[x]);
                string temp = result;



                //cout << temp << endl;

                bool flag = false;
                for(int y = 0 ; y < result.size() ; y++)
                {
                    if(result[y]==';')
                    {
                        flag = true;
                    }
                }
                if(x != context[i].rhs.size()-1)
                {
                    for(int k = 0 ; k < temp.size() ; k++)
                    {
                        int position = temp.find(';');
                        if(position < temp.size())
                        {

                            temp.erase(position, 1);
                        }
                    }


                }
                m[target]+=temp;
                if(flag == false)
                {
                    break;
                }

            }
           // m[target]+=first(context[i].rhs[0]);

        }

    }
    if(!isupper(target)){
        stringstream ss;
        ss << target;
        string a;
        a = ss.str();
        m[target]+=a;
        return a;
    }

    else{
        return m[target];
    }
}
