//
//  main.cpp
//  Ejercicios-Clase-3
//
//  Created by Javier Curiel on 10/29/15.
//  Copyright © 2015 Javier Curiel. All rights reserved.
//
#include <stdio.h>
#include <graphics.h>



void cubo();
void prismaRect();
void prismaTrian();
void cono();
void ellipse(int x, int y, int i);
void midEllipse(int a,int b);
void LiHo(int x0, int y0, int x1, int y1);
void LiVe(int x0, int y0, int x1, int y1);
void LiIn(int x0, int y0, int x1, int y1);


int main(int argc, char **argv)
{
    
    int gd = DETECT, gm = VGAMAX;
    
    int opcion = 0;
    
    printf("Selecciona una opción\n 1.- Cubo \n 2.- Prisma Rectangular\n 3.- Prisma Triangular\n 4.- Cono\n");
    scanf("%d\n",&opcion);
    
    initgraph(&gd, &gm, NULL);
    if(opcion == 1){
        cubo();
    }
    else if (opcion == 2){
        prismaRect();
    }
    else if(opcion == 3){
        prismaTrian();
    }
    else if(opcion == 4){
        cono();
    }
    else{
        printf("Opción no valida\n");
    }
    
    getch();
    closegraph();
    return 0;
}



void LiHo(int x0, int y0, int x1, int y1)
{
    bool haciaDerecha = false;
    bool haciaIzquierda = false;
    if(x0 < x1)
    {
        haciaDerecha = true;
    }
    else if (x0 > x1)
    {
        haciaIzquierda = true;
    }
    
    if (haciaDerecha)
    {
        for (int i = x0; i<=x1; i++)
        {
            putpixel(i,y0,WHITE);
        }
    }
    if(haciaIzquierda)
    {
        for (int i = x1; i>=x1; i--)
        {
            putpixel(i,y0,WHITE);
        }
    }
}

void LiVe(int x0, int y0, int x1, int y1)
{
    bool haciaArriba = false;
    bool haciaAbajo = false;
    if(y0 < y1)
    {
        haciaArriba = true;
    }
    else if (y0 > y1)
    {
        haciaAbajo = true;
    }
    
    if (haciaArriba)
    {
        for (int i = y0; i<=y1; i++)
        {
            putpixel(x0,i,WHITE);
        }
    }
    if(haciaAbajo)
    {
        for (int i = y1; i>=y0; i--)
        {
            putpixel(x0,i,WHITE);
        }
    }
}


void LiIn(int x0, int y0, int x1, int y1)
{
    int maxY, i;
    
    float dx, dy, m, x, y;
    
    i=0;
    
    dx=x1-x0;
    dy=y1-y0;
    
    maxY=getmaxy();
    
    if (dy <= dx) /* Es una línea con pendiente < 1 */
    {
        m = dy/dx;
        y = y0;
        
        for(x = x0; x <= x1; ++x)
        {
            putpixel(x, y, WHITE);
            i += 2;
            y = y + m;
        }
    }
    else /* Es una línea con pendiente > 1 */
    {
        m = dx/dy;
        x = x0;
        for(y = y0; y <= y1; ++y)
        {
            putpixel((int)x, y, WHITE);
            i += 2;
            x = x + m;
        }
    }
}



void cubo()
{
    //Cuadrado 1
    int x0 = 300;
    int y0 = 300;
    int x1 = 350;
    int y1 = 300;
    int x2 = 300;
    int y2 = 250;
    int x3 = 350;
    int y3 = 250;
    
    //Cuadrado 3
    int x4 = 300+20;
    int y4 = 300-20;
    int x5 = 350+20;
    int y5 = 300-20;
    int x6 = 300+20;
    int y6 = 250-20;
    int x7 = 350+20;
    int y7 = 250-20;
    
    LiHo(x0,y0,x1,y1);
    LiHo(x2,y2,x3,y3);
    LiVe(x2,y2,x0,x0);
    LiVe(x3,y3,x1,y1);
    
    LiHo(x4,y4,x5,y5);
    LiHo(x6,y6,x7,y7);
    LiVe(x6,y6,x4,y4);
    LiVe(x7,y7,x5,y5);
    
    LiIn(x0,y0,x4,y4);
    LiIn(x1,y1,x5,y5);
    LiIn(x2,y2,x6,y6);
    LiIn(x3,y3,x7,y7);
    
}

void prismaRect()
{
    //Cuadrado 1
    int x0 = 300;
    int y0 = 350;
    int x1 = 350;
    int y1 = 350;
    int x2 = 300;
    int y2 = 200;
    int x3 = 350;
    int y3 = 200;
    
    //Cuadrado 3
    int x4 = x0+30;
    int y4 = y0-50;
    int x5 = x1+30;
    int y5 = y1-50;
    int x6 = x2+30;
    int y6 = y2-50;
    int x7 = x3+30;
    int y7 = y3-50;
    
    LiHo(x0,y0,x1,y1);
    LiHo(x2,y2,x3,y3);
    LiVe(x2,y2,x0,y0);
    LiVe(x3,y3,x1,y1);
    
    LiHo(x4,y4,x5,y5);
    LiHo(x6,y6,x7,y7);
    LiVe(x6,y6,x4,y4);
    LiVe(x7,y7,x5,y5);
    
    LiIn(x0,y0,x4,y4);
    LiIn(x1,y1,x5,y5);
    LiIn(x2,y2,x6,y6);
    LiIn(x3,y3,x7,y7);
}

void prismaTrian()
{
    //Puntos Base
    int x0 = 300;
    int y0 = 300;
    int x1 = 350;
    int y1 = 300;
    int x2 = 325;
    int y2 = 343;
    
    //Puntos Tapa
    int x3 = x0;
    int y3 = y0-100;
    int x4 = x1;
    int y4 = y1-100;
    int x5 = x2;
    int y5 = y2-100;
    
    LiHo(x0,y0,x1,y1);
    LiIn(x0,y0,x2,y2);
    LiIn(x1,y1,x2,y2);
    
    LiHo(x3,y3,x4,y4);
    LiIn(x3,y3,x5,y5);
    LiIn(x4,y4,x5,y5);
    
    LiVe(x3,y3,x0,y0);
    LiVe(x4,y4,x1,y1);
    LiVe(x5,y5,x2,y2);
    
}

/* Dibuja los puntos por simetría en los demás cuadrantes */

void ellipse(int x, int y, int i)
{
    int maxx = getmaxx()/2;
    int maxy = getmaxy()/2;
    
    putpixel(maxx+x,maxy+y,WHITE);
    
    i+=2;
    
    putpixel(maxx-x,maxy+y,WHITE);
    putpixel(maxx+x,maxy-y,WHITE);
    putpixel(maxx-x,maxy-y,WHITE);
    
}

/* Algoritmo MidPointElipse */
void midEllipse(int a,int b)
{
    int i = 0;
    double d2;
    int x=0;
    int y=b;
    
    double dl=b*b-(a*a*b)+(0.25*a*a);
    
    putpixel(x,y, WHITE);
    
    while((a*a*(y-0.5))>(b*b*(x+1)))
    {
        if(dl<0)
            dl+=b*b*(2*x+3);
        else
        {
            dl+=b*b*(2*x+3)+a*a*(-2*y+2);
            y--;
        }
        x++;
        
        ellipse(x, y, i);
    }
    
    d2=b*b*(x+0.5)*(x+0.5)+a*a*(y-1)*(y-1)-a*a*b*b;
    
    while(y>0)
    {
        if(d2<0)
        {
            d2+=b*b*(2*x+2)+a*a*(-2*y+3);
            x++;
        }
        else
            d2+=a*a*(-2*y+3);
        y--;
        
        ellipse(x, y, i);
    }
}

void cono()
{
    midEllipse(50,20);
    
    int x0 = (getmaxx()/2) - 50;
    int y0 = getmaxy()/2;
    int x1 = (getmaxx()/2) + 50;
    int y1 = y0;
    int x2 = getmaxx()/2;
    int y2 = y0 + 100;
    
    LiIn(x0,y0,x2,y2);
    LiIn(x2,y2,x1,y1);
    
}