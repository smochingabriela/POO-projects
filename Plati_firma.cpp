#include <iostream>
#include<tr1/unordered_map>
#include <stdlib.h>

using namespace std;


class plata
{
protected:
    string tip;

public:
    plata(string);
    plata(plata&);
    virtual ~plata();

    string get_tip(){return tip;}

    virtual void citire(istream &in);
    virtual void afisare(ostream &out);
    plata& operator=(plata &c);
    friend istream& operator>>(istream&, plata&);
    friend ostream& operator<<(ostream&, plata&);

};
plata::plata(string t="")
{
    tip=t;
}
plata::plata(plata &c)
{
    tip=c.tip;
}
plata::~plata()
{
    this->tip="";

}
void plata::citire(istream &in)
{


}
void plata::afisare(ostream &out)
{


}
plata& plata::operator=(plata &c)
{
    if(this!=&c)
        tip=c.tip;
    return *this;
}
istream& operator>>(istream& in,plata& c)
{
    c.citire(in);
    return in;
}

ostream& operator<<(ostream& out,plata& c)
{
    c.afisare(out);
    return out;
}
///------------------------------------------------
class numerar:public plata
{
private:
    string data;
    double suma;
public:
    numerar(string,string,double);
    numerar(numerar&);
    ~numerar();

    string get_data(){return data;}
    double get_suma(){return suma;}

    void citire(istream &in);
    void afisare(ostream &out);

    numerar& operator=(numerar &n);
    friend istream& operator>>(istream&, numerar&);
    friend ostream& operator<<(ostream&, numerar&);
};
numerar::numerar(string tip="",string d="",double s=0):plata(tip)
{
    data=d;
    suma=s;
}
numerar::numerar(numerar &n):plata(n)
{
    data=n.data;
    suma=n.suma;
}
numerar::~numerar()
{
    data="";
    suma=0;
}
void numerar::citire(istream &in)
{
    plata::citire(in);
    cout<<"Introduceti data tranzactiei (zi/luna/an): ";
    in>>data;
    cout<<"Introduceti suma tranzactiei (doar sume fixe): ";
    in>>suma;
    cout<<endl;

}
void numerar::afisare(ostream &out)
{
    plata::afisare(out);
    out<<"Modalitatea de plata: numerar";
    cout<<endl;
    out<<"Data tranzictiei: ";
    out<<data<<endl;
    out<<"Suma tranzictiei: ";
    out<<suma;
    out<<endl;
}
numerar &numerar::operator=(numerar &x)
{
    if(this!=&x)
    {
        plata::operator=(x);
        data=x.data;
        suma=x.suma;
    }
    return *this;
}
istream& operator>>(istream& in,numerar& n)
{
    n.citire(in);
    return in;
}

ostream& operator<<(ostream& out, numerar& n)
{
    n.afisare(out);
    return out;
}
///------------------------------------------------
class cec:public plata
{
    private:
        string data;
        double suma;
    public:
        cec(string, string,double);
        cec(cec&);
        ~cec();

        string get_data(){return data;}
        double get_suma(){return suma;}

        void citire(istream &in);
        void afisare(ostream &out);

        cec& operator=(cec &c);
        friend istream& operator>>(istream&, cec&);
        friend ostream& operator<<(ostream&, cec&);
};
cec::cec(string tip="",string d="",double s=0):plata(tip)
{
    data=d;
    suma=s;
}
cec::cec(cec &c):plata(c)
{
    data=c.data;
    suma=c.suma;
}
cec::~cec()
{
    data="";
    suma=0;
}
void cec::citire(istream &in)
{
    plata::citire(in);
    cout<<"Introduceti data tranzactiei (zi/luna/an): ";
    in>>data;
    cout<<"Introduceti suma tranzactiei (doar sume fixe): ";
    in>>suma;
    cout<<endl;

}
void cec::afisare(ostream &out)
{
    plata::afisare(out);
    out<<"Modalitatea de plata: cec";
    cout<<endl;
    out<<"Data tranzictiei: ";
    out<<data<<endl;
    out<<"Suma tranzictiei: ";
    out<<suma;
    out<<endl;
}
cec &cec::operator=(cec &x)
{
    if(this!=&x)
    {
        plata::operator=(x);
        data=x.data;
        suma=x.suma;
    }
    return *this;
}
istream& operator>>(istream& in,cec& c)
{
    c.citire(in);
    return in;
}

ostream& operator<<(ostream& out,cec& c)
{
    c.afisare(out);
    return out;
}
///----------------------------------------------------
class card:public plata
{
private:
    long long nr_card;
    double suma;
    string data;
public:
    card(string,string,double,long long);
    card(const card&);
    ~card();

    long long get_nr_card(){return nr_card;};
    double get_suma(){return suma;};
    string get_data(){return data;};

    void citire(istream &in);
    void afisare(ostream &out);

    card& operator=(card &c);
    friend istream& operator>>(istream&, card&);
    friend ostream& operator<<(ostream&, card&);
};
card::card(string tip="",string d="",double s=0,long long nr=0):plata(tip)
{
    nr_card=nr;
    suma=s;
    data=d;
}
card::card(const card &c)
{
    nr_card=c.nr_card;
    suma=c.suma;
    data=c.data;
}
card::~card()
{
    this->nr_card=0;
    suma=0;
    data="";
}
void card::citire(istream &in)
{
    plata::citire(in);
    cout<<"Nr. cardului este: ";
    in>>nr_card;
    int len=0;
    while(nr_card!=0)
    {
        len++;
        nr_card=nr_card/10;
    }
    if(len<16)
    {
        cout<<"Nr. cardului trebuie sa aiba 16 cifre";
        in>>nr_card;
    }
    cout<<"Introduceti data tranzactiei (zi/luna/an): ";
    in>>data;
    cout<<"Introduceti suma tranzactiei (doar sume fixe): ";
    in>>suma;
    cout<<endl;

}
void card::afisare(ostream &out)
{
    plata::afisare(out);
    out<<"Modalitatea de plata: card";
    cout<<endl;
    out<<"Nr. cardului este: ";
    out<<nr_card<<endl;
    out<<"Data tranzictiei: ";
    out<<data<<endl;
    out<<"Suma tranzictiei: ";
    out<<suma;
    out<<endl;
}
card &card::operator=(card &x)
{
    if(this!=&x)
    {
        plata::operator=(x);
        nr_card=x.nr_card;
        data=x.data;
        suma=x.suma;
    }

    return *this;
}
istream& operator>>(istream& in,card& c)
{
    c.citire(in);
    return in;
}

ostream& operator<<(ostream& out,card& c)
{
    c.afisare(out);
    return out;
}
///----------------------------------------------------
/*template <class t> class Gestiune
{
private:
    string nume_firma;
    static int index;
    int nr;
    std::tr1::unordered_map<int,t*> *plati;
public:
    Gestiune(string nume="", int n=0)
    {
        nume_firma=nume;
        nr=n;
        std::tr1::unordered_map<int,t*> *plati=new std::tr1::unordered_map<int,t*>[nr];

    }
    Gestiune(const Gestiune &a)
    {
        nume_firma=a.nume_firma;
        nr=a.nr;
    }
    ~Gestiune()
    {
        nume_firma="";
        delete [] plati;
        this->nr=0;
    }
    Gestiune& operator=(const Gestiune &a)
    {
        nume_firma=a.nume_firma;
        nr=a.nr;
        return *this;
    }

    void citire(istream &in)
    {
        cout<<"Introduceti numele firmei: ";in>>nume_firma;
        cout<<"Introduceti nr. de plati: ";in>>nr;
        std::tr1::unordered_map<int,t*> *plati=new std::tr1::unordered_map<int,t*>[nr];
        for(int i=0;i<nr;i++)
        {
            string tip;
            plata *aux;
            cout<<"Introduceti modalitatea de plata: ";
            in>>tip;
            if(tip=="cec")
                aux=new cec;
            if(tip=="card")
                aux=new card;
            if(tip=="numerar")
                aux=new numerar;
            in>>*aux;
            plati->insert(std::make_pair <std::static int,plata>(index,aux));
            index++;
        }
    }
    void afisare(ostream &out)
    {
        out<<"Firma: "<<nume_firma;
        for (typename std::tr1::unordered_map<int,t*>::iterator itr = plati->begin(); itr != plati->end(); itr++)
        {
            out << "ID plata: "<<itr->first << "\t" << *itr->second << "\n";
        }
    }

    friend istream& operator>>(istream& in,Gestiune& c)
    {
        c.citire(in);
        return in;
    }

    friend ostream& operator<<(ostream& out,Gestiune& c)
    {
        c.afisare(out);
        return out;
    }
};
template <class t> int Gestiune <t> ::index = 0;

void tip(plata *&p, int &i) {
    string s;
    cout<<"\n";
    cout<<"Introduceti modalitatea de plata "<<i+1<<": ";
    cin>>s;
    try
    {
        if(s=="numerar")
        {
                p=new numerar;
                cin>>*p;
                i++;
        }
        else
            if(s=="cec")
            {
                p=new cec;
                cin>>*p;
                i++;
            }
            else
                if(s=="card")
                {
                    p=new card;
                    cin>>*p;
                    i++;
                }
                else
                    throw 10;
    }
    catch (bad_alloc var)
    {
        cout << "Allocation Failure\n";
        exit(EXIT_FAILURE);
    }
    catch(int j)
    {
        cout<<"Nu ati introdus o modalitate valida. Incercati numerar, cec sau card.\n ";
    }
}
void menu_output()
{
    cout<<"\nPlati firma\n";
    cout<<"\n\t\tMENIU:";
    cout<<"\n===========================================\n";
    cout<<"\n";
    cout<<"1. Citeste informatii despre o firma.";
    cout<<"\n";
    cout<<"2. Afiseaza platile de tip numerar.";
    cout<<"\n";
    cout<<"3. Afiseaza platile de tip cec.";
    cout<<"\n";
    cout<<"4. Afiseaza platile de tip card.";
    cout<<"\n";
    cout<<"5. Contorizare plati.";
    cout<<"\n";
    cout<<"0. Iesire.";
    cout<<"\n";
}
void menu()
{
    int option;
    option=0;
    int n=0;
    plata **v;
    do
    {
        menu_output();
        cout<<"\nIntroduceti numarul actiunii: ";
        cin>>option;
        if (option==1)
        {
            cout<<"Introduceti numarul de obiecte citite: ";
            cin>>n;
            v=new plata*[n];
            if (n>0)
            {
                for(int i=0;i<n;)
                    tip(v[i],i);
                cout<<"\nAfisam platile citite anterior:\n";
                for(int i=0;i<n;i++)
                   {
                        cout<<"\n"<<*v[i];
                        cout<<"--------------------------\n";
                   }
            }
            else
                cout<<"Numarul introdus trebuie sa fie pozitiv.\n";
        }
        if (option==2)
        {
            Gestiune <numerar> x;
            cin>>x;
            cout<<x;
        }
        if (option==3)
        {
            Gestiune <cec> x;
            cin>>x;
            cout<<x;
        }
        if (option==4)
        {
            Gestiune <card> x;
            cin>>x;
            cout<<x;
        }
        if (option==5)
        {
            int N_num,N_cec,N_card;
            N_num=N_cec=N_card=0;
            if (n>0){
            for(int i=0;i<n;i++)
            {
                ///incerc cast catre numerar
                numerar *p1=dynamic_cast<numerar*>(v[i]);
                ///incerc cast catre cec
                cec *p2=dynamic_cast<cec*>(v[i]);
                ///incerc cast catre card
                card *p3=dynamic_cast<card*>(v[i]);
                ///daca sunt nenuli atunci incrementez corespunzator
                if (p1)
                    N_num++;
                if (p2)
                    N_cec++;
                if (p3)
                    N_card++;
            }
            cout<<"Numarul de plati de tip numerar: "<<N_num<<"\n";
            cout<<"Numarul de plati de tip cec: "<<N_cec<<"\n";
            cout<<"Numarul de plati de tip card: "<<N_card<<"\n";}
            else{
                cout<<"Nu s-au citit plati. Reveniti la actiunea 1.\n";
            }
        }
        if (option==0)
        {
            cout<<"\nEXIT\n\n";
        }
        if (option<0||option>5)
        {
            cout<<"\nSelectie invalida\n";
        }
        cout<<"\n";
        system("pause"); ///Pauza - Press any key to continue...
        system("cls");   ///Sterge continutul curent al consolei
    }
    while(option!=0);
}
*/
void tip(plata *&p, int &i) {
    string s;
    cout<<"\n";
    cout<<"Introduceti modalitatea de plata (numerar/cec/card) "<<i+1<<": ";
    cin>>s;
    try
    {
        if(s=="numerar")
        {
                p=new numerar;
                cin>>*p;
                i++;
        }
        else
            if(s=="cec")
            {
                p=new cec;
                cin>>*p;
                i++;
            }
            else
                if(s=="card")
                {
                    p=new card;
                    cin>>*p;
                    i++;
                }
                else
                    throw 10;
    }
    catch (bad_alloc var)
    {
        cout << "Allocation Failure\n";
        exit(EXIT_FAILURE);
    }
    catch(int j)
    {
        cout<<"Nu ati introdus o modalitate valida. Incercati numerar, cec sau card.\n ";
    }
}
void menu_output()
{
    cout<<"\nSmochin Gabriela Alina - Proiect: 1 - Nume proiect: Plati firma\n";
    cout<<"\n\t\tMENIU:";
    cout<<"\n===========================================\n";
    cout<<"\n";
    cout<<"1. Citeste informatii despre o firma.";
    cout<<"\n";
    cout<<"2. Platile de tip numerar.";
    cout<<"\n";
    cout<<"3. Platile de tip cec.";
    cout<<"\n";
    cout<<"4. Platile de tip card.";
    cout<<"\n";
    cout<<"5. Contorizare plati.";
    cout<<"\n";
    cout<<"0. Iesire.";
    cout<<"\n";
}
void menu()
{
    int option;
    option=0;
    int n=0;
    plata **v;
    do
    {
        menu_output();
        cout<<"\nIntroduceti numarul actiunii: ";
        cin>>option;
        if (option==1)
        {
            cout<<"Introduceti numarul de obiecte citite: ";
            cin>>n;
            v=new plata*[n];
            if (n>0)
            {
                for(int i=0;i<n;)
                    tip(v[i],i);
                cout<<"\nAfisam platile citite anterior:\n";
                for(int i=0;i<n;i++)
                   {
                        cout<<"\n"<<*v[i];
                        cout<<"--------------------------\n";
                   }
            }
            else
                cout<<"Numarul introdus trebuie sa fie pozitiv.\n";
        }
        if (option==2)
        {
            numerar x;
            cin>>x;
            cout<<x;
        }
        if (option==3)
        {
            cec x;
            cin>>x;
            cout<<x;
        }
        if (option==4)
        {
            card x;
            cin>>x;
            cout<<x;
        }
        if (option==5)
        {
            int N_num,N_cec,N_card;
            N_num=N_cec=N_card=0;
            if (n>0){
            for(int i=0;i<n;i++)
            {
                ///incerc cast catre numerar
                numerar *p1=dynamic_cast<numerar*>(v[i]);
                ///incerc cast catre cec
                cec *p2=dynamic_cast<cec*>(v[i]);
                ///incerc cast catre card
                card *p3=dynamic_cast<card*>(v[i]);
                ///daca sunt nenuli atunci incrementez corespunzator
                if (p1)
                    N_num++;
                if (p2)
                    N_cec++;
                if (p3)
                    N_card++;
            }
            cout<<"Numarul de plati de tip numerar: "<<N_num<<"\n";
            cout<<"Numarul de plati de tip cec: "<<N_cec<<"\n";
            cout<<"Numarul de plati de tip card: "<<N_card<<"\n";}
            else{
                cout<<"Nu s-au citit plati. Reveniti la actiunea 1.\n";
            }
        }
        if (option==0)
        {
            cout<<"\nEXIT\n\n";
        }
        if (option<0||option>5)
        {
            cout<<"\nSelectie invalida\n";
        }
        cout<<"\n";
        system("pause"); ///Pauza - Press any key to continue...
        system("cls");   ///Sterge continutul curent al consolei
    }
    while(option!=0);
}
int main()
{
    /*Gestiune<plata> *p=new Gestiune<plata>;
    cin>>*p;
    cout<<*p;*/

    menu();

    ///Am comentat mai sus partea de cod care nu compileaza din cauza unei erori din template

}
