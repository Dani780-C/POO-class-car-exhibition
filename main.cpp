#include <iostream>
#include <vector>
#include <string>
#include <typeinfo>

using namespace std;

class hot_hatch{
protected:
    string marca;
    string model;
    int an_fabricatie;
    double putere;
    double capacitate_cilindrica;
    double pret_standard;
    double investitie;
public:
    hot_hatch(){
        marca = "";
        model = "";
        an_fabricatie = 0;
        putere = 0;
        capacitate_cilindrica = 0;
        pret_standard = 0;
        investitie = 0;
    }
    hot_hatch(string marca, string model, int an, double pow, double cap, double pret, double invest){
        this->marca = marca;
        this->model = model;
        this->an_fabricatie = an;
        this->putere = pow;
        this->capacitate_cilindrica = cap;
        this->pret_standard = pret;
        this->investitie = invest;
    }
    ~hot_hatch(){
        this->marca = "";
        this->model = "";
        this->an_fabricatie = 0;
        this->putere = 0;
        this->capacitate_cilindrica = 0;
        this->pret_standard = 0;
        this->investitie = 0;
    }

    hot_hatch& operator= (const hot_hatch& c){
        this->marca = c.marca;
        this->model = c.model;
        this->an_fabricatie = c.an_fabricatie;
        this->putere = c.putere;
        this->capacitate_cilindrica = c.capacitate_cilindrica;
        this->pret_standard = c.pret_standard;
        this->investitie = c.investitie;
    }

    virtual void afisare(){
        cout<<this->marca<<'\n';
        cout<<this->model<<'\n';
        cout<<this->an_fabricatie<<'\n';
        cout<<this->putere<<'\n';
        cout<<this->capacitate_cilindrica<<'\n';
        cout<<this->pret_standard<<'\n';
        cout<<this->investitie<<'\n';
    }

    virtual void citire(){
        cin>>this->marca;
        cin>>this->model;
        cin>>this->an_fabricatie;
        cin>>this->putere;
        cin>>this->capacitate_cilindrica;
        cin>>this->pret_standard;
        cin>>this->investitie;
    }

    friend ostream& operator<< (ostream&,const hot_hatch&);
    friend istream& operator>> (istream&, hot_hatch&);
};

ostream& operator<< (ostream& out, const hot_hatch& c){
    out<<"\n ---------- Masina ---------\n"<<'\n';
    out<<"Marca: "<<c.marca<<'\n';
    out<<"Model: "<<c.model<<'\n';
    out<<"An: "<<c.an_fabricatie<<'\n';
    out<<"Putere: "<<c.putere<<'\n';
    out<<"Capacitate cilindrica: "<<c.capacitate_cilindrica<<'\n';
    out<<"Pret fabrica: "<<c.pret_standard<<'\n';
    out<<"Investitie: "<<c.investitie<<'\n';
    return out;
}

istream& operator>> (istream& in, hot_hatch& c){
    cout<<"\n --------- Cititi datele despre o masina ---------\n"<<'\n';
    cout<<"Marca: ";
    in>>c.marca;
    cout<<"Modelul: ";
    in>>c.model;
    cout<<"Anul de fabricatie: ";
    in>>c.an_fabricatie;
    cout<<"Putere(CP): ";
    in>>c.putere;
    cout<<"Capacitate cilindrica: ";
    in>>c.capacitate_cilindrica;
    cout<<"Pret de fabrica: ";
    in>>c.pret_standard;
    cout<<"Investitie: ";
    in>>c.investitie;
    return in;
}

class cabrio: public hot_hatch{
protected:
    string tip_plafon;
public:
    cabrio(){
        tip_plafon = "";
    }
    cabrio(string marca, string model, int an, double pow, double cap, double pret, double invest, string plaf):
    hot_hatch(marca,model,an,pow,cap,pret,invest){
        this->tip_plafon = plaf;
    }
    ~cabrio(){
        tip_plafon = "";
    }

    cabrio& operator= (const cabrio& c){
        hot_hatch::operator=(c);
        this->tip_plafon = c.tip_plafon;
    }

    virtual void afisare(){
        hot_hatch::afisare();
        cout<<this->tip_plafon<<'\n';
    }

    virtual void citire(){
        hot_hatch::citire();
        cin>>this->tip_plafon;
    }

    friend ostream& operator<< (ostream&,const cabrio&);
    friend istream& operator>> (istream&, cabrio&);
};

ostream& operator<< (ostream& out, const cabrio& c){
    out<<dynamic_cast<const hot_hatch&>(c);
    out<<"Tip plafon: "<<c.tip_plafon<<'\n';
    return out;
}

istream& operator>> (istream& in, cabrio& c){
    in>>dynamic_cast<hot_hatch&>(c);
    cout<<"Tipul plafonului(material textil sau metal): ";
    in>>c.tip_plafon;
    return in;
}

class supersport:public cabrio{
    double pret_vanzare;
public:
    supersport(){
        this->pret_vanzare = -1;
    }
    supersport(string marca, string model,int an, double pow, double cap, double pret, double invest, string plaf, double pret_vanzare = -1):
    cabrio(marca,model,an,pow,cap,pret,invest,plaf){
        this->pret_vanzare = pret_vanzare;
    }
    ~supersport(){
        this->pret_vanzare = -1;
    }

    supersport& operator= (const supersport& c){
        cabrio::operator=(c);
        this->pret_vanzare = c.pret_vanzare;
    }

    void afisare(){
        cabrio::afisare();
        cout<<this->pret_vanzare<<'\n';
    }

    void citire(){
        cabrio::citire();
        cin>>this->pret_vanzare;
    }

    const double get_pret_vanzare(){
        return this->pret_vanzare;
    }

    friend bool operator== (const supersport& a, const supersport& b){
        if(a.marca != b.marca) return false;
        if(a.model != b.model) return false;
        if(a.capacitate_cilindrica != b.capacitate_cilindrica) return false;
        if(a.an_fabricatie != b.an_fabricatie) return false;
        if(a.putere != b.putere) return false;
        if(a.investitie != b.investitie) return false;
        if(a.tip_plafon != b.tip_plafon) return false;
        if(a.pret_standard != b.pret_standard) return false;
        if(a.pret_vanzare != b.pret_vanzare) return false;
        return true;
    }

    friend ostream& operator<< (ostream&,const supersport&);
    friend istream& operator>> (istream&, supersport&);
};

ostream& operator<< (ostream& out,const supersport& c){
    out<<dynamic_cast<const cabrio&>(c);
    if(c.pret_vanzare == -1)
        out<<"Pretul de vanzare: masina nu se vinde"<<'\n';
    else out<<"Pretul de vanzare: "<<c.pret_vanzare<<'\n';
    return out;
}

istream& operator>> (istream& in, supersport& c){
    in>>dynamic_cast<cabrio&>(c);
    cout<<"Pretul de vanzare(-1 daca masina nu este de vanzare): ";
    in>>c.pret_vanzare;
    return in;
}

template <typename type>
class Expozitie{
    vector<type> masini;
    int numar_masini;
    static int numar_expozitii;
public:
    Expozitie(){
        masini.reserve(1000);
        numar_masini = 0;
        numar_expozitii++;
    }

    ~Expozitie(){
        masini.clear();
    }

    Expozitie& operator= (const Expozitie<type>& expo){
        for(int i=0;i<expo.numar_masini;i++){
            masini.push_back(expo.masini[i]);
        }
        numar_masini = expo.numar_masini;
    }

    int get_numar_masini(){
        return numar_masini;
    }

    void listare(type& d){
        masini.push_back(d);
        numar_masini++;
    }

    void afisare(){
        for(int i=0;i<numar_masini;i++){
            cout<<masini[i]<<'\n';
        }
    }

    friend ostream& operator<< (ostream& out, const Expozitie<type>& expo){
        string nume = typeid(expo).name();
        if(nume == "9ExpozitieI9hot_hatchE") out<<"\n>>> Numarul de masini hot hatch este "<<expo.numar_masini<<'\n';
        else out<<"\n>>> Numarul de masini cabrio este "<<expo.numar_masini<<'\n';
        for(int i=0;i<expo.numar_masini;i++){
            out<<expo.masini[i];
        }
        return out;
    }

    friend istream& operator>> (istream& in, Expozitie<type>& expo){
        cout<<">>> Numarul de masini ";
        string nume = typeid(expo).name();
        if(nume == "9ExpozitieI9hot_hatchE") cout<<"hot hatch este: ";
        else cout<<"cabrio este: ";
        in>>expo.numar_masini;
        for(int i=0;i<expo.numar_masini;i++){
            type a;
            in>>a;
            expo.masini.push_back(a);
        }
        return in;
    }
};

template <typename type>
int Expozitie<type>::numar_expozitii = 0;

template<>
class Expozitie<supersport>{
    vector<supersport*> masini_vandute;
    vector<supersport*> masini_expuse;
    int numar_masini_expuse;
    int numar_masini_vandute;
    static int numar_expozitii_supersport;
public:
    Expozitie(){
        masini_vandute.reserve(1000);
        masini_expuse.reserve(1000);
        numar_masini_expuse = 0;
        numar_masini_vandute = 0;
        numar_expozitii_supersport++;
    }

    ~Expozitie(){
        for(int i = 0; i<numar_masini_expuse; i++){
            delete masini_expuse[i];
        }
        for(int i = 0; i<numar_masini_vandute; i++){
            delete masini_vandute[i];
        }
        masini_vandute.clear();
        masini_expuse.clear();
        numar_masini_expuse = 0;
        numar_masini_vandute = 0;
    }

    Expozitie& operator= (const Expozitie<supersport>& expo){
        this->numar_masini_expuse = expo.numar_masini_expuse;
        this->numar_masini_vandute = expo.numar_masini_vandute;
        for(int i=0;i<expo.numar_masini_expuse;i++){
            supersport *a = new supersport{};
            *a = *expo.masini_expuse[i];
            masini_expuse.push_back(a);
        }
        for(int i=0;i<expo.numar_masini_vandute;i++){
            masini_vandute[i] = expo.masini_vandute[i];
            supersport *a = new supersport{};
            *a = *expo.masini_vandute[i];
            masini_vandute.push_back(a);
        }
    }

    int get_numar_masini_expuse(){
        return this->numar_masini_expuse;
    }

    int get_numar_masini_vandute(){
        return this->numar_masini_vandute;
    }

    void set_numar_masini_expuse(int n){
        this->numar_masini_expuse = n;
    }

    static int get_numar_expozitii_supersport(){
        return numar_expozitii_supersport;
    }

    void listare(supersport& d){
        masini_expuse.push_back(&d);
        numar_masini_expuse++;
    }

    supersport* vanzare_cumparare(){
        bool verif = false;
        bool v[1000] = {};
        for(int i=0;i<numar_masini_expuse;i++){
            if((*masini_expuse[i]).get_pret_vanzare() != -1){
                cout<<"\nCod de cumparare: ----------------------- cod "<<i;
                cout<<*masini_expuse[i];
                verif = true;
                v[i] = 1;
            }
        }
        if(verif == false){
            cout<<"\nNu a fost gasita nicio masina super sport de vanzare!\n";
            return nullptr;
        }
        else{
            cout<<"\nCiteste codul de cumparare: ";
            int cod;
            cin>>cod;
            if(v[cod] == 1)
                return masini_expuse[cod];
            else{
                return nullptr;
            }
        }
    }

    void afisare_masini_expuse(){
        for(int i=0;i<numar_masini_expuse;i++){
            cout<<*masini_expuse[i]<<endl;
        }
    }

    void afisare_masini_vandute(){
        for(int i=0;i<numar_masini_vandute;i++){
            cout<<*masini_vandute[i]<<endl;
        }
    }

    void afisare_masini_de_vanzare(){
        bool verif = false;
        for(int i=0;i<numar_masini_expuse;i++){
            if((*masini_expuse[i]).get_pret_vanzare() != -1){
                cout<<*masini_expuse[i];
                verif = true;
            }
        }
        if(verif == false){
            cout<<"\nNu a fost gasita nicio masina super sport de vanzare!\n";
        }
    }

    Expozitie& operator-= (supersport& a){
        masini_vandute.push_back(&a);
        numar_masini_vandute++;
        vector<supersport*>::iterator it;
        for(auto it=masini_expuse.begin();it!=masini_expuse.end();it++){
            if(*it == &a){
                masini_expuse.erase(it);
                break;
            }
        }
        numar_masini_expuse--;
    }

    int numara_masini_de_vanzare(){
        int nr = 0;
        for(int i=0;i<numar_masini_expuse;i++)
            if((*masini_expuse[i]).get_pret_vanzare() != -1)
                nr++;
        return nr++;
    }

    friend ostream& operator<< (ostream& out, const Expozitie<supersport>& expo){
        out<<"\n>>> Numarul de masini super sport este "<<expo.numar_masini_expuse<<'\n';
        for(int i=0;i<expo.numar_masini_expuse;i++){
            out<<*expo.masini_expuse[i];
        }
        return out;
    }

    friend istream& operator>> (istream& in, Expozitie<supersport>& expo){
        cout<<">>> Numarul de masini super sport este: ";
        in>>expo.numar_masini_expuse;
        for(int i=0;i<expo.numar_masini_expuse;i++){
            supersport* a = new supersport{};
            in>>*a;
            expo.masini_expuse.push_back(a);
        }
        return in;
    }
};

template<>
int Expozitie<supersport>::numar_expozitii_supersport = 0;

void meniu1(){
    cout<<" *cod 1 - Creeaza-ti propria expozitie.\n";
    cout<<" *cod 2 - Admira expozitia mea.\n";
}

void meniu2(){
    cout<<'\n';
    cout<<" *cod 1 - Afiseaza expozitia de masini hot hatch-uri.\n";
    cout<<" *cod 2 - Afiseaza expozitia de masini cabrio.\n";
    cout<<" *cod 3 - Afiseaza expozitia de masini super sport.\n";
    cout<<" *cod 4 - Afiseaza expozitia mixta.\n";
    cout<<" *cod 5 - Afiseaza masinile super sport care pot fi cumparate.\n";
    cout<<" *cod 6 - Cumpara o masina supersport.\n";
    cout<<" *cod 0 - Paraseste expozitia.\n";
}

void meniu3(){
    cout<<'\n';
    cout<<" *cod 1 - Creeaza expozitie de masini hot hatch.\n";
    cout<<" *cod 2 - Creeaza expozitie de masini cabrio.\n";
    cout<<" *cod 3 - Creeaza expozitie de masini super sport.\n";
    cout<<" *cod 4 - Creeaza expozitie mixta.\n";
}

int main(){

    meniu1();
    int optiune0,optiune;
    cout<<"\nCiteste optiunea: ";
    cin>>optiune0;
    Expozitie<hot_hatch> expo_hh;
    Expozitie<cabrio> expo_cabrio;
    Expozitie<supersport> expo_ss;
    int run = 1;
    while(run){
        switch(optiune0){
            case 2:{
                hot_hatch a1("Renault","5 Turbo",1982,312,2000,89700,19500);
                expo_hh.listare(a1);
                hot_hatch a2("Ford","Escort RS",1996,450,3000,56000,23400);
                expo_hh.listare(a2);
                hot_hatch a3("Mini Cooper","S",2000,340,2200,34000,12000);
                expo_hh.listare(a3);
                hot_hatch a4("Subaru","WRX  STI",2007,315,2700,56000,7000);
                expo_hh.listare(a4);
                hot_hatch a5("Mitsubishi","Evolution X",2002,600,5000,78000,17500);
                expo_hh.listare(a5);
                cabrio b1("Audi","A5 S-line TFSI",2019,234,3000,23000,3000,"textil");
                expo_cabrio.listare(b1);
                cabrio b2("Mercedes-Benz","SL Coupe",2020,311,4000,56000,6000,"metal");
                expo_cabrio.listare(b2);
                cabrio b3("BMW","Seria 2",2018,290,3000,51000,4500,"textil");
                expo_cabrio.listare(b3);
                cabrio b4("Ford","Mustang",2021,512,3000,61000,5600,"metal");
                expo_cabrio.listare(b4);
                cabrio b5("Porsche","911 Carrera",2017,459,2700,90000,12400,"metal");
                expo_cabrio.listare(b5);
                supersport *c1 = new supersport{"Aston Martin","DB8 GT",2020,750,2700,120000,12400,"metal",-1};
                expo_ss.listare(*c1);
                supersport *c2 = new supersport{"McLaren","F1",2021,780,6000,4500000,1000000,"metal",6500000};
                expo_ss.listare(*c2);
                supersport *c3 = new supersport{"Bugatti","Veyron 16.4",2020,1120,8000,7000000,2300000,"metal",-1};
                expo_ss.listare(*c3);
                supersport *c4 = new supersport{"Ferrari","F40",2013,912,6000,1500000,700000,"metal",3200000};
                expo_ss.listare(*c4);
                supersport *c5 = new supersport{"Lamborghini","Miura P400SV",1967,300,4000,5000000,2000000,"metal",9000000};
                expo_ss.listare(*c5);
                optiune = -1;
                run--;
                break;
            }
            case 1:{
                meniu3();
                cout<<"\nCiteste optiunea: ";
                cin>>optiune;
                cout<<'\n';
                switch(optiune){
                    case 1:{
                        cin>>expo_hh;
                        cout<<"\nExpozitia de masini hot hatch a fost creata!\n";
                        break;
                    }
                    case 2:{
                        cin>>expo_cabrio;
                        cout<<"\nExpozitia de masini cabrio a fost creata!\n";
                        break;
                    }
                    case 3:{
                        cin>>expo_ss;
                        cout<<"\nExpozitia de masini super sport a fost creata!\n";
                        break;
                    }
                    case 4:{
                        cin>>expo_hh;
                        cout<<'\n';
                        cin>>expo_cabrio;
                        cout<<'\n';
                        cin>>expo_ss;
                        cout<<'\n';
                        cout<<"\nExpozitia mixta a fost creata!\n";
                        break;
                    }
                    default:{
                        break;
                    }
                }
                run--;
                break;
            }
            default:{
                while(optiune0!=1 and optiune0!=2){
                    cout<<"Citeste optiune corecta(1/2): ";
                    cin>>optiune0;
                }
                break;
            }
        }
    }
    meniu2();
    int optiune1;
    cout<<"\nCiteste optiunea: ";
    cin>>optiune1;
    int test = 1;
    while(optiune1){
        switch(optiune1){
            case 1:{
                if(optiune == 1 or optiune == -1){
                    cout<<expo_hh;
                }
                else{
                    cout<<"\nNu exista nicio expozitie de masini hot hatch!\n";
                }
                break;
            }
            case 2:{
                if(optiune == 2 or optiune == -1){
                    cout<<expo_cabrio;
                }
                else{
                    cout<<"\nNu exista nicio expozitie de masini cabrio!\n";
                }
                break;
            }
            case 3:{
                if(optiune == 3 or optiune == -1){
                    cout<<expo_ss;
                }
                else{
                    cout<<"\nNu exista nicio expozitie de masini super sport!\n";
                }
                break;
            }
            case 4:{
                if(optiune == 4 or optiune == -1){
                    cout<<expo_hh;
                    cout<<expo_cabrio;
                    cout<<expo_ss;
                }
                else{
                    if(optiune == 1) cout<<expo_hh;
                    else if(optiune == 2) cout<<expo_cabrio;
                        else if(optiune == 3) cout<<expo_ss;
                }
                break;
            }
            case 5:{
                if(optiune == 3 or optiune == 4 or optiune == -1){
                     expo_ss.afisare_masini_de_vanzare();
                }
                else{
                    cout<<"\nNu exista masini super sport de vanzare!\n";
                }
                break;
            }
            case 6:{
                if(optiune == 3 or optiune == 4 or optiune == -1){
                    supersport *ptr = expo_ss.vanzare_cumparare();
                    if(ptr != nullptr){
                        expo_ss -= *ptr;
                        cout<<"\nVanzare incheiata cu succes!\n";
                    }
                    else if(expo_ss.numara_masini_de_vanzare()>0){
                        cout<<"\n ~~~ ! Codul de cumparare nu apartine niciunei masini cu oferta de vanzare ! ~~~ \n";
                    }
                }
                else{
                    cout<<"\nNu exista masini super sport de vanzare!\n";
                }
                break;
            }
            case 0:{
                optiune1 = 0;
                break;
            }
            default:{
                cout<<"Citeste optiune valida: ";
                cin>>optiune1;
                test = 0;
                break;
            }
        }
        if(test){
            meniu2();
            cout<<"\nCiteste optiunea: ";
            cin>>optiune1;
        }
        test = 1;
    }
    return 0;
}
