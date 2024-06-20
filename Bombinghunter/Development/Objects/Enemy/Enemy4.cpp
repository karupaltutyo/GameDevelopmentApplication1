#include "Enemy4.h"
#include "../GameObject.h"
#include "DxLib.h"

//コンストラクタ
Enemy4::Enemy4() :animation_count(0), filp_flag(FALSE)
{
	animation[0] = NULL;
	animation[1] = NULL;

}

//デストラクタ
Enemy4::~Enemy4()
{

}
//初期化処理
void Enemy4::Initialize()
{
	//画像の読み込み
	animation[0] = LoadGraph("Resource/Images/1.png");
	animation[1] = LoadGraph("Resource/Images/2.png");


	//エラーチェック
	if (animation[0] == -1 || animation[1] == -1)
	{
		throw("ハネテキの画像がありません\n");
	}

	//向きの設定
	radian = 0.0;

	//矩形の大きさの設定
	box_size = 64.0;

	//初期化処理の設定
	image = animation[0];
}

//更新処理
void Enemy4::Update()
{
	//移動処理
	Movement();
	//アニメーション制御
	AnimeControl();
}

//描画処理
void Enemy4::Draw() const
{
	//画像反転フラグ
	int flip_flag = FALSE;
	//ハネテキ画像の描画
	DrawRotaGraphF(location.x, 200.0, 1.0, radian, image, TRUE, filp_flag);


}

//終了時処理
void Enemy4::Finalize()
{
	//使用した画像を解放する
	DeleteGraph(animation[0]);
	DeleteGraph(animation[1]);
}

//当たり判定通知処理
void Enemy4::OnHitCollision(GameObject* hit_object)
{
	//当たった時の処理
	direction = 0.0f;
}

//移動処理
void Enemy4::Movement()
{
	//移動の速さ
	Vector2D velocity = 0.0f;

	//左方向に進み続ける
	location.x += -1.5f;

	//左の端に行くと、右の端へ移動する
	if (location.x <= 0.0f)
	{
		location.x = 640.0f;
	}

	//現在の位置座標に速さを加算する
	location += velocity;
}

//アニメーション制御
void Enemy4::AnimeControl()
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