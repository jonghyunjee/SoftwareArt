#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "Person.h"
#include <vector>

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
        void setupPeople(); // reset the array "people"
        void socialDistChange(int & socialDistance); // event handler receiving the parameter from GUI

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

        ofxPanel gui;
        ofxIntField socialDistance;
    
        vector <Person> people; // array of vectors from the class "Person"
};
