#include "colors.inc"

#declare AshTray =
union {
  cylinder { y * .1, y * .15, .7}
  #declare counter = 0;
  #while (counter < 360)
    union { 
      sphere {y * .3, .1} 
      sphere {y * .1, .1} 
      cylinder { y * .1, y * .3, .1 }
      scale<1.1, 1, .75>
      translate z * .7
      rotate y * counter
    }
    #declare counter = counter + 15;
  #end
}
