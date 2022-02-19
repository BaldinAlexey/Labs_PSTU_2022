#include <iostream>
#include <string>

using namespace std;

int main() 
{
    setlocale(LC_ALL, "Rus");
   
    string text;
    string tmp;
    bool flag = false;
    int k=0;
    int a = 1;
    int l = 1;
    int j = 0;
    int count = 1;
    cout << "Enter a line :" << endl;
    getline(cin, text);
    text += ".";
    string sim1;
    int s = 0;
    while (text[s] != ' ')
    {
        
        sim1 += text[s];
        s += 1;
        k += 1;

    }
    s = 0;
    while (text[s] !='\0')
    {
       
        if (text[s]== sim1[j] )
        {
            flag = true;
            j++;
            l++;
            a++;
        }
        else if (text[s] != ' ')
        {
            flag = false;
              j = 0;
              l++;
              a--;
        }
        if (text[s] == '.')
        {
            flag = true;
            l--;
            a++;
        }
   

        if ((text[s] == ' ' || text[s] == '.') && (flag) && (l<=k) && (a==k) )
        {
   
            count++;
            j = 0;
            l = 0;

            a = 0;
        }
        if (text[s] == ' ')
        {
  
            flag = false;
            j = 0;
            l = 0;
            a = 0;
        }
        s++;
    }
    cout << endl;
    cout << "The first word in the line : " << sim1 << endl;
    cout << "Number of repetitions : " << count << endl; 
    return 0;
}