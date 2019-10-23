#ifndef MACROS_H
#define MACROS_H

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
  static T value;
};

template <typename T>
struct Defaults<T*>
{
  static T* value;
};

template<typename T>
T Defaults<T>::value = 0;

template<typename T>
T* Defaults<T*>::value = nullptr;

template<>
string Defaults<string>::value = "";

template<>
char Defaults<char>::value = '\0';

#endif
