#include <iostream>
#include <cmath>
#include <numeric>
using namespace std;

int main() {

//Primer inciso generar la seguncia M=9, c=1, r=3 y a = 4 por el método lineal congruente.
    int c = 1;
    int r =3;
    int M = 9;
    int a = 4;

    cout << "Secuencia r_i:" << endl;

    for(int i = 0; i <M; i++) {

        cout << r << endl;

        r = (a*r + c)% M;

    }
    
    cout << endl;
    cout << "Secuencia normalizada x_i:" << endl;

    
////////Normalizando 0 <= r_i <= 1///////
    r = 3;

    double x[M];

    for(int i = 0; i<M; i++) {

        x[i] = (double) r/M;

        cout << x[i] << endl;

        r = (r*a + c)% M;

    }
    

//Segundo Inciso reescalar la secuencia al intervalo [A,B].
    cout << endl;
    cout << "Sencuencia reescalada al intervalo [A,B];" << endl;
    r = 3;

    for(int i = 0; i<M; i++) {

        double y = (double) 10 + (20 - 10)*x[i];

        cout << y << endl;
    }

    cout << endl;

//Tercero escribir una secuencia lo más grande posible.
// Haciendo uso de la tecnica bit shitf en vez de la libre cmath
//para evitar posibles errores de redondeo
// de acuerdo a la formula (x << n) = x⋅2n
//Los parametros son decididos a partir de las condiciones de Hull-Dobell para
//maximizar el periodo de un generador congruencial lineal

    long long r2 = 1;
    long long a2 = 1103515245;
    long long c2 = 12345;
    long long M2 = 1LL << 31; // 2147483648
    long long semilla = r2;
    long long contador = 0;

    cout <<"Secuencia lo más grande posible:"<<endl;
    cout <<"Eligiendo el Modulo(M) más grande posible en número LONGLONG"<<endl;
    cout <<"verifiquemos condiciones de Hull-Dobell"<<endl;
    
    cout <<"condición 1; c y M no deben compartir factores(exceptuando el 1)"<<endl;
    if (gcd(c2, M2) == 1) {
        cout<<"condición 1 cumplida"<<endl;
    }
    else
        cout<<"condición 3 no cumplida"<<endl;



    cout <<"condición 2; (a-1) debe ser divisible por cada factor primo de M( en este caso unicamente es el dos)"<<endl;
    if ((a2 -1)% 2 == 0) {
        cout<<"condición 2 cumplida"<<endl;
    }
    else
        cout<<"condición 2 no cumplida"<<endl;

    cout <<"condición 3; Sí M es divisible entre 4 entonces (a-1) es divisible entro 4"<<endl;
    if (M2 % 4 == 0){
        if ((a2-1) % 4 == 0)
            cout<<"condición 3 cumplida"<<endl;
        else
            cout<<"condición 3 no cumplida"<<endl;
    }
    else 
        cout<<"condición 3 cumplida"<<endl;

    
    do {
        r2 = (r2*a2 + c2)% M2;

        contador++;

    }while (contador<M2 && r2 != semilla);
    
   cout << "Periodo obtenido: " << contador << endl;




return 0;
}