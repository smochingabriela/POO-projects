#include <iostream>
#include <vector>
#include <time.h>
#include <stdlib.h>
using namespace std;

class Mancare
{
public:
    friend class Client;
    virtual void citire(istream& in)=0;
    virtual int get_pret()=0;
    virtual void afisare(ostream &out)=0;
    friend istream& operator>>(istream& in, Mancare& m)
    {
        m.citire(in);
        return in;
    }

    friend ostream& operator<<(ostream& out, Mancare& m)
    {
        m.afisare(out);
        return out;
    }

};
class Ciorba:public Mancare
{
protected:
    string fel_de_ciorba;
    int pret;
public:
    Ciorba(string fel_de_ciorba="\0",int pret=0,int x=0)
    {
        pret=pret;
        this->fel_de_ciorba=fel_de_ciorba;
    }
    int get_pret(){return pret;}
    Ciorba(const Ciorba& c)
    {
        this->pret=c.pret;
        this->fel_de_ciorba=c.fel_de_ciorba;
    }

    ~Ciorba()
    {
        this->pret=0;
        this->fel_de_ciorba="\0";
    }

    void citire(istream& in)
    {
        cout<<"Ce fel de ciorba? legume/ciuperci/burta";
        in>>fel_de_ciorba;
        while(fel_de_ciorba!="legume" && fel_de_ciorba!="ciuperci" && fel_de_ciorba!="burta")
        {
            cout<<"Alegeti dintre ciorba de legume/ciuperci/burta";
            in>>fel_de_ciorba;
        }
        if(fel_de_ciorba=="legume")
            pret=20;
        if(fel_de_ciorba=="ciuperci")
            pret=25;
        if(fel_de_ciorba=="burta")
            pret=30;
    }

    void afisare(ostream& out)
    {
        out<<fel_de_ciorba<<"       ";
        out<<pret;
    }

    Ciorba& operator=(Ciorba& c)
    {
        this->fel_de_ciorba=c.fel_de_ciorba;
        this->pret=c.pret;
        return *this;
    }

    friend istream& operator>>(istream& in, Ciorba& c)
    {
        c.citire(in);
        return in;
    }

    friend ostream& operator<<(ostream& out, Ciorba& c)
    {
        c.afisare(out);
        return out;
    }
};

class Friptura:public Mancare
{
protected:
    string fel_de_friptura;
    int pret;
public:
    Friptura(string fel_de_friptura="\0",int pret=0):Mancare()
    {
        this->pret=pret;
        this->fel_de_friptura=fel_de_friptura;
    }
    int get_pret(){return pret;}
    Friptura(const Friptura& c)
    {
        this->pret=c.pret;
        this->fel_de_friptura=c.fel_de_friptura;
    }

    Friptura& operator=(const Friptura& c)
    {
        this->pret=c.pret;
        this->fel_de_friptura=c.fel_de_friptura;
        return *this;
    }

    ~Friptura()
    {
        this->pret=0;
        this->fel_de_friptura="\0";
    }

    void citire(istream& in)
    {
        cout<<"Ce fel de friptura? pui/vita/porc";
        in>>fel_de_friptura;
        while(fel_de_friptura!="pui" && fel_de_friptura!="vita" && fel_de_friptura!="porc")
        {
            cout<<"Alegeti dintre friptura de pui/vita/porc";
            in>>fel_de_friptura;
        }
        if(fel_de_friptura=="pui")
            pret=20;
        if(fel_de_friptura=="vita")
            pret=30;
        if(fel_de_friptura=="porc")
            pret=25;
    }

    void afisare(ostream& out)
    {
        out<<fel_de_friptura<<"         ";
        out<<pret;
    }

    friend istream& operator>>(istream& in, Friptura& c)
    {
        c.citire(in);
        return in;
    }

    friend ostream& operator<<(ostream& out, Friptura& c)
    {
        c.afisare(out);
        return out;
    }
};

class Garnitura:public Mancare
{
protected:
    string fel_de_garnitura;
    int pret;
public:
    Garnitura(string fel_de_garnitura="\0",int pret=0):Mancare()
    {
        this->pret=pret;
        this->fel_de_garnitura=fel_de_garnitura;
    }
    int get_pret(){return pret;}
    Garnitura(const Garnitura& c)
    {
        this->pret=c.pret;
        this->fel_de_garnitura=c.fel_de_garnitura;
    }

    Garnitura& operator=(const Garnitura& c)
    {
        this->pret=c.pret;
        this->fel_de_garnitura=c.fel_de_garnitura;
        return *this;
    }

    ~Garnitura()
    {
        this->pret=0;
        this->fel_de_garnitura="\0";
    }

    void citire(istream& in)
    {
        cout<<"Ce fel de garnitura? cartofi prajiti/piure/orez";
        in>>fel_de_garnitura;
        while(fel_de_garnitura!="cartofi prajiti" && fel_de_garnitura!="piure" && fel_de_garnitura!="orez")
        {
            cout<<"Alegeti dintre garnitura de cartofi prajiti/piure/orez";
            in>>fel_de_garnitura;
        }
        if(fel_de_garnitura=="cartofi prajiti")
            pret=15;
        if(fel_de_garnitura=="piure")
            pret=10;
        if(fel_de_garnitura=="orez")
            pret=15;
    }

    void afisare(ostream& out)
    {
        out<<fel_de_garnitura<<"            ";
        out<<pret;
    }

    friend istream& operator>>(istream& in, Garnitura& c)
    {
        c.citire(in);
        return in;
    }

    friend ostream& operator<<(ostream& out, Garnitura& c)
    {
        c.afisare(out);
        return out;
    }
};

class Desert:public Mancare
{
protected:
    string fel_de_desert;
    int pret;
public:
    Desert(string fel_de_desert="\0",int pret=0):Mancare()
    {
        this->pret=pret;
        this->fel_de_desert=fel_de_desert;
    }
    int get_pret(){return pret;}
    Desert(const Desert& c)
    {
        this->pret=c.pret;
        this->fel_de_desert=c.fel_de_desert;
    }

    Desert& operator=(const Desert& c)
    {
        this->pret=c.pret;
        this->fel_de_desert=c.fel_de_desert;
        return *this;
    }

    ~Desert()
    {
        this->pret=0;
        this->fel_de_desert="\0";
    }

    void citire(istream& in)
    {
        cout<<"Ce fel de desert? inghetata/tort";
        in>>fel_de_desert;
        while(fel_de_desert!="inghetata" && fel_de_desert!="tort")
        {
            cout<<"Alegeti dintre inghetata/tort";
            in>>fel_de_desert;
        }
        if(fel_de_desert=="tort")
            pret=55;
        if(fel_de_desert=="inghetata")
            pret=45;
    }

    void afisare(ostream& out)
    {
        out<<fel_de_desert<<"           ";
        out<<pret;
    }

    friend istream& operator>>(istream& in, Desert& c)
    {
        c.citire(in);
        return in;
    }

    friend ostream& operator<<(ostream& out, Desert& c)
    {
        c.afisare(out);
        return out;
    }
};

class Bautura
{
public:
    friend class Client;
    virtual int get_pret()=0;

    virtual void citire(istream& in)=0;

    virtual void afisare(ostream &out)=0;

    friend istream& operator>>(istream& in, Bautura& b)
    {
        b.citire(in);
        return in;
    }

    friend ostream& operator<<(ostream& out, Bautura& b)
    {
        b.afisare(out);
        return out;
    }

};

class Vin: public Bautura
{
protected:
    string fel_de_vin;
    int pret;
public:
    friend class Client;
    Vin(string fel_de_vin="\0",int pret=0)
    {
        this->pret=pret;
        this->fel_de_vin=fel_de_vin;
    }
    int get_pret(){return pret;}
    Vin(const Vin& c)
    {
        this->pret=c.pret;
        this->fel_de_vin=c.fel_de_vin;
    }

    ~Vin()
    {
        this->pret=0;
        this->fel_de_vin="\0";
    }

    void citire(istream& in)
    {
        cout<<"Ce fel de vin? alb/rosu";
        in>>fel_de_vin;
        while(fel_de_vin!="alb" && fel_de_vin!="rosu")
        {
            cout<<"Alegeti dintre vin alb/rosu";
            in>>fel_de_vin;
        }
        if(fel_de_vin=="alb")
            pret=515;
        if(fel_de_vin=="rosu")
            pret=145;
    }

    void afisare(ostream& out)
    {
        out<<fel_de_vin<<"           ";
        out<<pret;
    }

    Vin& operator=(Vin& c)
    {
        this->fel_de_vin=c.fel_de_vin;
        this->pret=c.pret;
        return *this;
    }

    friend istream& operator>>(istream& in, Vin& c)
    {
        c.citire(in);
        return in;
    }

    friend ostream& operator<<(ostream& out, Vin& c)
    {
        c.afisare(out);
        return out;
    }
};

class Bere:public Bautura
{
protected:
    string fel_de_bere;
    int pret;
public:
    Bere(string fel_de_bere="\0",int pret=0):Bautura()
    {
        this->pret=pret;
        this->fel_de_bere=fel_de_bere;
    }
    int get_pret(){return pret;}
    Bere(const Bere& c)
    {
        this->pret=c.pret;
        this->fel_de_bere=c.fel_de_bere;
    }

    Bere& operator=(Bere& c)
    {
        this->fel_de_bere=c.fel_de_bere;
        this->pret=c.pret;
        return *this;
    }

    ~Bere()
    {
        this->pret=0;
        this->fel_de_bere="\0";
    }

    void citire(istream& in)
    {
        cout<<"Ce fel de bere? cu/fara alcool";
        in>>fel_de_bere;
        while(fel_de_bere!="cu" && fel_de_bere!="fara")
        {
            cout<<"Alegeti dintre bere cu/fara alcool";
            in>>fel_de_bere;
        }
        if(fel_de_bere=="cu")
            pret=15;
        if(fel_de_bere=="fara")
            pret=10;
    }

    void afisare(ostream& out)
    {
        out<<fel_de_bere<<"           ";
        out<<pret;
    }

    friend istream& operator>>(istream& in, Bere& c)
    {
        c.citire(in);
        return in;
    }

    friend ostream& operator<<(ostream& out, Bere& c)
    {
        c.afisare(out);
        return out;
    }
};

class Apa:public Bautura
{
protected:
    int pret;
public:
    Apa(int pret=0):Bautura()
    {
        this->pret=10;
    }
    int get_pret(){return pret;}
    Apa(const Apa& c)
    {
        this->pret=c.pret;
    }

    Apa& operator=(Apa& c)
    {
        this->pret=c.pret;
        return *this;
    }

    ~Apa()
    {
        this->pret=0;
    }

    void citire(istream& in){}

    void afisare(ostream& out)
    {
        out<<"Apa           ";
        out<<pret;
    }

    friend ostream& operator<<(ostream& out, Apa& c)
    {
        c.afisare(out);
        return out;
    }
};


class Client
{
private:
    int nota;
    vector<Mancare*> m;
    vector<Bautura*> b;
public:
    friend class Restaurant;
    friend class Masa;
    friend class Mancare;
    friend class Bautura;

    Client(vector<Mancare*> m={},vector<Bautura*> b={},int nota=0)
    {
        m=m;
        b=b;
        this->nota=nota;
    }

    Client(Client& c)
    {
        m=c.m;
        b=c.b;
        this->nota=c.nota;
    }
    Client& operator=(Client& c)
    {
        m=c.m;
        b=c.b;
        this->nota=c.nota;
        return *this;
    }

    ~Client()
    {
        this->m={};
        this->b={};
        this->nota=0;
    }

    void citire(istream& in)
    {
        string rasp;
        Mancare* x;
        Bautura* y;
        try
        {

            cout<<"De baut va aduc ceva? da/nu";
            in>>rasp;
            while(rasp!="da" && rasp!="nu")
            {
                cout<<"Raspundenti cu da sau nu";
                in>>rasp;
            }

            if(rasp=="da")
                throw rasp;

        }

        catch(string rasp)
        {
            try
            {
                cout<<"Vin, bere sau apa?";
                in>>rasp;
                while(rasp!="bere" && rasp!="vin" && rasp!="apa")
                {
                    cout<<"Alegeti dintre bere, vin sau apa";
                    in>>rasp;
                }

                throw rasp;


            }

            catch(string rasp)
            {
                if(rasp=="vin")
                {
                    y=new Vin;
                    in>>*y;
                }
                else
                    if(rasp=="bere")
                    {
                        y=new Bere;
                        in>>*y;
                    }
                    else
                        {
                            y=new Apa;
                            in>>*y;
                        }
                b.push_back(y);

            }
        }

        try
        {
            cout<<"Doriti ciorba? da/nu";
            in>>rasp;
            while(rasp!="da" && rasp!="nu")
            {
                cout<<"Raspundeti cu da sau nu";
                in>>rasp;
            }

            if(rasp=="da")
                throw rasp;

        }

        catch(string rasp)
        {
            x=new Ciorba;
            in>>*x;
            nota=nota+x->get_pret();

            m.push_back(x);
        }

        try
        {
            cout<<"Doriti friptura? da/nu";
            in>>rasp;
            while(rasp!="da" && rasp!="nu")
            {
                cout<<"Raspundeti cu da sau nu";
                in>>rasp;
            }

            if(rasp=="da")
                throw rasp;

        }

        catch(string rasp)
        {
            x=new Friptura;
            in>>*x;
            nota=nota+x->get_pret();
            m.push_back(x);

            try
            {
                cout<<"Doriti garnitura? da/nu";
                in>>rasp;
                while(rasp!="da" && rasp!="nu")
                {
                    cout<<"Raspundeti cu da sau nu";
                    in>>rasp;
                }

                if(rasp=="da")
                    throw rasp;

            }

            catch(string rasp)
            {
                x=new Garnitura;
                in>>*x;
                nota=nota+x->get_pret();
                m.push_back(x);
            }
        }

        try
        {
            cout<<"Doriti desert? da/nu";
            in>>rasp;
            while(rasp!="da" && rasp!="nu")
            {
                cout<<"Raspundeti cu da sau nu";
                in>>rasp;
            }

            if(rasp=="da")
                throw rasp;

        }

        catch(string rasp)
        {
            x=new Desert;
            in>>*x;
            nota=nota+x->get_pret();
            m.push_back(x);
        }

    }

    void afisare(ostream& out)
    {
        out<<"Consumatia dvs. este :";
        vector<Mancare*>::iterator iter=m.begin();
        vector<Mancare*>::iterator x=m.end();
        for(; iter != x; iter++)
            out<<**iter;
        vector<Bautura*>::iterator iter2=b.begin();
        vector<Bautura*>::iterator x2=b.end();
        for(; iter2 != x2; iter2++)
            out<<**iter2;
        out<<endl<<"Total de plata: "<<nota;
    }

    friend istream& operator>>(istream& in,Client& c)
    {
        c.citire(in);
        return in;
    }

    friend ostream& operator<<(ostream& out,Client& c)
    {
        c.afisare(out);
        return out;
    }
};


class Masa
{
private:
    int ID;
    int nr_max;
    int nr_actual;
    Client* clienti;
public:
    friend class Client;
    friend class Restaurant;
    Masa(int ID=0,int nr_max=0,int nr_actual=0)
    {
        this->ID=ID;
        this->nr_max=nr_max;
        this->nr_actual=nr_actual;
        clienti=new Client[nr_actual];
    }

    Masa(const Masa& m)
    {
        delete[] clienti;
        this->nr_actual=nr_actual;
        this->nr_max=nr_max;
        this->ID=ID;
        for(int i=0;i<nr_actual;i++)
            clienti[i]=m.clienti[i];
    }

    Masa& operator=(const Masa& m)
    {
        delete[] clienti;
        this->nr_actual=nr_actual;
        this->nr_max=nr_max;
        this->ID=ID;
        for(int i=0;i<nr_actual;i++)
            clienti[i]=m.clienti[i];
        return *this;
    }

    int get_nr_clienti()
    {
        return nr_actual;
    }

    ~Masa()
    {
        delete[] clienti;
        this->nr_actual=0;
        this->ID=0;
        this->nr_max=0;
    }

    Client& operator[](int i)
    {
        return clienti[i];
    }

    void citire(istream& in)
    {
        cout<<"Nr. mesei: ";in>>ID;
        cout<<"Nr. maxim de persoane: ";in>>nr_max;
        cout<<"Nr. de persoane: ";in>>nr_actual;
        for(int i=0;i<nr_actual;i++)
        {
            cout<<"Clientul #"<<i+1<<":"<<endl;
            in>>clienti[i];
        }
    }

    void afisare(ostream& out)
    {
        out<<"Masa "<<ID<<" are "<<nr_actual<<"/"<<nr_max<<endl;
        for(int i=0;i<nr_actual;i++)
        {
            out<<"Clientul #"<<i+1<<":"<<endl;
            out<<clienti[i];
        }
    }

    friend istream& operator>>(istream& in, Masa& m)
    {
        m.citire(in);
        return in;
    }

    friend ostream& operator<<(ostream& out, Masa& m)
    {
        m.afisare(out);
        return out;
    }
};

class Restaurant
{
private:
    int nr_mese;
    Masa* mese;
public:
    friend class Client;
    friend class Masa;

    Restaurant(int nr_mese=0)
    {
        this->nr_mese=nr_mese;
        mese=new Masa[nr_mese];
    }

    Restaurant(const Restaurant& r)
    {
        delete[] mese;
        this->nr_mese=nr_mese;
        for(int i=0;i<nr_mese;i++)
            mese[i]=r.mese[i];
    }

    Restaurant& operator=(const Restaurant& r)
    {
        delete[] mese;
        this->nr_mese=nr_mese;
        for(int i=0;i<nr_mese;i++)
            mese[i]=r.mese[i];
        return *this;
    }

    ~Restaurant()
    {
        delete[] mese;
        this->nr_mese=0;
    }

    int get_nr_mese()
    {
        return nr_mese;
    }

    Masa& operator[](int i)
    {
        return mese[i];
    }

    void citire(istream& in)
    {
        cout<<"Nr. de mese: ";in>>nr_mese;
        for(int i=0;i<nr_mese;i++)
        {
            cout<<"Masa #"<<i+1<<":"<<endl;
            in>>mese[i];
        }
    }

    void afisare(ostream& out)
    {
        out<<"Restaurantul are "<<nr_mese<<" mese"<<endl;
        for(int i=0;i<nr_mese;i++)
        {
            out<<"Masa #"<<i+1<<":";
            out<<mese[i];
        }
    }

    friend istream& operator>>(istream& in, Restaurant& r)
    {
        r.citire(in);
        return in;
    }

    friend ostream& operator<<(ostream& out, Restaurant& r)
    {
        r.afisare(out);
        return out;
    }
};



int main()
{
    Restaurant r;
    int x,y;
    srand (time(NULL));
    for(;;)
    {
        cout<<"1. Cititi informatii despre restaurant, mese, clienti.\n";
        cout<<"2. Un client doreste sa plece. \n";
        cout<<"3. Toti clientii de la o masa doresc sa plece. \n";
        cout<<"4. Ora inchiderii. \n";

        cout<<"Selectati un numar intre 1 si 4: ";
        cin>>x;
        while(!(x<5 && x>0))
        {
            cout<<"Selectati un numar intre 1 si 4: ";
            cin>>x;
        }

        switch(x)
        {
            case 1:
                cin>>r;

                system("PAUSE");
                system("cls");

                break;

            case 2:
                y=rand()%r.get_nr_mese();
                x=rand()%r[y].get_nr_clienti();

                cout<<"Clientul "<<x<<"de la masa "<<y<<" doreste sa plece. Nota lui de plata este: "<<r[y][x];

                system("PAUSE");
                system("cls");
                break;

            case 3:
                y=rand()%r.get_nr_mese();

                cout<<"Clientii de la masa "<<y<<" doresc sa plece. Notele lor de plata sunt: ";
                cout<<r[y];

                system("PAUSE");
                system("cls");

                break;

            case 4:

                cout<<"Inchis.";
                return 0;
        }
    }
}
