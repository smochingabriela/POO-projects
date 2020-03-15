#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

class matrix;
class complex {
private:
    int real;
    int imaginar;
public:
    complex (int, int);                     ///constructor initializare
    complex (const complex& z)
    {
        real=z.real;
        imaginar=z.imaginar;
    }                                       ///constructor copiere
    ~complex ();                            ///destructor
    void set_real(int);                     ///set
    void set_imaginar(int);                 ///set
    int get_real(){return real;};           ///get
    int get_imag(){return imaginar;};       ///get
    friend istream& operator>>(istream &in, class complex& z);  ///supraincarcare pe >>
    friend ostream& operator<<(ostream &out, class complex& z); ///supraincarcare pe <<
    friend istream& operator>>(istream &in, matrix& m);
    friend ostream& operator<<(ostream &out, matrix& m);
    //complex& operator=(complex &z); ///supraincarcarea operatorului de atribuire (doar ca metoda nu ca functie friend)
    friend complex& operator+(complex& z1, complex& z2); ///supraincarcare operator +
    friend complex& operator*(complex& z1, complex& z2); ///supraincarcare operator *
    friend class matrix;
};
class matrix{
private:
    complex **m;
    int lin;
    int col;
public:
    matrix(int,int);
    matrix(matrix&);
    ~matrix();
    friend istream& operator>>(istream &in, complex& z);
    friend ostream& operator<<(ostream &out, complex& z);
    friend istream& operator>>(istream &in, class matrix& m);
    friend ostream& operator<<(ostream &out, class matrix& m);
    friend matrix& operator+(matrix&m1, matrix& m2);
    friend matrix& operator*(matrix& m1, matrix& m2);
    friend class complex;

};
complex::complex(int real = 0, int imaginar = 0){
    this->real = real;
    this->imaginar = imaginar;
}

complex::~complex(){
    this->real=0;
    this->imaginar=0;
}
void complex::set_real(int x){
    real = x;
}
void complex::set_imaginar(int y){
    imaginar=y;
}
matrix::matrix(int lin = 0,int col = 0){
    this->lin=lin;
    this->col=col;
    m=new complex*[lin];
    for(int i=0;i<lin;i++)
        m[i]=new complex[col];

}
matrix::matrix(matrix &mat){
    this->lin=mat.lin;
    this->col=mat.col;
    m=new complex*[mat.lin];
    for(int i=0;i<mat.lin;i++)
        m[i]=new complex[mat.col];
    for(int i=0;i<mat.lin;i++)
        for(int j=0;j<mat.col;j++)
        m[i][j]=mat.m[i][j];
}
matrix::~matrix(){
    for(int i=0;i<lin;i++)
        delete[] m[i];
    delete[] m;
}


istream& operator>>(istream& in,complex& z){
    cout<<"Cititi partea reala: ";
    in>>z.real;
    cout<<"Cititi partea imaginara: ";
    in>>z.imaginar;
    return in;
}
ostream& operator<<(ostream& out, complex& z){
    if (z.imaginar==0) {
        out<<z.real;
    }
    else{
        if (z.imaginar < 0){
            out<<z.real<<z.imaginar<<"*i    ";
        }
        else{
            out<<z.real<<"+"<<z.imaginar<<"*i   ";
        }
    }

    return out;
}

inline complex& operator+(complex &z1, complex& z2){
    complex *z = new complex;
    z->real = z1.real + z2.real;
    z->imaginar = z1.imaginar + z2.imaginar;
    return *z;
}
inline complex& operator*(complex &z1, complex& z2){
    complex *z=new complex;
    z->real = z1.real * z2.real - z1.imaginar * z2.imaginar;
    z->imaginar = z1.real * z2.imaginar + z2.real * z1.imaginar;
    return *z;
}

complex& complex::operator=(complex &z){
    real=z.real;
    imaginar=z.imaginar;
}
istream& operator>>(istream& in, matrix& m){

    cout<<endl<<"Elementele matricii: "<<endl;
    for(int x=0;x<m.lin;x++)
    {
        for(int y=0;y<m.col;y++)
            in>>m.m[x][y];
    }

    return in;
}
ostream& operator<<(ostream& out,matrix& m){

    //out<<"Matricea este: ";
    for(int i=0;i<m.lin;i++)
    {
        out<<endl;
        for(int j=0;j<m.col;j++)
            out<<m.m[i][j];
    }
    return out;
}

inline matrix& operator +(matrix &m1, matrix &m2)
{
    matrix *m3 = new matrix(m1.lin,m2.col);

    for(int i = 0 ;i < m1.lin ; i++)
    {
        for(int j = 0 ; j < m2.col ; j++)
        m3->m[i][j] = m1.m[i][j] + m2.m[i][j];

    }
    return *m3;
}

inline matrix& operator*(matrix &m1, matrix& m2){

    if(m1.col==m2.lin)
    {
        matrix *mat=new matrix(m1.lin,m2.col);
        for(int i=0;i<m1.lin;i++)
            for(int j=0;j<m1.col;j++)
            {
                //mat->m[i][j]=0;
                for(int k=0;k<m1.col;k++)
                    mat->m[i][j]=mat->m[i][j]+m1.m[i][k]*m2.m[k][j];
            }
        return *mat;
    }
    else cout<<"Matricile nu sunt compatibile"<<endl;

}


void menu_output()
{
    printf("\n Smochin Gabriela Alina - Proiect: 2 - Nume proiect: Matrice complexa \n");
    printf("\n\t MENIU:");
    printf("\n===========================================\n");
    printf("\n");
    printf("1. Citirea si afisarea pentru n obiecte"); printf("\n");
    printf("2. Citirea si afisarea unei matrice"); printf("\n");
    printf("3. Suma pentru 2 matrice"); printf("\n");
    printf("4. Produsul pentru 2 matrice"); printf("\n");
    printf("0. Iesire."); printf("\n");
}
void menu()
{
    int option;///optiunea aleasa din meniu
    option=0;

    do
    {
        menu_output();

        printf("\nIntroduceti numarul actiunii: ");
        scanf("%d", &option);

        if (option==1)
        {
            int n,i;
            int lin,col;
            cout<<"n= ";
            cin>>n;
            cout<<"Citesc de "<<n<<" obiecte"<<endl;
            i=n;
            while(i!=0){
            cout<<"Nr. linii: ";
            cin>>lin;
            cout<<"Nr. coloane: ";
            cin>>col;

            matrix m1(lin,col);
            cin>>m1;
            matrix m2(m1);
            cout<<"Matricea 1: "<<m1<<endl;
            cout<<endl;
            cout<<"Matricea 2: "<<m2<<endl;
            cout<<endl;
            i--;
            }

        }
        if (option==2)
        {
            int lin,col;
            cout<<"Nr. linii: ";
            cin>>lin;
            cout<<"Nr. coloane: ";
            cin>>col;

            matrix m1(lin,col);
            cin>>m1;
            cout<<"Matricea : "<<m1<<endl;


        }
        if (option==3)
        {
            int lin,col;
            cout<<"Nr. linii: ";
            cin>>lin;
            cout<<"Nr. coloane: ";
            cin>>col;

            matrix m1(lin,col);
            cin>>m1;
            matrix m2(m1);
            cout<<"Matricea 1: "<<m1<<endl;
            cout<<endl;
            cout<<"Matricea 2: "<<m2<<endl;
            cout<<endl;
            matrix m=m1+m2;
            cout<<endl<<"Matricea dupa adunare: ";
            cout<<m<<endl;
        }
        if (option==4)
        {
            int lin,col;
            cout<<"Nr. linii: ";
            cin>>lin;
            cout<<"Nr. coloane: ";
            cin>>col;

            matrix m1(lin,col);
            cin>>m1;
            matrix m2(m1);
            cout<<"Matricea 1: "<<m1<<endl;
            cout<<endl;
            cout<<"Matricea 2: "<<m2<<endl;
            cout<<endl;
            matrix m3=m1*m2;
            cout<<endl<<"Matricea dupa inmultire: ";
            cout<<m3;

        }

        if (option==0)
        {
            printf("\nEXIT!\n");
        }
        if (option<0||option>5)
        {
            printf("\nSelectie invalida\n");
        }
        printf("\n");
        system("pause"); ///Pauza - Press any key to continue...
        system("cls");   ///Sterge continutul curent al consolei
    }
    while(option!=0);
}

int main()
{
    menu();
    return 0;
}
