//
//Fernado Guanoluisa
//
#include<iostream>
using namespace std;
void corazones();
int vidas = 3;

int main ()
{
    corazones();
    return 0;
}

void corazones()
{
    if (vidas==1)
    {
       cout<<char(3);
    }
    if (vidas==2)
    {
       cout<<char(3)<<char(3);
    }
    if (vidas==3)
    {
       cout<<char(3)<<char(3)<<char(3);
    }
}