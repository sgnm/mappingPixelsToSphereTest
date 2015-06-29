#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0,0,0);
    ofEnableSmoothing();
    ofEnableDepthTest();
    
    image.loadImage("world.png");
    image.resize(400, 200);
    w = image.width;
    h = image.height;
    threshold = 140;
    //画像データを配列に格納
    unsigned char *pixels = image.getPixels();
    //高さと幅の取得
    
    mesh.setMode(OF_PRIMITIVE_POINTS);
    mesh.enableColors();
    glPointSize(2);
    glEnable(GL_DEPTH_TEST);
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    float radius = h * PI;
    float map_x, map_y;
    
    for(int x = 0; x < w; x+=10){
        for(int y = 0; y < h; y+=10){
            float position_x;
            float position_y;
            
            // xy平面で、radを-π/2~π/2まで回してあげる
            for (float k = -PI/2; k < PI/2; k += 0.1) {
                
                // 画像から色と明るさ取得
                ofColor imgColor = image.getColor(x, y);
                float intensity = imgColor.getLightness();
                
                if (intensity < threshold) {
                    // 明るさの閾値より低い時、青を表示
                    mesh.addColor(ofColor(0, 0, 255));
                }else{
                    mesh.addColor(ofColor(0, 255, 0));
                }

                ofPushMatrix();

                ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
                
                // その座標の円周しりたいのでx座標とy座標求める
                position_x = radius * cos(k);
                position_y = radius * sin(k);
                
                // そのx座標での円周と、y座標の円周算出
                float circumference_x = position_x * 2 * PI;
                float circumference_y = position_y * 2 * PI;
                
                // x座標が、画像の0~widthの中でのどの位置にあたるかを出して、
                // 画像の幅は、球体で言うと、そのx座標の円周になる！
                map_x = ofMap(x, 0, w, 0, circumference_x);
                map_y = ofMap(y, 0, h, 0, circumference_y / 2); //heightなので、球体の半円でマッピング(π * r)

                cout << mesh.getNumVertices() << endl;
                
                ofMap(rad, 0, circumference_x, 0, 2 * PI);
                ofVec3f pos(map_x, map_y, map_x * tan(rad));
                mesh.addVertex(pos);
                
                ofPopMatrix();
            }
        }
    }

    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    mesh.draw();
    
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
