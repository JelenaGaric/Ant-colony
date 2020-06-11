#include "Mrav.cpp"

class Menadzer{
private:
    Mrav m;
    int P[4][4];
public:
    Menadzer(){
        for(int i = 0; i < 4; i ++){
            for(int j = 0; j < 4; j++){
                P[i][j] = 0;
            }
        }
        for(int i = 0; i < 4; i ++){
            for(int j = 0; j < 4; j++){
                if(i == j){
                    P[i][j] = -1;
                } else {
                    if(P[i][j]==0){
                        P[i][j] = 1+(rand() % 19);
                        P[j][i] = P[i][j];
                        }
                    }
                }
            }

            Mrav m(P, 0);
    }

    void ostaviTrag(int trenutnaPozicija, int sljedecaPozicija){
        this->P[trenutnaPozicija][sljedecaPozicija]++;
    }

    azuriraj(){
        for(int i = 0; i < 5; i++){
        do{
            int *pozicije = m.napraviKorak(P);
         // int trenutnaPozicija = pozicije[0];
           // int sljedecaPozicija = pozicije[1];
            // cout<<trenutnaPozicija<<" ****************** "<<sljedecaPozicija<<endl;
           // ostaviTrag(trenutnaPozicija, sljedecaPozicija);
           cout<<pozicije[0]<<endl;
        }while(m.getPrethodnaPozicija()!=3);
        do{
            int *pozicije = m.napraviKorak(P);
        }while(m.getPozicija()!=0);
        if(m.getPozicija()==0){
            //cout<<"Mrav "<<i<<" je zavrsio svoju putanju."<<endl;
            cout<<"Mrav je "<<i<<" zavrsio svoju putanju."<<endl;
        }
        }
    }
};
