#include "mbed.h"
#define tiempo_conteo  150
#define tiempo_refresco  1
#define tiempo  99999999        

DigitalIn btn_1(A1);
DigitalIn btn_2(A2);
DigitalOut led_verde(A0);
DigitalOut led_rojo(A5);
DigitalIn bit1(D10);
DigitalIn bit2(D11);
DigitalIn bit3(D12);
DigitalIn bit4(D13);
DigitalIn bit5(D14);
DigitalIn bit6(D15);
DigitalIn bit7(PB_12);
DigitalIn botonup(PB_14);
DigitalIn botondown(PB_15);
static int unidad=0,x=0;

BusOut Segmentos(D2,D3,D4,D5,D6,D7,D8,D9); 
BusOut Display(A4,A3);


const char numeros[7] = {0xC0/*0*/, 0xF9 /*1*/,  0xA4/*2*/, 0xB0/*3*/, 0x99/*4*/, 0x92/*5*/, 0x82/*6*/};
const char segmentos [12] = {0xC0/*0*/, 0xF9 /*1*/,  0xA4/*2*/, 0xB0/*3*/, 0x99/*4*/, 0x92/*5*/,0x82/*6*/, 0x78/*7*/, 0x00/*8*/, 0x18/*9*/, 0xf9,/*1*/,0xFF/*6*/};

int num_1, num_2,numero,button1,button2;
int a=0,b=0,c=0,d=0,e=0,f=0,g=0;
int unidades=0,decenas=0,parpadeo=0;
        
void conteo(void);
void dado(void);

int main(){   

    Segmentos = 0xC0;

    dado();

    while(true){ 

    }   

}

void dado(void){

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
                num_2 = 0;
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

        

        if(num_1 > num_2 && num_2 != 0 && !Switch_1 && Switch_2){

            led_rojo  = 0;
            led_verde = 1;

        } 
        else if(num_1 > num_2 && num_2 != 0 && Switch_1 && !Switch_2){

            led_rojo  = 1;
            led_verde = 0;

        } 
        else if(num_1 <= num_2 && num_2 != 0 &&  Switch_1 && !Switch_2){

            led_rojo  = 0;
            led_verde = 1;

        }
        else if(num_1 <= num_2 && num_2 != 0 &&  !Switch_1 && Switch_2){

            led_rojo  = 1;
            led_verde = 0;

        }
       

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
            
            button1=botonup.read();
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
                                               x=x+1;
                                        break;
                                        default: decenas=11;unidades=11; parpadeo=0; break;
                                }
                                 if (x==6)     
                                 {
                                   thread_sleep_for(tiempo);
                            } 
                            thread_sleep_fsor(tiempo_conteo);
                        }
                    }
                }          
                        thread_sleep_for(tiempo_conteo);
                        }
                }    
                 button2=botondown.read();
                if (botondown == false)
                 {
                  while(true)
             {
                if (unidades==0)
                {
                    unidades=10;
                    if (decenenas==0)
                    {
                        while(true)
                        { 
                            switch  (parpadeo)
                            { 
                            case 0:  decenas=10;unidades=10; parpadeo=1; x++; break;
                            default: decenas=11;unidades=11; parpadeo=0; break;
                            }
                            if (x== 6)
                            {
                                thread_sleep_for(tiempo);
                            } 
                            thread_sleep_for(tiempo_conteo);
                        }
                    }
                    decenas=decenas-1;
                }
                unidades=unidades-1;
            thread_sleep_for(tiempo_conteo);
            }
       }
    }  
    }
}
                
        
