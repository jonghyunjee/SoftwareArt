# Software Art

## Assignment 1 - Still

**Jonghyun Jee**
jj2171@nyu.edu

## Introduction

[Dan Buzzo's Tutorial on Sinewave Animation](https://youtu.be/kYejiSrzFzs?list=PL6QF0yo3Zj7DbN76C5-_6VCDF5CPBIz6l) explores a simple yet powerful way to visualize sine waves in OpenFrameworks. For my first assignment, I wanted to experiment with a variety of parameters that alter the shapes of the sketch. Instead of visualizing specific shapes, I tried to give some random tweaks to the code and see how everything unfolds. 

## Work Process

The draw function is characterized by two for loops. The nested loop with *i* generates an array of circle/ellipse vertically, so that overlapping shapes create a continuous geometrical pattern. The other loop with *x* replicates that pattern horizontally. The original example from Dan uses a specific set of values to create patterns. With the help of GUI, I wanted to change these values and observe how it affects the patterns. I named the first parameter "interval," as it controls how densely placed those circles are. The greater the interval value, the wider the distance among circles and thus creates a bigger shape. The second parameter "curvature" controls the varying degree of the radius of each circle. The greater the curvature value, the faster the size variation and thus creates more curved patterns.  


![i50_c50_ff-1](https://user-images.githubusercontent.com/50460806/113558186-2b150700-963a-11eb-966a-a13fda3e485a.png)
Interval: 50, Curvature: 50, Toggle: Off, Alpha Mode: Off

![i250_c10_ff-1](https://user-images.githubusercontent.com/50460806/113558284-5697f180-963a-11eb-8b55-99e836d6b8d6.png)
Interval: 250, Curvature: 10, Toggle: Off, Alpha Mode: Off

The toggle button allows to switch between 1) *ofDrawCircle(interval * x + 100 * sin(i * curvature * 0.001 + time + x), interval + i, interval + 40 * sin(i * curvature * 0.0005 + time + x))* and 2) *ofDrawEllipse(interval * x + 100 * sin(i * curvature * 0.001 + time + x), interval + i, interval + 60 * cos(i * curvature * 0.0005 + time + x), interval + 40 * tan(i * curvature * 0.001 + time + x));.* When the toggle is switched on, my sketch replaces each circle with an ellipse that uses cosine and tangent function for width and height, respectively. Since the tangent function has a vertical asymptote, it generates drastically different visuals.


![i50_c5_a500_nn-1](https://user-images.githubusercontent.com/50460806/113559068-b9d65380-963b-11eb-846b-db85ccb9f11a.png)
Interval: 50, Curvature: 5, Alpha Offset: 500, Toggle: On, Alpha Mode: On

![i100_c20_a200_w4_nn-1](https://user-images.githubusercontent.com/50460806/113559144-d6728b80-963b-11eb-856b-7f28d5b1fe83.png)
Interval: 100, Curvature: 20, Alpha Offset: 200, Alpha Value: 4, Toggle: On, Alpha Mode: On

