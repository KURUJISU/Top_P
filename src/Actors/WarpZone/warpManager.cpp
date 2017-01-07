
#include "precompiled.h"


WarpManager::WarpManager() {
	name_ = "WarpManager";
	tag_ = WARP_MANAGER;
	destPos_ = ofVec2f::zero();
}

void WarpManager::setup() {
	spawnWarp();
	enableUpdate();
}

void WarpManager::update(float deltaTime) {
	if (warpZone_->isDead()) {
		spawnWarp();
	}
}

void WarpManager::spawnWarp() {
	ofVec2f spawnPos = ofVec2f(ofRandom(100, g_local->Width() - 100),
		destPos_.y + (g_local->Height() + ofRandom(-100, 100)));
	destPos_ = ofVec2f(g_local->HalfWidth(),
		spawnPos.y + (g_local->Height()));

	warpZone_ = make_shared<WarpZone>();
	warpZone_->setPos(spawnPos);
	warpZone_->setDistination(destPos_);
	AddActor(warpZone_);
}