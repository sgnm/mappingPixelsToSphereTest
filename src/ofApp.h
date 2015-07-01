#pragma once

#include "ofMain.h"
#include "ofxJSON.h"

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
    
    static const int NUM_PARTICLES = 20000;

    ofImage image, outImage;
    ofVboMesh mesh;
    ofxJSONElement response;    
    
    int threshold;
    float rad = 0.0;
    
    ofEasyCam cam;
    
    int w, h;
    int rotate;
    
    float theta, phi;
    
    int imgVec[200];
    int i = 0;
    
    ofColor imgColor[NUM_PARTICLES];
    float intensity[NUM_PARTICLES];
		
};
