
#include "precompiled.h"


uiTitle::uiTitle() {}

void uiTitle::setup(){
	shared_ptr<uiInformation> uiInfo = make_shared<uiInformation>();
	uiInfo->setPos(ofVec2f(0, g_local->HalfHeight()));
	AddUI(uiInfo);
	wp_uiInfo_ = uiInfo;

	shared_ptr<uiScoreRank> uiScore = make_shared<uiScoreRank>();
	uiScore->disableDrawCurrentScore();
	uiScore->setPos(ofVec2f(0, g_local->HalfHeight()));
	AddUI(uiScore);
	wp_uiScore_ = uiScore;
}

void uiTitle::update(float deltaTime){}

void uiTitle::draw(){

}