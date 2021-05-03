# Software Art

## Assignment 3 - Storytelling

**Jonghyun Jee**
jj2171@nyu.edu

## Introduction

Project Title: Social Distancing Experiment

Since the last year, the term “social distancing” has become an example of COVID-19 lingo. Numerous governments implemented the social distancing polity to reduce human contact and prevent the spread of the pandemic. My project aims to visualize how effective “social distancing” is by simulating a brief experiment of its impact.

I was primarily inspired by this video clip [Ping Pong Balls and Mouse Traps Demonstrate Social Distancing Impact](https://youtu.be/YxVxc6ccqtQ) by the Ohio Department of Health. I watched this video quite a while ago and thought it succinctly showed why social distancing matters. Browsing around the examples from [Dan Shiffman's Nature of Code rewritten for openFrameworks](https://github.com/superartificial/Nature-Of-Code-Open-Frameworks-Port/tree/master/Nature%20Of%20Code%20OF), I wanted to emulate that experiment in the OpenFrameworks settings. 

The blueprint for my algorithm was to create: 1. A series of motionless balls (individuals) generated on the canvas, keeping same distance with each other. 2. With a click, a user can put a new ball (carrier) that randomly moves around and changes the color of the other balls when collided. 3. A user can reset the social distance between individuals, and see how the idea of social distancing can drastically alter the result.

## Work Process

1. Creating Classes

<img width="736" alt="capture1" src="https://user-images.githubusercontent.com/50460806/116861526-31e56880-ac3e-11eb-852e-6ef4be14c908.png">

The first step of this project was to create a class called “Person,” which constructs circles that symbolize individuals. Since I intended to generate an array of motionless balls, I set the initial values of both velocity and acceleration zero. This class also contains a vector "force," which is later used for calculating the force of each collision. A boolean "touched" labels whether a person has contacted with a carrier. I set the maximum velocity to prevent the object’s movement becoming a way too crazier. I specified the radius value as welll, in order to calculate the collision between two objects. 

The "Carrier" class inherits the "Person," taking the parameters from it except the velocity, location, and boolean "touched." I randomized the velocity of a carrier because a newly added carrier requires some degree of initial velocity. The location (should have named it position) receives the x-y coordinate from a mouse click. And of course, the boolean state should be different from the parent class so that a newly added person automatically becomes a carrier.

2. Force Functions

I referred to [NoC 2.1: Forces](https://github.com/superartificial/Nature-Of-Code-Open-Frameworks-Port/tree/master/Nature%20Of%20Code%20OF/NOC2_1__Forces) get the idea of how to calculate and apply forces accordingly. 

<img width="752" alt="capture2" src="https://user-images.githubusercontent.com/50460806/116863037-a4574800-ac40-11eb-9a06-3112dd55886a.png">

The applyForce() function which allows to update the acceleration value when the collision happens. The checkCollision() function below detects colliding objects on the canvas, and update the vector movement of these objects like that of a billiards table. When the state of the other object is “touched,” the collided one  also becomes “touched.” Once a white circle (uncontacted) collides with a red circle (carrier), the force value gets updated by subtracting the position values.

## Reflection

I think my project has a lot of room for improvement, both in terms of visual components and future application. It might be further developed into a sort of game, with more human-like objects and more delicate system of infection (latent period, recovery, etc.)

It was also interesting that, once the canvas is filled with red circles, they rarely cease to the dead-stop but constantly hitting each other. I think this model, if equipped with more physics, can be a good sketch to model the development of entropy. 

