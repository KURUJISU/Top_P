
#include "precompiled.h"


WarpManager::WarpManager() {
	name_ = "WarpManager";
	tag_ = WARP_MANAGER;
}

void WarpManager::setup() {
	player_ = FindActor(PLAYER);
	spawnWarp();
	enableUpdate();
}

void WarpManager::update(float deltaTime) {
	if (warpZone_->isDead()) {
		spawnWarp();
	}

	if ((player_->getPos().y - 200) > warpZone_->getPos().y) {
		warpZone_->destroy();
	}

	ofLog() << player_->getPos().y;
}

void WarpManager::spawnWarp() {
	ofVec2f spawnPos = ofVec2f(ofRandom(100, g_local->Width() - 100),
		player_->getPos().y + (g_local->Height() + ofRandom(-100, 100)));
	ofVec2f destPos = ofVec2f(g_local->HalfWidth(),
		spawnPos.y + (g_local->Height()));

	warpZone_ = make_shared<WarpZone>();
	warpZone_->setPos(spawnPos);
	warpZone_->setDistination(destPos);
	AddActor(warpZone_);
}