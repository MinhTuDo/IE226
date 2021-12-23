#include "colors.inc"

#declare MovS=seed(18521578);//move pigment seed

#macro Cigarette(Len, Ash, Fire)
 #local HandleA = texture {
    pigment {
       crackle 
       color_map { [.5 Orange] [.5 Gold] } 
       scale .02
    }
 }
 
#local HandleB = texture {
    pigment{ Gold }
    finish{ specular .3 roughness 1/30 }
}

 #local Handle = texture{gradient y 
                    texture_map{[.1 HandleA scale 2.9][.1 HandleB]
                                [.13 HandleB][.13 HandleA scale 2.9]
                                [.16 HandleA scale 2.9] [.16 HandleB]
                                [.19 HandleB][.19 HandleA scale 2.9]
                    } scale.35}



 #local BasPig=pigment{White*.76}
 #local TB=pigment{agate color_map{[.8 rgb<0.6471,0.4353,0.3255>][.8 rgb<0.5922,0.3804,0.2706>][1 rgb 0]}
  rotate x*90 scale <.01,.01,.01> translate x*rand(MovS)*5}
  //rotate x*90 scale <.1,.5,.1> translate x*rand(MovS)*5}
 #local CutPig=pigment{agate color_map{[.8 rgb<0.6471,0.4353,0.3255>][.8 rgb<0.5922,0.3804,0.2706>][1 rgb 0]}
  rotate x*90 scale <.01,.01,.01> translate x*rand(MovS)*5}
 #local Ash0Pig=pigment{granite 
    color_map{[0 rgb 1][.6 rgb 1][1 rgb 0]}
    scale <.1,.1,.1> translate x*rand(MovS)*5}
 #local Ash1Pig=pigment{granite 
    color_map{[0 rgb 0][.5 rgbt 1][1 rgb 1]}
    scale <.1,.1,.1> translate x*rand(MovS)*5}
 #local FirePig=pigment{granite 
    color_map{[0 rgb 0][1 rgb<1,.5,.5>]}
    scale <.1,.1,.1> translate x*rand(MovS)*5}

 #local BurnPig=pigment{gradient y 
    pigment_map{[.495 Ash0Pig scale.5][.496 Black][.505 Black][.508 BasPig scale.5]}
    turbulence <0,.08,0> scale 2 translate -y*.95 translate x*rand(MovS)*5}

 #local Cut=box{<.1,.1,.1><-.1,-(.35+.65*Len),-.1> 
  #if(!Ash)pigment{CutPig}#end
  }
 //unburned
#local But=union{
   cylinder{0,-y*.35,.05 open texture{Handle}} 
   cylinder{0,-y*.35,.049 pigment{White*.8}} 
   cylinder{-y*.35,-y,.05 open} 
   cylinder{-y*.35,-y,.049 pigment{TB}}
   text {
      ttf "timrom.ttf" "18521578" 0, 0
      pigment { Black }
      scale .06
      rotate<6, 0, -90>
      translate<-0.02, -0.4, -.1>
   }
}
#local Wend=union{cylinder{-y*.35,-y*(.35+.65*Len),.05}
                  sphere{0,.05 scale<1,8*(1-Len),1> translate -y*(.35+.65*Len)}
                 } 
                  



#if (Len>=1) #local Out= object{But pigment{BasPig}//cut cigarette
#else
 #local Out=object{
 #if (Ash) union{ #end
 intersection{object{But} object{Cut} pigment{BurnPig translate -y*(.35+.65*Len)}}
 #if (Ash) 
  intersection{object{Wend} object{Cut inverse}
  translate y*(.35+.65*Len) scale <1,Ash,1> 
  #if (Fire=0)  pigment{Ash0Pig}#end
  #if (Fire>0)  pigment{Ash1Pig}#end 
  translate -y*(.35+.65*Len)}
  intersection{object{Wend} object{Cut inverse}
  translate y*(.35+.65*Len) scale <1,Ash,1>*.9 
   pigment{FirePig}
  #if (Fire=2) finish{ambient <1,.5,.5>} #end 
  translate -y*(.35+.65*Len)}
 } #end
 #end 
 }
 Out
#end



