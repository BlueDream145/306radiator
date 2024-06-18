# 306radiator
 
A radiator is placed in a square room. We want to know how the temperature is distributed in the roombased on the radiator’s location. The temperature in the room verifies the very famous heat equation:∂2T∂x2(x, y) +∂2T∂y2(x, y) =f(x, y)where:

•Tis the room temperature,

•∂2T /∂u2is the second partial derivative ofTrelative tou,

•fis the heating power emitted by the radiator.

To simplify things, we assume that the temperature along the room’s walls is non-existent (these are theboundary conditions), and that the radiator is regular; the f function is therefore null everywhere except inthis point.It is impossible to analytically solve this equation. Therefore, you must look for an approximation. In or-der to do this, we map the room on a grid ofN2points, by only considering

Nvalues ofx(namedx0=0, x1, . . . , xN−1) andNvalues ofy(namedy0= 0, y1, . . . , yN−1) and defining

has the distance betweentwo points.

It is therefore possible to approximate the second derivative inxandyby using the following formulas,with

1≤i, j≤N−2:∂2T∂x2(xi, yj) =T(xi−1, yj)−2T(xi, yj) +T(xi+1, yj)h2∂2T∂y2(xi, yj) =T(xi, yj−1)−2T(xi, yj) +T(xi, yj+1)h2

USAGE

./306radiator n ir jr [i j]

DESCRIPTION

n           size of the room

(ir, jr)    coordinates of the radiator

(i, j)      coordinates of a point in the room
