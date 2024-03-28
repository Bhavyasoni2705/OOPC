
#include<iostream>
using namespace std;

class emp
{
private:

    char name[20];
    char quf[30];
    float exp;
    long long con_no;
    static int average_exp;

public:
    int id;
    void getdata()
    {
        cout<<"Enter employee id :";
        cin>>id;
        cout<<"Enter name:";
        cin>>name;
        cout<<"Enter qualifucation :";
        cin>>quf;
        cout<<"Enter expriance :";
        cin>>exp;
        cout<<"Enter contact number :";
        cin>>con_no;

        average_exp +=exp;
    }
    void display_data()
    {
        cout<<"\n...................................";
        cout<<"\nEmployee Name : "<<name;
        cout<<"\nQualifacation : "<<quf;
        cout<<"\nExperience  : "<<exp;
        cout<<"\ncontact number : "<<con_no<<endl;
    }

    void average_exprience()
    {
        cout<<"Average exprience : "<<average_exp;
    }

};
int emp::average_exp;

int main()
{
    int n,id_no,tag=0,i;
    char c,a;
    cout<<"\nEnter number of employe :";
    cin>>n;
    emp e[n];
    for(int i=0; i<n; i++)
    {
        cout<<"\nEnter "<<i+1<<" employe details \n";
        e[i].getdata();
    }

    cout<<"DETAIL OF EMPLOYEE :--"<<endl;


    do
    {
        cout<<"Enter id no :";
        cin>>id_no;

        for(i=0; i<n; i++)
        {
            if(e[i].id==id_no)
            {
                e[i].display_data();
                tag++;
                break;
            }
        }

        if(tag==0)
        {
            cout<<"Employee is not exist."<<endl;

        }


        cout<<"Press (y) for check more employee details and (n) for exit :";
        cin>>a;

        if(a=='n'||a=='N')
            break;


    }
    while(a=='y'||a=='Y');
    emp ed;
    ed.average_exprience();

    return 0;
}
