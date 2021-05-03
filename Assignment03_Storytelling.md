# Software Art

## Assignment 3 - Storytelling

**Jonghyun Jee**
jj2171@nyu.edu

## Introduction

Project Title: Social Distancing Experiment

Since the last year, the term “social distancing” has become an example of COVID-19 lingo. Numerous governments implemented the social distancing polity to reduce human contact and prevent the spread of the pandemic. My project aims to visualize how effective “social distancing” is by simulating a brief experiment of its impact.

I was primarily inspired by this video clip [Ping Pong Balls and Mouse Traps Demonstrate Social Distancing Impact](https://youtu.be/YxVxc6ccqtQ) by the Ohio Department of Health. I watched this video quite a while ago and thought it succinctly showed why social distancing matters. Browsing around the examples from [Dan Shiffman's Nature of Code rewritten for openFrameworks](https://github.com/superartificial/Nature-Of-Code-Open-Frameworks-Port/tree/master/Nature%20Of%20Code%20OF), I wanted to emulate that experiment in the OpenFrameworks settings. 

The blueprint for my algorithm is to create: 1. A series of motionless balls (individuals) are generated on the canvas, keeping same distance with each other. 2. With a click, a user can put a new ball (carrier) that randomly moves around and change the color of the other balls when collided. 3. A user can reset the social distance between individuals, and see how the idea of social distancing can drastically change the result.

## Work Process

![yinyang](https://user-images.githubusercontent.com/50460806/115202667-962e0580-a131-11eb-8cae-44c59a7bb0f7.png)

In my previous sketch, I used arc and circle functions to draw a yin-yang shape. My original plan was to get a boundary of this path and fill it with strings of 0 and 1. And yet, it was pretty challenging to trace the boundary of this shape because it consists of several smaller paths. So instead, I replaced my shape with the image above and grayscaled it to get color values of each pixel. I referred to this forum [RGB data from ofImage](https://forum.openframeworks.cc/t/rbg-data-from-ofimage/1645) and created double for loops that store RGB values in an unsigned char. Instead of going pixel by pixel, I updated the counter by 10 pixels to optimize the computation process. I put an if statement within the nested loop so that if a red value is smaller than 127 (darker), it will draw a text string that is either 0 or 1. A digit is randomly assigned between these two and thus it keeps flickering when called in draw function. Reminds me of ASCII art.

![yinyang](https://user-images.githubusercontent.com/50460806/115205106-2bca9480-a134-11eb-9845-4fa2b43160d4.gif)

Once the digital yin-yang sign is done, I applied several rotate functions to keep it rotating along its local x and y axis. What I had envisioned was to experiment with these digits. I wanted them to be dispersed, morph into different form, and turn back into its original yin-yang shape at the end of the loop. However, time was scarce and so my skill. I need to further research on how to manipulate these 0s and 1s. As a workaround, I created a separate spiral that consists of 0s and 1s. I wanted to visualize a twirling array of digits orbiting around the yin-yang sign. I referred to the chapter of the OF Book [Intro to Graphics.](http://openframeworks.kr/ofBook/chapters/intro_to_graphics.html) I modified this source code to regularly clear the screen, using a transparent rectangle and draw a spiral. Whereas the source code generates a series of rectangles, I replaced that part with drawString() function that generates digits instead. 

https://vimeo.com/538567132

https://vimeo.com/538567584

As a result, strings of 0 and 1 are orbiting the flickering yin-yang sign, which also consists of 0 and 1. 

https://vimeo.com/538581919

If the ofBackground() function is commented out in a draw function, it generates some interesting visuals that keep all the afterimages. Feels like a digital eye of truth. 

## Reflection

I spent too much time on the ideation part. To visualize the parallel between the digital world and yin-yang duality was harder than I had thought. But still, I'm very intrigued with this idea and would like to continue developing this sketch afterwards. On the visual side, I think there's much room for improvement. I limited the color scheme in black and white because of the original shades of the yin-yang symbol. I intended to focus more on harmony than discord, or paradoxically the balance between harmony and discord. I initially used some noise function to control the movement of the spiral, but it easily got too messy. Thus I had to stick with repetitive cyclical motions. If given more time, I would like to create a brief animation that begins with this yin-yang symbol, which in turn disintegrates into digits (entropy?) and morphs into natural forms. The cycle of water, for example, can be a suitable narrative. A bunch of 0s and 1s form a cloud, transform to raindrops, be a part of a river, go underground, flow into an ocean, evaporate and again form a cloud, and so forth. This animation will visualize a *poem* that presents the digital interpretation of Taoism and Yin-Yang duality.

