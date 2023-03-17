#include "Keys.h"
#include <iostream>

Keys::Keys(ofxBox2d& box2d, ofPoint point, float width, float height, ofVec3f hsb, float alpha)
{
	this->rect = new ofxBox2dRect();
	this->rect->setPhysics(0.0, 1.0, 1.0);
	this->rect->setup(box2d.getWorld(), point.x, point.y, width, height);
	this->rect->setData(this);

	this->color.setHsb(hsb.x, hsb.y, hsb.z, alpha);
}

Keys::~Keys()
{
	if (this->rect != nullptr) {

		this->rect->destroy();
		delete this->rect;
	}
}

void Keys::Update() 
{
	for (int i = this->waves.size() - 1; i >= 0; i -= 1) {

		this->waves[i] += 1;
		if (this->waves[i] > 60) {

			this->waves.erase(this->waves.begin() + i);
		}
	}
}

void Keys::Draw() 
{
	float width = this->rect->getWidth();
	float height = this->rect->getHeight();

	//draw the keys
	ofFill();
	ofSetColor(this->color);
	ofDrawRectangle(this->rect->getPosition() + ofPoint(width * -0.5, height * -0.5), width, height);

	//Drawing keyboard sound waves
	for (int i = 0; i < this->waves.size(); i++) {
		ofNoFill();
		ofSetLineWidth(2*i);
		ofSetColor(this->color, ofMap(this->waves[i], 0, 60, 255, 0));

		float wave_width = width + waves[i];
		float wave_height = height + waves[i];

		ofDrawRectangle(this->rect->getPosition() + ofPoint(wave_width * -0.5, wave_height * -0.5), wave_width, wave_height);
	}
}

void Keys::SoundPlay() 
{
	this->sound.play();
	this->waves.push_back(0);
}


void Keys::SetSound(string sound_path) 
{
	this->sound.load(sound_path);
	this->sound.setVolume(0.5);
	this->sound.setMultiPlay(true);
}


ofColor Keys::GetColor() 
{ 
	return this->color; 
}