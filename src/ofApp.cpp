#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0,0,0);
    ofSetFrameRate(30);
//    ofScale(1, -1);
    ofEnableSmoothing();
    ofEnableDepthTest();
    ofEnableAlphaBlending();
    
    image.loadImage("world.png");
    image.resize(200, 100);
    w = image.width;
    h = image.height;
    image.allocate(w, h, OF_IMAGE_COLOR);
    threshold = 140;
    //画像データを配列に格納
    unsigned char *pixels = image.getPixels();
    //高さと幅の取得
    
    mesh.setMode(OF_PRIMITIVE_POINTS);
    mesh.enableColors();
    glPointSize(1);
    glEnable(GL_DEPTH_TEST);
}

//--------------------------------------------------------------
void ofApp::update(){
    mesh.clearVertices();
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    cam.begin();
    float radius = h * PI;
    float map_x, map_y;
    
    for(int x = 0; x < w; x+=5){
        for(int y = 0; y < h; y+=5){
            float position_x;
            float position_y;
            
            // xy平面で、radを-π/2~π/2まで回してあげる
            for (float k = 0; k < 2 *PI; k += 0.1) {
                
                // 画像から色と明るさ取得
                ofColor imgColor = image.getColor(x, y);
                float intensity = imgColor.getLightness();
                
                if (intensity < threshold) {
                    // 明るさの閾値より低い時、青を表示
                    mesh.addColor(ofColor::fromHsb(240, 255, 255));
                }else{
                    mesh.addColor(ofColor::fromHsb(120, 255, 255));
                }

                ofPushMatrix();

                ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
                
                float theta = (float)y * M_PI / h;
                float phi = -(float)x * 2.0f * M_PI / w;
                float px = radius * sin(theta) * cos(phi);
                float py = radius * sin(theta) * sin(phi);
                float pz = radius * cos(theta);
                ofVec3f pos(px, py, pz);
                ofScale(0.5, 0.5);
                mesh.addVertex(pos);
                
                ofPopMatrix();
            }
        }
    }

    mesh.draw();
    cam.end();
    
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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
