#pragma once
#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(60);
	ofSetWindowTitle("openFrameworks");

	ofBackground(255);

	//Initialize the physical model
	this->box2d.init();
	this->box2d.enableEvents();
	this->box2d.setGravity(0, 15);
	this->box2d.createBounds();
	this->box2d.setFPS(60);
	//this->box2d.registerGrabbing();

	//Start event monitoring, listen for collision events
	ofAddListener(box2d.contactStartEvents, this, &ofApp::contactStart);
	ofAddListener(box2d.contactEndEvents, this, &ofApp::contactEnd);

	string sound_path_list[13] = { 
		"C8.wav",
		"Db8.wav",
		"D8.wav", 
		"Eb8.wav",
		"E8.wav", 
		"F8.wav",
		"F#8.wav",
		"G8.wav",
		"G#8.wav",
		"A8.wav", 
		"Bb8.wav"
		"B8.wav", 
		"C9.wav" 
	};

	int a = 0;
	int b = 0;
	for (int i = 0; i < 12; i++) 
	{
		if (i == 1 || i == 3 || i == 6 || i == 8 || i == 10) {
			//Initialize black keys
			ofVec3f hsb_b = ofVec3f(i * 18 + 15, 140, 255);
			//Initialize the keys, set the key position, size, hue
			unique_ptr<Keys> k(new Keys(this->box2d, ofPoint(ofGetWidth() * (1.0 / 5.0) * a + ofGetWidth() * 0.5 / 5.0, 700), 50, 50, hsb_b, 50));
			//load audio path
			k->SetSound(sound_path_list[i]);
			this->keys.push_back(std::move(k));
			a += 1;
		}
		else
		{
			//Initialize white keys
			ofVec3f hsb_w = ofVec3f(i * 18 + 15, 140, 255);
			//Initialize the keys, set the key position, size, hue
			unique_ptr<Keys> k(new Keys(this->box2d, ofPoint(ofGetWidth() * (1.0 / 7.0) * b + ofGetWidth() * 0.5 / 7.0, 400), 100, 100, hsb_w, 255));
			//load audio path
			k->SetSound(sound_path_list[i]);
			this->keys.push_back(std::move(k));
			b += 1;
		}
	}
}

//--------------------------------------------------------------
void ofApp::update(){

	//Initialize particles
	if (ofGetFrameNum() % 20 == 0) {
		ofPoint point_circle(ofRandom(ofGetWidth()), 25);
		ofPoint point_rect(ofRandom(ofGetWidth()), 25);
		ofPoint point_tria(ofRandom(ofGetWidth()), 25);

		float radius = 8;
		float side = 16;
		float side_t = 20;

		unique_ptr<Particle> p(new Particle_Circle(this->box2d, point_circle, radius));
		unique_ptr<Particle> w(new Particle_Rect(this->box2d, point_rect, side));
		unique_ptr<Particle> y(new Particle_Triangle(this->box2d, point_tria, side_t));

		this->particles.push_back(std::move(p));
		this->particles.push_back(std::move(w));
		this->particles.push_back(std::move(y));
	}

	for (int i = this->particles.size() - 1; i >= 0; i--) {
		this->particles[i]->Update();
		if (this->particles[i]->IsDead()) {

			this->particles.erase(this->particles.begin() + i);
		}
	}

	for (int i = 0; i < this->keys.size(); i++) {
		this->keys[i]->Update();
	}

	this->box2d.update();
	ofSoundUpdate();

}

//--------------------------------------------------------------
void ofApp::draw(){
	for (int i = 0; i < this->keys.size(); i++) {
		this->keys[i]->Draw();
	}

	for (int i = 0; i < this->particles.size(); i++) {
		this->particles[i]->Draw();
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

//--------------------------------------------------------------
void ofApp::contactStart(ofxBox2dContactArgs& e) {

	//collision
	if (e.a != NULL && e.b != NULL) {

		if (e.a->GetType() == b2Shape::e_circle && e.b->GetType() == b2Shape::e_circle) 
		{
			Particle* p_a = (Particle*)e.a->GetBody()->GetUserData();
			Particle* p_b = (Particle*)e.b->GetBody()->GetUserData();
			if (p_a != nullptr && p_b != nullptr) {

			}
			return;
		}

		if (e.a->GetType() == b2Shape::e_polygon && e.b->GetType() == b2Shape::e_circle) 
		{
			Keys* o_a = (Keys*)e.a->GetBody()->GetUserData();
			Particle* p_b = (Particle*)e.b->GetBody()->GetUserData();
			if (o_a != nullptr && p_b != nullptr) {
				p_b->SetColor(o_a->GetColor());
				o_a->SoundPlay();
			}
			return;
		}

		if (e.a->GetType() == b2Shape::e_circle && e.b->GetType() == b2Shape::e_polygon) 
		{
			Particle* p_a = (Particle*)e.a->GetBody()->GetUserData();
			Keys* o_b = (Keys*)e.b->GetBody()->GetUserData();
			if (p_a != nullptr && o_b != nullptr) {
				p_a->SetColor(o_b->GetColor());
				o_b->SoundPlay();
			}
			return;
		}
	}
}

//--------------------------------------------------------------
void ofApp::contactEnd(ofxBox2dContactArgs& e) {
	if (e.a != NULL && e.b != NULL) {

	}
}