#include "math.h"

float absf(float a){
  if(a<0.0f)
    a= -a;
  return a;
}

float floatMod(float a, float b){
  return absf(a - (int)(a/b) * b);
}

float clampf(float a, float min, float max){
  if(a<=min)
    a = min;
  else if(a>=max)
    a = max;
  return a;
}

float clampfnorm(float a) {
  return clampf(a, 0.0f, 1.0f);
}

void clampfnormv(float* a){
  int sz = sizeof(a)/sizeof(float*);

  for(int i = 0; i < sz; i++){
    a[i] = clampfnorm(a[i]);
  }
}

