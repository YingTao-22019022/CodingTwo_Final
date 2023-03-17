#pragma once
#include "Particle_Triangle.h"
#include "ofMath.h"

Particle_Triangle::Particle_Triangle(ofxBox2d& box2d, ofPoint point, float radius)
{
	//Create a Box2d object
	this->tria = new ofxBox2dCircle();
	//Set physical properties: density, friction, elasticity
	this->tria->setPhysics(0.6, 0.2, 4.0);
	//Set properties and positions
	this->tria->setup(box2d.getWorld(), point.x, point.y, radius);
	this->tria->setData(this);

	//Initialize color and life
	color = ofColor(255, 200, 219);
	life = 255;
}

Particle_Triangle::~Particle_Triangle() {
	if (this->tria != nullptr) {
		this->tria->destroy();
		delete this->tria;
	}
}

void Particle_Triangle::Draw()
{
	int x = this->tria->getPosition().x;
	int y = this->tria->getPosition().y;
	int a = this->tria->getRadius();

	ofPoint point1(x, y - a / (2 * sqrt(3)));
	ofPoint point2(x - a / 2, y + a / (2 * sqrt(3)));
	ofPoint point3(x + a / 2, y + a / (2 * sqrt(3)));

	ofFill();
	ofSetColor(this->color, this->life > 64 ? 255 : ofMap(this->life, 0, 64, 0, 255));
	ofDrawTriangle(point1, point2, point3);
	ofNoFill();
	ofSetLineWidth(2);
	ofSetColor(this->color);
	ofDrawTriangle(point1, point2, point3);
}