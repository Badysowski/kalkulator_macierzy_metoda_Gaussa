#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

void eliminacja(double **tab, int n, bool zamiana);
void usun_tab(double **tab, int n);
void wyswietl(double **tab, int n);
void wprowadz1(double **tab);
void wprowadz2(double **tab);
void wprowadz3(double **tab);
void wprowadz(double **tab, int n);
int *maksymalny_element(double **tab, int n, int krok);
void wybor(bool zamiana);


int main(){

    int x;
    cout << "Wybierz metode: " << endl;
    cout << "1 - algorytm podstawowy" << endl;
    cout << "2 - algorytm z wyborem najwiekszego elementu w kolumnie" << endl;
    cout << "3 - wyjdz z programu" << endl;
    cout << endl;
    cin >> x;

    while(x != 3){
        switch(x){
        case 1:{
            cout << endl;
            cout << "Wybrales metode numer 1" << endl;
            wybor(false);
        }break;

        case 2:{
            cout << endl;
            cout << "Wybrales metode numer 2" << endl;
            wybor(true);
        }break;

        default:{
            cout <<endl;
            cout << "Nieprawidlowy numer" << endl;
        }break;
        }
        cout << endl;
        cout << "Wybierz metode: " << endl;
        cout << "1 - algorytm podstawowy" << endl;
        cout << "2 - algorytm z wyborem najwiekszego elementu w kolumnie" << endl;
        cout << "3 - wyjdz z programu" << endl;
        cout << endl;
        cin >> x;
    }
    return 0;
}
void eliminacja(double **tab, int n, bool zamiana){
    double r;
    double e = 1e-7;
    int s;
    bool przelacznik = true;
    if(zamiana){
        for(int i=0; i<n; i++){
            s = 0;
            for(int j=0; j<n; j++){
                if(abs(tab[j][i]) <= e )
                    s += 1;
            }
        if(s==n){
            cout << "Co najmniej jedna kolumna sklada sie z samych zer! Nie da sie wykonac algorytmu ta metoda!" << endl;
            przelacznik = false;
            break;
        }
        }
    }
    for (int k=0; k<n-1; k++){
        if(zamiana){
            int *a = new int[2];
            a = maksymalny_element(tab,n,k);
            swap(tab[k], tab[a[0]]);
        }

        if(abs(tab[k][k]) <= e){
            if(!zamiana){
                cout << "Na przekatnej wystepuje zero! Nie mozna obliczyc metoda podstawowa!" << endl;
                przelacznik = false;
                break;
            }
        }
        else{
            for (int i=k+1; i<n; i++){
                r=tab[i][k]/tab[k][k];
                tab[i][k]=0;
                for (int j=k+1; j<=n+1; j++)
                    tab[i][j]=tab[i][j]-r*tab[k][j];
            }
        }
    }

    if(przelacznik){
        cout << "Obliczona macierz trojkatna: " << endl;
        wyswietl(tab, n);
        cout << endl;

        double x[n];
        x[n-1] = tab[n-1][n] / tab[n-1][n-1];

        for (int i = n-2; i>=0; i--){
        double suma=0.0;
        for (int j=i+1; j<n; j++)
            suma += tab[i][j] * x[j];
        x[i]=(tab[i][n]-suma)/tab[i][i];
        if(abs(x[i])<= e)
            x[i] = 0;
        }

        cout << "Wynik: " << endl;
        for(int i=0; i<n; i++){
            cout << "x" << i+1 << " = " << x[i] << endl;
        }
    }
}

void wyswietl(double **tab, int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n+1; j++){
            cout << tab[i][j] << " ";
        }
        cout << endl;
    }
}
void wprowadz1(double **tab){
    tab[0][0] = 1;
    tab[0][1] = 1;
    tab[0][2] = 0;
    tab[0][3] = -3;
    tab[0][4] = 1;
    tab[1][0] = 1;
    tab[1][1] = 4;
    tab[1][2] = -1;
    tab[1][3] = -4;
    tab[1][4] = -2;
    tab[2][0] = 0.5;
    tab[2][1] = 0.5;
    tab[2][2] = -3;
    tab[2][3] = -5.5;
    tab[2][4] = 1.5;
    tab[3][0] = 1.5;
    tab[3][1] = 3;
    tab[3][2] = -5;
    tab[3][3] = -9;
    tab[3][4] = -0.5;
}

void wprowadz2(double **tab){
    tab[0][0] = 1;
    tab[0][1] = 2;
    tab[0][2] = -1;
    tab[0][3] = 2;
    tab[0][4] = 0;
    tab[1][0] = 1;
    tab[1][1] = 0;
    tab[1][2] = -2;
    tab[1][3] = 4;
    tab[1][4] = 4;
    tab[2][0] = 0;
    tab[2][1] = -3;
    tab[2][2] = 1.5;
    tab[2][3] = 7;
    tab[2][4] = 0;
    tab[3][0] = 0;
    tab[3][1] = -1;
    tab[3][2] = 1;
    tab[3][3] = 6;
    tab[3][4] = -1;
}

void wprowadz3(double **tab){
    tab[0][0] = 14;
    tab[0][1] = -13;
    tab[0][2] = 3;
    tab[0][3] = -16;
    tab[0][4] = -42;
    tab[0][5] = -37;
    tab[1][0] = 3.5;
    tab[1][1] = -18;
    tab[1][2] = 13;
    tab[1][3] = -23.75;
    tab[1][4] = -21;
    tab[1][5] = -5.5;
    tab[2][0] = 3.5;
    tab[2][1] = 3;
    tab[2][2] = -5.25;
    tab[2][3] = 9.25;
    tab[2][4] = 10.5;
    tab[2][5] = 12.5;
    tab[3][0] = 2;
    tab[3][1] = 14.5;
    tab[3][2] = -10.5;
    tab[3][3] = 18.5;
    tab[3][4] = 21;
    tab[3][5] = 23.5;
    tab[4][0] = 1.5;
    tab[4][1] = 6.75;
    tab[4][2] = -9.25;
    tab[4][3] = 17;
    tab[4][4] = -10.5;
    tab[4][5] = -45.25;
}

void wprowadz(double **tab, int n){
    double x;
    for(int i=0; i<n; i++){
        cout << endl;
        cout << "Wprowadz wartosci " << i+1 << " wiersza" << endl;
        for(int j=0; j<n+1; j++){
            cout << "Podaj " << j+1 << " wartosc: ";
            cin >> x;
            tab[i][j] = x;
        }
    }
    cout << endl;
}

void usun_tab(double **tab, int n){
    for ( int i=0; i < n; ++i )
        delete [] tab[i];
    delete [] tab;
    tab = NULL;
}

void wybor(bool zamiana){
    cout << endl;
    cout << "Wpisz odpowiedni numer, aby wybrac akcje:" << endl;
    cout << "1 - przetestuj program dla danych podanych w skrypcie" << endl;
    cout << "2 - przetestuj program dla recznie wpisanych danych" << endl;
    cout << "3 - cofnij do wyboru metody" << endl;
    cout << endl;
    int x;
    cin >> x;
    while(x != 3){
        switch(x){
        case 1:{
            cout <<endl;
            cout << "Wybrales opcje numer 1" << endl;

            int wiersze, y;
            bool sprawdz = true;

            cout << endl;
            cout << "Wybierz zestaw danych (1, 2 lub 3): ";
            cin >> y;
            while(sprawdz){
                switch(y){
                    case 1:{
                        wiersze = 4;
                        sprawdz = false;
                    }break;
                    case 2:{
                        wiersze = 4;
                        sprawdz = false;
                    }break;
                    case 3:{
                        wiersze = 5;
                        sprawdz = false;
                    }break;
                    default:{
                        cout << endl;
                        cout << "Nieprawidlowy numer, podaj poprawny: ";
                        cin >> y;
                    }break;
                }
            }
            double **tab = new double *[wiersze];
            for ( int i = 0; i < wiersze; ++i )
                tab[i] = new double [wiersze+1];

            if(y == 1)
                wprowadz1(tab);
            else if(y == 2)
                wprowadz2(tab);
            else
                wprowadz3(tab);

            cout << endl;
            cout << "Wczytane dane: " << endl;
            wyswietl(tab,wiersze);
            cout << endl;
            eliminacja(tab, wiersze, zamiana);
            usun_tab(tab, wiersze);
        }break;

        case 2:{
            cout <<endl;
            cout << "Wybrales opcje numer 2" << endl;
            cout << endl;
            int n;
            cout << "Podaj liczbe wierszy: ";
            cin >> n;
            if(n<=0){
                cout << "blad" << endl;
            }
            else{
            double **tab = new double *[n];
            for ( int i = 0; i < n; ++i )
                tab[i] = new double [n+1];

            wprowadz(tab, n);
            cout << "Wczytane dane: " << endl;
            wyswietl(tab,n);
            cout << endl;
            eliminacja(tab, n, zamiana);
            usun_tab(tab, n);
            }

        }break;

        default:{
            cout <<endl;
            cout << "Nieprawidlowy numer" << endl;
        }break;
        }
        cout << endl;
        cout << "Wpisz odpowiedni numer, aby wybrac akcje:" << endl;
        cout << "1 - przetestuj program dla danych podanych w skrypcie" << endl;
        cout << "2 - przetestuj program dla recznie wpisanych danych" << endl;
        cout << "3 - cofnij do wyboru metody" << endl;
        cout << endl;
        cin >> x;
    }
}

int *maksymalny_element(double **tab, int n, int krok){
    int *a = new int[2];
    a[0] = krok;
    a[1] = krok;
    for ( int i = krok; i<n; i++ ){
        if (abs(tab[i][krok]) > abs(tab[a[0]][a[1]])){
                a[0] = i;
                a[1] = krok;
        }
    }
    return a;
}
