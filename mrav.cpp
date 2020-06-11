#include<iostream>
#include <math.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

class Mrav{
private:
    int pozicija, prethodnaPozicija;
    bool uzeoHranu;
    int redniBroj;
    int P[4][4];            //kopija matrice vjerovatnoca prelaza iz cvora u cvor
public:
    Mrav():pozicija(0), redniBroj(0), uzeoHranu(false){}

    Mrav(int (&matrica)[4][4], int i):pozicija(0), uzeoHranu(false){
        redniBroj = i;
        cout<<"Napravljen mrav, redni broj: "<<redniBroj<<endl;
    }

    int getPozicija(){
        return this->pozicija;
    }

    void setPozicija(int p){
        this->pozicija = p;
    }

    void setPrethodnaPozicija(int p){
        this->prethodnaPozicija = p;
    }

     int getPrethodnaPozicija(){
        return this->prethodnaPozicija;
    }

    void uzmiHranu(){
        this->uzeoHranu=true;
        cout<<"Mrav je uzeo hranu i vraca se prema 0-tom cvoru."<<endl;

    }

     int* napraviKorak(int (&matrica)[4][4]){
        int povratnaVrijednost[2];          //niz u koji se smijestaju povratne vrijednosti

        for(int i = 0; i < 2; i++){
            povratnaVrijednost[i] = 0;          //inicijalizacija
        }

         //prepisivanje trenutne matrice vjerovatnoca
        for(int i = 0; i < 4; i++){
             for(int j = 0; j < 4; j++){
                P[i][j] = matrica[i][j];
             }
        }

        cout<<"Matrica vjerovatnoca prije azuriranja:"<<endl;

        cout<<" (0)---"<<P[0][1]<<"---(1) "<<endl;
        cout<<" | \\       / | "<<endl;
        cout<<" |  \\     /  | "<<endl;
        cout<<" |   "<<P[0][3]<<"   " <<P[1][2]<<"  | "<<endl;
        cout<<" "<<P[0][2]<<"    \\ /    "<<P[1][3]<<" "<<endl;
        cout<<" |     \\     | "<<endl;
        cout<<" |    / \\    | "<<endl;
        cout<<" |   /   \\   | "<<endl;
        cout<<" |  /     \\  | "<<endl;
        cout<<" (2)---"<<P[2][3]<<"---(3) "<<endl;
        cout<<"***************************************************************"<<endl;

        double Pmax = 0;         // trazenje najvece vjerovatnoce u toj vrsti

        int trenutnaPozicija = this->getPozicija();   //vrsta za trazenje maksimuma

        int sljedecaPozicija = 0;       //indeks vrste u koju ce mrav preci

        for(int indMax = 0; indMax < 4; indMax++){
            if(trenutnaPozicija == 3){
                if(P[trenutnaPozicija][indMax] > Pmax){
                    Pmax = P[trenutnaPozicija][indMax];
                    sljedecaPozicija = indMax;
                }
            } else {
                if(P[trenutnaPozicija][indMax] > Pmax && indMax != this->prethodnaPozicija){
                    Pmax = P[trenutnaPozicija][indMax];
                    sljedecaPozicija = indMax;
                }
            }
        }

        povratnaVrijednost[0] = trenutnaPozicija;

        povratnaVrijednost[1] = sljedecaPozicija;

        cout<<"Mrav osjeti najvisi nivo feromona na ["<<trenutnaPozicija<<"]["<<sljedecaPozicija<< "] putanji."<<endl;

        if(this->getPozicija() == 3){
            this->uzmiHranu();
        }

        this->setPrethodnaPozicija(trenutnaPozicija);       //pamcenje

        this->setPozicija(sljedecaPozicija);            //prelazak na cvor do kog je najvise feromona

        cout<<"Sljedeca pozicija mrava: "<<sljedecaPozicija<<endl;

        return povratnaVrijednost;

     }

};
