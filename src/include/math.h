#ifndef __MATH_H__
#define __MATH_H__

#ifdef __cplusplus
extern "C" {
#endif

// Misc math functions (misc.c).
int abs(int x);
double fabs(double x);

// Trigonometry (trig.c).
double sin(double x);
double cos(double x);
double tan(double x);
double asin(double x);
double acos(double x);
double atan(double x);
double atan2(double x);

#ifdef __cplusplus
}
#endif

#endif
