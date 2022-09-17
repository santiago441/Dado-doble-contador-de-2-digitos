#include "mbed.h"

DigitalIn btn_1(A1);
DigitalIn btn_2(A2);
DigitalIn btn_3(BUTTON1);

BusOut Segmentos(D2,D3,D4,D5,D6,D7,D8,D9); // pines segmentos A B C D E F G DP
BusOut Display(A4,A3);

const char secuencia[6] = {0xFE, 0xFD, 0xFB, 0xF7, 0xEF, 0xDF}; // A B C D E F
const char numeros[6] = {0xF9,  0xB0, 0xA4, 0x99, 0x92, 0x82}; // 1 2 3 4 5 6

char num_1; 
char num_2; 

void Efecto(void);
void visualizar(void);
void random(void);

int main(){  

    while(true){

        }

    }

}

void visualizar(void){

    bool flag;

    while(true){

        if(flag){

            Display = 0b01;
            Segmentos = numeros[num_1];
        }
        else{

            Display = 0b10;
            Segmentos = numeros[num_2];
        }

        flag = !flag;
        ThisThread::sleep_for(11ms);
    }
}
