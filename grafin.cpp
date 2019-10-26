#include <GLUT/glut.h>
#include <iostream>
//probar aparte
//usar para OSX: g++ grafin.cpp -o gl -framework OpenGL -framework GLUT
float pantalla_x = 640.0;
float pantalla_y = 480.0;

float l, m;
float l_,m_;

bool prueba = false;
int prueba1 = 0;
int prueba6 = 0;

bool eliminar = false;

bool seleccion_1 = false;
bool seleccion_2 = false;
bool seleccion_3 = false;
bool seleccion_4 = false;
bool seleccion_5 = false;
bool seleccion_6 = false;

//Posicion general de pantalla
float posicion(float x,int pantalla){
    return ((x*2)/pantalla);
}

//Limites del grafo
float recalculo_x1(float x,int pantalla_x){
    if(x <= pantalla_x-80){
        return ((x*2)/pantalla_x)+posicion(40,pantalla_x);
    }
    else{
        x = pantalla_x-80;
        return ((x*2)/pantalla_x)+posicion(40,pantalla_x);
    }
}

float recalculo_y1(float y,int pantalla_y){
    if(y <= pantalla_y-140){
        return ((y*2)/pantalla_y)+posicion(120,pantalla_y);
    }
    else{
        y = pantalla_y-140;
        return ((y*2)/pantalla_y)+posicion(120,pantalla_y);    
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
float x,y;

Vertice menu[4] = {
    {{posicion(0,pantalla_x),posicion(100,pantalla_y),0},{236.0/100,240.0/100,241.0/100}},
    {{posicion(480,pantalla_x),posicion(100,pantalla_y),0},{236.0/100,240.0/100,241.0/100}},
    {{posicion(480,pantalla_x),posicion(0,pantalla_y),0},{236.0/100,240.0/100,241.0/100}},
    {{posicion(0,pantalla_x),posicion(0,pantalla_y),0},{236.0/100,240.0/100,241.0/100}}
};
Vertice Dar_dato[4] = {
    {{posicion(480,pantalla_x),posicion(100,pantalla_y),0},{155.0/100,89.0/100,182.0/100}},
    {{posicion(640,pantalla_x),posicion(100,pantalla_y),0},{155.0/100,89.0/100,182.0/100}},
    {{posicion(640,pantalla_x),posicion(0,pantalla_y),0},{155.0/100,89.0/100,182.0/100}},
    {{posicion(480,pantalla_x),posicion(0,pantalla_y),0},{155.0/100,89.0/100,182.0/100}}
};
Vertice Limites[4] = {
    {{posicion(40,pantalla_x),posicion(120,pantalla_y),0},{0,1,1}},
    {{posicion(40,pantalla_x),posicion(460,pantalla_y),0},{0,1,1}},
    {{posicion(600,pantalla_x),posicion(120,pantalla_y),0},{0,1,1}},
    {{posicion(600,pantalla_x),posicion(460,pantalla_y),0},{0,1,1}}
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
    {{posicion(60,pantalla_x),posicion(75,pantalla_y),0},{0,1,0}},
    {{posicion(60,pantalla_x),posicion(25,pantalla_y),0},{0,1,0}},
    {{posicion(110,pantalla_x),posicion(75,pantalla_y),0},{0,1,0}},
    {{posicion(110,pantalla_x),posicion(25,pantalla_y),0},{0,1,0}}
};
Vertice Eliminar[4] = {
    {{posicion(160,pantalla_x),posicion(75,pantalla_y),0},{211.0/100,84.0/100,0.0/100}},
    {{posicion(160,pantalla_x),posicion(25,pantalla_y),0},{211.0/100,84.0/100,0.0/100}},
    {{posicion(210,pantalla_x),posicion(75,pantalla_y),0},{211.0/100,84.0/100,0.0/100}},
    {{posicion(210,pantalla_x),posicion(25,pantalla_y),0},{211.0/100,84.0/100,0.0/100}}
};
EstadoRaton raton;

void IniciarGLUT(){
    glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
    glutInitWindowSize(pantalla_x,pantalla_y);
    glutInitWindowPosition(100,100);
    glutCreateWindow("UwU");
}  

void Pintar(){

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

    glPointSize(9);
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

   // glLoadIdentity();

   
    if(prueba == true)  
    {     
        glColor3f(44.0/100,44.0/100,84.0/100);
        glPointSize(9); 
        glBegin(GL_POINTS); 
        glVertex2f(1.5,1);  

        glEnd();
    }
    if(prueba1 == 1)  
    {     
        glColor3f(44.0/100,44.0/100,84.0/100);
        glPointSize(9); 
        glBegin(GL_POINTS); 
        glVertex2f((l_-(l-m)),m_);  

        glEnd();
    }
    if(prueba1 == 2)  
    {     
        glColor3f(44.0/100,44.0/100,84.0/100);                                                                  
        glPointSize(9); 
        glBegin(GL_POINTS); 
        glVertex2f(l_,(m-l));  

        glEnd();
    }
    if(prueba1 == 3)  
    {     
        glColor3f(44.0/100,44.0/100,84.0/100);
        glPointSize(9); 
        glBegin(GL_POINTS); 
        glVertex2f(1,1);  

        glEnd();
    }

    if(prueba6 == 1)  
    {     
        glColor3f(44.0/100,44.0/100,84.0/100);
        glPointSize(9); 
        glBegin(GL_POINTS); 
        glVertex2f((l_+(l-m)),m_);  

        glEnd();
    }
    if(prueba6 == 2)  
    {     
        glColor3f(44.0/100,44.0/100,84.0/100);
        glPointSize(9); 
        glBegin(GL_POINTS); 
        glVertex2f(l_,(m-l));  

        glEnd();
    }
    if(prueba6 == 3)  
    {     
        glColor3f(44.0/100,44.0/100,84.0/100);
        glPointSize(9); 
        glBegin(GL_POINTS); 
        glVertex2f(1,1);  

        glEnd();
    }
    if(eliminar == true){

        glClear(GL_COLOR_BUFFER_BIT);
    }

    //Eliminar matriz...
    glPopMatrix();

    glFlush();
}

void Control_Raton(int boton,int state,int mousex,int mousey){
    if (boton == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {

        raton.x = ((mousex)*2)/pantalla_x;
        //x = raton.x;
        //std::cout<<mousex<< " ";
        //std::cout<<raton.x<<std::endl;
        //std::cout<<"______"<<std::endl;
        
        raton.y = ((pantalla_y-mousey)*2)/pantalla_y;
        //y = raton.y;
        //std::cout<<pantalla_y-mousey<< " ";
        //std::cout<<raton.y<<std::endl;

        if(posicion(160,pantalla_x) <= raton.x && raton.x <= posicion(210,pantalla_x)){
            if(posicion(25,pantalla_y) <= raton.y && raton.y <= posicion(75,pantalla_y)){
                eliminar = true;
            }
        }

        if((recalculo_x1(180,pantalla_x))-(posicion(3,pantalla_x)) <= raton.x && raton.x <= (recalculo_x1(180,pantalla_x))+(posicion(3,pantalla_x))){
            if((recalculo_y1(90,pantalla_y))-(posicion(3,pantalla_y)) <= raton.y && raton.y <= (recalculo_y1(90,pantalla_y))+(posicion(3,pantalla_y))){
                
                l=raton.x;
                m=posicion((pantalla_y-140),pantalla_y)-(raton.y);          
                l_=raton.x;
                m_=raton.y;
                std::cout<<std::endl<<l<<" ";
                std::cout<<m<<" ";
                std::cout<<l_<<" ";
                std::cout<<m_<<" ";

                seleccion_1=true;

            }
        }
        if(seleccion_1 == true){
           if(posicion(60,pantalla_x) <= raton.x && raton.x <= posicion(110,pantalla_x)){
            if(posicion(25,pantalla_y) <= raton.y && raton.y <= posicion(75,pantalla_y)){
                if(l_>m_){
                    prueba1=1;
                }
                if(l_<m_){
                    prueba1=2;
                }
                if(l_==m_){
                    prueba1=3;
                }
            }
        } 
        }

        if((recalculo_x1(120,pantalla_x))-(posicion(3,pantalla_x)) <= raton.x && raton.x <= (recalculo_x1(120,pantalla_x))+(posicion(3,pantalla_x))){
            if((recalculo_y1(180,pantalla_y))-(posicion(3,pantalla_y)) <= raton.y && raton.y <= (recalculo_y1(180,pantalla_y))+(posicion(3,pantalla_y))){
                seleccion_2 = true;
            }
        }
        if(seleccion_2 == true){
           if(posicion(60,pantalla_x) <= raton.x && raton.x <= posicion(110,pantalla_x)){
            if(posicion(25,pantalla_y) <= raton.y && raton.y <= posicion(75,pantalla_y)){
                prueba = true;
            }
        } 
        }
        if((recalculo_x1(180,pantalla_x))-(posicion(3,pantalla_x)) <= raton.x && raton.x <= (recalculo_x1(180,pantalla_x))+(posicion(3,pantalla_x))){
            if((recalculo_y1(270,pantalla_y))-(posicion(3,pantalla_y)) <= raton.y && raton.y <= (recalculo_y1(270,pantalla_y))+(posicion(3,pantalla_y))){
                seleccion_3 = true;
            }
        }
        if(seleccion_3 == true){
           if(posicion(60,pantalla_x) <= raton.x && raton.x <= posicion(110,pantalla_x)){
            if(posicion(25,pantalla_y) <= raton.y && raton.y <= posicion(75,pantalla_y)){
                prueba = true;
            }
        } 
        }
        if((recalculo_x1(300,pantalla_x))-(posicion(3,pantalla_x)) <= raton.x && raton.x <= (recalculo_x1(300,pantalla_x))+(posicion(3,pantalla_x))){
            if((recalculo_y1(270,pantalla_y))-(posicion(3,pantalla_y)) <= raton.y && raton.y <= (recalculo_y1(270,pantalla_y))+(posicion(3,pantalla_y))){
                seleccion_4 = true;
            }
        }
        if(seleccion_4 == true){
           if(posicion(60,pantalla_x) <= raton.x && raton.x <= posicion(110,pantalla_x)){
            if(posicion(25,pantalla_y) <= raton.y && raton.y <= posicion(75,pantalla_y)){
                prueba = true;
            }
        } 
        }
        if((recalculo_x1(360,pantalla_x))-(posicion(3,pantalla_x)) <= raton.x && raton.x <= (recalculo_x1(360,pantalla_x))+(posicion(3,pantalla_x))){
            if((recalculo_y1(180,pantalla_y))-(posicion(3,pantalla_y)) <= raton.y && raton.y <= (recalculo_y1(180,pantalla_y))+(posicion(3,pantalla_y))){
                seleccion_5 = true;
            }
        }
        if(seleccion_5 == true){
           if(posicion(60,pantalla_x) <= raton.x && raton.x <= posicion(110,pantalla_x)){
            if(posicion(25,pantalla_y) <= raton.y && raton.y <= posicion(75,pantalla_y)){
                prueba = true;
            }
        } 
        }
        if((recalculo_x1(300,pantalla_x))-(posicion(3,pantalla_x)) <= raton.x && raton.x <= (recalculo_x1(300,pantalla_x))+(posicion(3,pantalla_x))){
            if((recalculo_y1(90,pantalla_y))-(posicion(3,pantalla_y)) <= raton.y && raton.y <= (recalculo_y1(90,pantalla_y))+(posicion(3,pantalla_y))){
                
                l=posicion((pantalla_x-80),pantalla_x)-(raton.x);
                m=posicion((pantalla_y-140),pantalla_y)-(raton.y);          
                l_=raton.x;
                m_=raton.y;
                
                seleccion_6 = true;
            }
        }
        if(seleccion_6 == true){
           
           if(posicion(60,pantalla_x) <= raton.x && raton.x <= posicion(110,pantalla_x)){
            if(posicion(25,pantalla_y) <= raton.y && raton.y <= posicion(75,pantalla_y)){
                if(l_>m_){
                    prueba6=1;
                }
                if(l_<m_){
                    prueba6=2;
                }
                if(l_==m_){
                    prueba6=3;
                }
            }
        } 
        }

    }else if(boton == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
        //glClearColor(1, 1, 1, 0); 
        glClear(GL_COLOR_BUFFER_BIT);
         
        
    }
    glutPostRedisplay();
}

int main(int argc,char** argv){
    glutInit(&argc,argv);
    IniciarGLUT();

    glClear(GL_COLOR_BUFFER_BIT);
    glutDisplayFunc(Pintar);
    //glutIdleFunc(Pintar);
    glutMouseFunc(Control_Raton);
    
    glutMainLoop();
    return EXIT_SUCCESS;
}