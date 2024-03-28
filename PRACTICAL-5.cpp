#include<iostream>
#include<iomanip>
using namespace std;

int count=0;

class fun
{
    int redius;
    float area;
public:
    fun()
    {
        redius=1;
        area=3.14*redius*redius;
        count++;
    }

    fun(int r)
    {
        redius=r;
        area=3.14*redius*redius;
        count++;
    }

    fun(fun & f)
    {
        redius=f.redius;
        area=3.14*redius*redius;
        count++;
    }

    ~fun()
    {
        cout<<"one object is deleted"<<endl;
        count--;
        cout<<"total active objects are "<<count<<endl;
    }

    void display()
    {
        cout<<"circle with Redius "<<redius;
        cout<<" has Area = "<<area<<endl;
    }
};

int main()
{
    fun o1;
    o1.display();

    fun o2(20);
    o2.display();

    fun o3(o1);
    o3.display();
}
