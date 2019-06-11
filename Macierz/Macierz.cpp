#include <iostream>

using namespace std;
int x;
int tab_1[3][3];
int tab_2[3][3];
void print(int tab[3][3])
{
	for (int i = 0; i<3;i++)
	{
		for (int j=0;j<3;j++)
		{
			cout<<tab[i][j]<<" ";
		}cout<<endl;
	}cout<<endl;
}

void zapolnienie (int tab[3][3])
{
	for (int i = 0; i<3;i++)
	{
		for (int j = 0; j<3;j++)
		{	
			cout<<"Kolumna : " <<i<<"/ Wersz : "<<j<<endl;
			cin>>x;
			tab[i][j] = x;
		}
	}
	
}

int wyznacznik(int tab[3][3])
{
	cout<< "Wyznacznik : "<<endl;
	int wyznacznik = tab[0][0]*tab[1][1]*tab[2][2]+tab[1][0]*tab[2][1]*tab[0][2]+tab[2][0]*tab[0][1]*tab[1][2]
	-tab[0][2]*tab[1][1]*tab[2][0]-tab[1][2]*tab[2][1]*tab[0][0]-tab[2][2]*tab[0][1]*tab[1][0];
	print(tab);
	cout<<"det(A)= " <<wyznacznik<<endl;
	return wyznacznik;
}


void matrixplus(int tab[3][3],int tab_1[3][3])
{	
	print(tab);
	cout<<"  +  "<<endl<<endl;
	print(tab_1);
	cout<<"  ||  "<<endl<<endl;
	for (int i = 0; i<3;i++)
		{
		for (int j=0;j<3;j++)
		{
			cout<<tab[i][j]+tab_1[i][j]<<" ";
		}cout<<endl;
	}cout<<endl;
}

void matrixminus(int tab[3][3],int tab_1[3][3])
{
	print(tab);
	cout<<"  +  "<<endl<<endl;
	print(tab_1);
	cout<<"  ||  "<<endl<<endl;
	for (int i = 0; i<3;i++)
		{
		for (int j=0;j<3;j++)
		{
			cout<<tab[i][j]-tab_1[i][j]<<" ";
		}cout<<endl;
	}cout<<endl;
}
/*
				00|01|02
				10|11|12
				20|21|22
		00|01|02
		10|11|12
		20|21|22
*/
void mnozeniematrix(int tab[3][3],int tab_1[3][3])
{
	cout<<"Mnożenie Macierzej"<<endl;
	int tab_new[3][3]={{tab[0][0]*tab_1[0][0]+tab[0][1]*tab_1[1][0]+tab[0][2]*tab_1[2][0],tab[0][0]*tab_1[0][1]+tab[0][1]*tab_1[1][1]+tab[0][2]*tab_1[2][1],tab[0][0]*tab_1[0][2]+tab[0][1]*tab_1[1][2]+tab[0][2]*tab_1[2][2]},
                      {tab[1][0]*tab_1[0][0]+tab[1][1]*tab_1[1][0]+tab[1][2]*tab_1[2][0],tab[1][0]*tab_1[0][1]+tab[1][1]*tab_1[1][1]+tab[1][2]*tab_1[2][1],tab[1][0]*tab_1[0][2]+tab[1][1]*tab_1[1][2]+tab[1][2]*tab_1[2][2]},
					  {tab[2][0]*tab_1[0][0]+tab[2][1]*tab_1[1][0]+tab[2][2]*tab_1[2][0],tab[2][0]*tab_1[0][1]+tab[2][1]*tab_1[1][1]+tab[2][2]*tab_1[2][1],tab[2][0]*tab_1[0][2]+tab[2][1]*tab_1[1][2]+tab[2][2]*tab_1[2][2]}};
		cout<<"Macierz po przemnozeniu : "<<endl;		
		for (int i = 0; i<3;i++)
		{
		for (int j=0;j<3;j++)
		{
			cout<<tab_new[i][j]<<" ";
		}cout<<endl;
	}cout<<endl;
}




/*
		00|01|02	(-1)^1+1*(11*22-12*21)|(-1)^1+2*(10*22-20*12)|(-1)^1+3*(10*21-11*20)
		10|11|12 =  (-1)^2+1*(00*22-02*20)|(-1)^2+2*(00*22-02*20)|(-1)^2+3*(00*21-01*20)
		20|21|22	(-1)^3+1*(01*12-11*02)|(-1)^3+2*(00*12-10*02)|(-1)^3+3*(00*11-01*10)
*/
void matrixodwrotna(int tab[3][3])
	{
		int wyz = wyznacznik(tab);
		int tab_dop[3][3] =	{{tab[1][1]*tab[2][2]-tab[1][2]*tab[2][1],(-1)*(tab[1][0]*tab[2][2]-tab[2][0]*tab[1][2]),tab[1][0]*tab[2][1]-tab[1][1]*tab[2][0]},
						    {(-1)*(tab[0][1]*tab[2][2]-tab[2][1]*tab[0][2]),tab[0][0]*tab[2][2]-tab[0][2]*tab[2][0],(-1)*(tab[0][0]*tab[2][1]-tab[0][1]*tab[2][0])},
							{tab[0][1]*tab[1][2]-tab[1][1]*tab[0][2],(-1)*(tab[0][0]*tab[1][2]-tab[1][0]*tab[0][2]),tab[0][0]*tab[1][1]-tab[0][1]*tab[1][0]}};

		cout<<"Macierz dop : "<<endl;
		for (int i = 0; i<3;i++)
			{
			for (int j=0;j<3;j++)
			{
				cout<<tab_dop[i][j]<<" ";
			}cout<<endl;
		}cout<<endl;

		int tab_trans[3][3] = {{tab_dop[0][0],tab_dop[1][0],tab_dop[2][0]},{tab_dop[0][1],tab_dop[1][1],tab_dop[2][1]},{tab_dop[0][2],tab_dop[1][2],tab_dop[2][2]}};
		cout<<"Macierz Transponowana : "<<endl;		
		print(tab_trans);

		double tab_odwrotna[3][3]={{(double)tab_trans[0][0]/wyz,(double)tab_trans[0][1]/wyz,(double)tab_trans[0][2]/wyz},{(double)tab_trans[1][0]/wyz,(double)tab_trans[1][1]/wyz,(double)tab_trans[1][2]/wyz},{(double)tab_trans[2][0]/wyz,(double)tab_trans[2][1]/wyz,(double)tab_trans[2][2]/wyz}};
		cout<<"Macier Odwrotna"<<endl;		
		for (int i = 0; i<3;i++)
		{
			for (int j=0;j<3;j++)
			{
				cout<<tab_odwrotna[i][j]<<" ";
			}cout<<endl;
		}cout<<endl;
}

int main()
{	
	int y;

	
    for(;; )
    {
        char y;
        cout << "[1]Składanie macierzej\n[2]Odejmowanie macierzej\n[3]Wyznacznik\n[4]Przemnozenie macierzej\n[5]complex_int\n[6]complex_long\n[7]complex_float\n[8]complex_double\n[x]koniec\n";
        cin >> y;
       
        switch( y )
        {
        case 'q': return 0;
        //składanie macierzej;   
        case '1': 
		{
			zapolnienie(tab_1);
			zapolnienie(tab_2);

			matrixplus(tab_1,tab_2);
		}

        case '2':
			zapolnienie(tab_1);
			zapolnienie(tab_2);
			matrixminus(tab_1,tab_2);
			 
        case '3':
			zapolnienie(tab_1);
			wyznacznik(tab_1);

        case '4': 
		
		case '5':
		
		case '6':
        	   
        }
       
        cout << endl << endl;
    }
			
	

	return 0;
}
