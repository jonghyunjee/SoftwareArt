#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ofSetFrameRate(60);
    ofSetCircleResolution(360);
    last = ofGetElapsedTimeMillis();
    col.setHsb(45,125,195); //HSB for hue change
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    ofBackground(col);
        if(ofGetElapsedTimeMillis() - last > 50) //hue change loop
        {
            col.setHue(counter % 256);
            counter ++;
            last = ofGetElapsedTimeMillis();
        }
    
    rotate++;
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    for (int i = 0; i < 100; i++) { //generate 100 yin-yang signs
    
        ofPushMatrix();
    
        ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
    
        ofRotateDeg(i * rotate/10); //rotate coordinate system
        ofRotateXDeg(i * rotate/10); //rotate each circle along its local x-axis
            
        ofTranslate( diameter/2 + i * 10, 0 ); //lay out circles
            
        float scl = 1.0 - i * 0.8 / 20.0; //scale decreases with i
            
        ofScale(scl, scl); //circles become gradually smaller
        
        ofPath curve1; //white semicircle
        ofColor w(0xF9F9F9);
        curve1.setFilled(true);
        curve1.setFillColor(w);
        curve1.arc(0, 0, diameter, diameter, 90, 270);
        curve1.close();
        curve1.draw();
        
        ofPath curve2; //black semicircle
        ofColor b(0x262626);
        curve2.setFilled(true);
        curve2.setFillColor(b);
        curve2.arc(0, 0, diameter, diameter, 270, 450);
        curve2.close();
        curve2.draw();
        
        ofSetHexColor(0xF9F9F9); //white bigger circle
        ofDrawEllipse(0, -diameter/2, diameter, diameter);
        ofSetHexColor(0x262626); //black smaller circle
        ofDrawEllipse(0, diameter/2, diameter, diameter);
        
        ofSetHexColor(0x262626); //black bigger circle
        ofDrawEllipse(0, -diameter/2, diameter/4, diameter/4);
        ofSetHexColor(0xF9F9F9); //white smaller circle
        ofDrawEllipse(0, diameter/2, diameter/4, diameter/4);
        
        ofPopMatrix();
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
