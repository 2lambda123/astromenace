/************************************************************************************

	AstroMenace
	Hardcore 3D space scroll-shooter with spaceship upgrade possibilities.
	Copyright (c) 2006-2018 Mikhail Kurinnoi, Viewizard


	AstroMenace is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	AstroMenace is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with AstroMenace. If not, see <https://www.gnu.org/licenses/>.


	Website: https://www.viewizard.com/
	Project: https://github.com/viewizard/astromenace
	E-mail: viewizard@viewizard.com

*************************************************************************************/

#include "ground_object.h"
#include "../../assets/texture.h"
#include "../weapon/weapon.h"

// NOTE switch to nested namespace definition (namespace A::B::C { ... }) (since C++17)
namespace viewizard {
namespace astromenace {

struct sTrackedData {
	float Strength;
	float SpeedToRotate;
	std::string Model3DFileName;
	std::string TextureFileName;
};

const std::vector<sTrackedData> PresetTrackedData{
	{250,	60.0f,	"models/tracked/tank-01.vw3d", "models/gr-01.vw2d"},
	{200,	45.0f,	"models/tracked/tank-03.vw3d", "models/gr-01.vw2d"},
	{300,	45.0f,	"models/tracked/tank-05.vw3d", "models/gr-06.vw2d"},
	{300,	55.0f,	"models/tracked/tank-06.vw3d", "models/gr-03.vw2d"},
	{400,	60.0f,	"models/tracked/tank-07.vw3d", "models/gr-06.vw2d"},
	{250,	70.0f,	"models/tracked/tank-08.vw3d", "models/gr-01.vw2d"},
	{400,	60.0f,	"models/tracked/tank-09.vw3d", "models/gr-01.vw2d"},
	{300,	60.0f,	"models/tracked/tank-10.vw3d", "models/gr-03.vw2d"},
	{350,	60.0f,	"models/tracked/tank-11.vw3d", "models/gr-03.vw2d"},
	{300,	60.0f,	"models/tracked/apc-01.vw3d", "models/gr-03.vw2d"},
	{400,	60.0f,	"models/tracked/apc-03.vw3d", "models/gr-03.vw2d"},
	{250,	60.0f,	"models/tracked/apc-aa-01.vw3d", "models/gr-03.vw2d"},
	{200,	42.0f,	"models/tracked/apc-aa-02.vw3d", "models/gr-02.vw2d"},
	{50,	50.0f,	"models/tracked/engineering-01.vw3d", "models/gr-03.vw2d"}
};


//-----------------------------------------------------------------------------
// Конструктор, инициализация всех переменных
//-----------------------------------------------------------------------------
cTracked::cTracked(int TrackedNum)
{
	if ((TrackedNum <= 0) || (static_cast<unsigned>(TrackedNum) > PresetTrackedData.size())) {
		std::cerr << __func__ << "(): " << "Could not init cTracked object with Number " << TrackedNum << "\n";
		return;
	}

	ObjectType = eObjectType::PirateVehicle;
	MaxSpeed = 20.0f;
	MaxAcceler = 5.0f;
	MaxSpeedRotate = 20.0f;
	InternalType = TrackedNum;

	// ставим без оптимизации, иначе не увидим гусениц
	NeedCullFaces = false;

	LoadObjectData(PresetTrackedData[TrackedNum - 1].Model3DFileName, this);

	for (unsigned int i = 0; i < Model3DBlocks.size(); i++) {
		Texture[i] = GetPreloadedTextureAsset(PresetTrackedData[TrackedNum - 1].TextureFileName);
	}
	ResistanceHull = 1.0f;
	ResistanceSystems = 1.0f;
	SpeedToRotate = PresetTrackedData[TrackedNum - 1].SpeedToRotate;

	Strength = StrengthStart = PresetTrackedData[TrackedNum - 1].Strength/GameEnemyArmorPenalty;

	// установка доп. текстуры и других настроек для каждой модели
	switch (TrackedNum) {
	case 1:
		Weapon.emplace_back(CreateWeapon(211), sVECTOR3D(0.0f, 5.5f, 9.0f));

		WheelObjects.resize(16);
		WheelObjects[0] = 2;
		WheelObjects[1] = 3;
		WheelObjects[2] = 4;
		WheelObjects[3] = 6;
		WheelObjects[4] = 7;
		WheelObjects[5] = 8;
		WheelObjects[6] = 9;
		WheelObjects[7] = 10;
		WheelObjects[8] = 11;
		WheelObjects[9] = 12;
		WheelObjects[10] = 13;
		WheelObjects[11] = 14;
		WheelObjects[12] = 15;
		WheelObjects[13] = 16;
		WheelObjects[14] = 17;
		WheelObjects[15] = 18;

		TargetHorizBlocks.resize(2);
		TargetHorizBlocks[0] = 1;
		TargetHorizBlocks[1] = 5;

		TargetVertBlocks.emplace_back(5);
		TargetVertBlocksMaxAngle = 50.0f;

		TrackObjectNum = 19;
		Texture[19] = GetPreloadedTextureAsset("models/track.vw2d");
		break;

	case 2:
		Weapon.resize(2);
		Weapon[0](CreateWeapon(204), sVECTOR3D(0.1f, 6.1f, -0.4f));
		Weapon[1](CreateWeapon(204), sVECTOR3D(-0.1f, 6.1f, -0.4f));
		WeaponFireType = 2;

		WheelObjects.resize(10);
		WheelObjects[0] = 1;
		WheelObjects[1] = 2;
		WheelObjects[2] = 3;
		WheelObjects[3] = 4;
		WheelObjects[4] = 5;
		WheelObjects[5] = 6;
		WheelObjects[6] = 7;
		WheelObjects[7] = 8;
		WheelObjects[8] = 9;
		WheelObjects[9] = 10;

		TargetHorizBlocks.resize(2);
		TargetHorizBlocks[0] = 11;
		TargetHorizBlocks[1] = 12;

		TargetVertBlocks.emplace_back(12);
		TargetVertBlocksMaxAngle = 50.0f;

		TrackObjectNum = 13;
		Texture[13] = GetPreloadedTextureAsset("models/track.vw2d");
		break;

	case 3:
		Weapon.emplace_back(CreateWeapon(213), sVECTOR3D(0.0f, 5.2f, 3.7f));

		WheelObjects.resize(14);
		WheelObjects[0] = 0;
		WheelObjects[1] = 1;
		WheelObjects[2] = 2;
		WheelObjects[3] = 3;
		WheelObjects[4] = 4;
		WheelObjects[5] = 6;
		WheelObjects[6] = 7;
		WheelObjects[7] = 10;
		WheelObjects[8] = 11;
		WheelObjects[9] = 12;
		WheelObjects[10] = 13;
		WheelObjects[11] = 14;
		WheelObjects[12] = 15;
		WheelObjects[13] = 16;

		TargetHorizBlocks.resize(2);
		TargetHorizBlocks[0] = 8;
		TargetHorizBlocks[1] = 9;

		TargetVertBlocks.emplace_back(9);
		TargetVertBlocksMaxAngle = 50.0f;

		TrackObjectNum = 17;
		Texture[17] = GetPreloadedTextureAsset("models/track.vw2d");
		break;

	case 4:
		Weapon.emplace_back(CreateWeapon(208), sVECTOR3D(0.0f, 5.3f, 6.5f));

		WheelObjects.resize(16);
		WheelObjects[0] = 1;
		WheelObjects[1] = 2;
		WheelObjects[2] = 3;
		WheelObjects[3] = 4;
		WheelObjects[4] = 5;
		WheelObjects[5] = 6;
		WheelObjects[6] = 7;
		WheelObjects[7] = 8;
		WheelObjects[8] = 9;
		WheelObjects[9] = 10;
		WheelObjects[10] = 11;
		WheelObjects[11] = 12;
		WheelObjects[12] = 13;
		WheelObjects[13] = 14;
		WheelObjects[14] = 15;
		WheelObjects[15] = 16;

		TargetHorizBlocks.resize(3);
		TargetHorizBlocks[0] = 17;
		TargetHorizBlocks[1] = 18;
		TargetHorizBlocks[2] = 19;

		TargetVertBlocks.emplace_back(18);
		TargetVertBlocksMaxAngle = 50.0f;

		Model3DBlocks[19].Location.z -= 1.0f;

		TrackObjectNum = 20;
		Texture[20] = GetPreloadedTextureAsset("models/track.vw2d");
		break;

	case 5:
		Weapon.emplace_back(CreateWeapon(208), sVECTOR3D(0.0f, 5.8f, 4.5f));

		WheelObjects.resize(14);
		WheelObjects[0] = 1;
		WheelObjects[1] = 2;
		WheelObjects[2] = 3;
		WheelObjects[3] = 4;
		WheelObjects[4] = 5;
		WheelObjects[5] = 6;
		WheelObjects[6] = 7;
		WheelObjects[7] = 10;
		WheelObjects[8] = 11;
		WheelObjects[9] = 12;
		WheelObjects[10] = 13;
		WheelObjects[11] = 14;
		WheelObjects[12] = 15;
		WheelObjects[13] = 16;

		TargetHorizBlocks.resize(2);
		TargetHorizBlocks[0] = 9;
		TargetHorizBlocks[1] = 8;

		TargetVertBlocks.emplace_back(8);
		TargetVertBlocksMaxAngle = 30.0f;

		TrackObjectNum = 17;
		Texture[17] = GetPreloadedTextureAsset("models/track.vw2d");
		break;

	case 6:
		Weapon.emplace_back(CreateWeapon(211), sVECTOR3D(0.0f, 4.9f, 4.0f));

		WheelObjects.resize(16);
		WheelObjects[0] = 2;
		WheelObjects[1] = 3;
		WheelObjects[2] = 4;
		WheelObjects[3] = 5;
		WheelObjects[4] = 6;
		WheelObjects[5] = 7;
		WheelObjects[6] = 8;
		WheelObjects[7] = 9;
		WheelObjects[8] = 10;
		WheelObjects[9] = 11;
		WheelObjects[10] = 12;
		WheelObjects[11] = 13;
		WheelObjects[12] = 14;
		WheelObjects[13] = 15;
		WheelObjects[14] = 16;
		WheelObjects[15] = 17;

		TargetHorizBlocks.resize(2);
		TargetHorizBlocks[0] = 1;
		TargetHorizBlocks[1] = 18;

		TargetVertBlocks.emplace_back(18);
		TargetVertBlocksMaxAngle = 50.0f;

		TrackObjectNum = 19;
		Texture[19] = GetPreloadedTextureAsset("models/track.vw2d");
		break;

	case 7:
		Weapon.emplace_back(CreateWeapon(212), sVECTOR3D(0.0f, 7.6f, 5.5f));

		WheelObjects.resize(16);
		WheelObjects[0] = 1;
		WheelObjects[1] = 2;
		WheelObjects[2] = 3;
		WheelObjects[3] = 4;
		WheelObjects[4] = 5;
		WheelObjects[5] = 6;
		WheelObjects[6] = 7;
		WheelObjects[7] = 8;
		WheelObjects[8] = 9;
		WheelObjects[9] = 10;
		WheelObjects[10] = 13;
		WheelObjects[11] = 14;
		WheelObjects[12] = 15;
		WheelObjects[13] = 16;
		WheelObjects[14] = 17;
		WheelObjects[15] = 18;

		TargetHorizBlocks.resize(2);
		TargetHorizBlocks[0] = 12;
		TargetHorizBlocks[1] = 11;

		TargetVertBlocks.emplace_back(11);
		TargetVertBlocksMaxAngle = 50.0f;

		TrackObjectNum = 19;
		Texture[19] = GetPreloadedTextureAsset("models/track.vw2d");
		break;

	case 8:
		Weapon.emplace_back(CreateWeapon(208), sVECTOR3D(0.0f, 7.0f, 8.5f));

		WheelObjects.resize(16);
		WheelObjects[0] = 1;
		WheelObjects[1] = 2;
		WheelObjects[2] = 3;
		WheelObjects[3] = 4;
		WheelObjects[4] = 5;
		WheelObjects[5] = 6;
		WheelObjects[6] = 7;
		WheelObjects[7] = 8;
		WheelObjects[8] = 9;
		WheelObjects[9] = 10;
		WheelObjects[10] = 11;
		WheelObjects[11] = 12;
		WheelObjects[12] = 13;
		WheelObjects[13] = 14;
		WheelObjects[14] = 15;
		WheelObjects[15] = 16;

		TargetHorizBlocks.resize(2);
		TargetHorizBlocks[0] = 17;
		TargetHorizBlocks[1] = 18;

		TargetVertBlocks.emplace_back(18);
		TargetVertBlocksMaxAngle = 50.0f;

		TrackObjectNum = 19;
		Texture[19] = GetPreloadedTextureAsset("models/track.vw2d");
		break;

	case 9:
		Weapon.emplace_back(CreateWeapon(211), sVECTOR3D(0.0f, 6.7f, 6.8f));
		Weapon.back().Weapon->NextFireTime /= 2.0f;

		WheelObjects.resize(16);
		WheelObjects[0] = 1;
		WheelObjects[1] = 2;
		WheelObjects[2] = 3;
		WheelObjects[3] = 4;
		WheelObjects[4] = 5;
		WheelObjects[5] = 6;
		WheelObjects[6] = 7;
		WheelObjects[7] = 8;
		WheelObjects[8] = 9;
		WheelObjects[9] = 10;
		WheelObjects[10] = 11;
		WheelObjects[11] = 12;
		WheelObjects[12] = 13;
		WheelObjects[13] = 14;
		WheelObjects[14] = 15;
		WheelObjects[15] = 16;

		TargetHorizBlocks.resize(2);
		TargetHorizBlocks[0] = 18;
		TargetHorizBlocks[1] = 0;

		TargetVertBlocks.emplace_back(0);
		TargetVertBlocksMaxAngle = 50.0f;

		TrackObjectNum = 19;
		Texture[19] = GetPreloadedTextureAsset("models/track.vw2d");
		break;

	case 10:
		Weapon.emplace_back(CreateWeapon(204), sVECTOR3D(0.0f, 6.1f, 0.5f));
		Weapon.back().Weapon->NextFireTime /= 2.0f;

		WheelObjects.resize(16);
		WheelObjects[0] = 1;
		WheelObjects[1] = 2;
		WheelObjects[2] = 3;
		WheelObjects[3] = 4;
		WheelObjects[4] = 5;
		WheelObjects[5] = 6;
		WheelObjects[6] = 7;
		WheelObjects[7] = 8;
		WheelObjects[8] = 9;
		WheelObjects[9] = 10;
		WheelObjects[10] = 11;
		WheelObjects[11] = 12;
		WheelObjects[12] = 13;
		WheelObjects[13] = 14;
		WheelObjects[14] = 15;
		WheelObjects[15] = 16;

		TargetHorizBlocks.resize(2);
		TargetHorizBlocks[0] = 18;
		TargetHorizBlocks[1] = 0;

		TargetVertBlocks.emplace_back(0);
		TargetVertBlocksMaxAngle = 50.0f;

		TrackObjectNum = 19;
		Texture[19] = GetPreloadedTextureAsset("models/track.vw2d");
		break;

	case 11:
		Weapon.resize(2);
		Weapon[0](CreateWeapon(209), sVECTOR3D(2.2f, 5.4f, 7.0f));
		Weapon[1](CreateWeapon(209), sVECTOR3D(-2.2f, 5.4f, 7.0f));
		WeaponFireType = 3;

		WheelObjects.resize(16);
		WheelObjects[0] = 1;
		WheelObjects[1] = 2;
		WheelObjects[2] = 3;
		WheelObjects[3] = 4;
		WheelObjects[4] = 5;
		WheelObjects[5] = 6;
		WheelObjects[6] = 7;
		WheelObjects[7] = 8;
		WheelObjects[8] = 9;
		WheelObjects[9] = 10;
		WheelObjects[10] = 11;
		WheelObjects[11] = 12;
		WheelObjects[12] = 13;
		WheelObjects[13] = 14;
		WheelObjects[14] = 15;
		WheelObjects[15] = 16;

		TargetVertBlocks.emplace_back(0);
		TargetVertBlocksMaxAngle = 55.0f;

		TrackObjectNum = 18;
		Texture[18] = GetPreloadedTextureAsset("models/track.vw2d");
		break;

	case 12:
		Weapon.resize(4);
		Weapon[0](CreateWeapon(206), sVECTOR3D(0.55f, 5.0f, 2.0f));
		Weapon[0].Weapon->NextFireTime /= 2.0f;
		Weapon[1](CreateWeapon(206), sVECTOR3D(-0.55f, 5.0f, 2.0f));
		Weapon[1].Weapon->NextFireTime /= 2.0f;
		Weapon[2](CreateWeapon(206), sVECTOR3D(1.65f, 5.0f, 2.0f));
		Weapon[2].Weapon->NextFireTime /= 2.0f;
		Weapon[3](CreateWeapon(206), sVECTOR3D(-1.65f, 5.0f, 2.0f));
		Weapon[3].Weapon->NextFireTime /= 2.0f;
		WeaponFireType = 3;

		WheelObjects.resize(16);
		WheelObjects[0] = 1;
		WheelObjects[1] = 2;
		WheelObjects[2] = 3;
		WheelObjects[3] = 4;
		WheelObjects[4] = 5;
		WheelObjects[5] = 6;
		WheelObjects[6] = 7;
		WheelObjects[7] = 8;
		WheelObjects[8] = 9;
		WheelObjects[9] = 10;
		WheelObjects[10] = 11;
		WheelObjects[11] = 12;
		WheelObjects[12] = 13;
		WheelObjects[13] = 14;
		WheelObjects[14] = 15;
		WheelObjects[15] = 16;


		TargetVertBlocks.resize(2);
		TargetVertBlocks[0] = 18;
		TargetVertBlocks[1] = 0;
		TargetVertBlocksMaxAngle = 40.0f;

		TrackObjectNum = 19;
		Texture[19] = GetPreloadedTextureAsset("models/track.vw2d");
		break;

	case 13:
		Weapon.resize(2);
		Weapon[0](CreateWeapon(206), sVECTOR3D(1.4f, 5.0f, 0.4f));
		Weapon[0].Weapon->NextFireTime /= 2.0f;
		Weapon[1](CreateWeapon(206), sVECTOR3D(-1.4f, 5.0f, 0.4f));
		Weapon[1].Weapon->NextFireTime /= 2.0f;
		WeaponFireType = 3;

		WheelObjects.resize(14);
		WheelObjects[0] = 2;
		WheelObjects[1] = 3;
		WheelObjects[2] = 4;
		WheelObjects[3] = 5;
		WheelObjects[4] = 6;
		WheelObjects[5] = 7;
		WheelObjects[6] = 8;
		WheelObjects[7] = 9;
		WheelObjects[8] = 10;
		WheelObjects[9] = 11;
		WheelObjects[10] = 12;
		WheelObjects[11] = 13;
		WheelObjects[12] = 14;
		WheelObjects[13] = 15;

		TargetHorizBlocks.resize(2);
		TargetHorizBlocks[0] = 0;
		TargetHorizBlocks[1] = 16;

		TargetVertBlocks.emplace_back(16);
		TargetVertBlocksMaxAngle = 50.0f;

		TrackObjectNum = 17;
		Texture[17] = GetPreloadedTextureAsset("models/track.vw2d");
		break;

	case 14:
		WheelObjects.resize(8);
		WheelObjects[0] = 0;
		WheelObjects[1] = 2;
		WheelObjects[2] = 3;
		WheelObjects[3] = 4;
		WheelObjects[4] = 5;
		WheelObjects[5] = 6;
		WheelObjects[6] = 7;
		WheelObjects[7] = 8;

		TrackObjectNum = 10;
		Texture[10] = GetPreloadedTextureAsset("models/track.vw2d");
		TrackRotationDirection = -1;
		break;
	}

	// делаем сдвиг поворота колес, чтобы смотрелось естественнее
	for (unsigned i = 0; i < WheelObjects.size(); i++) {
		Model3DBlocks[WheelObjects[i]].Rotation.x = vw_fRandNum(360.0f);
	}

	// вычисляем данные для нахождения точки стрельбы
	if (!TargetHorizBlocks.empty()) {
		BaseBound = Model3DBlocks[TargetHorizBlocks[0]].Location;
	}

	if (!TargetVertBlocks.empty()) {
		if (!TargetHorizBlocks.empty())
			MiddleBound = Model3DBlocks[TargetVertBlocks[0]].Location - Model3DBlocks[TargetHorizBlocks[0]].Location;
		else
			MiddleBound = Model3DBlocks[TargetVertBlocks[0]].Location;
	}

	for (auto &tmpWeapon : Weapon) {
		if (!TargetVertBlocks.empty())
			tmpWeapon.Bound = tmpWeapon.Location - Model3DBlocks[TargetVertBlocks[0]].Location;
		else if (!TargetHorizBlocks.empty())
			tmpWeapon.Bound = tmpWeapon.Location - Model3DBlocks[TargetHorizBlocks[0]].Location;
		else
			tmpWeapon.Bound = tmpWeapon.Location;
	}
}

} // astromenace namespace
} // viewizard namespace
