
/**
 * @file   ninjaScene.h
 * @brief  テストシーン
 *
 * @author y.akira
 * @date   2016.12.21
 */

#include "precompiled.h"


void NinjaScene::setup() {
	bg_.setup();

	font_.load("Font/mono.ttf", 30);

	auto result = scoreJson.open("Scene/pScene.json");
	if (result) {
		score_ = scoreJson["Score"].asInt();
		rnkScore_.push_back(scoreJson["Score"].asInt());
		rnkScore_.push_back(scoreJson["1stScore"].asInt());
		rnkScore_.push_back(scoreJson["2ndScore"].asInt());
		rnkScore_.push_back(scoreJson["3rdScore"].asInt());
		rnkScore_.push_back(scoreJson["4thScore"].asInt());
		rnkScore_.push_back(scoreJson["5thScore"].asInt());
		sort(rnkScore_.begin(), rnkScore_.end());
	}
}

void NinjaScene::update(float deltaTime) {
	bg_.update(deltaTime);

	UpdateUIs(deltaTime);
}

void NinjaScene::draw() {
	bg_.draw();

	string str = ofToString(score_);
	font_.drawString("SCORE",
		g_local->HalfWidth() - font_.stringWidth("SCORE") / 2, g_local->HalfHeight() - 100);
	font_.drawString(str,
		g_local->HalfWidth() - font_.stringWidth(str) / 2, g_local->HalfHeight());

	for (int i = 1; i < 6; i++) {
		string rnkStr = ofToString(rnkScore_[i]);
		font_.drawString(ofToString(6 - i) + "th",
			g_local->HalfWidth() / 2 - font_.stringWidth(ofToString(6 - i) + "th") / 2, g_local->Height() - 40 * i);
		font_.drawString(rnkStr,
			g_local->HalfWidth() + font_.stringWidth(rnkStr) / 2, g_local->Height() - 40 * i);
	}

	DrawUIs();
}

void NinjaScene::exit() {
	ofLog() << "NinjaScene exit";

	scoreJson["5thScore"] = rnkScore_[1];
	scoreJson["4thScore"] = rnkScore_[2];
	scoreJson["3rdScore"] = rnkScore_[3];
	scoreJson["2ndScore"] = rnkScore_[4];
	scoreJson["1stScore"] = rnkScore_[5];

	// 登録されたアクターとUIを削除
	ClearActors();
	ClearUIs();
}

// Gui用に独立した関数
void NinjaScene::gui() {
	if (ImGui::BeginMenu("NinjaScene")) {
		ImGui::Text("this is test scene.");
		ImGui::EndMenu();
	}

	// 背景のGuiを描画
	bg_.gui();

	// UIのGuiを描画
	DrawUIsGui();
}

void NinjaScene::keyPressed(int key) {}