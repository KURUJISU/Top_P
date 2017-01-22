
#pragma once



class uiTitle :public uiBase {
private:
	weak_ptr<uiScoreRank> wp_uiScore_;
	weak_ptr<uiInformation> wp_uiInfo_;
public:
	uiTitle();
	void setup() override;
	void update(float deltaTime) override;
	void draw() override;
};