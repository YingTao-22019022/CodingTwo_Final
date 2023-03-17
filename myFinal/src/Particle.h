#pragma once
#include "ofMain.h"
#include "ofxBox2d.h"

class Particle
{
public:

	Particle();
	Particle(ofxBox2d& box2d, ofPoint point, float radius);
	~Particle();

	void Update();
	virtual void Draw() = 0;
	//void Draw();

	void SetColor(ofColor color);
	ofColor GetColor();
	ofPoint GetVelocity();
	bool IsDead();

	ofxBox2dCircle* bit = nullptr;
	ofColor color;
	float life;

private:

};
