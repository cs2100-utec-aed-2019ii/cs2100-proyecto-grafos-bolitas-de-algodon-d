#include <GLUT/glut.h>
#include <iostream>

typedef struct {
   GLfloat verticeXYZ[3];
   GLfloat colorRGB[3];
} Vertice;

typedef struct {
   float x,y;
   int izda, dcha;
} EstadoRaton;

Vertice cuadrado[4] = {
   {{1,0,0},{1,0,0}},
   {{5,-4,0},{1,1,0}},
   {{9,0,0},{0,1,0}},
   {{5,4,0},{0,0,1}}
};
Vertice triangulo[3] = {
   {{-9,4,0},{1,0,0}},
   {{-5,-4,0},{0,1,0}},
   {{-1,4,0},{0,0,1}}
};
Vertice selector = {{-9,4,0},{0,1,1}};
EstadoRaton raton;
int ventana[2], vertice_sel;
GLfloat formato_global;

void IniciarGLUT() {
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize(602,600);
  glutInitWindowPosition(100,100);
  glutCreateWindow("Practica III,6 de OpenGL");
}

void PintarEscena() {
  glMatrixMode(GL_MODELVIEW);
  glClear(GL_COLOR_BUFFER_BIT);
  glLoadIdentity();
 
  int i;
 
  glBegin(GL_TRIANGLES);
      for (i=0; i<3; i++) {
         glColor3fv(triangulo[i].colorRGB);
         glVertex3fv(triangulo[i].verticeXYZ);
      }
  glEnd();
 
  glBegin(GL_QUADS);
        for (i=0; i<4; i++) {
         glColor3fv(cuadrado[i].colorRGB);
         glVertex3fv(cuadrado[i].verticeXYZ);
      }
  glEnd();
 
  glPointSize(7);
  glBegin(GL_POINTS);
      glColor3fv(selector.colorRGB);
      glVertex3fv(selector.verticeXYZ);
  glEnd();
 
  glutSwapBuffers();
}

void ReProyectar(int w, int h) {
  GLfloat formato;

  ventana[0] = w;
  ventana[1] = h;

  if(h == 0) h = 1;
     
    glViewport(0, 0, w, h);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  formato = (GLfloat)w / (GLfloat)h;
  formato_global = formato;
    if (w <= h){ 
        glOrtho (-10.0f, 10.0f, -10.0f / formato, 10.0f / formato, -1.0f, 1.0f);
    }    
    else{ 
        glOrtho (-10.0f * formato, 10.0f * formato, -10.0f, 10.0f, -1.0f, 1.0f);
    }
}

float ObtenerPosPlanoX(float x, int ancho_ventana, int alto_ventana, float pos_x_min, float pos_x_max, float format) {
   float pos_x_relativa = ((float)x/ancho_ventana); //La posición relativa de 0 a 1 en X
   float pos_plano;
   
   if (ancho_ventana<=alto_ventana){ 
    pos_plano = (pos_x_min+((pos_x_max-pos_x_min)*pos_x_relativa));
   }
   else{ 
    pos_plano = ((pos_x_min * format)+(((pos_x_max-pos_x_min) * format)*pos_x_relativa));
   }
   return pos_plano;
}

float ObtenerPosPlanoY(float y, int ancho_ventana, int alto_ventana, float pos_y_min, float pos_y_max, float format) {
   float pos_y_relativa = ((float)y/alto_ventana); //La posición relativa de 0 a 1 en Y
   float pos_plano;
   
   if (ancho_ventana<=alto_ventana) pos_plano = -((pos_y_min / format)+(((pos_y_max-pos_y_min) / format)*pos_y_relativa));
   else pos_plano = -(pos_y_min+((pos_y_max-pos_y_min)*pos_y_relativa));
   
   return pos_plano;
}

void ControlRaton(int button, int state, int x, int y) {
   if (button==GLUT_LEFT_BUTTON) {
      if (state==GLUT_DOWN) raton.izda = 1;
      else raton.izda = 0;
   }
   else if (button==GLUT_RIGHT_BUTTON) {
      if (state==GLUT_DOWN) {
            raton.dcha = 1;
         
         raton.x = ObtenerPosPlanoX(x,ventana[0],ventana[1],-10,10,formato_global);
         raton.y = ObtenerPosPlanoY(y,ventana[0],ventana[1],-10,10,formato_global);
   
         int i;
         for (i=0; i<3; i++) {
            if (raton.x > triangulo[i].verticeXYZ[0] - 0.5f &&
               raton.x < triangulo[i].verticeXYZ[0] + 0.5f &&
               raton.y > triangulo[i].verticeXYZ[1] - 0.5f &&
               raton.y < triangulo[i].verticeXYZ[1] + 0.5f ) {
               vertice_sel = i;
            }
         }
         for (i=0; i<4; i++) {
            if (raton.x > cuadrado[i].verticeXYZ[0] - 0.5f &&
               raton.x < cuadrado[i].verticeXYZ[0] + 0.5f &&
               raton.y > cuadrado[i].verticeXYZ[1] - 0.5f &&
               raton.y < cuadrado[i].verticeXYZ[1] + 0.5f ) {
               vertice_sel = 3 + i;
            }
         }
        }
      else raton.dcha = 0;
   }
}

void MovimRaton(int x, int y) {
   raton.x = ObtenerPosPlanoX(x,ventana[0],ventana[1],-10,10,formato_global);
   raton.y = ObtenerPosPlanoY(y,ventana[0],ventana[1],-10,10,formato_global);
}



void MoverVertice(int value) {
   switch (vertice_sel) {
      case 0: case 1: case 2:
         selector.verticeXYZ[0] = triangulo[vertice_sel].verticeXYZ[0];
         selector.verticeXYZ[1] = triangulo[vertice_sel].verticeXYZ[1];
      break;
      case 3: case 4: case 5: case 6:
         selector.verticeXYZ[0] = cuadrado[vertice_sel-3].verticeXYZ[0];
         selector.verticeXYZ[1] = cuadrado[vertice_sel-3].verticeXYZ[1];
      break;
   }
   
   if (raton.izda) {
      if (vertice_sel<=2) {
         triangulo[vertice_sel].verticeXYZ[0] = selector.verticeXYZ[0] = raton.x;
         triangulo[vertice_sel].verticeXYZ[1] = selector.verticeXYZ[1] = raton.y;
      }
      else {
         cuadrado[vertice_sel-3].verticeXYZ[0] = selector.verticeXYZ[0] = raton.x;
         cuadrado[vertice_sel-3].verticeXYZ[1] = selector.verticeXYZ[1] = raton.y;
      }
   }
   
   glutTimerFunc(33,MoverVertice,1);
   glutPostRedisplay();
}

int main(int argc, char **argv) {
   glutInit(&argc,argv); //Solo necesario en Linux
   IniciarGLUT();
   
   glutReshapeFunc(ReProyectar);
   glutDisplayFunc(PintarEscena);
   glutIdleFunc(PintarEscena);
   glutMouseFunc(ControlRaton);
   glutTimerFunc(33,MoverVertice,1);
   glutMotionFunc(MovimRaton);
   
   glutMainLoop();
   

   return 0;
}