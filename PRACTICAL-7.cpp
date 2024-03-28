#include<iostream>
using namespace std;

class complex
{
    int x,y;
public:
    void getdata()
    {
        cout<<"Enter real part :";
        cin>>x;
        cout<<"Enter imaginary part :";
        cin>>y;
    }

    complex operator+(complex &o)
    {
        complex temp;
        temp.x=x+o.x;
        temp.y=y+o.y;
        return temp;
    }

    complex operator-(complex &o)
    {
        complex temp;
        temp.x=x-o.x;
        temp.y=y-o.y;
        return temp;
    }

    void display()
    {
        if(y<0)
        cout<<x<<" "<<y<<"i"<<endl;
        else
        cout<<x<<"+"<<y<<"i"<<endl;
    }

    complex operator !()
    {
        complex temp;

        temp.x=-x;
        temp.y=-y;
        return temp;
    }
    friend complex operator /(complex &o1,complex &o2);
    friend complex operator *(complex &o1,complex &o2);
};


 complex operator /(complex &o1,complex &o2)
{
    complex temp;
    temp.x=( (o1.x*o2.x) + (o1.y*o2.y) ) / ( (o2.x*o2.x) + (o2.y*o2.y) );
    temp.y=( (o1.y*o2.x) - (o1.x*o2.y) ) / ( (o2.x*o2.x) + (o2.y*o2.y) );
    return temp;
}

 complex operator *(complex &o1,complex &o2)
{
    complex temp;
    temp.x=(o1.x*o2.x) - (o1.y*o2.y);
    temp.y=(o1.y*o2.x) + (o1.x*o2.y);
    return temp;
}



int main()
{
    complex o1,o2,o3;
    int s;

    o1.getdata();
    o2.getdata();

    cout<<"1 -(+) addition\n2 -(-) subtraction\n3 -(*) multiplication\n4 -(/) division\n5 -(!) negation\n";

    cout<<"Enter choice :";
    cin>>s;

    switch(s)
    {
    case 1:
        o3=o1+o2;
        o3.display();
        break;


    case 2:
        o3=o1-o2;
        o3.display();
        break;


    case 3:
        o3=o1*o2;
        o3.display();
        break;



    case 4:
        o3=o1/o2;
        o3.display();
        break;


    case 5:
        o2=!o1;
        o2.display();
        break;

    }
}
