#include "colors.inc"

#include "mug.inc"
#include "ash_tray.inc"
#include "cigarette.inc"
#include "glasses.inc"

background{Black}

light_source{<0, 10, -30> color 1}

camera{location <0, 5, -17> look_at <2, 4, 0>}

#declare D = .3;

sky_sphere {
        pigment {
                crackle
                color_map {
                        [pow(0.3, D) color rgb<0.03529412, 0., 0.43137255>]
                        [pow(0.5, D) color White*10]
                }
                scale .005/D
        }
        translate <0, 0, 3> // <x, y, z>

}

sphere { <0,1,0>, -4  
         scale<40,1.25,5>
         
        
       texture{ Polished_Chrome
                pigment {color Red * 3}
                normal { waves 1.6 phase clock turbulence 3.2  }
                finish { reflection 0.60 specular .9 roughness .1 }
                scale  15
              }
         rotate<0,0,0>  translate<-5,-1,85>  
       }

plane { <0,1,0>, -4 
        texture{ pigment{ color rgb<0.90196078, 0.85882353, 0.70196078> }
             normal { bumps 0.75 scale 0.015 }
                 finish { phong 0.1 }
               } // end of texture
      } // end of plane

// fog on the ground -----------------------
fog { fog_type   2
      distance   50
      color      rgb<1, 0.07058824, 0.78431373> * 0.4
      fog_offset 0.1
      fog_alt    1.3
      turbulence 1.8
    } //

text {
      ttf "timrom.ttf" "Do Minh Tu - 18521578" 0, 0
      pigment { Black }
      scale .8
      rotate <0, 5, 0>
      translate<-2, -0.5, -5>
}


object{Mug rotate <-10, 40, -5> translate <2, -1, 5> scale 0.5}
object{AshTray pigment{rgb<0.60392157, 0.65882353, 0.58823529>*.75} finish{specular.5 roughness 1/30} translate<-2, -1, 1> rotate <-10, 5, 2> scale 2.5}

object{Cigarette(0.7,0.4,0.9) rotate<120, -80, 2> translate<-1.9, -0.6, 1.1> scale 5}
object{Cigarette(0.2,0.1,0.3) rotate<80, -1, 3> translate<-1, -0.3, 0.9> scale 4}
object{Cigarette(0.2,0.1,0.3) rotate<80, 80, 3> translate<-1, -0.3, 0.9> scale 4}
object{Cigarette(0.3,0.1,0.15) rotate<-88, 88, 5> translate<-1.4, -0.3, 0.4> scale 4}

object{Glasses rotate<-90, 30, 0> translate<25, 0, 0> scale .3}



