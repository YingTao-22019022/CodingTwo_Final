#pragma once
#include "Particle_Circle.h"

Particle_Circle::Particle_Circle(ofxBox2d& box2d, ofPoint point, float radius)
{
	//Create a Box2d object
	this->circle = new ofxBox2dCircle();
	//Set physical properties: density, friction, elasticity
	this->circle->setPhysics(1.0, 0.3, 2.0);
	//Set properties and positions
	this->circle->setup(box2d.getWorld(), point.x, point.y, radius);
	this->circle->setData(this);

	//Initialize color and life
	color = ofColor(231,249,255);
	life = 255;
}

Particle_Circle::~Particle_Circle() {
	if (this->circle != nullptr) {
		this->circle->destroy();
		delete this->circle;
	}
}

void Particle_Circle::Draw()
{
	ofFill();
	ofSetColor(this->color, this->life > 64 ? 255 : ofMap(this->life, 0, 64, 0, 255));
	//ofDrawCircle(this->circle->getPosition(), this->circle->getRadius());
	ofDrawCircle(this->circle->getPosition(), this->circle->getRadius());
	ofNoFill();
	ofSetLineWidth(2);
	ofSetColor(this->color);
	ofDrawCircle(this->circle->getPosition(), this->circle->getRadius());
}
