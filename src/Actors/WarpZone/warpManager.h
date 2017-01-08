
#pragma once


class WarpManager : public Actor {
private:
	shared_ptr<WarpZone> warpZone_;
	shared_ptr<Actor> player_;
	ofVec2f spawnPos_;
	ofVec2f destPos_;
	const float limitPos_ = 200;
	const float spwPosXMin_ = 100;
	const float spwPosXMax_ = g_local->Width() - 100;
	void spawnWarp();
public:
	WarpManager();
	void setup() override;
	void update(float deltaTime) override;
};