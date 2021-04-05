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

The toggle button allows us to switch between 1) *ofDrawCircle(interval * x + 100 * sin(i * curvature * 0.001 + time + x), interval + i, interval + 40 * sin(i * curvature * 0.0005 + time + x))* and 2) *ofDrawEllipse(interval * x + 100 * sin(i * curvature * 0.001 + time + x), interval + i, interval + 60 * cos(i * curvature * 0.0005 + time + x), interval + 40 * tan(i * curvature * 0.001 + time + x));.* When the toggle is switched on, my sketch replaces each circle with an ellipse that uses cosine and tangent function for width and height, respectively. Since the tangent function has a vertical asymptote, it generates drastically different visuals.


![i50_c5_a500_nn-1](https://user-images.githubusercontent.com/50460806/113559068-b9d65380-963b-11eb-846b-db85ccb9f11a.png)
Interval: 50, Curvature: 5, Alpha Offset: 500, Toggle: On, Alpha Mode: On

![i100_c20_a200_w4_nn-1](https://user-images.githubusercontent.com/50460806/113559144-d6728b80-963b-11eb-856b-7f28d5b1fe83.png)
Interval: 100, Curvature: 20, Alpha Offset: 200, Alpha Value: 4, Toggle: On, Alpha Mode: On

I particularly like this use of tangent function because of its unpredicatbility. Since the tangent function goes between negative and positive infinity, the result shows a lot more glitchy shapes. This aesthetics sharply contrasts with that of sine and cosine function, which yield relatively stable patterns. 

The other button "alphaValue" enables the alpha mode. The user can directly control the alpha value of shapes with the RGBA setup and also control the varying degree of alpha value (alpha offset) too. Images with low alpha values shows out-of-focus patterns that resemble soft bokeh. 

![i100_c15_a100_w3_fn-1](https://user-images.githubusercontent.com/50460806/113560170-872d5a80-963d-11eb-8742-079c1c1ecd30.png)
Interval: 100, Curvature: 15, Alpha Offset: 100, Alpha Value: 3, Toggle: Off, Alpha Mode: On

![i50_c50_a200_x255_z255_w3_fn-1](https://user-images.githubusercontent.com/50460806/113560213-9a402a80-963d-11eb-9083-85ea9bd0b4cf.png)
Interval: 50, Curvature: 50, Alpha Offset: 200, Red: 255, Green: 127, Blue: 255, Alpha Value: 3, Toggle: Off, Alpha Mode: On

![i200_c5_a500_y255_w5_fn-1](https://user-images.githubusercontent.com/50460806/113560286-b8a62600-963d-11eb-8dc3-0ff0c3f28370.png)
Interval: 200, Curvature: 5, Alpha Offset: 500, Red: 127, Green: 255, Blue: 127, Alpha Value: 5, Toggle: Off, Alpha Mode: On

## Reflection

Shapes: It was tantalizing to learn how an overlapped array of circles could create such a variety of shapes. Unlike straight lines, circles generated more vibrant, organic-like dynamics especially when combined with sine functions. On the other hand, those with tangent functions yielded drastically different results from the same inputs. If the alpha mode is turned off, however, tangent-based patterns displayed rather bland stripes that resemble TV color bars.

Colors: The default color setting of my sketch seems like the shades of sky: a smooth gradation between sky-blue and sunset glow. In this sense, the repeated color transition (blue, red, black) reminds me of the passage of time. Since the code itself uses "elapsed time" as one of the main inputs, I feel the color scheme accordingly reflects the idea of temporality underlying this sketch.

Rules: The mechanism of this sketch is straightforward. In a nutshell, this sketch is a contniuum of circles. The various parameters above modify not only the features of circles but also how fast those features get changed. I wanted to include more variations such as changing the default shape to something else than a circle. The generated results, however, were not very visually interesting. It would be better if I were more familiar with mathematical/geometrical concepts. For the future projects, I would like to do further research on math principles such as fractals, spirals, sequences, and so forth.

