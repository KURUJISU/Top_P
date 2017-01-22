
#include "precompiled.h"


uiTitle::uiTitle() {}

void uiTitle::setup(){}

void uiTitle::update(float deltaTime){
	if (!uiScore_.lock()) {
		uiScore_ = FindUI(SCORE_RANK);
	}
	if (!uiInfo_.lock()) {
		uiInfo_ = FindUI(INFORMATION);
	}
}

void uiTitle::draw(){}