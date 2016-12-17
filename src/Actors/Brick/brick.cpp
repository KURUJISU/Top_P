
#include "precompiled.h"


Brick::Brick() {
	name_ = "Brick";
	size_ = ofVec2f(100, 30);
	pos_ = ofVec3f(ofGetWindowWidth() / 2, -size_.y);
	vel_ = ofVec3f(0, 50.0f);
	tag_ = 1;
}

void Brick::setup() {
	enableUpdate();
	enableCollision();
}

void Brick::update(float deltaTime) {
	pos_.y += vel_.y * deltaTime;
}

void Brick::draw() {
	ofSetColor(ofColor(255, 0, 0));
	ofDrawRectangle(getRectangle());
}

void Brick::onCollision(Actor* c_actor) {
	if (c_actor->getTag() == 1) {
		vel_ = ofVec2f(0, 0);
	}
}