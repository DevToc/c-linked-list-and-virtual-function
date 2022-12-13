#include <string>
#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
class Performer
{

public:
  string name;
  bool ishired;
  Performer(string iname)
  {
    name = iname;
    ishired = false;
  }
  virtual void perform()
  {
    cout << "perform";
  }
};

class Actor : public Performer
{

public:
  string script;
  Actor(string iname, string iscript) : Performer(iname)
  {
    script = iscript;
  }
  void perform()
  {
    cout << "I am "<<name<<". "<<script<<endl;
  }
};


class Mime : public Performer
{

public:
  string script;
  Mime(string iname) : Performer(iname)
  {

  }
  void perform()
  {
    cout << "(silence)"<<endl;
  }
};


class Company {
  public:
    vector<Performer*> hired;
    void hire(Performer &iperformer){
      if(iperformer.ishired==true){
        return;
      }
      Performer* tmp = &iperformer;
      iperformer.ishired = true;
      hired.push_back(tmp);
    }
    void showtime(){
      for(int i=0;i<hired.size();i++){
        hired.at(i)->perform();
      }
    }
};

int main()
{
  
  Company troupe;
  Company otherTroupe;
  Actor frog("Froggie","Hiya, Kids!");
  Mime red("Red Skelton");
  Actor bogie("Humphrey Bogart", "Play it again.");

  troupe.hire(frog);
  otherTroupe.hire(frog);
  troupe.hire(red);
  troupe.hire(bogie);
  troupe.showtime();
  otherTroupe.showtime();
  return 0;
}
