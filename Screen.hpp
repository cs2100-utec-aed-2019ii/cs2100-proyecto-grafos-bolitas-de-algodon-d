#ifndef SCREEN_H
#define SCREEN_H
#include<thread>
#include "./Graph.hpp"
#include "./file_management/Parser.hpp"
#include "./Macros.hpp"

typedef struct{
    GLfloat verticeXYZ[3];
    GLfloat colorRGB[3];
}Vertice;

typedef struct{
    float x,y;
    int izq,der;
}EstadoRaton;

template<typename T=char>
class Screen
{
private:
  graph<false,T> *values;
  graph<true,T> *values2;
  bool isdirected;
  string filename;
  float pantalla_x;
  float pantalla_y;
  Parser<T> *parser;
  EstadoRaton raton;
  float x,y;
public:
  Screen(int &argc, char **argv, float x, float y, void(*draw)(void), void(mouse)(int, int, int, int)):values(nullptr), values2(nullptr), isdirected(false), pantalla_x(x), pantalla_y(y)
  {
    parser = new Parser<T>(isdirected, &filename);
    glutInit(&argc, argv);
    IniciarGLUT();
    glClear(GL_COLOR_BUFFER_BIT);
    glutDisplayFunc(draw);
    glutMouseFunc(mouse);
  }
  ~Screen()
  {
    if(values){delete values; values = nullptr;}
    if(values2){delete values2; values2 = nullptr;}
    delete parser;
  }
  float posicion(float x,int pantalla){
    return ((x*2)/pantalla);
  }

  float valx(float x)
  {
    graph<false,T> *val = (isdirected)? (graph<false,T> *)values2 : values;
    float result = 0;
    if(val)
    {
      float max_x = val->max_x;
      result = x*(1.705/max_x);
      result += 0.17;
    }
    return result;
  }
  float valy(float y)
  {
    graph<false,T> *val = (isdirected)? (graph<false,T> *)values2 : values;
    float result = 0;
    if(val)
    {
      float max_y = val->max_y;
      result = y*(1.416/max_y);
      result += 0.5;
    }
    return result;
  }

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
  void IniciarGLUT(){
    glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
    glutInitWindowSize(pantalla_x,pantalla_y);
    glutInitWindowPosition(100,100);
    glutCreateWindow("UwU");
  }

  void Start()
  {
    glutMainLoop();
  }

  void drawHandler(void)
  {
    graph<false,T> *val = (isdirected)? (graph<false,T> *)values2 : values;
    
    glPushMatrix();
    glTranslatef(-1.0,-1.0,0.0);

    if(val)
    {
      glPointSize(10);
      glBegin(GL_POINTS); 
      val->nodos.for_each(
          [this](Vertex<T> *i)
          {
            glColor3f(i->r/255.0,i->g/255.0,i->b/255.0);
            glVertex3f(valx(i->x), valy(i->y), 0);
          }
      );
      glEnd();

      glBegin(GL_LINES);
      val->links.for_each(
          [this](Link<T> *i)
          {
            glColor3f(i->r/255.0,i->g/255.0,i->b/255.0);
            glVertex2f(valx(i->partida->x), valy(i->partida->y));
            glVertex2f(valx(i->llegada->x), valy(i->llegada->y));
          }
      );
      glEnd();
    }

    glPopMatrix();

    glFlush();
  } 
  void eventHandler(int boton,int state,int mousex,int mousey)
  {
    if (boton == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        raton.x = ((mousex)*2)/pantalla_x;
        x = raton.x;
        std::cout<<mousex<< " ";
        std::cout<<raton.x<<std::endl;
        std::cout<<"______"<<std::endl;
        
        raton.y = ((pantalla_y-mousey)*2)/pantalla_y;
        y = raton.y;
        std::cout<<pantalla_y-mousey<< " ";
        std::cout<<raton.y<<std::endl;

        if(posicion(60,pantalla_x) <= raton.x && raton.x <= posicion(110,pantalla_x)){
            if(posicion(25,pantalla_y) <= raton.y && raton.y <= posicion(75,pantalla_y)){
               save();
            }
        }
        if(posicion(160,pantalla_x) <= raton.x && raton.x <= posicion(210,pantalla_x)){
            if(posicion(25,pantalla_y) <= raton.y && raton.y <= posicion(75,pantalla_y)){
               import();
            }
        }  
    }else if(boton == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
       glClear(GL_COLOR_BUFFER_BIT);
        
    }
    glutPostRedisplay();  

  }
  void save()
  {
    if(isdirected)
    {
      if(!values2){values2 = new graph<true, T>();}
      parser->save(values2);
    }
    else
    {
      if(!values){values = new graph<false, T>();}
      parser->save(values);
    }
  }
  void read()
  {
    void *temp = parser->load();
    if(isdirected)
    {
      if(values2){delete values2;values2 = nullptr;}
      values2 = (graph<true,T> *)temp;
    }
    else
    {
      if(values){delete values;values = nullptr;}
      values = (graph<false,T> *)temp;
    }
  }
  void import()
  {
    isdirected = false;
    if(!values){values = new graph<false, T>();}
    parser->import(values);
    cout << "VTK Cargado" << endl;
  }
};

#endif
