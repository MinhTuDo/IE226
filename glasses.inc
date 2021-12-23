#include "colors"
#include "shapes"
#include "textures"

declare Lens=
  intersection{
    sphere{<0,-5,0>, 8}
    sphere{<0,5,0>, 8}
    scale 0.16
    texture{Glass3}
    finish{ambient 0.3}}

#declare Frame=
  union{
    difference{
      torus{ 5, 0.3}
      cylinder{ <0,-1,0>, <0,1,0>, 4.7}
      scale <1,1,0.7>
      translate -7*x}
    difference{
      torus{ 5, 0.3}
      cylinder{ <0,-1,0>, <0,1,0>, 4.7}
      scale <1,1,0.7>
      translate 7*x}
    difference{
      torus{ 3, 0.3
             scale <0.9,1,1>}
      box{ <-5,-1,-5>, <5,1,0>}
      cylinder{ <0,-1,0>, <0,1,0>, 5
                scale <1,1,0.7>
                translate -7*x}
      cylinder{ <0,-1,0>, <0,1,0>, 5
                scale <1,1,0.7>
                translate 7*x}}
    cylinder{<-12,0,0>, <-12,-15,0>, 0.3}
    cylinder{<12,0,0>, <12,-15,0>, 0.3}
    union{
      intersection{
        torus{5, 0.3}
        box{<0,-1,0>, <8,1,6>}}
      sphere{<5,0,0>, 0.3}
      scale <1.5,1,1>
      rotate -90*z
      translate <-12,-15,-5>}
    union{
      intersection{
        torus{5, 0.3}
        box{<0,-1,0>, <8,1,6>}}
      sphere{<5,0,0>, 0.3}
      scale <1.5,1,1>
      rotate -90*z
      translate <12,-15,-5>}
    texture{pigment{color DarkWood scale 0.3}}
    finish{ambient 0.5}}

#declare Glasses=
  union{
    object{Frame pigment {color rgb <0.20392157, 0.21176471, 0.15686275> * .3}}
    object{Lens
           pigment {color rgbt <0.99607843, 0.97647059, 0.8627451>}
           scale <5,1,5*0.7>
           translate -7*x}
    object{Lens
           pigment {color rgbt <0.99607843, 0.97647059, 0.8627451>}
           scale <5,1,5*0.7>
           translate 7*x}}


// camera{ location <0,100,-300>
//         look_at <0,0,0>}
// light_source{ <100,200,-200>
//               color White}
// light_source{ <-100,200,-200>
//               color White}

// object{Glasses scale 15 rotate <-90,45,0> translate -80*x}