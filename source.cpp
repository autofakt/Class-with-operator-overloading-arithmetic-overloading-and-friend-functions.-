#include <iostream>
#include <cmath>  // Needed for absolute value function abs in the arithmetic overload operator.

using namespace std;

class Circle
{
private:
  int m_radius;

public:
    Circle ()
  {
    m_radius = 0;
  }
  Circle (int value)
  {
    m_radius = value;
  }
  Circle (const Circle & c){
      this->m_radius = c.m_radius;
  }
  void display () const
  {
    cout << "Radius: " << m_radius << endl;
  }
  int getRadius () const{
      return m_radius;
  }
  void setRadius(int value){
      m_radius = value;
  }
  Circle operator+ (const Circle & rho)
  {
    Circle result;
    result = this->m_radius + rho.m_radius;
    return result;
  }
  Circle operator- (const Circle & rho)
  {
    Circle result;
    result = abs (this->m_radius - rho.m_radius);
    return result;
  }
  Circle operator++ ()
  {
    Circle result;
    ++this->m_radius;
    result.m_radius = this->m_radius;
    return result;
  }
  Circle operator++ (int)
  {
    Circle result;
    result.m_radius = this->m_radius;
    this->m_radius++;
    return result;
  }
  Circle operator--(){
      Circle result;
      result.m_radius = --this->m_radius;
      return result;
  }
  Circle operator--(int){
      Circle result;
      result.m_radius = this->m_radius;
      this->m_radius--;
      return result;
  }
  
  bool operator>(const Circle & rho){
      return this->m_radius > rho.m_radius;
  }
  bool operator<(const Circle & rho){
      return this->m_radius< rho.m_radius;
  }
  bool operator==(const Circle & rho){
      return this->m_radius==rho.m_radius;
  }
  bool operator!=(const Circle & rho){
      return this->m_radius!=rho.m_radius;
  }
  bool operator>=(const Circle & rho){
      return this->m_radius>=rho.m_radius;
  }
  bool operator<=(const Circle & rho){
      return this->m_radius<=rho.m_radius;
  }
  
  Circle& operator=(const Circle & rho);  //Example of body outside of class
  friend ostream& operator<< (ostream&, const Circle &);  //Friend function syntax
  friend istream& operator>> (istream&, Circle &);
  
};

Circle& Circle::operator=(const Circle & rho){  //Example of body outside of class with scope operator
      this->m_radius = rho.m_radius;
      return *this;
  }
  
ostream& operator<< (ostream& sout, const Circle & c){
      sout << c.m_radius;
      return sout;
  }
  
istream& operator>> (istream& in, Circle & c){
    in >> c.m_radius;
    return in;
    
}
  
int
main ()
{
    
  cout<<"-------------------------------" << endl;
  cout<<"     Operator Overloading      " << endl;
  cout<<"-------------------------------" << endl;
  cout << "Circle one: ";  
  Circle one (9);
  one.display ();

  cout << "Circle two: ";
  Circle two (17);
  two.display ();
  
  cout << "Circle one + two: ";
  Circle three = one + two;
  three.display ();

  cout << "Circle one - two: ";
  Circle four = one - two;
  four.display ();

  cout << "Circle ++one: ";
  Circle five = ++one;
  five.display ();

  cout << "Circle two++: ";
  two.display();
  two++;
  cout << "Circle two++ after: ";
  two.display();
  
  cout << "Circle --one: "; //Went from 9 to 8 again.
  Circle six = --one;
  six.display();
  
  cout << "Circle two--: ";
  Circle seven = two--;
  seven.display();
  cout << "Circle two-- after: ";
  two.display();
  
  cout<<"-------------------------------" << endl;
  cout<<"   Arithmetic Overloading      " << endl;
  cout<<"-------------------------------" << endl;
  
  cout << "Current value of circle one: ";
  one.display();
  cout << "Current value of circle two: ";
  two.display();
  
  cout << "Circle one > two: ";
  cout << (one>two) << endl;
  
  cout << "Circle one < two: ";
  cout << (one<two) << endl;
  
  cout << "Circle one == two: ";
  cout << (one==two) << endl;
  
  cout << "Circle one != two: ";
  cout << (one!=two) << endl;
  
  cout << "Circle one >= two: ";
  cout << (one>=two) << endl;
  
  cout << "Circle one <= two: ";
  cout << (one<=two) << endl;  

  return 0;
}

