#include "Person.h"
#include "ofApp.h"

Person::Person(){
    acceleration = ofVec2f(0.0, 0.0);
    velocity = ofVec2f(0.0, 0.0);
    location = ofVec2f(0.0, 0.0);
    force = ofVec2f(0.0, 0.0);
    
    maxSpeed = 7; // limits the max velocity
    radius = 5;
    touched = false;
}

Person::Person(float initX, float initY, bool state){ // receive values from the setupPeople()
    acceleration = ofVec2f(0.0, 0.0);
    velocity = ofVec2f(0.0, 0.0);
    location = ofVec2f(initX,initY);
    force = ofVec2f(0.0,0.0);

    maxSpeed = 7;
    radius = 5;
    touched = state;
}

Carrier::Carrier(){ // inherit the class "Person"
    velocity = ofVec2f(ofRandom(-maxSpeed, maxSpeed), ofRandom(-maxSpeed, maxSpeed)); // a new person requires initial velocity
    
    touched = true; // a new person is already "contacted" from the beginning
}

Carrier::Carrier(float initX, float initY, bool state){ //receive values from the mousePressed()
    velocity = ofVec2f(ofRandom(-maxSpeed, maxSpeed), ofRandom(-maxSpeed, maxSpeed));
    location = ofVec2f(initX,initY);
    
    touched = true;
}

void Person::applyForce(ofVec2f f) {
    force = f;
    acceleration += f;
}

void Person::checkCollision(Person & p) {
    float d = ofDist(location.x, location.y, p.location.x, p.location.y); // calculate the distance between two people
    if (d < radius + p.radius && p.touched == true){ // if the collision happens
        touched = true; // that person turns to a carrier
        
        // collided
        force = ofVec2f(location - p.location); // update the force of collision by subtracting the position values
        force.normalize(); // describe a vector's direction without regard to its length
        force *= -1; // reverse the direction
        force *= p.velocity.length(); // multiply the magnitude of velocity
        applyForce(force);
        
        // collider (vice versa)
        force = ofVec2f(p.location - location);
        force.normalize();
        force *= -1;
        force *= velocity.length();
        p.applyForce(force);
    }
}

void Person::checkEdges(){ // keep people within the canvas by reversing the velocity
    if (location.x > ofGetWindowWidth()) {
        location.x = ofGetWindowWidth();
        velocity.x *= -1;
    } else if(location.x < 0 ){
        location.x = 0;
        velocity.x *= -1;
    }
    if (location.y > ofGetWindowHeight()) {
        location.y = ofGetWindowHeight();
        velocity.y *= -1;
    } else if (location.y < 0 ){
        location.y = 0;
        velocity.y *= -1;
    }
}

void Person::update(){
    velocity.limit(maxSpeed); // apply the maxSpeed
    if (velocity.length() < 0.1) {
        velocity = ofVec2f(0.0, 0.0); // stop the motion if velocity gets near zero
    } else if (velocity.length() < 2){
        velocity *= 0.99; // apply additional friction if velocity falls below a certain magnitude
    }
    velocity *= 0.99; // apply friction
    checkEdges();
    velocity += acceleration;
    location += velocity;
    acceleration *= 0;
}

void Person::display(){
    
    ofPushMatrix();
    
    ofTranslate(location.x, location.y);
    if (touched == false) {
        ofSetColor(255); // default color is white
    } else {
        ofSetColor(255, 0, 0); // a contacted one turns red
    }
    ofDrawCircle(0, 0, radius);
    //ofDrawLine(0, 0, velocity.x * 10, velocity.y * 10); // visualize the magnitude of velocity of each circle
    
    ofPopMatrix();
}

