
#pragma once



class uiTitle :public uiBase {
private:
	weak_ptr<uiScoreRank> uiScore_;
	weak_ptr<uiInformation> uiInfo_;
public:
	uiTitle();
	void setup() override;
	void update(float deltaTime) override;
	void draw() override;
};