#include "BusOut.h"
#include "mbed.h"
#include "Thread.h"

#define TIEMPO_REFRESCO 11ms
#define TIEMPO_CONTEO 1s

DigitalIn btn_1(A1);
DigitalIn btn_2(A2);
DigitalOut led_verde(A0);
DigitalOut led_rojo(A5);
DigitalIn Switch(PC_8);
DigitalIn btn1(BUTTON1);
DigitalIn bit1(D10);
DigitalIn bit2(D11);

BusIn  Disp_1 (D13,D12,D11,D10);
BusIn  Disp_2 (PA_11,PB_12,D15,D14);
BusOut Segmentos(D2,D3,D4,D5,D6,D7,D8,D9); 
BusOut Display(A4,A3);

const char numeros[10] = {0xC0/*0*/, 0xF9 /*1*/,  0xA4/*2*/, 0xB0/*3*/, 0x99/*4*/, 0x92/*5*/, 0x82/*6*/,0XF8/*7*/, 0x80/*8*/, 0x98/*9*/};

static char unidades = 0;
static char decenas  = 0;
static bool flag_run = false;

int num_1, num_2;

Thread hilo_visualizar;
Thread hilo_contar;
Thread hilo_boton1;
Thread hilo_boton2;
Thread hilo_numero;


void dado(void);
void visualizar(void);
void contar(void);
void boton1(void);
void boton2(void);
void numero(void);


int main(){   

    Segmentos = 0xC0;

    if(Switch){
        dado();
    }
    else{
        hilo_visualizar.start(visualizar);
        hilo_contar.start(contar);
        hilo_boton1.start(boton1);
        hilo_boton2.start(boton2);
        hilo_numero.start(numero);
    }
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

            if(btn_1 && (!bit1 || !bit2)){

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

            if(btn_2 && (bit1 || bit2)){

                srand(time(NULL));
                num_2 = rand()%6+1;
            }

            Display = 0b01;
            Segmentos = numeros[num_2];

        }
        flag = !flag;
        ThisThread::sleep_for(10ms);

        

        if(num_1 > num_2 && num_2 != 0 && !bit1 && bit2){

            led_rojo  = 0;
            led_verde = 1;

        } 
        else if(num_1 > num_2 && num_2 != 0 && bit1 && !bit2){

            led_rojo  = 1;
            led_verde = 0;

        } 
        else if(num_1 <= num_2 && num_2 != 0 &&  bit1 && !bit2){

            led_rojo  = 0;
            led_verde = 1;

        }
        else if(num_1 <= num_2 && num_2 != 0 &&  !bit1 && bit2){

            led_rojo  = 1;
            led_verde = 0;

        }
       

    }


}
void visualizar(void){

    bool flag;

    while(true){

        if(flag){

            Display = 0b01;
            Segmentos = numeros[unidades];

        }
        else{

            Display = 0b10;
            Segmentos = numeros[decenas];
        }
        flag = !flag;
        ThisThread::sleep_for(TIEMPO_REFRESCO);

    }
    
}

void contar(void){

    while(true){

        if(flag_run){

            unidades++;

        }
        if(unidades==10){

            unidades=0;
            decenas++;

            if(decenas==10) decenas=0;

        }
        
        
     ThisThread::sleep_for(TIEMPO_CONTEO);

    }

}

void boton1(void){

    bool Q0,Q1,Q2;

    while(true){

        Q2=Q1;
        Q1=Q0;
        Q0=btn1;

        if(!Q0 && Q1 && Q2){

            flag_run = true;
  
        }

        ThisThread::sleep_for(50ms);

    }
    
}

void boton2(void){

    bool Q0,Q1,Q2;

    while(true){

        Q2=Q1;
        Q1=Q0;
        Q0=btn_2;

        if(!Q0 && Q1 && Q2){

            flag_run = false;
  
        }

        ThisThread::sleep_for(50ms);

    }
    
}

void numero(void){

    if(!flag_run){

    if(Disp_1==0x00){decenas = 0;}
    else if(Disp_1==0x01){decenas = 1;}
    else if(Disp_1==0x02){decenas = 2;}
    else if(Disp_1==0x03){decenas = 3;}
    else if(Disp_1==0x04){decenas = 4;}
    else if(Disp_1==0x05){decenas = 5;}
    else if(Disp_1==0x06){decenas = 6;}
    else if(Disp_1==0x07){decenas = 7;}
    else if(Disp_1==0x08){decenas = 8;}
    else if(Disp_1==0x09){decenas = 9;}

    if(Disp_2==0x00){unidades = 0;}
    else if(Disp_2==0x01){unidades = 1;}
    else if(Disp_2==0x02){unidades = 2;}
    else if(Disp_2==0x03){unidades = 3;}
    else if(Disp_2==0x04){unidades = 4;}
    else if(Disp_2==0x05){unidades = 5;}
    else if(Disp_2==0x06){unidades = 6;}
    else if(Disp_2==0x07){unidades = 7;}
    else if(Disp_2==0x08){unidades = 8;}
    else if(Disp_2==0x09){unidades = 9;}

    }

}
