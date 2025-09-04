#ifndef __colors_h_
#define __colors_h_

typedef struct{
  float r, g, b, a;
}RGBAn;

RGBAn* setRGBAn(float r, float g, float b, float a);
RGBAn* setRGBAnEmpty();
RGBAn makeRGBAn(float r, float g, float b, float a);
RGBAn* addRGBAn(RGBAn* col1, RGBAn* col2);
RGBAn* addRGBAnScalar(RGBAn* col1, float s);
RGBAn* subtractRGBAn(RGBAn* col1, RGBAn* col2);
#endif
