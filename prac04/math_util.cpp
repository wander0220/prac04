#include "math_until.h"
#include <cmath>

bool isCircleCollided(float ax, float ay, float ar
	, float bx, float by, float br){

float dx = bx - ax;
float dy = by - ay;

float d = sqrt(dx * dx + dy * dy);

if (ax + bx < d) {
	return true;
}
return false;
}