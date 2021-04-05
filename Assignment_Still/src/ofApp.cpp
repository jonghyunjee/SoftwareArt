#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetBackgroundColor(20);
    ofSetCircleResolution(100);

    gui.setup();
    
    gui.add(interval.setup("interval", 50, 1, 500));
    gui.add(curvature.setup("curvature", 10, 1, 200));
    gui.add(alphaOffset.setup("alpha offset", 100, 1, 10000));
    gui.add(RGBA.setup("RGBA", ofVec4f(127, 127, 127, 127), ofVec4f(0, 0, 0, 0), ofVec4f(255, 255, 255, 255)));
    gui.add(toggle.setup("toggle", false));
    gui.add(alphaValue.setup("alphaValue", false));
    
    }

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    if (isSaving){
        ofBeginSaveScreenAsPDF("print-" + ofToString(ofGetElapsedTimeMicros()) + ".pdf");
    }
    
    ofEnableAlphaBlending();
    float time = ofGetElapsedTimef();
    for (int x = 1; x < 20; x++) { // horizontal reiteration
        for (int i = 0; i < 900; i++) { // vertical reiteration
            
            if (alphaValue == false) {
                ofSetColor(127 + 127 * sin(i * 0.01 + time), 127 + 127 * sin(i * 0.011 + time), 127 + 127 * sin(i * 0.012 + time));
            } else {
                ofSetColor(RGBA -> x + RGBA -> x * sin(i * 0.01 + time), RGBA -> y + RGBA -> y * sin(i * 0.011 + time), RGBA -> z + RGBA -> z * sin(i * 0.012 + time), RGBA -> w + RGBA -> w * sin(i * alphaOffset * 0.0001 + time));
            }

            if (toggle == false) {
                ofDrawCircle(interval * x + 100 * sin(i * curvature * 0.001 + time + x), interval + i, interval + 40 * sin(i * curvature * 0.0005 + time + x));
            } else {
                ofDrawEllipse(interval * x + 100 * sin(i * curvature * 0.001 + time + x), interval + i, interval + 60 * cos(i * curvature * 0.0005 + time + x), interval + 40 * tan(i * curvature * 0.001 + time + x));
            }
        }
    }
    
    if (isSaving) {
        ofEndSaveScreenAsPDF();
        isSaving = false;
    }
    
    gui.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if (key == 's'){
        isSaving = true;
    }
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
