#pragma once
#include "Particle_Rect.h"

Particle_Rect::Particle_Rect(ofxBox2d& box2d, ofPoint point, float radius)
{
	//Create a Box2d object
	this->rect = new ofxBox2dCircle();
	//Set physical properties: density, friction, elasticity
	this->rect->setPhysics(1.0, 0.3, 4.0);
	//Set properties and positions
	this->rect->setup(box2d.getWorld(), point.x, point.y, radius);
	this->rect->setData(this);

	//Initialize color and life
	color = ofColor(255, 252, 231);
	life = 255;
}

Particle_Rect::~Particle_Rect() {
	if (this->rect != nullptr) {
		this->rect->destroy();
		delete this->rect;
	}
}

void Particle_Rect::Draw()
{
	ofFill();
	ofSetColor(this->color, this->life > 64 ? 255 : ofMap(this->life, 0, 64, 0, 255));
	ofDrawRectRounded(this->rect->getPosition(), this->rect->getRadius(), this->rect->getRadius(), 2, 2, 2, 2);
	ofNoFill();
	ofSetLineWidth(2);
	ofSetColor(this->color);
	ofDrawRectRounded(this->rect->getPosition(), this->rect->getRadius(), this->rect->getRadius(), 2, 2, 2, 2);
}