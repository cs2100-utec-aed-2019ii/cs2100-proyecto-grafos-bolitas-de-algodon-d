#include <GLUT/glut.h>

int pantalla_x = 640;
int pantalla_y = 480;

//Posicion general de pantalla
float posicion_x(float x,int pantalla_x){
    return ((x*2)/pantalla_x);
}
float posicion_y(float y,int pantalla_y){
    return ((y*2)/pantalla_y);
}
//Limites del grafo
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


typedef struct{
    GLfloat verticeXYZ[3];
    GLfloat colorRGB[3];
}Vertice;

typedef struct{
    float x,y;
    int izq,der;
}EstadoRaton;
GLfloat formato = pantalla_x/pantalla_y;

Vertice menu[4] = {
    {{posicion_x(0,pantalla_x),posicion_y(100,pantalla_y),0},{236.0/100,240.0/100,241.0/100}},
    {{posicion_x(480,pantalla_x),posicion_y(100,pantalla_y),0},{236.0/100,240.0/100,241.0/100}},
    {{posicion_x(480,pantalla_x),posicion_y(0,pantalla_y),0},{236.0/100,240.0/100,241.0/100}},
    {{posicion_x(0,pantalla_x),posicion_y(0,pantalla_y),0},{236.0/100,240.0/100,241.0/100}}
};
Vertice Dar_dato[4] = {
    {{posicion_x(480,pantalla_x),posicion_y(100,pantalla_y),0},{155.0/100,89.0/100,182.0/100}},
    {{posicion_x(640,pantalla_x),posicion_y(100,pantalla_y),0},{155.0/100,89.0/100,182.0/100}},
    {{posicion_x(640,pantalla_x),posicion_y(0,pantalla_y),0},{155.0/100,89.0/100,182.0/100}},
    {{posicion_x(480,pantalla_x),posicion_y(0,pantalla_y),0},{155.0/100,89.0/100,182.0/100}}
};
Vertice Limites[4] = {
    {{posicion_x(40,pantalla_x),posicion_y(120,pantalla_y),0},{0,1,1}},
    {{posicion_x(40,pantalla_x),posicion_y(460,pantalla_y),0},{0,1,1}},
    {{posicion_x(600,pantalla_x),posicion_y(120,pantalla_y),0},{0,1,1}},
    {{posicion_x(600,pantalla_x),posicion_y(460,pantalla_y),0},{0,1,1}}
};
//El tamaño del grafo puede alterarse, como tambien la cordenas X Y Z
Vertice Grafo[6] = {
    {{recalculo_x1(180,pantalla_x),recalculo_y1(90,pantalla_y),0},{44.0/100,44.0/100,84.0/100}},
    {{recalculo_x1(120,pantalla_x),recalculo_y1(180,pantalla_y),0},{44.0/100,44.0/100,84.0/100}},
    {{recalculo_x1(180,pantalla_x),recalculo_y1(270,pantalla_y),0},{44.0/100,44.0/100,84.0/100}},
    {{recalculo_x1(300,pantalla_x),recalculo_y1(270,pantalla_y),0},{44.0/100,44.0/100,84.0/100}},
    {{recalculo_x1(360,pantalla_x),recalculo_y1(180,pantalla_y),0},{44.0/100,44.0/100,84.0/100}},
    {{recalculo_x1(300,pantalla_x),recalculo_y1(90,pantalla_y),0},{44.0/100,44.0/100,84.0/100}}
};
//Botones
Vertice Insertar[4] = {
    {{posicion_x(60,pantalla_x),posicion_y(75,pantalla_y),0},{0,1,0}},
    {{posicion_x(60,pantalla_x),posicion_y(25,pantalla_y),0},{0,1,0}},
    {{posicion_x(110,pantalla_x),posicion_y(75,pantalla_y),0},{0,1,0}},
    {{posicion_x(110,pantalla_x),posicion_y(25,pantalla_y),0},{0,1,0}}
};
Vertice Eliminar[4] = {
    {{posicion_x(160,pantalla_x),posicion_y(75,pantalla_y),0},{211.0/100,84.0/100,0.0/100}},
    {{posicion_x(160,pantalla_x),posicion_y(25,pantalla_y),0},{211.0/100,84.0/100,0.0/100}},
    {{posicion_x(210,pantalla_x),posicion_y(75,pantalla_y),0},{211.0/100,84.0/100,0.0/100}},
    {{posicion_x(210,pantalla_x),posicion_y(25,pantalla_y),0},{211.0/100,84.0/100,0.0/100}}
};
EstadoRaton raton;

void IniciarGLUT(){
    glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
    glutInitWindowSize(pantalla_x,pantalla_y);
    glutInitWindowPosition(100,100);
    glutCreateWindow("UwU");
}   

void Pintar(){

    glClear(GL_COLOR_BUFFER_BIT);
    //Matriz...
    glPushMatrix();
    glTranslatef(-1.0,-1.0,0);

    glBegin(GL_QUADS);
        for (int i=0; i<4; i++) {
         glColor3fv(menu[i].colorRGB);
         glVertex3fv(menu[i].verticeXYZ);
        }
    glEnd();

    glBegin(GL_QUADS);
        for (int i=0; i<4; i++) {
         glColor3fv(Dar_dato[i].colorRGB);
         glVertex3fv(Dar_dato[i].verticeXYZ);
        }
    glEnd();

    glPointSize(10);
    glBegin(GL_POINTS);
        for (int i=0; i<4; i++) {
         glColor3fv(Limites[i].colorRGB);
         glVertex3fv(Limites[i].verticeXYZ);
        }
    glEnd();

    glBegin(GL_LINES);
    glColor3f(231.0/100,76.0/100,60.0/100);
    glVertex2f(recalculo_x1(180,pantalla_x),recalculo_y1(90,pantalla_y));
    glVertex2f(recalculo_x1(120,pantalla_x),recalculo_y1(180,pantalla_y));

    glVertex2f(recalculo_x1(120,pantalla_x),recalculo_y1(180,pantalla_y));
    glVertex2f(recalculo_x1(180,pantalla_x),recalculo_y1(270,pantalla_y));

    glVertex2f(recalculo_x1(180,pantalla_x),recalculo_y1(270,pantalla_y));
    glVertex2f(recalculo_x1(300,pantalla_x),recalculo_y1(270,pantalla_y));

    glVertex2f(recalculo_x1(300,pantalla_x),recalculo_y1(270,pantalla_y));
    glVertex2f(recalculo_x1(360,pantalla_x),recalculo_y1(180,pantalla_y));

    glVertex2f(recalculo_x1(360,pantalla_x),recalculo_y1(180,pantalla_y));
    glVertex2f(recalculo_x1(300,pantalla_x),recalculo_y1(90,pantalla_y));

    glVertex2f(recalculo_x1(300,pantalla_x),recalculo_y1(90,pantalla_y));
    glVertex2f(recalculo_x1(180,pantalla_x),recalculo_y1(90,pantalla_y));

    glVertex2f(recalculo_x1(180,pantalla_x),recalculo_y1(90,pantalla_y));
    glVertex2f(recalculo_x1(300,pantalla_x),recalculo_y1(270,pantalla_y));

    glVertex2f(recalculo_x1(300,pantalla_x),recalculo_y1(90,pantalla_y));
    glVertex2f(recalculo_x1(180,pantalla_x),recalculo_y1(270,pantalla_y));
    glEnd();

    glPointSize(7);
    glBegin(GL_POINTS);
        for (int i=0; i<6; i++) {
         glColor3fv(Grafo[i].colorRGB);
         glVertex3fv(Grafo[i].verticeXYZ);
        }
    glEnd();

    glBegin(GL_QUADS);
        for (int i=0; i<4; i++) {
         glColor3fv(Insertar[i].colorRGB);
         glVertex3fv(Insertar[i].verticeXYZ);
        }
    glEnd();

    glBegin(GL_QUADS);
        for (int i=0; i<4; i++) {
         glColor3fv(Eliminar[i].colorRGB);
         glVertex3fv(Eliminar[i].verticeXYZ);
        }
    glEnd();

    //Eliminar matriz...
    glPopMatrix();

    glFlush();
}

float ObtenerPosPlanoX(float x, int ancho_ventana) {
   
   float pos_plano;
    
    pos_plano = (2*x)/ancho_ventana;

   return pos_plano;
}

float ObtenerPosPlanoY(float y, int ancho_ventana) {

   float pos_plano;
   
   pos_plano = (2*y)/ancho_ventana;
   
   return pos_plano;
}

void Control_Raton_Nodo(int boton,int state,int x,int y){
    if (boton == GLUT_LEFT_BUTTON)
    {
        if(state == GLUT_DOWN){
            raton.izq = 1;
        }else{
            raton.izq = 0;
        }
        
        /*raton.x = ObtenerPosPlanoX(x,pantalla_x);
        raton.y = ObtenerPosPlanoY(y,pantalla_y);

        if(raton.x == recalculo_x1(300,pantalla_x) && raton.y == recalculo_y1(90,pantalla_x)){
            
        }*/
    }else if(boton == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
    
        raton ;
    }
    
}
void MovimRaton(int x, int y) {

    raton.x = ObtenerPosPlanoX(x,pantalla_x);
    raton.y = ObtenerPosPlanoY(y,pantalla_y);
    
    if(raton.izq == 1){
        if(posicion_x(60,pantalla_x)<= raton.x && raton.x <= (110,pantalla_x)){
            if(posicion_y(25,pantalla_y) <= raton.y && raton.y <= posicion_y(75,pantalla_y)){
                
            }
        }
    }
}

int main(int argc,char** argv){
    glutInit(&argc,argv);
    IniciarGLUT();

    glutDisplayFunc(Pintar);
    glutIdleFunc(Pintar);
    glutMouseFunc(Control_Raton_Nodo);

    glutMainLoop();
}