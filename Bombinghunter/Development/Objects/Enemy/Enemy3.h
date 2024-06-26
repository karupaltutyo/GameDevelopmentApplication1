#pragma once

#include "../GameObject.h"

class Enemy3 :public GameObject
{
private:
	int animation[5];     //アニメーション画像
	int animation_count;  //アニメーション時間
	int filp_flag;        //反転フラグ
	Vector2D direction;

public:
	Enemy3();
	~Enemy3();

	virtual void Initialize() override;      //初期化処理
	virtual void Update() override;          //更新処理
	virtual void Draw() const override;      //描画処理
	virtual void Finalize() override;        //終了時処理

	//当たり判定通知処理
	virtual void OnHitCollision(GameObject* hit_obJect) override;

private:
	//移動処理
	void Movement();
	//アニメーション制御
	void AnimeControl();
};


