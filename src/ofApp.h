#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    ofImage image, outImage;
    ofVboMesh mesh;
    
    int threshold;
    float rad = 0.0;
    
    ofEasyCam cam;
    
    int w, h;
    int rotate;
    
    float theta, phi;
    
    int imgVec[200];
    int i = 0;
		
};
