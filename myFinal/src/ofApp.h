#pragma once
#include "ofMain.h"

#include "ofxBox2d.h"
#include "ofxMaxim.h"

#include "Particle.h"
#include "Keys.h"
#include "Particle_Circle.h"
#include "Particle_Rect.h"
#include "Particle_Triangle.h"

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
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		void contactStart(ofxBox2dContactArgs& e);
		void contactEnd(ofxBox2dContactArgs& e);

		ofxBox2d box2d;
		vector<unique_ptr<Particle>> particles;
		vector<unique_ptr<Keys>> keys;

};
