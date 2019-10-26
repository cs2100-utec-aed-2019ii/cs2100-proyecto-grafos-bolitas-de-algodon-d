#ifndef SCREEN_H
#define SCREEN_H
#include<thread>
#include "./Graph.hpp"
#include "./file_management/Parser.hpp"
#include "./Macros.hpp"

template<typename T>
void screen1(Screen<T> *val){val->drawHandler();}

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
public:
  Screen(int &argc, char **argv, float x, float y):values(nullptr), values2(nullptr), isdirected(false), pantalla_x(x), pantalla_y(y)
  {
    parser = new Parser<T>(isdirected, &filename);
    glutInit(&argc, argv);
    IniciarGLUT();
    glutDisplayFunc();
    glutMouseFunc();
  }
  ~Screen()
  {
    if(values){delete values; values = nullptr;}
    if(values2){delete values2; values2 = nullptr;}
    delete parser;
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
    
  } 
  void eventHandler(int boton,int state,int mousex,int mousey)
  {

  }
  void save()
  {
    if(isdirected)
    {
      parser->save(values2);
    }
    else
    {
      parser->save(values);
    }
  }
  void read()
  {
    void *temp = parser->load();
    if(isdirected)
    {
      values2 = temp;
    }
    else
    {
      values = temp;
    }
  }
};

#endif
