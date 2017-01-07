
#pragma once


class WarpManager : public Actor {
private:
	shared_ptr<WarpZone> warpZone_;
	int val_;

	void spawnWarp();

public:
	WarpManager();
	void setup() override;
	void update(float deltaTime) override;
};