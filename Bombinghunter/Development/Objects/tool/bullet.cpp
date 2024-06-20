#include "bullet.h"
#include "../../Utility/InputControl.h"
#include "DxLib.h"

//コンストラクタ
bullet::bullet() :animation_count(0)
{
	animation[0] = NULL;
	/*animation[1] = NULL;
	animation[2] = NULL;
	animation[3] = NULL;*/
}

//デストラクタ
bullet::~bullet()
{

}
//初期化処理
void bullet::Initialize()
{
	//画像の読み込み
	animation[0] = LoadGraph("Resource/Images/1 (5).png");
	/*animation[1] = LoadGraph("Resource/images/eff1.png");
	animation[2] = LoadGraph("Resource/images/eff2.png");
	animation[3] = LoadGraph("Resource/images/eff3.png");*/

	//エラーチェック
	if (animation[0] == -1/*||animation[1]==-1||animation[2]==-1||animation[3]==-1*/)
	{
		throw("爆弾の画像がありません\n");
	}

	//向きの設定
	radian = 360.0;

	//当たり判定の大きさを設定
	box_size = 64.0;

	//初期化処理の設定
	image = animation[0];
}

//更新処理
void bullet::Update()
{
	//移動処理
	Movement();
	//アニメーション制御
	AnimeControl();
}

//描画処理
void bullet::Draw() const
{
	//爆弾画像の描画
	DrawRotaGraphF(location.x, location.y, 1.0, radian, image, TRUE);

	//デバッグ用
#if _DEBUG
	//当たり判定の可視化
	Vector2D box_collision_upper_left = location - (box_size / 2.0f);
	Vector2D box_collision_lower_right = location + (box_size / 2.0f);

	DrawBoxAA(box_collision_upper_left.x, box_collision_upper_left.y, box_collision_lower_right.x, box_collision_lower_right.y, GetColor(255, 0, 0), FALSE);

#endif
}

//終了時処理
void bullet::Finalize()
{
	//使用した画像を解放する
	DeleteGraph(animation[0]);
	/*DeleteGraph(animation[1]);
	DeleteGraph(animation[2]);
	DeleteGraph(animation[3]);*/
}

//当たり判定通知処理
void bullet::OnHitCollision(GameObject* hit_object)
{
	//当たった時の処理
}

//移動処理
void bullet::Movement()
{
	//移動の速さ
	Vector2D velocity = 0.0f;

	//上に動く
	velocity.y += -1.0f;

	location += velocity;
}

//アニメーション制御
void bullet::AnimeControl()
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
			image = animation[0];
		}
		else
		{
			image = animation[0];
		}
	}
}

void bullet::SetDirection(Vector2D dir)
{
	// 自分と相手の方向ベクトルを算出する

	// 算出した方向ベクトルを正規化する

	// 正規化した値を移動量とする

}
