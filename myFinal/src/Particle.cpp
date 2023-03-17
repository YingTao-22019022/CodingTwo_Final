#pragma once
#include "Particle.h"

Particle::Particle() {

}

Particle::Particle(ofxBox2d& box2d, ofPoint point, float radius)
{
	////����Box2d����
	//this->bit = new ofxBox2dCircle();
	////�����������ԣ��ܶȡ�Ħ��������
	//this->bit->setPhysics(1.0, 0.3, 1.0);
	////�������Ժ�λ��
	//this->bit->setup(box2d.getWorld(), point.x, point.y, radius);
	//this->bit->setData(this);
	//
	////��ʼ����ɫ������
	//color = ofColor(70);
	//life = 255;
}

Particle::~Particle()
{
	//if (this->bit != nullptr) {
	//	this->bit->destroy();
	//	delete this->bit;
	//}
}

void Particle::Update() {
	this->life -= 1.5;
}

//void Particle::Draw() {
//	ofFill();
//	ofSetColor(this->color, this->life > 64 ? 255 : ofMap(this->life, 0, 64, 0, 255));
//	ofDrawCircle(this->bit->getPosition(), this->bit->getRadius());
//}

void Particle::SetColor(ofColor color) 
{ 
	this->color = color; 
}


ofColor Particle::GetColor() 
{ 
	return this->color; 
}

ofPoint Particle::GetVelocity() 
{ 
	return this->bit->getVelocity(); 
}

bool Particle::IsDead() 
{ 
	return this->life <= 0 ? true : false; 
}