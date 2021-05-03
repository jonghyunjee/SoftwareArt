#include "ofApp.h"

#ifndef PERSON_H_INCLUDED
#define PERSON_H_INCLUDED

class Person {
public:
    ofVec2f location;
    ofVec2f velocity;
    ofVec2f acceleration;
    ofVec2f force; // force of collision
    
    int maxSpeed; // limit the velocity
    int radius;
    bool touched; // whether a person is contacted or not
    
    void applyForce(ofVec2f); // affect the acceleration when collided
    void checkCollision(Person&); // detect the collision between two people
    void checkEdges(); // people don't leave the canvas
    void update();
    void display();
    Person();
    Person(float, float, bool);

};

class Carrier : public Person { // set the class to inherit from "Person"
    public:
        Carrier();
        Carrier(float, float, bool);
};

#endif // PARTICLE_H_INCLUDED
