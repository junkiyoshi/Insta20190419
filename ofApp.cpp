#include "ofApp.h"	

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openFrameworks");

	ofBackground(239);
	ofEnableDepthTest();
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();

	for (int v = 0; v < 360; v += 6) {
	
		ofColor color;
		color.setHsb(ofMap((ofGetFrameNum() * 5 + v) % 360, 0, 360, 0, 255), 255, 230);

		int tmp_v = v;
		for (int u = -180; u <= 180; u += 6) {

			ofSetColor(color);
			ofBeginShape();
			ofVertex(this->make_point(300, 80, u - 3, tmp_v - 3));
			ofVertex(this->make_point(300, 80, u - 9, tmp_v - 3));
			ofVertex(this->make_point(300, 80, u - 3, tmp_v + 3));
			ofVertex(this->make_point(300, 80, u + 3, tmp_v + 3));
			ofEndShape(true);
			
			tmp_v += 6;
		}
	}

	this->cam.end();
}

//--------------------------------------------------------------
glm::vec3 ofApp::make_point(float R, float r, float u, float v) {

	// 数学デッサン教室 描いて楽しむ数学たち　P.31

	u *= DEG_TO_RAD;
	v *= DEG_TO_RAD;

	float x = (R + r * cos(u)) * cos(v);
	float y = (R + r * cos(u)) * sin(v);
	float z = r * sin(u);

	return glm::vec3(x, y, z);
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}