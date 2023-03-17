#pragma once
#include "ofMain.h"
#include "ofxBox2d.h"
#include "Particle.h"

class Particle_Rect :public Particle
{
public:

	Particle_Rect(ofxBox2d& box2d, ofPoint point, float radius);
	~Particle_Rect();
	void Draw();

	ofxBox2dCircle* rect = nullptr;
};