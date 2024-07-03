#include "Enemy.h"
#include "../GameObject.h"
#include "DxLib.h"


//�R���X�g���N�^
Enemy::Enemy() :animation_count(0), direction(0.0f)
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

	//�i�s�����ɂ���āA���]��Ԃ����肷��
	if (direction.x > 0.0f)
	{
		flip_flag = FALSE;
	}
	else
	{
		flip_flag = TRUE;
	}
	//�n�R�e�L�摜�̕`��
	DrawRotaGraphF(location.x, 420.0, 0.7, radian, image, TRUE, filp_flag);
	

	

	//�e�N���X�̕`�揈�����Ăяo��
	__super::Draw();

	//�f�o�b�O�p
#if _DEBUG
	//�����蔻��̉���
	Vector2D box_collision_upper_left = location - (box_size / 2.0f);
	Vector2D box_collision_lower_right = location + (box_size / 2.0f);

	DrawBoxAA(box_collision_upper_left.x, box_collision_upper_left.y, box_collision_lower_right.x, box_collision_lower_right.y, GetColor(255, 0, 0), FALSE);

#endif
	
	
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
	DeleteGraph(animation[0]);
	DeleteGraph(animation[1]);
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