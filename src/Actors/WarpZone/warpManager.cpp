
#include "precompiled.h"


WarpManager::WarpManager() {
	name_ = "WarpManager";
	tag_ = WARP_MANAGER;
}

void WarpManager::setup() {
	spawnPos_ = ofVec2f(g_local->HalfWidth(), (g_local->Height() + 100));
	destPos_ = ofVec2f(g_local->HalfWidth(), g_local->Height() * 2);

	for (val_ = 1; warpZones_.size() < 5;) {
		spawnWarp();
		val_++;
	}

	enableUpdate();
}

void WarpManager::update(float deltaTime) {
	if (warpZones_.front()->isDead()) {
		warpZones_.erase(warpZones_.begin());
		spawnWarp();
		val_++;
	}
}

void WarpManager::spawnWarp() {
	shared_ptr<WarpZone> warpZone = make_shared<WarpZone>();
	warpZone->setPos(ofVec2f(spawnPos_.x, spawnPos_.y * val_));
	warpZone->setDistination(ofVec2f(destPos_.x, destPos_.y*val_));
	AddActor(warpZone);
	warpZones_.emplace_back(warpZone);
}

void WarpManager::setDestPos(ofVec2f pos) { destPos_ = pos; }
void WarpManager::setSpawnPos(ofVec2f pos) { spawnPos_ = pos; }