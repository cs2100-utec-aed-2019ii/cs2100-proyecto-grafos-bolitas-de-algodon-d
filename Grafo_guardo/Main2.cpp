#include<GLUT/glut.h>
#include<iostream>
using namespace std;

int pantalla_x = 640;
int pantalla_y = 480;
bool check=true;

float posicion_x(float x,int pantalla_x){
    return ((x*2)/pantalla_x);
}
float posicion_y(float y,int pantalla_y){
    return ((y*2)/pantalla_y);
}

float recalculo_x1(float x,int pantalla_x){
    if(x <= pantalla_x-80){
        return ((x*2)/pantalla_x)+posicion_x(40,pantalla_x);
    }
    else{
        x = pantalla_x-80;
        return ((x*2)/pantalla_x)+posicion_x(40,pantalla_x);
    }
}

float recalculo_y1(float y,int pantalla_y){
    if(y <= pantalla_y-140){
        return ((y*2)/pantalla_y)+posicion_y(120,pantalla_y);
    }
    else{
        y = pantalla_y-140;
        return ((y*2)/pantalla_y)+posicion_y(120,pantalla_y);    
    }
}

void dibujar(){
    glClear(GL_COLOR_BUFFER_BIT);

    glPushMatrix();
    glTranslatef(-1.0,-1.0,0);
    glPointSize(10);

    glBegin(GL_POINTS);

    glColor3f(236.0/100,240.0/100,241.0/100);
    //limite del espacio disponible

    glVertex2f(posicion_x(40,pantalla_x),posicion_y(120,pantalla_y));
    glVertex2f(posicion_x(40,pantalla_x),posicion_y(460,pantalla_y));
    glVertex2f(posicion_x(600,pantalla_x),posicion_y(120,pantalla_y));
    glVertex2f(posicion_x(600,pantalla_x),posicion_y(460,pantalla_y));
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(189.0/100,195.0/100,199.0/100);
    //menu_1

    glVertex2f(posicion_x(0,pantalla_x),posicion_y(100,pantalla_y));
    glVertex2f(posicion_x(480,pantalla_x),posicion_y(100,pantalla_y));
    glVertex2f(posicion_x(480,pantalla_x),posicion_y(0,pantalla_y));
    glVertex2f(posicion_x(0,pantalla_x),posicion_y(0,pantalla_y));
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(155.0/100,89.0/100,182.0/100);
    //menu_2

    glVertex2f(posicion_x(480,pantalla_x),posicion_y(100,pantalla_y));
    glVertex2f(posicion_x(640,pantalla_x),posicion_y(100,pantalla_y));
    glVertex2f(posicion_x(640,pantalla_x),posicion_y(0,pantalla_y));
    glVertex2f(posicion_x(480,pantalla_x),posicion_y(0,pantalla_y));
    glEnd();
    
    glBegin(GL_POLYGON);
    glColor3f(51.0/100,217.0/100,178.0/100);
    //boton insetar

    glVertex2f(posicion_x(60,pantalla_x),posicion_y(25,pantalla_y));
    glVertex2f(posicion_x(60,pantalla_x),posicion_y(75,pantalla_y));
    glVertex2f(posicion_x(110,pantalla_x),posicion_y(25,pantalla_y));
    glVertex2f(posicion_x(110,pantalla_x),posicion_y(75,pantalla_y));
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(211.0/100,84.0/100,0.0/100);
    //boton eliminar

    glVertex2f(posicion_x(160,pantalla_x),posicion_y(25,pantalla_y));
    glVertex2f(posicion_x(160,pantalla_x),posicion_y(75,pantalla_y));
    glVertex2f(posicion_x(210,pantalla_x),posicion_y(25,pantalla_y));
    glVertex2f(posicion_x(210,pantalla_x),posicion_y(75,pantalla_y));
    glEnd();

    glBegin(GL_LINE_STRIP);
    glColor3f(231.0/100,76.0/100,60.0/100);
    //aqui se puede graficar el grafo

    //glVertex2f(0.345,0.7083);
    glVertex2f(recalculo_x1(70,pantalla_x),recalculo_y1(50,pantalla_y));
    //glVertex2f(0.5,0.7083);
    glVertex2f(recalculo_x1(120,pantalla_x),recalculo_y1(50,pantalla_y));
    //glVertex2f(0.345,0.916);
    glVertex2f(recalculo_x1(70,pantalla_x),recalculo_y1(100,pantalla_y));
    //glVertex2f(0.5,0.916);
    glVertex2f(recalculo_x1(350,pantalla_x),recalculo_y1(100,pantalla_y));

    //glVertex2f(recalculo_x1(570,pantalla_x),recalculo_y1(100,pantalla_y));
    glEnd();  

    glBegin(GL_POINTS);
    glColor3f(44.0/100,44.0/100,84.0/100);
    //aqui se puede graficar el grafo

    //glVertex2f(0.345,0.7083);
    glVertex2f(recalculo_x1(70,pantalla_x),recalculo_y1(50,pantalla_y));
    //glVertex2f(0.5,0.7083);
    glVertex2f(recalculo_x1(120,pantalla_x),recalculo_y1(50,pantalla_y));
    //glVertex2f(0.345,0.916);
    glVertex2f(recalculo_x1(70,pantalla_x),recalculo_y1(100,pantalla_y));
    //glVertex2f(0.5,0.916);
    glVertex2f(recalculo_x1(350,pantalla_x),recalculo_y1(100,pantalla_y));

    //glVertex2f(recalculo_x1(570,pantalla_x),recalculo_y1(100,pantalla_y));
    glEnd();

    glPopMatrix();

    glFlush();
}

void mouse(int boton,int state,int x,int y){

    if(boton == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
        
      
    }
    else if(boton == GLUT_RIGHT_BUTTON && state == GLUT_DOWN){
    
        glClearColor(1, 1, 1, 0); 
        glClear(GL_COLOR_BUFFER_BIT);

    }
    glutPostRedisplay();
}


void iniciar(){
    glClearColor(0,0,0,1);

    glOrtho(800,0,600,0,-1,1);

}

int main(int argc,char** argv){

    glutInit(&argc,argv);

    glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);

    glutInitWindowSize(pantalla_x,pantalla_y);
    glutInitWindowPosition(50,50);
    glutCreateWindow("OwO");

    glutDisplayFunc(dibujar);
    glutMouseFunc(mouse);



    glutMainLoop();
}