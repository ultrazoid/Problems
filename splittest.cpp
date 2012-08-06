#include <iostream>
#include <string>
//a
using namespace std;

string strRange(string superstring, int start, int end)
{
    if (end-start <= 0) {return string("\0");}
    char retr[end-start];
    for (int i=start; i<end; i++)
    {retr[i-start] = superstring[i];}
    return string(retr);
}

int charCount(string field, char find)
{
    int occs = 0;
    for (int i=0; i<field.length(); i++)
    {if (field[i] == find) {occs++;}}
    return occs;
}

string* split(string original, char div)
{
    int len = charCount(original, div);
    string *store = new string[len+1];
    len = 0;
    int pos = 0;
    for (int i=0; i<original.length(); i++)
    {
        if (original[i] == div)
        {
            store[len] = strRange(original, pos, i);
            len++;
            pos = i+1;
        }
    }
    store[len] = strRange(original, pos, original.length()-1);
    return store;
}

int main()
{
    string test = "THIS IS A TEST";
    for (int i=0; i<4; i++)
    {cout << split(test, ' ')[i] << "\n";}
    cin.get();
}
