#include "colors.inc"
#include "textures.inc"

#declare mug_sleeve = cylinder {
    <0, 0, 0>, <0, 1, 0>, 1
    pigment {
        image_map { jpeg "img/shinji.jpg" interpolate 2}
        translate -.5
        scale .5
    }
    finish {
        specular 1
        roughness .001
        reflection .1
    }
}

#declare mug_sleeve_not = cylinder {
    <0, .3, 0>, <0, 9, 0>, 3.7
    pigment { color White }
    finish { Glossy }
}

#declare mug_sleeve_top = torus {
    3.85, .15
    translate <0, 8, 0>
    pigment { color White }
    finish {
        specular 1
        roughness .001
        reflection .1
    }
}

#declare mug_sleeve_base = cone {
    <0, 0, 0>, 3.9
    <0, .1, 0>, 4
    pigment { color White }
    finish {
        specular 1
        roughness .001
        reflection .1
    }
}

#declare main_mug_sleeve = difference {
    object {
        mug_sleeve
        scale<4, 8, 4>
        rotate<0, -45, 0>
    }
    object { mug_sleeve_not }
}

#declare mug_body = union {
    object {
        main_mug_sleeve
        translate <0, 0.1, 0>
    }
    object { mug_sleeve_base }
    object { mug_sleeve_top }
}

#declare coffee = cylinder {
    <0, 0.4, 0>, <0, 6.8, 0>, 3.7
    pigment { color NewTan * .2 }
    normal { ripples .6 }
    finish { Glossy }
}

#declare handle = difference {
    torus {
        1, .1
        rotate<90, 0, 0>
        scale<2, 2.5, 8>
        translate<4, 4, 0>
    }
    object { mug_sleeve_not }
    pigment { color White }
    finish {
        specular 1
        roughness .001
        reflection .1
    }
}

#declare Mug = union {
    object { mug_body }
    object { handle }
    object { coffee }
}