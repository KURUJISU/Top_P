
#include "precompiled.h"


WarpManager::WarpManager() {
	name_ = "WarpManager";
	tag_ = WARP_MANAGER;

	val_ = 0;
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
	ofVec2f spawnPos = ofVec2f(ofRandom(0, g_local->Width()), 
		(g_local->Height() - 200) + (val_ * g_local->HalfHeight()));
	ofVec2f destPos = ofVec2f(spawnPos.x, 
		(g_local->Height() + g_local->HalfHeight()) + (val_ * g_local->HalfHeight()));

	warpZone_ = make_shared<WarpZone>();
	warpZone_->setPos(spawnPos);
	warpZone_->setDistination(destPos);
	AddActor(warpZone_);
	val_++;
}