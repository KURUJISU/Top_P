
#pragma once


class Brick : public Actor {
private:

public:
	Brick();

	void setup() override;
	void update(float deltaTime) override;
	void draw() override;

	void onCollision(Actor* c_actor) override;
};
		