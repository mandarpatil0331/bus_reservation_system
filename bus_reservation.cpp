#include<cstdlib>
#include<conio.h>
#include<iostream>
#include<string.h>
#include<cstdio>
using namespace std;
static int p=0;
class a
{
	char busn[5],driver[10],arrival[5],depart[5],from[10],to[10],seat[8][4][10];
	public:
		void install();
		void allotment();
		void empty();
		void show();
		void avail();
		void position(int i);
}
bus[10];
void vline(char ch)
{
	for(int i=50;i>0;i--)
	cout<<ch;
}
void a::install()
{
	cout<<"enter bus no:";
	cin>>bus[p].busn;
	cout<<"\n enter driver's name:";
	cin>>bus[p].driver;
	cout<<"\nArrival time: ";
	cin>>bus[p].arrival;
	cout<<"\nDepature time:";
	cin>>bus[p].depart;
	cout<<"\n from:\t\t\t";
	cin>>bus[p].from;
	cout<<"to";
	cin>>bus[p].to;
	bus[p].empty();
	p++;
}
void a::allotment()
{
	int seat;
	char number[5];
	int top;
	top:
	cout<<"bus no:";
	cin>> number;
	int n;
	for(n=0;n<=p;n++)
	{
		if(strcmp(bus[n].busn,number)==0)
		break;
	}
	while(n<=p)
	{
		cout<<"\nseat Number: ";
		cin>>seat;
		if(seat>32)
		{
			cout<<"\nThere are only 32 seats available in this bus.";
		}
		else
		{
			if(strcmp(bus[n].seat[seat/4][(seat%4)-1] ,"Empty")==0)
			{
				cout<<"enter passenger's name: ";
				cin>>bus[n].seat[seat/4][(seat%4)-1];
				break;
			}
			else
				cout<<"the seat no. is already reserved.\n";
		}
		
	}
	if(n>p)
	{
		cout<<"enter correct bus no.\n";
		goto top;
	}	
}
void a::empty()
{
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<4;j++)
		{
			strcmp(bus[p].seat[i][j],"empty");
			
		}
	}
}
void a::show()

{
	int n;
	char number[3];
	cout<<"Enter bus no. ";
	cin>>number;
	for(n=0;n<=p;n++)
	{
		if(strcmp(bus[n].busn,number)==0)
		
		break;
	}
	while(n<=p)
	{
		vline('*');
		cout<<"bus no:\t"<<bus[n].busn
		<<"\nDriver: \t"<<bus[n].driver<<"\t\tArrival time:\t"
		<<bus[n].arrival<<"\tDeparture time :"<<bus[n].depart
		<<"\nFrom:\t\t"<<bus[n].from<<"\t\tTo: \t\t"<<
		bus[n].to<<"\n";
		vline('*');
		bus[0].position(n);
		int a=1;
		for(int i=0;i<8;i++)
		{
			for(int j=0;j<4;j++)
			{
				a++;
				if(strcmp(bus[n].seat[i][j],"empty")!=0)
				cout<<"\nThe seat no"<<a-1<<"is reserved for"<<bus[n].seat[i][j]<<".";
			}
		}
		break;
	}
	if(n>p)
	cout<<"enter correct bus no:";
}
void a::position(int l)
{
	int s=0,p=0;
	for(int i=0;i<8;i++)
	{
		cout<<"\n";
		for(int j=0;j<4;j++)
		{
			s++;
			if(strcmp(bus[l].seat[i][j],"Empty")==0)
			{
				cout.width(5);
				cout.fill(' ');
				cout<<s<<".";
				cout.width(10);
				cout.fill(' ');
				cout<<bus[l].seat[i][j];
			}
		}
	}
	cout<<"\n\nThere are "<<p<<" seats empty in bus No:"<<bus[l].busn;
}
void a::avail()
{
	for(int n=0;n<p;n++)
	{
		vline('*');
		cout<<"bus no: \t"<<bus[n].busn<<"\nDriver: \t"<<bus[n].driver
		<<"\t\tArrival time :\t"<<bus[n].arrival<<"\tDeparture Time: \t"
		<<bus[n].depart<<"\ninform: \t\t"<<bus[n].from<<"\t\tTo: \t\t\t"
		<<bus[n].to<<"\n";
		vline('*');
		vline('_');
	}
}
int main()
{
	system("cls");
	int w;
	while(1)
	{
		//system("cis");
		cout<<"\n\n\n\n\n";
		cout<<"\t\t\t1.Install\n\t\t\t"
		<<"2.Reservation\n\t\t\t"
		<<"3.show\n\t\t\t"
		<<"4.Buses Available.\n\t\t\t"
		<<"5.exit";
		cout<<"\n\t\t\tEnter your choice:->";
		cin>>w;
		switch(w)
		{
			case 1: bus[p].install();
			break;
			case 2: bus[p].allotment();
			break;
			case 3: bus[p].show();
			break;
			case 4: bus[p].avail();
			break;
			case 5: exit(0);
		}
	}
	return 0;
}




	



