
/**
 * @file   ninjaScene.h
 * @brief  テストシーン
 *
 * @author y.akira
 * @date   2016.12.21
 */

#pragma once


//! @brief テスト用シーンクラス
class NinjaScene : public ofxScene {
private:
	BackGround  bg_;

	ofxJSON scoreJson;
	int score_;
	vector<int> rnkScore_;
	ofTrueTypeFont font_;
public:
	void setup() override;
	void exit() override;
	void update(float deltaTime) override;
	void draw() override;
	void gui() override;

	void keyPressed(int key) override;
};
