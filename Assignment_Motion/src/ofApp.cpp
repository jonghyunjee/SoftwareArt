#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetFrameRate(60);
    ofSetBackgroundAuto(false); // disable automatic background redraw
    ofEnableAlphaBlending(); // turn on alpha blending
    
    clearAlpha = 0.5;
    resolution = 10; // to  obtain color values from an image by every 10 pixels
    
    digital = "01"; // to use text string 0 and 1
    
    yinyang.load("images/yinyang.png");
    yinyang.resize(400, 400);
    yinyang.setImageType(OF_IMAGE_GRAYSCALE);
    
    font.load("fonts/BebasNeue.ttf", 12);
}

//--------------------------------------------------------------
void ofApp::update(){
    
    rotate ++; // counter for rotation
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofBackground(10);
    
    float time = ofGetElapsedTimef(); // time in seconds
    
    int w = yinyang.getWidth();
    int h = yinyang.getHeight();
    
    // draw strings (0 or 1) over the loaded image
    ofPushMatrix();
        ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
        ofRotateDeg(rotate/10); // rotate the yin-yang sign
        ofRotateXDeg(rotate); // rotate the yin-yang sign along its x-axis
        ofRotateYDeg(rotate); // rotate the yin-yang sign along its y-axis
        for (int i = 0; i < w; i += resolution){
            for (int j = 0; j < h; j += resolution){
                unsigned char * pixels = yinyang.getPixels().getData(); // store color values of pixels
                int index = j * yinyang.getWidth() + i; // specify a pixel
                int color = pixels[index];
                if (color < 127){ // create 0 or 1 on darker pixels
                    font.drawString(digital.substr((int)ofRandom(2), 1), i - w/2, j - h/2); // subtract the half width & height to center the circle
                    }
                }
            }
    ofPopMatrix();
    
    // reverse the contrast over time
    ofColor darkColor(0,0,0,255);  // opaque black
    ofColor lightColor(255,255,255,255);  // opaque white
    float percent = ofMap(cos(time/2.0), -1, 1, 0, 1);  // create a value that oscillates between 0 to 1
    ofColor bgColor = darkColor;  // color for the transparent rectangle we use to clear the screen
    bgColor.lerp(lightColor, percent);  // this modifies our color "in place"
    bgColor.a = clearAlpha;  // initial colors were opaque, but our spiral needs to be transparent
    ofColor fgColor = lightColor;  // color for the spiral outlines
    fgColor.lerp(darkColor, percent);  // modifies color in place

    // semi-clear the screen, using a transparent rectangle
    ofSetColor(bgColor);
    ofSetRectMode(OF_RECTMODE_CORNER);
    ofFill();
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());  // ofBackground doesn't work with alpha, so draw a transparent rect

    // draw the spiral of 0 and 1
    ofSetColor(fgColor);
    ofNoFill();
    ofPushMatrix();
        ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
        for (int i = 0; i < 100; i++) {
            time = ofGetElapsedTimef();
            // draw small strings first and scale out to bigger ones progressively
            ofScale(1.01, 1.01);

            // make the strings spiral
            ofRotateDeg(i * time/10); //rotate coordinate system
                     
            ofTranslate(i+1, 0); //lay out strings
                
            font.drawString(digital.substr((int)ofRandom(2), 1), i - w/2, i - h/2);
        }
    ofPopMatrix();
   
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
