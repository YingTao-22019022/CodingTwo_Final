#pragma once
#include "ofMain.h"
#include "ofxBox2d.h"
#include "Particle.h"

class Particle_Circle :public Particle 
{
public:

	Particle_Circle(ofxBox2d& box2d, ofPoint point, float radius);
	~Particle_Circle();
	void Draw();

	ofxBox2dCircle* circle = nullptr;
	//ofColor color;
	//float life;
	
};
