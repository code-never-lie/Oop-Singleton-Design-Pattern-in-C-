Singleton
- singleton pattern is a design pattern used to implement the mathematical concept of a singleton, by restricting the instantiation of a class to one object.

-used  when exactly one object is needed to coordinate actions across the system. 
- The concept is sometimes generalized to systems that operate more efficiently when only one object exists, or that restrict the instantiation to a certain number of objects.
- Constructor Should be private
- Object can only be created through static method

class Biscuit{
private:
static int count;
static bool flag;

Biscuit() {count++;
      cout<<count <<" Biscuit created\n"; }
public :

static Biscuit * getBiscuit(){
  if (flag==true){
      flag=false;
      return new Biscuit();
   }else{
       cout<<" you have already one first consume it\n";
       return  NULL;
}
}
  
void eat(){cout<<" i m going to eat one"<<endl;}

~Biscuit() { cout<<count <<" Biscuit Consumed "<<endl;
flag=true;}
};
bool Biscuit::flag=true;
int Biscuit::count=0;


void main ( ){
//Biscuit ob; //error not allowed reason constructor is priavte
Biscuit *b1;// allowed reason pointer is not object

b1=Biscuit::getBiscuit();
b1->eat();
Biscuit *b2;
b2=Biscuit::getBiscuit();
if (b2!=NULL)
  b2->eat();
delete b1;//consume first biscuit, it will assign true to flag in destructor
//try again
b2=Biscuit::getBiscuit();

if (b2!=NULL)
  b2->eat();
}
