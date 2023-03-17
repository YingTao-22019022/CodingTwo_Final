#pragma once
#include "ofMain.h"
#include "ofxBox2d.h"
#include "Particle.h"

class Particle_Triangle :public Particle
{
public:

	Particle_Triangle(ofxBox2d& box2d, ofPoint point, float radius);
	~Particle_Triangle();
	void Draw();

	ofxBox2dCircle* tria = nullptr;
};