#pragma once

#include "../GameObject.h"

class bullet :public GameObject
{
private:
	int animation[4];     //アニメーション画像
	int animation_count;  //アニメーション時間
	Vector2D direction;	 //進行方向

public:
	bullet();
	~bullet();

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

public:
	void SetDirection(Vector2D dir);
};
