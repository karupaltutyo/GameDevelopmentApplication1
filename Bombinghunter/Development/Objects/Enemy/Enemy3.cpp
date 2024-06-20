#include "Enemy3.h"
#include "../GameObject.h"
#include "DxLib.h"

//�R���X�g���N�^
Enemy3::Enemy3() :animation_count(0), filp_flag(FALSE)
{
	animation[0] = NULL;
	animation[1] = NULL;

}

//�f�X�g���N�^
Enemy3::~Enemy3()
{

}
//����������
void Enemy3::Initialize()
{
	//�摜�̓ǂݍ���
	animation[0] = LoadGraph("Resource/Images/1 (3).png");
	animation[1] = LoadGraph("Resource/Images/2 (3).png");
	animation[2] = LoadGraph("Resource/Images/3.png");
	animation[3] = LoadGraph("Resource/Images/4.png");
	animation[4] = LoadGraph("Resource/Images/5.png");

	//�G���[�`�F�b�N
	if (animation[0] == -1 || animation[1] == -1||animation[2]==-1||animation[3]==-1||animation[4]==-1)
	{
		throw("���̃e�L�̉摜������܂���\n");
	}

	//�����̐ݒ�
	radian = 0.0;

	//��`�̑傫���̐ݒ�
	box_size = 64.0;

	//�����������̐ݒ�
	image = animation[0];
}

//�X�V����
void Enemy3::Update()
{
	//�ړ�����
	Movement();
	//�A�j���[�V��������
	AnimeControl();
}

//�`�揈��
void Enemy3::Draw() const
{
	//�摜���]�t���O
	int flip_flag = FALSE;
	//�n�[�s�[�摜�̕`��
	DrawRotaGraphF(location.x, 420.0, 1.0, radian, image, TRUE, filp_flag);


}

//�I��������
void Enemy3::Finalize()
{
	//�g�p�����摜���������
	DeleteGraph(animation[0]);
	DeleteGraph(animation[1]);
	DeleteGraph(animation[2]);
	DeleteGraph(animation[3]);
	DeleteGraph(animation[4]);
}

//�����蔻��ʒm����
void Enemy3::OnHitCollision(GameObject* hit_object)
{
	//�����������̏���
	direction = 0.0f;
}

//�ړ�����
void Enemy3::Movement()
{
	//�ړ��̑���
	Vector2D velocity = 0.0f;

	//�E�����ɐi�ݑ�����
	location.x += -1.0f;

	//�E�̒[�ɍs���ƁA���̒[�ֈړ�����
	if (location.x <= 0.0f)
	{
		location.x = 640.0f;
	}

	//���݂̈ʒu���W�ɑ��������Z����
	location += velocity;
}

//�A�j���[�V��������
void Enemy3::AnimeControl()
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