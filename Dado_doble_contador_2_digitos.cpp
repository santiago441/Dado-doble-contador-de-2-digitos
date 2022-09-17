#include "mbed.h"

DigitalIn btn_1(A1);
DigitalIn btn_2(A2);
DigitalOut led_verde(A0);
DigitalOut led_rojo(A5);

BusOut Segmentos(D2,D3,D4,D5,D6,D7,D8,D9); 
BusOut Display(A4,A3);

const char numeros[7] = {0xC0/*0*/, 0xF9 /*1*/,  0xA4/*2*/, 0xB0/*3*/, 0x99/*4*/, 0x92/*5*/, 0x82/*6*/};

int num_1, num_2; 


void visualizar(void);

int main(){   

    Segmentos = 0xC0;

    visualizar();

    while(true){ 

    }   

}

void visualizar(void){

    bool flag;

    while(true){

        if(Segmentos == 0xC0){

            led_verde = 0;
            led_rojo  = 0; 

        }

        if(flag){

            if(btn_1){

                srand(time(NULL));
                num_1 = rand()%6+1;
                ThisThread::sleep_for(500ms);
                num_2 = 0xC0;
                led_rojo  = 0;
                led_verde = 0;

            }

            Display = 0b10;
            Segmentos = numeros[num_1];

        }
        else{

            if(btn_2){

                srand(time(NULL));
                num_2 = rand()%6+1;
            }

            Display = 0b01;
            Segmentos = numeros[num_2];

        }
        flag = !flag;
        ThisThread::sleep_for(10ms);

        

        if(num_1 > num_2){

            led_verde = 0;
            led_rojo  = 1;

        } 
        else if(num_1 <= num_2){

            led_rojo  = 0;
            led_verde = 1;

        }
        
       

    }


}
