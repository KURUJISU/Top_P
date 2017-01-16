
/**
 * @file   ninjaScene.h
 * @brief  テストシーン
 *
 * @author y.akira
 * @date   2016.12.21
 */

#include "precompiled.h"



void NinjaScene::setup() {
	// gameTitle.jsonから設定を読み込む
	ofxJSON json;
	json.open("game.json");
	string j_path = json["gameTitlePath"].asString();
	json.open(j_path);

	// fontの設定をjsonから読み込む
	string path = json["Navi"]["fontPath"].asString();
	int    size = json["Navi"]["fontSize"].asInt();
	font_.load(path, size);

	// 文字の色を読み込む
	for (int i = 0; i < 3; i++) {
		naviColor_[i] = json["Navi"]["color"][i].asFloat();
	}

	cam_.setup();
	bg_.setup();
	joy_.setup(GLFW_JOYSTICK_1);

	auto brickMgr = make_shared<BrickManager>();
	wp_brickMgr_ = brickMgr;
	AddActor(brickMgr);

	auto player = make_shared<Player>();
	player->setPos(g_local->WindowHalfSize());
	shared_ptr<Spawner> spwPlayer = make_shared<Spawner>();
	spwPlayer->setActor(player);
	spwPlayer->setSpawnTime(1);
	AddActor(spwPlayer);
	wp_player_ = player;

	shared_ptr<WarpZone> warpZone = make_shared<WarpZone>();
	warpZone->setSize(ofVec2f(70, 70));
	warpZone->setPos(ofVec2f(g_local->Width() - 100, g_local->HalfHeight() + 100));
	warpZone->setDistination(ofVec2f(g_local->HalfWidth(), g_local->Height() * 2));
	AddActor(warpZone);

	spawn_ = false;
	information_ = 0;
	count_ = 0;
	alpha_ = 0;
}

void NinjaScene::update(float deltaTime) {
	bg_.update(deltaTime);
	UpdateActors(deltaTime);
	UpdateUIs(deltaTime);

	if (!wp_brickMgr_.lock()) {
		wp_brickMgr_ = dynamic_pointer_cast<BrickManager>(FindActor(BRICK_MANAGER));
		return;
	}
	if (auto brickMgr = wp_brickMgr_.lock()) {
		if (brickMgr->shouldUpdate()) {
			brickMgr->disableUpdate();
		}
	}

	if (!spawn_) {
		DeleteActors(BRICK);
		if (auto brickMgr = wp_brickMgr_.lock()) {
			for (int i = 0; i < 5; i++) {
				brickMgr->createBrick(i, 0);
			}
		}
		spawn_ = true;
	}

	if (joy_.anyButton()) {
		information_ = 0;
		count_ = 0;
	}
	else {
		count_ += deltaTime;
		if (count_ >= 10) {
			information_ = 1;
		}
	}
	
	switch (information_)
	{
	case 0:
		alpha_ += deltaTime / 2;
		if (alpha_ >= 1) { alpha_ = 1; }
		break;
	case 1:
		alpha_ -= deltaTime / 2;
		if (alpha_ <= 0) { alpha_ = 0; }
		break;
	}
}

void NinjaScene::draw() {
	bg_.draw();

	cam_.begin();
	DrawActors();
	cam_.end();

	ofPushStyle();
	ofSetColor(ofFloatColor(naviColor_, alpha_));
	//操作説明
	float h = font_.stringHeight("Control Information");
	font_.drawString("Control Information",
		50, h + 30);
	font_.drawString("A = Jump",
		50, h * 2 + 30);
	ofPopStyle();

	ofPushStyle();
	ofSetColor(ofFloatColor(naviColor_, 1 - alpha_));
	//スコア
	h = font_.stringHeight("RANKING");

	font_.drawString("RANKING",
		50, h + 30);
	font_.drawString("1st 1500",
		50, h * 2 + 30);
	font_.drawString("2nd 1000",
		50, h * 3 + 30);

	//タイトル
	font_.drawString("To The Top",
		g_local->HalfWidth() - font_.stringWidth("To The Top"), g_local->HalfHeight());
	ofPopStyle();
}

// Gui用に独立した関数
void NinjaScene::gui() {
	// 背景のGuiを描画
	bg_.gui();

	// アクターのGuiを描画
	DrawActorsGui();

	// UIのGuiを描画
	DrawUIsGui();
}

void NinjaScene::exit() {
	ofLog() << "NinjaScene exit";

	// 登録されたアクターとUIを削除
	ClearActors();
	ClearUIs();
}

void NinjaScene::keyPressed(int key) {}