#include "Enemy.h"
#include "../GameObject.h"
#include "DxLib.h"

//�R���X�g���N�^
Enemy::Enemy() :animation_count(0), filp_flag(FALSE)
{
	animation[0] = NULL;
	animation[1] = NULL;
	
}

//�f�X�g���N�^
Enemy::~Enemy()
{

}
//����������
void Enemy::Initialize()
{
	//�摜�̓ǂݍ���
	animation[0] = LoadGraph("Resource/Images/1 (1).png");
	animation[1] = LoadGraph("Resource/Images/2 (1).png");

	//�G���[�`�F�b�N
	if (animation[0] == -1 || animation[1] == -1)
	{
		throw("�n�R�e�L�̉摜������܂���\n");
	}

	//�����̐ݒ�
	radian = 0.0;

	//��`�̑傫���̐ݒ�
	box_size = 64.0;

	//�����������̐ݒ�
	image = animation[0];
}

//�X�V����
void Enemy::Update()
{
	//�ړ�����
	Movement();
	//�A�j���[�V��������
	AnimeControl();
}

//�`�揈��
void Enemy::Draw() const
{
	//�摜���]�t���O
	int flip_flag = FALSE;
	//�n�R�e�L�摜�̕`��
	DrawRotaGraphF(location.x, 420.0, 1.0, radian, image, TRUE, filp_flag);
	if()
	DrawRotaGraphF(location.x, 420.0, 1.0, radian, image, TRUE, filp_flag);

	DrawRotaGraphF(location.x, 420.0, 1.0, radian, image, TRUE, filp_flag);


}

//�I��������
void Enemy::Finalize()
{
	//�g�p�����摜���������
	DeleteGraph(animation[0]);
	DeleteGraph(animation[1]);
}

//�����蔻��ʒm����
void Enemy::OnHitCollision(GameObject* hit_object)
{
	//�����������̏���
	direction = 0.0f;
}

//�ړ�����
void Enemy::Movement()
{
	//�ړ��̑���
	Vector2D velocity = 0.0f;

	//�E�����ɐi�ݑ�����
	location.x += 1.0f;

	//�E�̒[�ɍs���ƁA���̒[�ֈړ�����
	if (location.x >= 640.0f)
	{
		location.x = 0.0f;
	}

	//���݂̈ʒu���W�ɑ��������Z����
	location += velocity;
}

//�A�j���[�V��������
void Enemy::AnimeControl()
{
	//�t���[���J�E���g�����Z����
	animation_count++;

	//60�t���[���ڂɓ��B������
	if (animation_count >= 60)
	{
		//�J�E���g�̃��Z�b�g
		animation_count = 0;

		//�摜�̐؂�ւ�
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
