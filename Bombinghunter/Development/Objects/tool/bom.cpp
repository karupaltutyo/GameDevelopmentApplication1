#include "bom.h"
#include "../../Utility/InputControl.h"
#include "DxLib.h"

//�R���X�g���N�^
Bom::Bom() :animation_count(0)
{
	animation[0] = NULL;
	animation[1] = NULL;
}

//�f�X�g���N�^
Bom::~Bom()
{

}
//����������
void Bom::Initialize()
{
	//�摜�̓ǂݍ���
	animation[0] = LoadGraph("Resource/Images/���e.png");

	//�G���[�`�F�b�N
	if (animation[0] == -1)
	{
		throw("���e�̉摜������܂���\n");
	}

	//�����̐ݒ�
	radian = 360.0;

	//�����蔻��̑傫����ݒ�
	box_size = 64.0;

	//�����������̐ݒ�
	image = animation[0];
}

//�X�V����
void Bom::Update()
{
	//�ړ�����
	Movement();
	//�A�j���[�V��������
	AnimeControl();
}

//�`�揈��
void Bom::Draw() const
{
	//���e�摜�̕`��
	DrawRotaGraphF(location.x, location.y, 1.0, radian, image, TRUE);

	//�f�o�b�O�p
#if _DEBUG
	//�����蔻��̉���
	Vector2D box_collision_upper_left = location - (box_size / 2.0f);
	Vector2D box_collision_lower_right = location + (box_size / 2.0f);

	DrawBoxAA(box_collision_upper_left.x, box_collision_upper_left.y, box_collision_lower_right.x, box_collision_lower_right.y, GetColor(255, 0, 0), FALSE);

#endif
}

//�I��������
void Bom::Finalize()
{
	//�g�p�����摜���������
	DeleteGraph(animation[0]);
}

//�����蔻��ʒm����
void Bom::OnHitCollision(GameObject* hit_object)
{
	//�����������̏���
}

//�ړ�����
void Bom::Movement()
{
	//�ړ��̑���
	Vector2D velocity = 0.0f;

	//���ړ�
		velocity.y+= +1.0f;

	location += velocity;
}

//�A�j���[�V��������
void Bom::AnimeControl()
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
			image = animation[0];
		}
		else
		{
			image = animation[0];
		}
	}
}