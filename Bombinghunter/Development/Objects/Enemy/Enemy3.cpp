#include "Enemy3.h"
#include "../GameObject.h"
#include "DxLib.h"

//コンストラクタ
Enemy3::Enemy3() :animation_count(0), filp_flag(FALSE)
{
	animation[0] = NULL;
	animation[1] = NULL;

}

//デストラクタ
Enemy3::~Enemy3()
{

}
//初期化処理
void Enemy3::Initialize()
{
	//画像の読み込み
	animation[0] = LoadGraph("Resource/Images/1 (3).png");
	animation[1] = LoadGraph("Resource/Images/2 (3).png");
	animation[2] = LoadGraph("Resource/Images/3.png");
	animation[3] = LoadGraph("Resource/Images/4.png");
	animation[4] = LoadGraph("Resource/Images/5.png");

	//エラーチェック
	if (animation[0] == -1 || animation[1] == -1||animation[2]==-1||animation[3]==-1||animation[4]==-1)
	{
		throw("金のテキの画像がありません\n");
	}

	//向きの設定
	radian = 0.0;

	//矩形の大きさの設定
	box_size = 64.0;

	//初期化処理の設定
	image = animation[0];
}

//更新処理
void Enemy3::Update()
{
	//移動処理
	Movement();
	//アニメーション制御
	AnimeControl();
}

//描画処理
void Enemy3::Draw() const
{
	//画像反転フラグ
	int flip_flag = FALSE;
	//ハーピー画像の描画
	DrawRotaGraphF(location.x, 420.0, 1.0, radian, image, TRUE, filp_flag);


}

//終了時処理
void Enemy3::Finalize()
{
	//使用した画像を解放する
	DeleteGraph(animation[0]);
	DeleteGraph(animation[1]);
	DeleteGraph(animation[2]);
	DeleteGraph(animation[3]);
	DeleteGraph(animation[4]);
}

//当たり判定通知処理
void Enemy3::OnHitCollision(GameObject* hit_object)
{
	//当たった時の処理
	direction = 0.0f;
}

//移動処理
void Enemy3::Movement()
{
	//移動の速さ
	Vector2D velocity = 0.0f;

	//右方向に進み続ける
	location.x += -1.0f;

	//右の端に行くと、左の端へ移動する
	if (location.x <= 0.0f)
	{
		location.x = 640.0f;
	}

	//現在の位置座標に速さを加算する
	location += velocity;
}

//アニメーション制御
void Enemy3::AnimeControl()
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