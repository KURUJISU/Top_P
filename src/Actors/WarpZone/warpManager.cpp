
#include "precompiled.h"


WarpManager::WarpManager() {
	name_ = "WarpManager";
	tag_ = WARP_MANAGER;

	val_ = 0;
	count_ = 0;
}

void WarpManager::setup() {
	spawnWarp();

	enableUpdate();
}

void WarpManager::update(float deltaTime) {
	if (warpZone_->isDead()) {
		spawnWarp();
		count_ = 0;
	}
}

void WarpManager::spawnWarp() {
	spawnPos_ = ofVec2f(ofRandom(0, g_local->Width()), 
		(g_local->Height() - 200) + (val_ * g_local->HalfHeight()));
	destPos_ = ofVec2f(0, 
		(g_local->Height() + g_local->HalfHeight()) + (val_ * g_local->HalfHeight()));

	warpZone_ = make_shared<WarpZone>();
	warpZone_->setPos(ofVec2f(spawnPos_.x, spawnPos_.y));
	warpZone_->setDistination(ofVec2f(warpZone_->getPos().x, destPos_.y));
	AddActor(warpZone_);
	val_++;
}