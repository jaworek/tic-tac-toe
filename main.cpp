#include <iostream>
#include <cstdlib>

using namespace std;

char tab[8][8];
int i;
int j;
int gracz=1;

//Wypelnienie tablicy pustymi polami lub wyczyszczenie jej
void start()
{
    for(int i=0; i<8; i++)
    {
        if(i==0)
        {
            cout<<" ";
            for(int k=0; k<8; k++)
            {
                cout<<" "<<k+1;
            }
            cout<<endl;
        }
        for(int j=0; j<8; j++)
        {

            if(j==0)
            {
                cout<<i+1;
            }
            tab[i][j]=' ';
            cout<<"|"<<tab[i][j];
            if(j==7)
            {
                cout<<"|"<<endl;
            }
        }
    }
}

//Wypisanie tablicy z wpisanymi elementami
void wypisz()
{
    for(int i=0; i<8; i++)
    {
        if(i==0)
        {
            cout<<" ";
            for(int k=0; k<8; k++)
            {
                cout<<" "<<k+1;
            }
            cout<<endl;
        }
        for(int j=0; j<8; j++)
        {
            if(j==0)
            {
                cout<<i+1;
            }
            cout<<"|"<<tab[i][j];
            if(j==7)
            {
                cout<<"|"<<endl;
            }
        }
    }
}

//Wyswietla kto wygral
void wygrany()
{
    cout<<"Wygral gracz nr: "<<gracz;
    exit(0);
}

//Sprawdza czy dany gracz wygral
void sprawdz()
{
    char z;
    char y;
    if(gracz==1)
    {
        z='X';
        y='O';
    }
    else
    {
        z='O';
        y='Z';
    }

    //Poziomo
    for(int i=0; i<8; i++)
    {
        int licznik=0;
        for(int j=0; j<8; j++)
        {
            if(tab[i][j]==z)
            {
                licznik++;
            }
            else if(tab[i][j]==' ' || tab[i][j]==y)
            {
                licznik=0;
            }
            if(licznik==5)
            {
                wygrany();
            }
        }
    }

    //Pionowo
    for(int j=0; j<8; j++)
    {
        int licznik=0;
        for(int i=0; i<8; i++)
        {
            if(tab[i][j]==z)
            {
                licznik++;
            }
            else if(tab[i][j]==' ' || tab[i][j]==y)
            {
                licznik=0;
            }
            if(licznik==5)
            {
                wygrany();
            }
        }
    }

    //Na ukos
    int licznik=0;
    int i=4;
    int j=0;
    for(int x=0; x<7; x++)
    {
        if(i<7)
        {
            int a=i;
            int b=j;
            for(int c=0; c<8; c++)
            {
                if(a<8 || b<8)
                {
                    if(tab[a][b]==z)
                    {
                        licznik++;
                    }
                    else if(tab[i][j]==' ' || tab[i][j]==y)
                    {
                        licznik=0;
                    }
                    if(licznik==5)
                    {
                        wygrany();
                    }
                }
                a--;
                b++;
            }
            i++;
            if(i==8)
            {
                i--;
            }
        }
        else if(i==7 && j<4)
        {
            int a=i;
            int b=j;
            for(int c=0; c<8; c++)
            {

                if(a<8 || b<8)
                {
                    if(tab[a][b]==z)
                    {
                        licznik++;
                    }
                    else if(tab[i][j]==' ' || tab[i][j]==y)
                    {
                        licznik=0;
                    }
                    if(licznik==5)
                    {
                        wygrany();
                    }
                }
                a--;
                b++;
            }
            j++;
        }
        //cout<<licznik;
        licznik=0;
    }

    int k=3;
    int l=0;
    for(int x=0; x<7; x++)
    {
        if(k>0)
        {
            int a=k;
            int b=l;
            for(int c=0; c<8; c++)
            {
                if(a<8 || b<8)
                {
                    if(tab[a][b]==z)
                    {
                        licznik++;
                    }
                    else if(tab[k][l]==' ' || tab[k][l]==y)
                    {
                        licznik=0;
                    }
                    if(licznik==5)
                    {
                        wygrany();
                    }
                }
                a--;
                b++;
            }
            k--;
            if(k==-1)
            {
                k++;
            }
        }
        else if(k==0 && l<4)
        {
            int a=k;
            int b=l;
            for(int c=0; c<8; c++)
            {

                if(a<8 || b<8)
                {
                    if(tab[a][b]==z)
                    {
                        licznik++;
                    }
                    else if(tab[k][l]==' ' || tab[k][l]==y)
                    {
                        licznik=0;
                    }
                    if(licznik==5)
                    {
                        wygrany();
                    }
                }
                a++;
                b++;
            }
            l++;
        }
        licznik=0;
    }
}


//Wstawianie znakow na tablicy przez graczy
void wstaw()
{
    for(i=0; i<1000; i++)
    {
        cout<<"Gracz nr: "<<gracz;
        cout<<endl<<"Podaj wspolrzedne: ";
        if(!(cin>>i>>j))
        {
            cerr<<"To nie liczby!";
            exit(0);
        }
        cout<<endl;
        i=i-1;
        j=j-1;

        if(i>7 || j>7)
        {
            system("cls");
            wypisz();
            cout<<"Zle wspolrzedne"<<endl<<endl;
        }
        else
        {
            if(gracz==1)
            {
                if(tab[i][j]==' ')
                {
                    tab[i][j]='X';
                    system("cls");
                    wypisz();
                    sprawdz();
                    gracz=2;
                }
                else
                {
                    system("cls");
                    wypisz();
                    cout<<"Tu miejsce jest juz zajete"<<endl;
                }
            }
            else
            {
                if(tab[i][j]==' ')
                {
                    tab[i][j]='O';
                    system("cls");
                    wypisz();
                    sprawdz();
                    gracz=1;
                }
                else
                {
                    system("cls");
                    wypisz();
                    cout<<"Tu miejsce jest juz zajete"<<endl;
                }
            }
        }
    }
}

int main()
{
    start();
    wstaw();

    return 0;
}
