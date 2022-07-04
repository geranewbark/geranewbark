#include <iostream>
#include <windows.h>
#include <iomanip>

//если в spaceup space=0 => колво пробелов = 2, а если space=1 => колво пробелов = 4 
//и так дальше: 0-2; 1-4; 2-6; 3-8; 4-10; 
using namespace std;
int a = 0; // а определяет возрастают пробелы или не 
double space = 0;
int spaceupcount = 0; int spacedowncount = 0; // будут считать разы выполнения
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
        for (int k = 0; k <= 4; k ++) //колво елементов в строке
	    {
            cout<<"\xB2\xB2";
            if (k < 4)
			    amountofspaces = spaceup ();
	    }
        
	}
    else if (a == 1) 
	{
		for (int k = 0; k <= 4; k ++) //колво елементов в строке
	    {
            cout<<"\xB2\xB2";
		    if (k < 4)
			    amountofspaces = spacedown ();
	    }
	} 

       
        // cout работает для spaceup
	    cout<<endl<<setw(amountofspaces*8+10)<<" "<<endl<<setw(amountofspaces*8+10)<<" "<<endl;	    
	
    
	Sleep (100);   
}
}
   // теперь реализуем две функции, которые будут ставить пробелы
int spaceup () 
{
    spaceupcount ++;
	int k = 0; //space;
	for (k >= 0; k <= space; k ++)
	{
		cout<<"  ";
	}
    
	k = space + 1; //если итерация 1=> space==0 => возвращается ноль, прибавляем один
	if (spaceupcount == 4) // предпологается, что отпечатались 5 символов в строке
	{
		space++; // поэтому увеличиваем колво пробелов
	    spaceupcount = 0; // и обнуляем счетчик для 5 новых елементов
    }
	
		if (space == 4) // колво пробелов достигло макс уровня
		{ 
		    a = 1;   // после этого должна работать функция понижения пробела
	
			space = 4;
	    }
    //k = space;
	return k; 	
}
int spacedown () 
{
	spacedowncount ++;
	int k = space; // тут к будет = 4
	for (k >= 0; k >= 0; k --)
	{
		cout<<"  ";
	}
    k = space; // тут почему-то не нужно единицу ставить
	if (spacedowncount == 4)
	{
		space--;
	    spacedowncount = 0;     
	}	
	if (space == 0)
		{ 
		    a = 0;   // после этого должна работать функция повышения пробела
		  //  cout<<endl<<"a = 0, заход в spaceup\n\n";
			space = 0;
	    }
//	k = space;
	return k;    
}
