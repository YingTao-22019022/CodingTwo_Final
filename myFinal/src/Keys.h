#pragma once
#include "ofMain.h"
#include "ofxBox2d.h"
#include "ofSoundPlayer.h"

class Keys
{
public:
	Keys(ofxBox2d& box2d, ofPoint point, float width, float height, ofVec3f hsb, float alpha);
	~Keys();

	void Update();
	void Draw();
	void SoundPlay();

	void SetSound(string soude_path);
	ofColor GetColor();

private:
	ofxBox2dRect* rect = nullptr;
	ofColor color;
	ofSoundPlayer sound;
	vector<float> waves;
};