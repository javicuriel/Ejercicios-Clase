//
//  main.cpp
//  Ejercicios-Clase-1
//
//  Created by Javier Curiel on 10/29/15.
//  Copyright © 2015 Javier Curiel. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#include <graphics.h>


void drawLine(int xi, int yi, int xf, int yf);

int main(){
    int N,r,maxY,maxX;
    int gd = DETECT, gm = VGAMAX;
    printf("Ingrese el número de lados: ");
    scanf("%d", &N);
    r = 100;
    double x[N],y[N];
    for(int n = 0; n < N;n++){
        x[n] = r * cos(2*M_PI*n/N);
        y[n] = r * sin(2*M_PI*n/N);
    }
    
    initgraph(&gd, &gm, NULL);
    maxy=getmaxy()/2;
    maxx=getmaxx()/2;
    for (int i= 0;i < N;i++){
        drawLine(maxx+x[i], maxy+[i], maxx+x[i+1], maxy+y[i+1]);
    }
    getch();
    closegraph();
    return 0;
}

void drawLine(int xi, int yi, int xf, int yf)
{
    int x0, y0, x1, y1;
    
    if(xi > xf || yi > yf)
    {
        x0 = xf;
        y0 = yf;
        x1 = xi;
        y1 = yi;
    }
    else
    {
        x0 = xi;
        y0 = yi;
        x1 = xf;
        y1 = yf;
    }
    
    
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
            putpixel(x, (maxY-y), WHITE);
            y = y + m;
        }
    }
    else /* Es una línea con pendiente > 1 */
    {
        m = dx/dy;
        x = x0;
        for(y = y0; y <= y1; ++y)
        {
            putpixel(x, maxY-y, WHITE);
            x = x + m;
        }
    }
}

