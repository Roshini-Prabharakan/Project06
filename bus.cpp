#include<iostream>
#include<conio.h>
#include<string.h>
#include<cstdlib>
#include<stdio.h>
using namespace std;
static int p=0;
class bus
{
  char busno[10],driver[10],arrival[10],depart[10],from[10],to[10];
  char seat[8][4][10];
  public:
  	void add();
  	void reserve();
  	void empty();
  	void show();
  	void available();
  	void pos(int i);	
}
b[10];
void bus::add()
{
 cout<<"Enter bus number:";
 cin>>b[p].busno;
 cout<<"\nEnter driver name:";
 cin>>b[p].driver;
 cout<<"\nArrival time:";
 cin>>b[p].arrival;
 cout<<"\nDeparture time:";
 cin>>b[p].depart;
 cout<<"\nFrom place:";
 cin>>b[p].from;
 cout<<"\nTo place:";
 cin>>b[p].to;
 cout<<"Added successfully.....";
 b[p].empty();
 p++;
getch();
}
void bus::reserve()
{
 int seat;
 char no[5];
 top:
 	cout<<"Bus number:";
    cin>>no;
    int n;
   for(n=0;n<=p;n++)
   {
   	if(strcmp(b[n].busno, no)==0)
    break;
	}
 while(n<=p)
 {
  cout<<"\nSeat number:";
  cin>>seat;
 if(seat>32)
 {
  cout<<"\nThere are only 32 seats availablein the bus..";	
 }
 else
  {
      if (strcmp(b[n].seat[seat/4][(seat%4)-1],"Empty")==0)
      {
        cout<<"Enter passenger's name:";
        cin>>b[n].seat[seat/4][(seat%4)-1];
        break;
      }
 else
       cout<<"\nThe seat number is already reserved..\n";
   }
}
if(n>p)
{
   cout<<"Enter correct bus number.\n";
   goto top;	
}
cout<<"\n Added successfully....." ;
getch();
}
void bus::empty()
{
  int i,j;
  for(i=0;i<8;i++)
  {
  	for(j=0;j<4;j++)
  	{
  	  strcpy(b[p].seat[i][j],"Empty");	
	}
  }
} 
void bus::show()
{
  int n;
  char no[5];
  cout<<"Enter bus number:";
  cin>>no;
  for(n=0;n<=p;n++)
 {
   if(strcmp(b[n].busno,no)==0)
    break;
 }
 while(n<=p)
 {
  cout<<"Bus no:"<<b[n].busno
  	  <<"\nDriver:"<<b[n].driver
	  <<"\nArrival time:"<<b[n].arrival
	  <<"\nDeparture time:"<<b[n].depart
  	  <<"\nFrom:"<<b[n].from
	  <<"\nTo:"<<b[n].to<<"\n";
b[0].pos(n);
int a=1,i,j;
for(i=0;i<8;i++)
  {
  	for(j=0;j<4;j++)
  	{
  	  a++;
  	  	if(strcmp(b[n].seat[i][j],"Empty")!=0)
      	cout<<"\nThe seat no "<<(a-1)<<" is reserved for "
		    <<b[n].seat[i][j]<<".";
	}
  }
break;	
 } 
 if(n>p)
 cout<<"\nEnter correct bus number:";
}
void bus::pos(int l) 
{
  int k=0,p=0,i,j;
 for(i=0;i<8;i++)
 {
   cout<<"\n";
for(j=0;j<4;j++)
{
  k++;
if(strcmp(b[l].seat[i][j],"Empty")==0)
{
    cout.width(5);
    cout.fill(' ');
    cout<<k<<".";
    cout.width(10);
    cout.fill(' ');
    cout<<b[l].seat[i][j];
    p++;
 }
else
{
    cout.width(5);
    cout.fill(' ');
    cout<<k<<".";
    cout.width(10);
    cout.fill(' ');
    cout<<b[l].seat[i][j];
 
}
}
}
cout<<"\n\nThere are"<<p<<"seat empty in bus no"<<b[l].busno;
}
void bus::available()
{
  int n;	
  for(n=0;n<p;n++)
 {
   cout<<"Bus no:"<<b[n].busno
  	   <<"\nDriver:"<<b[n].driver
	   <<"\nArrival time:"<<b[n].arrival
	   <<"\nDeparture time:"<<b[n].depart
  	   <<"\nFrom:"<<b[n].from
	   <<"\nTo:"<<b[n].to<<"\n";
 }
getch(); 
}
int main()
{
 system("cls");
 int w;
while (1)
 {
   cout<<"\n\n\n\n\n";
   cout<<"\t\t\t1.Add\n\t\t\t"
       <<"2.Reservation\n\t\t\t"
	   <<"3.Show\n\t\t\t"
	   <<"4.Busses Available\n\t\t\t"
	   <<"5.Exit\n\t\t\t";
   cout<<"Enter your choice:";
   cin>>w;
 switch(w)
 {
  case 1:b[p].add();
  break;
  case 2:b[p].reserve();
  break;
  case 3:b[0].show();
  break;
  case 4:b[0].available();
  break;
  case 5:exit(0);
 }	   	
 }
return 0;
}
