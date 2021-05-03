#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    socialDistance.addListener(this, &ofApp::socialDistChange); //listen to the change of the parameter socialDistance
    
    gui.setup();
    gui.add(socialDistance.setup("social distance", 30, 10, 300));
    
    ofBackground(25);
    ofSetBackgroundAuto(true);
    setupPeople(); //set up the array "people"
    
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    float time = ofGetElapsedTimef();
    
    ofClear(0);
    
    for (int a = 0; a < people.size(); a++) {
        for (int b = 0; b < people.size(); b++) {
            if (a != b){
                people[a].checkCollision(people[b]);
            }
        }
        people[a].update();
        people[a].checkEdges();
        people[a].display();
    }
    
    gui.draw();
}

//--------------------------------------------------------------

void ofApp::socialDistChange(int & socialDistance){
    
    setupPeople(); //refresh the array "people" when the GUI is updated

}

//--------------------------------------------------------------

void ofApp::setupPeople(){
    
    people.clear(); //clear the existing array
    
    for (int y = socialDistance/2; y < ofGetWindowHeight(); y+= socialDistance) {
        for (int x = socialDistance/2; x < ofGetWindowWidth(); x+= socialDistance) {
            people.push_back(Person(x, y, false)); //update the array with uncontacted people
        }
    }
    
}
                             
//--------------------------------------------------------------
                            
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
    people.push_back(Carrier(x, y, true)); // generate an infected person where the mouse is clicked

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
