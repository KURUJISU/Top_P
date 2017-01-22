
#include "precompiled.h"


uiInformation::uiInformation(){
	name_ = "uiInformation";
	tag_ = INFORMATION;
}

void uiInformation::setup(){
	ofxJSON json;
	json.open("UI/information.json");

	informations_.push_back(json["sentence"].asString());
	wordWidth_.push_back(font_.stringWidth(informations_[0]));

	font_.load("Font/mono.ttf", 20);
}

void uiInformation::update(float deltaTime){}

void uiInformation::draw(){
	ofSetColor(ofColor::blue);
	float stringHight = font_.stringHeight("A");
	ofLog() << informations_[0];
	font_.drawString("a", g_local->HalfWidth(), g_local->HalfHeight());
}