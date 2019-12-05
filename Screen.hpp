#ifndef SCREEN_H
#define SCREEN_H
#define ECHAP 27
#include <future>
#include "./Iterator.hpp"
#include "./Graph.hpp"
#include "./file_management/Parser.hpp"
#include "./Macros.hpp"

int llave1,llave2;

int puerta1;

typedef struct{
  GLfloat verticeXYZ[3];
  GLfloat colorRGB[3];
}Vertice;

typedef struct{
  float x,y;
  int izq,der;
}EstadoRaton;

template<typename T=int>
class Screen
{
private:
  graph<false,T> *values;
  graph<true,T> *values2;
  Vertex<T> *first;
  Vertex<T> *second;
  Iterator<T> *itr;
  bool isdirected;
  string filename;
  float pantalla_x;
  float pantalla_y;
  Parser<T> *parser;
  EstadoRaton raton;
  float x,y;
  future<void> thread;
public:
  Screen(int &argc, char **argv, float x, float y, void(*draw)(void), void(mouse)(int, int, int, int), void(keys)(unsigned char,int, int)):values(nullptr), values2(nullptr), isdirected(false), pantalla_x(x), pantalla_y(y), itr(nullptr), first(nullptr), second(nullptr)
  {
    parser = new Parser<T>(isdirected, &filename);
    glutInit(&argc, argv);
    IniciarGLUT();
    glClear(GL_COLOR_BUFFER_BIT);
    glutDisplayFunc(draw);
    glutMouseFunc(mouse);
    glutKeyboardFunc(keys);
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

    //Botones
  Vertice Insertar[4] = {
    {{posicion(60,pantalla_x),posicion(75,pantalla_y),0},{0,1,0}},
    {{posicion(110,pantalla_x),posicion(75,pantalla_y),0},{0,1,0}},
    {{posicion(110,pantalla_x),posicion(25,pantalla_y),0},{0,1,0}},
    {{posicion(60,pantalla_x),posicion(25,pantalla_y),0},{0,1,0}}    
  };
  Vertice Eliminar[4] = {
    {{posicion(160,pantalla_x),posicion(75,pantalla_y),0},{211.0/100,84.0/100,0.0/100}},
    {{posicion(210,pantalla_x),posicion(75,pantalla_y),0},{211.0/100,84.0/100,0.0/100}},
    {{posicion(210,pantalla_x),posicion(25,pantalla_y),0},{211.0/100,84.0/100,0.0/100}},
    {{posicion(160,pantalla_x),posicion(25,pantalla_y),0},{211.0/100,84.0/100,0.0/100}}
    
  };
  Vertice Siguiente[4] = {
    {{posicion(260,pantalla_x),posicion(75,pantalla_y),0},{192.0/250.0,57.0/250.0,43.0/250.0}},
    {{posicion(310,pantalla_x),posicion(75,pantalla_y),0},{192.0/250.0,57.0/250.0,43.0/250.0}},
    {{posicion(310,pantalla_x),posicion(25,pantalla_y),0},{192.0/250.0,57.0/250.0,43.0/250.0}},
    {{posicion(260,pantalla_x),posicion(25,pantalla_y),0},{192.0/250.0,57.0/250.0,43.0/250.0}}
  };

  Vertice Movimiento[4] = {
    {{posicion(360,pantalla_x),posicion(75,pantalla_y),0},{192.0/250.0,57.0/250.0,43.0/250.0}},
    {{posicion(410,pantalla_x),posicion(75,pantalla_y),0},{192.0/250.0,57.0/250.0,43.0/250.0}},
    {{posicion(410,pantalla_x),posicion(25,pantalla_y),0},{192.0/250.0,57.0/250.0,43.0/250.0}},
    {{posicion(360,pantalla_x),posicion(25,pantalla_y),0},{192.0/250.0,57.0/250.0,43.0/250.0}}
  };

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
  void drawtext(const char *text, int length, float x,float y){

    glRasterPos2f(x,y);
    for(int i=0;i<length;i++){
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15,(int)text[i]);
    }
  }
  void drawHandler(void)
  {
    graph<false,T> *val = (isdirected)? (graph<false,T> *)values2 : values;
    
    glPushMatrix();
    glTranslatef(-1.0,-1.0,0.0);

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

    glBegin(GL_QUADS);
        for (int i=0; i<4; i++) {
         glColor3fv(Siguiente[i].colorRGB);
         glVertex3fv(Siguiente[i].verticeXYZ);
        }
    glEnd();

    glBegin(GL_QUADS);
        for (int i=0; i<4; i++) {
         glColor3fv(Movimiento[i].colorRGB);
         glVertex3fv(Movimiento[i].verticeXYZ);
        }
    glEnd();

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

      if(llave1 == 1 && llave2 == 1)  
      {     
        glColor3f(1.0,0.0,0.0);
        glPointSize(10); 
        glBegin(GL_POINTS); 
        glVertex2f(raton.x,raton.y);  
        llave2 = 0;
        glEnd();
      }

      glPointSize(5);
      glBegin(GL_POINTS);
        //Vertex<T> *i;
        glColor3f(255/255.0,215/255.0,0/255.0);
        glVertex3f(valx(227), valy(340), 0);
      
      glEnd();
    }
    std::string text1;
    text1 ="Save";
    glColor3f(0,0,0);
    drawtext(text1.data(),text1.size(),posicion(65,pantalla_x),posicion(50,pantalla_y));

    std::string text2;
    text2 ="Read";
    glColor3f(0,0,0);
    drawtext(text2.data(),text2.size(),posicion(165,pantalla_x),posicion(50,pantalla_y));

    std::string text3;
    text3 ="Import";
    glColor3f(0,0,0);
    drawtext(text3.data(),text3.size(),posicion(260,pantalla_x),posicion(50,pantalla_y));

    std::string text4;
    text4 ="Movi";
    glColor3f(0,0,0);
    drawtext(text4.data(),text4.size(),posicion(365,pantalla_x),posicion(50,pantalla_y));
    
    glPopMatrix();

    glFlush();
  } 
  void eventHandler(int boton,int state,int mousex,int mousey)
  {
    graph<false,T> *val = (isdirected)? (graph<false,T> *)values2 : values;
    if (boton == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
      raton.x = ((mousex)*2)/pantalla_x;
      raton.y = ((pantalla_y-mousey)*2)/pantalla_y;
      y = raton.y;

      if(posicion(62.7808,pantalla_x) <= raton.x && raton.x <= posicion(600,pantalla_x)){
        if(posicion(125.67336,pantalla_y) <= raton.y && raton.y <= posicion(459.84,pantalla_y)){
          llave2 = 1;
          //aqui va la funcion insert
        }
      }

      if(val)
      {
        Vertex<T> *temp = nullptr;
        val->nodos.for_each(
          [this, temp](Vertex<T> *i) mutable -> void{
            if((valx(i->x))-posicion(4,pantalla_x) <= raton.x && raton.x <= (valx(i->x))+posicion(4,pantalla_x))
            {
              if((valy(i->y))-posicion(4,pantalla_y) <= raton.y && raton.y <= (valy(i->y))+posicion(4,pantalla_y))
              {
                temp = i;
                llave2 = 0; 
              }
            }
            if(temp)
            {
              //std::cout<<"Posicion del nodo: "<<std::endl; 
              //std::cout<<valx(i->x)<<" "<<valy(i->y)<<std::endl;        
              first = temp;
              if(!itr)
              {
                itr = new Iterator<T>(temp);
              }
              else
              {
                delete itr;
                itr = new Iterator<T>(temp);
              }
              //cout << "EL primero es: " << first << endl;
              temp=nullptr;
            }
          }
        );
      }

      if(posicion(60,pantalla_x) <= raton.x && raton.x <= posicion(110,pantalla_x)){
        if(posicion(25,pantalla_y) <= raton.y && raton.y <= posicion(75,pantalla_y)){
          thread = async(launch::async, save, this);
        }
      }
      if(posicion(160,pantalla_x) <= raton.x && raton.x <= posicion(210,pantalla_x)){
        if(posicion(25,pantalla_y) <= raton.y && raton.y <= posicion(75,pantalla_y)){
          thread = async(launch::async, read, this);
        }
      }
      if(posicion(260,pantalla_x) <= raton.x && raton.x <= posicion(310,pantalla_x)){
        if(posicion(25,pantalla_y) <= raton.y && raton.y <= posicion(75,pantalla_y)){
          thread = async(launch::async, import, this);
          llave1 = 1;
        }
      }  
      //nodo final
       if(posicion(360,pantalla_x) <= raton.x && raton.x <= posicion(410,pantalla_x)){
        if(posicion(25,pantalla_y) <= raton.y && raton.y <= posicion(75,pantalla_y)){
          graph<false, T>::dijkstra(first, second);
        }
      }
    }
    else if(boton == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {

      raton.x = ((mousex)*2)/pantalla_x;
      raton.y = ((pantalla_y-mousey)*2)/pantalla_y;
      y = raton.y;

      if(val)
      {
        Vertex<T> *temp = nullptr;
        val->nodos.for_each(
          [this, &temp](Vertex<T> *i) mutable -> void{
            if((valx(i->x))-posicion(4,pantalla_x) <= raton.x && raton.x <= (valx(i->x))+posicion(4,pantalla_x))
            {
              if((valy(i->y))-posicion(4,pantalla_y) <= raton.y && raton.y <= (valy(i->y))+posicion(4,pantalla_y))
              {
                llave2 = 0; 
                temp = i;
              }
            }
          }
        );
        if(temp)
        {
          second = temp;
          second->r = 255;
          second->g = 0;
          second->b = 0;
          //cout << "EL segundo es: " << second << endl;
          temp=nullptr;
        }
      }
      //nodo final
    }
    glutPostRedisplay();  
  }
  static void save(Screen<T> *val)
  {
    if(val->isdirected)
    {
      if(!val->values2){val->values2 = new graph<true, T>();}
      val->parser->save(val->values2);
    }
    else
    {
      if(!val->values){val->values = new graph<false, T>();}
      val->parser->save(val->values);
    }
    cout << "Grafo Guardado" << endl;
  }
  static void read(Screen<T> *val)
  {
    void *temp = val->parser->load();
    if(val->isdirected)
    {
      if(val->values2){delete val->values2;val->values2 = nullptr;}
      val->values2 = (graph<true,T> *)temp;
    }
    else
    {
      if(val->values){delete val->values;val->values = nullptr;}
      val->values = (graph<false,T> *)temp;
    }
    cout << "Grafo Leido" << endl;
    glutPostRedisplay();
  }
  static void import(Screen<T> *val)
  {
    val->isdirected = false;
    if(!val->values){val->values = new graph<false, T>();}
    val->parser->import(val->values);
    cout << "VTK Cargado" << endl;
    glutPostRedisplay();
  }
  void closeall(unsigned char tecla,int x,int y)
  {
    switch (tecla) {
	    case ECHAP:
        delete values2;
        delete values;
		    exit(0);
		    break;
      case 'a':
        ++(*itr);
        glutPostRedisplay();
        break;
      case 'd':
        --(*itr);
        glutPostRedisplay();
        break;
	    default:
	    	break;
	  }
  }
};

#endif
