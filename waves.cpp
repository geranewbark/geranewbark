#include <iostream>
#include <windows.h>
#include <iomanip>
//��� ���� ����� ��� ���������� ���� ����� ������������ ����� �������, 
//����� ���� ������� ��������, ����� ������� ������� �� ���� 

//���� � spaceup space=0 => ����� �������� = 2, � ���� space=1 => ����� �������� = 4 
//� ��� ������: 0-2; 1-4; 2-6; 3-8; 4-10; 
using namespace std;
int a = 0; // � ���������� ���������� ������� ��� �� 
double space = 0;
int spaceupcount = 0; int spacedowncount = 0; // ����� ������� ���� ����������
int spaceup (); int spacedown ();
int main ()
{   
    int amountofspaces;
	int u = 0;
	HANDLE hout = GetStdHandle (STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute (hout,BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN|BACKGROUND_BLUE);
    system ("cls");
    SetConsoleTextAttribute (hout,BACKGROUND_INTENSITY|BACKGROUND_RED|BACKGROUND_GREEN|FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	while (true)
	{
	u++;
	if (u == 100) 
	{
		SetConsoleTextAttribute (hout,BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN|BACKGROUND_BLUE);
        system ("cls");
        SetConsoleTextAttribute (hout,BACKGROUND_INTENSITY|BACKGROUND_RED|BACKGROUND_GREEN|FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		u = 0;
	}	
    if (a == 0)
	{
        for (int k = 0; k <= 4; k ++) //����� ��������� � ������
	    {
            cout<<"\xB2\xB2";
            if (k < 4)
			    amountofspaces = spaceup ();
	    }
        
	}
    else if (a == 1) 
	{
		for (int k = 0; k <= 4; k ++) //����� ��������� � ������
	    {
            cout<<"\xB2\xB2";
		    if (k < 4)
			    amountofspaces = spacedown ();
	    }
	} 
 //���� �������, ����� �� ������� ������ ���, � ����� ������� ������������,
 //����� ������� ��� ����� � �����   
       
        // cout �������� ��� spaceup
	    cout<<endl<<setw(amountofspaces*8+10)<<" "<<endl<<setw(amountofspaces*8+10)<<" "<<endl;	    
	
    
//	cout<<endl;
  //  cout<<endl;
	Sleep (100);   
}
}
   // ������ ��������� ��� �������, ������� ����� ������� �������
int spaceup () 
{
    spaceupcount ++;
	int k = 0; //space;
	for (k >= 0; k <= space; k ++)
	{
		cout<<"  ";
	}
    
	k = space + 1; //���� �������� 1=> space==0 => ������������ ����, ���������� ����
	if (spaceupcount == 4) // ��������������, ��� ������������ 5 �������� � ������
	{
		space++; // ������� ����������� ����� ��������
	    spaceupcount = 0; // � �������� ������� ��� 5 ����� ���������
    }
	
		if (space == 4) // ����� �������� �������� ���� ������
		{ 
		    a = 1;   // ����� ����� ������ �������� ������� ��������� �������
	
			space = 4;
	    }
    //k = space;
	return k; 	
}
int spacedown () 
{
	spacedowncount ++;
	int k = space; // ��� � ����� = 4
	for (k >= 0; k >= 0; k --)
	{
		cout<<"  ";
	}
    k = space; // ��� ������-�� �� ����� ������� �������
	if (spacedowncount == 4)
	{
		space--;
	    spacedowncount = 0;     
	}	
	if (space == 0)
		{ 
		    a = 0;   // ����� ����� ������ �������� ������� ��������� �������
		  //  cout<<endl<<"a = 0, ����� � spaceup\n\n";
			space = 0;
	    }
//	k = space;
	return k;    
}
