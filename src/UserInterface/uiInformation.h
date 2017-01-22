
#pragma once


class uiInformation :public uiBase {
private:
	vector<string> informations_;
	vector<float> wordWidth_;
	ofTrueTypeFont font_;
public:
	uiInformation();
	void setup() override;
	void update(float deltaTime) override;
	void draw() override;
};