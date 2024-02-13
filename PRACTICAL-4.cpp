#include<iostream>
using namespace std;

float Calculate_Area(float redius)
{  

 return 3.14*redius*redius;      

float Calculate_Area(float heigth , float width)
{  

return heigth*width;

}

float Calculate_Area(float heigth , float width , float depth)
{
  
return heigth*width*depth;

}


int main()
{

float heigth;  
float width;
float depth;


cout << "Enter Radius of a Circle : ";
cin >> heigth;

 // pass the adress of a veriable.
cout<< "The Area of Circle : " << Calculate_Area(heigth) << endl << endl;



cout << "Enter hiegth of rectangle : ";
cin >> heigth;

cout << "Enter width of rectangle : ";
cin >> width;


cout << "The Area of rectangle : " << Calculate_Area( heigth , width) << endl << endl;


cout << "Enter heigth of cuboid : ";
cin >> heigth;

cout << "Enter width of cuboid : ";
cin >> width;

cout << "Enter depth of cuboid : ";
cin >> depth;


cout << "The Area of cuboid : " << Calculate_Area(heigth , width, depth) << endl << endl;

}
