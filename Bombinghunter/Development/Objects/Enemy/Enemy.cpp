#include "Enemy.h"
#include "../GameObject.h"
#include "DxLib.h"

//コンストラクタ
Enemy::Enemy() :animation_count(0), filp_flag(FALSE)
{
	animation[0] = NULL;
	animation[1] = NULL;
	
}

//デストラクタ
Enemy::~Enemy()
{

}
//初期化処理
void Enemy::Initialize()
{
	//画像の読み込み
	animation[0] = LoadGraph("Resource/Images/1 (1).png");
	animation[1] = LoadGraph("Resource/Images/2 (1).png");

	//エラーチェック
	if (animation[0] == -1 || animation[1] == -1)
	{
		throw("ハコテキの画像がありません\n");
	}

	//向きの設定
	radian = 0.0;

	//矩形の大きさの設定
	box_size = 64.0;

	//初期化処理の設定
	image = animation[0];
}

//更新処理
void Enemy::Update()
{
	//移動処理
	Movement();
	//アニメーション制御
	AnimeControl();
}

//描画処理
void Enemy::Draw() const
{
	//画像反転フラグ
	int flip_flag = FALSE;
	//ハコテキ画像の描画
	DrawRotaGraphF(location.x, 420.0, 1.0, radian, image, TRUE, filp_flag);
	if()
	DrawRotaGraphF(location.x, 420.0, 1.0, radian, image, TRUE, filp_flag);

	DrawRotaGraphF(location.x, 420.0, 1.0, radian, image, TRUE, filp_flag);


}

//終了時処理
void Enemy::Finalize()
{
	//使用した画像を解放する
	DeleteGraph(animation[0]);
	DeleteGraph(animation[1]);
}

//当たり判定通知処理
void Enemy::OnHitCollision(GameObject* hit_object)
{
	//当たった時の処理
	direction = 0.0f;
}

//移動処理
void Enemy::Movement()
{
	//移動の速さ
	Vector2D velocity = 0.0f;

	//右方向に進み続ける
	location.x += 1.0f;

	//右の端に行くと、左の端へ移動する
	if (location.x >= 640.0f)
	{
		location.x = 0.0f;
	}

	//現在の位置座標に速さを加算する
	location += velocity;
}

//アニメーション制御
void Enemy::AnimeControl()
{
	//フレームカウントを加算する
	animation_count++;

	//60フレーム目に到達したら
	if (animation_count >= 60)
	{
		//カウントのリセット
		animation_count = 0;

		//画像の切り替え
		if (image == animation[0])
		{
			image = animation[1];
		}
		else
		{
			image = animation[0];
		}
	}
}
