#include "mbed.h"
#define tiempo_conteo  150
#define tiempo_refresco  1

DigitalIn btn_1(A1);
DigitalIn btn_2(A2);
DigitalOut led_verde(A0);
DigitalOut led_rojo(A5);
DigitalIn bit1(/los que vea conveniente*/)
DigitalIn bit2();
DigitalIn bit3();
DigitalIn bit4();
DigitalIn bit5();
DigitalIn bit6();
DigitalIn bit7();
DigitalIn botonup();
DigitalIn butondown();

static int unidad=0,x=0;

BusOut Segmentos(D2,D3,D4,D5,D6,D7,D8,D9); 
BusOut Display(A4,A3);


const char numeros[7] = {0xC0/*0*/, 0xF9 /*1*/,  0xA4/*2*/, 0xB0/*3*/, 0x99/*4*/, 0x92/*5*/, 0x82/*6*/};
const char segmentos [12] = {0xC0/*0*/, 0xF9 /*1*/,  0xA4/*2*/, 0xB0/*3*/, 0x99/*4*/, 0x92/*5*/,0x82/*6*/, 0x78/*7*/, 0x00/*8*/, 0x18/*9*/, 0xf9,/*1*/,0xFF/*6*/};

int num_1, num_2,numero,button1,button2;
int a=0,b=0,c=0,d=0,e=0,f=0,g=0;
int unidades=0,decenas=0,parpadeo=0;
        
void conteo(void);
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
void conteo (void)
{
    numero=bit5;
    if (numero==false)
    {
        while (true)
        {
            if bit1==true{
                a=1;
            }else{
                a=0;
            }
            if bit2==true{
                b=2;
            }else{
                b=0;
            }
            if bit3==true{
                c=4;
            }else{
                c=0;
            }
            if bit4==true{
                d=8;
            }else{
                d=0;
            }
            if bit5==true{
                e=16;
            }else{
                e=0;
            }
            if bit6==true{
                f=32;
            }else{
                f=0;
            }
            if bit1==true{
                g=64;
            }else{
                g=0;
            }
            unidad= a+b+c+d+f+e+g;
            if (unidad>99) unidad = 99;
                
              decenas=(unidades/10);
              unidades= (unidades-(decenas*10));
            
            button1=butonup.read();
            if(button1==false)
            {
                while==true;
                {
                   unidades=unidades+1;
                    if unidades==10
                    {
                        unidades=0;
                        decenas=decenas+1:
                        
                        if decenas==10{
                            while(true)
                            {
                                switch (parpadeo)
                                {
                                        case 0: decenas=9;
                                               unidades=9;
                                               parpadeo=1;
                                               x=0;
                                        break;
                                }
                                 if (x==6)     
                                 {
                                   thread_sleep_for(tiempo);
                            } 
                            thread_sleep_fsor(tiempo_conteo);
                        }
                    }
}
