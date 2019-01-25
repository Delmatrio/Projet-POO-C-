#include "match.h"
#include<string>
#include<iostream>
#include<fstream>
using namespace std;
match::match(string a,float pr,int plr,int plt,string t)
{
type=a;
date=t;
prix=pr;
places_res=plr;
places_tot=plt;
}
bool match::retirerplaces(int pl)
{
if((places_tot-places_res)>=pl)
{
places_tot=places_tot-pl;
return true;
}
else
return false;
}
void match::reserver()
{
int r;
cout<<"tapez le nombres de places a reserver (<="<<places_tot-places_res<<")"<<endl;
cin>>r;
if(places_tot-places_res<r)
cout<<"operation impossible"<<endl;
else
places_res=places_res+r;
}
void match::affichernom()
{
cout<<type<<endl;
}
void match::afficher()
{
cout<<"match : "<<type<<endl;
cout<<"prix : "<<prix<<endl;
cout<<"date : "<<date<<endl;
cout<<"places restantes : "<<places_tot-places_res<<endl;
}

ofstream& operator<<(ofstream& out,qualif q)
{
    out<<q.type<<" "<<q.prix<<" "<<q.places_tot<<" "<<q.places_res<<" "<<q.date<<" "<<q.groupe<<endl;
    return out;
}
ofstream& operator<<(ofstream& out,finale f)
{
    out<<f.type<<" "<<f.prix<<" "<<f.places_tot<<" "<<f.places_res<<" "<<f.date<<" "<<f.joueur1<<" "<<f.joueur2<<endl;
    return out;
}
