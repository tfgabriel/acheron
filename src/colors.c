#include "colors.h"
#include <stdlib.h>
#include <stdio.h>
#include "math.h"
RGBAn* setRGBAn(float r, float g, float b, float a){
  RGBAn* rgban = malloc(sizeof(RGBAn));
  rgban -> r = clampfnorm(r);
  rgban -> g = clampfnorm(g);
  rgban -> b = clampfnorm(b);
  rgban -> a = clampfnorm(a);

  return rgban;
}

RGBAn* addRGBAn(RGBAn* col1, RGBAn* col2){
  RGBAn* col = setRGBAn(
      col1->r + col2->r, 
      col1->g + col2->g, 
      col1->b + col2->b, 
      col1->a + col2->a);

  return col;
}

RGBAn* addRGBAnScalar(RGBAn* col1, float s){
  RGBAn* col = setRGBAn(
      col1->r + s, 
      col1->g + s, 
      col1->b + s, 
      col1->a);

  return col;
}

RGBAn* subtractRGBAn(RGBAn* col1, RGBAn* col2){
  RGBAn* col = setRGBAn(
      col1->r - col2->r, 
      col1->g - col2->g, 
      col1->b - col2->b, 
      col1->a - col2->a);

  return col;
}

void printColor(RGBAn* col){
   printf("red %.2f green %.2f blue %.2f alpha %.2f \n", col->r, col->g, col->b, col->a);
}
