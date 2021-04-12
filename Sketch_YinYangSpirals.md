# Software Art

## Sketch - Yin-Yang Spirals

**Jonghyun Jee**
jj2171@nyu.edu

## Introduction

The yin-yang sign consists of two interlocking spirals with two dots, symbolizing the balance between seemingly contrary yet interconnected qualities. I wanted to experiment with this yin-yang sign and cyclical animation techniques enabled by OpenFrameworks.

## Work Process

First, I tried to break down the symbol in 6 shapes: 2 big circles, 2 small circles, and 2 semicircles (arc). Since OpenFrameworks doesn't have a specific "ofDrawArc" function, I used "ofPath" instead to create an arc. I briefly struggled with creating these arc patterns because they didn't appear at the sketch. Later on I figured out that my input for the start and end angles was in radian not degree. I changed them from "PI/2, PI+PI/2" to "90, 270," and then they popped up in the way I had intended. Once a single symbol is completed, I used a for loop to generate a spiral by replicating this symbol in smaller scales. I created 100 yin-yang signs in total and arranged them with varying locations and scales. For the motion part, I used "ofRotateDeg" to rotate the entire coordinate system and "ofRotateXDeg" to rotate each sign along its local x-axis. 

![Apr-12-2021 15-44-30](https://user-images.githubusercontent.com/50460806/114351742-007cfe00-9ba6-11eb-833e-97e61c951124.gif)

## Reflection

Cyclic animation for this sketch produces dynamic and hypnotic visuals. What's interesting, perhaps, is that the code for this cycle motion is fairly simple and straightforward. On the other hand, the downer is that the dynamics are a little bit standardized and thus expectable after a single loop. To make it *better every loop* I think adding more random/noise might breathe in liveliness on this sketch. 
