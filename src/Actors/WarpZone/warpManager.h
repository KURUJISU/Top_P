
#pragma once


class WarpManager : public Actor {
private:
	vector<shared_ptr<WarpZone>> warpZones_;
	ofVec2f spawnPos_;
	ofVec2f destPos_;
	int val_;

	void spawnWarp();

public:
	WarpManager();
	void setup() override;
	void update(float deltaTime) override;

	void setDestPos(const ofVec2f pos);
	void setSpawnPos(const ofVec2f pos);
};