#include <stdint.h>
#include <bitset>
#include <iostream>
#include <cmath>
using namespace std;

int main() {

//Implementar los mapeos caóticos para generar números aleatorios entre [0,1]

// Regla 30
    uint64_t state = 1ULL << 31;
    uint32_t num_aleatorio = 0;
    cout << "Semilla: " << state << "\n";
    for (int i = 0; i < 32; ++i) {
        
        for (int j = 64; j--;) {
            cout << char(state >> j & 1 ? 'O' : '.');
        }
        cout << "  " << state % 10000 << '\n';
        state = (state >> 1) ^ (state | state << 1);
        int holder = (state >> 31) & 1;
        num_aleatorio = (num_aleatorio << 1) | (holder);
    }
    cout << "\n";
    cout <<"Generamos un número aleatorio a partir de la columna central, este es: "<< num_aleatorio<<"\n";
    double holder2 = (double) num_aleatorio/(1LL << 32);
    cout << "Reescalando el mismo número al intervalo [0,1] obtenemos;"<< holder2 <<"\n";
    cout << "\n";
    
//Mapeo Tienda de Campaña

    cout << "Ahora generemos números pseudoaletorios (entre [0,1]) con el Método del Mapeo Tienda de Campaña"<<"\n";

    double miu = 2;
    double x =  0.78539816; // se utiliza un número complejo para evitar ciclicidad de los números, en este caso
                            // se utilizo Pi/4 (normalizado entre [0, 1]) aproximado a 8 cifras significativas.
    for(int i = 0; i<10; i++) {
        if (x < 0.5) {
            x = miu *x;
        }
        else {
            x = miu*(1 - x);
        }

        cout << x << "\n";
    }
    cout << "\n";

 

//Mapeo Logístico.
//Este es el método al que le realizaremos el análisis estadístico
    
    double k = 1000;
    cout << "Ahora generemos "<< k <<" números pseudoaletorios (entre [0,1]) con el Método del mapeo estadístico"<<"\n";
    
    const int kh = k;
    double r = 4;
    double seed =  0.8;
    cout <<"Semilla:" << seed <<"\n";
    double num[kh];
    double sum=0;
    

    for (int i =0; i<k; ++i) {
        
        seed = seed*r*(1-seed);
        num[i] = seed;
        //cout << num[i]<<"\n";
        
        sum += num[i];
        
    }
    //Análisis estadistico
    //Media:
    double media= sum/ double(k);
    cout << "\n";
    cout << "La media es: "<< media<< "\n";
    //Varianza:
    double sum1=0;
    for(int i = 0; i<k; i++){
        sum1 += (num[i]- media) * (num[i] - media);
    }

    double varianza = sum1/k;

    cout << "La varianza es: "<< varianza<< "\n";

    //Asímetria estadística
    
    double sum2 =0;

    for(int i = 0; i<k; i++){
        sum2 += (num[i]- media) * (num[i] - media) * (num[i]- media) ; 
    }
    
    double asimetria = (1.0/k) * (sum2/(pow(varianza, 1.5)));

    cout << "La asímteria  estadística es: "<< asimetria<< "\n";




    


return 0;

}