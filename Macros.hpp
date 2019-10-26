#ifndef MACROS_H
#define MACROS_H

#define GL_SILENCE_DEPRECATION

#ifdef OSX

#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>

#else

#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

#endif

#include <iostream>
using namespace std;

template <typename T>
struct Defaults
{
  static int counter;
  static T value;
  static T get_value();
};

template <typename T>
struct Defaults<T*>
{
  static T* value;
};

template<typename T>
int Defaults<T>::counter = -1;

template<typename T>
T Defaults<T>::value = 0;

template<typename T>
T Defaults<T>::get_value()
{
  counter++;
  return value + counter;
}

template<typename T>
T* Defaults<T*>::value = nullptr;

template<>
int Defaults<string>::counter = -1;

template<>
string Defaults<string>::value = "";

template<>
string Defaults<string>::get_value()
{
  return value;
}

template<>
int Defaults<char>::counter = -1;

template<>
char Defaults<char>::value = 49;

template<>
char Defaults<char>::get_value()
{
  counter++;
  return value + counter;
}

#endif
