/******************************************************************************

	This source file is part of AstroMenace game
	(Hardcore 3D space shooter with spaceship upgrade possibilities.)
	For the latest info, see http://www.viewizard.com/

	File name: Menu_Credits.cpp

	Copyright (c) 2006-2007 Michael Kurinnoy, Viewizard
	All Rights Reserved.

	File Version: 1.2

******************************************************************************

	AstroMenace game source code available under "dual licensing" model.
	The licensing options available are:

	* Commercial Licensing. This is the appropriate option if you are
	  creating proprietary applications and you are not prepared to
	  distribute and share the source code of your application.
	  Contact us for pricing at viewizard@viewizard.com

	* Open Source Licensing. This is the appropriate option if you want
	  to share the source code of your application with everyone you
	  distribute it to, and you also want to give them the right to share
	  who uses it. You should have received a copy of the GNU General Public
	  License version 3 with this source codes.
	  If not, see <http://www.gnu.org/licenses/>.

******************************************************************************/


#include "../Defines.h"
#include "../Game.h"




float CreditsCurrentPos = 0.0f;
float LastCreditsCurrentPosUpdateTime = 0.0f;




void CreditsMenu()
{

	// делаем движение
	CreditsCurrentPos -= 40.0f*(vw_GetTime() - LastCreditsCurrentPosUpdateTime);
	LastCreditsCurrentPosUpdateTime = vw_GetTime();

	// зацикливание
	if (CreditsCurrentPos <= -2655) CreditsCurrentPos = 0.0f;




	RECT SrcRest, DstRest;


	int Y1 = 690+(int)CreditsCurrentPos;
	int Y2 = 690+25+(int)CreditsCurrentPos;
	int Offset1 = 25;
	int Offset2 = 90;


	float ttt = 0.0f;

	int SizeI = (Setup.iAspectRatioWidth-FontSize(GetText("10_PROJECT_LEADER")))/2;
	if (Y1 > 300) {ttt = (650 - Y1) /100.0f; if (ttt > 1.0f) ttt = 1.0f;}
	else {ttt = (Y1 - 100) /100.0f; if (ttt < 0.0f) ttt = 0.0f;}
	DrawFont(SizeI, Y1, 0, 0, 1, ttt*MenuContentTransp, GetText("10_PROJECT_LEADER"));
	SizeI = (Setup.iAspectRatioWidth-FontSize(GetText("10_Michael_Kurinnoy")))/2;
	if (Y2 > 300) {ttt = (650 - Y2) /100.0f; if (ttt > 1.0f) ttt = 1.0f;}
	else {ttt = (Y2 - 100) /100.0f; if (ttt < 0.0f) ttt = 0.0f;}
	DrawFont(SizeI, Y2, 0, 0, 0, ttt*MenuContentTransp, GetText("10_Michael_Kurinnoy"));



	Y1 += Offset2;
	Y2 += Offset2;
	SizeI = (Setup.iAspectRatioWidth-FontSize(GetText("10_2D_ARTWORK")))/2;
	if (Y1 > 300) {ttt = (650 - Y1) /100.0f; if (ttt > 1.0f) ttt = 1.0f;}
	else {ttt = (Y1 - 100) /100.0f; if (ttt < 0.0f) ttt = 0.0f;}
	DrawFont(SizeI, Y1, 0, 0, 1, ttt*MenuContentTransp, GetText("10_2D_ARTWORK"));
	SizeI = (Setup.iAspectRatioWidth-FontSize(GetText("10_Tatiana_Savitskaya")))/2;
	if (Y2 > 300) {ttt = (650 - Y2) /100.0f; if (ttt > 1.0f) ttt = 1.0f;}
	else {ttt = (Y2 - 100) /100.0f; if (ttt < 0.0f) ttt = 0.0f;}
	DrawFont(SizeI, Y2, 0, 0, 0, ttt*MenuContentTransp, GetText("10_Tatiana_Savitskaya"));


	Y1 += Offset2;
	Y2 += Offset2;
	SizeI = (Setup.iAspectRatioWidth-FontSize(GetText("10_3D_MODELING")))/2;
	if (Y1 > 300) {ttt = (650 - Y1) /100.0f; if (ttt > 1.0f) ttt = 1.0f;}
	else {ttt = (Y1 - 100) /100.0f; if (ttt < 0.0f) ttt = 0.0f;}
	DrawFont(SizeI, Y1, 0, 0, 1, ttt*MenuContentTransp, GetText("10_3D_MODELING"));
	SizeI = (Setup.iAspectRatioWidth-FontSize(GetText("10_Max_Shelekhov")))/2;
	if (Y2 > 300) {ttt = (650 - Y2) /100.0f; if (ttt > 1.0f) ttt = 1.0f;}
	else {ttt = (Y2 - 100) /100.0f; if (ttt < 0.0f) ttt = 0.0f;}
	DrawFont(SizeI, Y2, 0, 0, 0, ttt*MenuContentTransp, GetText("10_Max_Shelekhov"));

	Y1 += Offset1;
	Y2 += Offset1;
	SizeI = (Setup.iAspectRatioWidth-FontSize(GetText("10_Oleg_Linkov")))/2;
	if (Y2 > 300) {ttt = (650 - Y2) /100.0f; if (ttt > 1.0f) ttt = 1.0f;}
	else {ttt = (Y2 - 100) /100.0f; if (ttt < 0.0f) ttt = 0.0f;}
	DrawFont(SizeI, Y2, 0, 0, 0, ttt*MenuContentTransp, GetText("10_Oleg_Linkov"));
	Y1 += Offset1;
	Y2 += Offset1;
	SizeI = (Setup.iAspectRatioWidth-FontSize(GetText("10_Egor_Kurteanu")))/2;
	if (Y2 > 300) {ttt = (650 - Y2) /100.0f; if (ttt > 1.0f) ttt = 1.0f;}
	else {ttt = (Y2 - 100) /100.0f; if (ttt < 0.0f) ttt = 0.0f;}
	DrawFont(SizeI, Y2, 0, 0, 0, ttt*MenuContentTransp, GetText("10_Egor_Kurteanu"));





	Y1 += Offset2;
	Y2 += Offset2;
	SizeI = (Setup.iAspectRatioWidth-FontSize(GetText("10_MUSIC")))/2;
	if (Y1 > 300) {ttt = (650 - Y1) /100.0f; if (ttt > 1.0f) ttt = 1.0f;}
	else {ttt = (Y1 - 100) /100.0f; if (ttt < 0.0f) ttt = 0.0f;}
	DrawFont(SizeI, Y1, 0, 0, 1, ttt*MenuContentTransp, GetText("10_MUSIC"));
	SizeI = (Setup.iAspectRatioWidth-FontSize(GetText("10_Alexander_Matchugovsky")))/2;
	if (Y2 > 300) {ttt = (650 - Y2) /100.0f; if (ttt > 1.0f) ttt = 1.0f;}
	else {ttt = (Y2 - 100) /100.0f; if (ttt < 0.0f) ttt = 0.0f;}
	DrawFont(SizeI, Y2, 0, 0, 0, ttt*MenuContentTransp, GetText("10_Alexander_Matchugovsky"));


	Y1 += Offset2;
	Y2 += Offset2;
	SizeI = (Setup.iAspectRatioWidth-FontSize(GetText("10_SOUND_EFFECTS")))/2;
	if (Y1 > 300) {ttt = (650 - Y1) /100.0f; if (ttt > 1.0f) ttt = 1.0f;}
	else {ttt = (Y1 - 100) /100.0f; if (ttt < 0.0f) ttt = 0.0f;}
	DrawFont(SizeI, Y1, 0, 0, 1, ttt*MenuContentTransp, GetText("10_SOUND_EFFECTS"));
	SizeI = (Setup.iAspectRatioWidth-FontSize(GetText("10_Michael_Sirotkin")))/2;
	if (Y2 > 300) {ttt = (650 - Y2) /100.0f; if (ttt > 1.0f) ttt = 1.0f;}
	else {ttt = (Y2 - 100) /100.0f; if (ttt < 0.0f) ttt = 0.0f;}
	DrawFont(SizeI, Y2, 0, 0, 0, ttt*MenuContentTransp, GetText("10_Michael_Sirotkin"));
	Y1 += Offset1;
	Y2 += Offset1;
	SizeI = (Setup.iAspectRatioWidth-FontSize(GetText("10_Alexander_Matchugovsky")))/2;
	if (Y2 > 300) {ttt = (650 - Y2) /100.0f; if (ttt > 1.0f) ttt = 1.0f;}
	else {ttt = (Y2 - 100) /100.0f; if (ttt < 0.0f) ttt = 0.0f;}
	DrawFont(SizeI, Y2, 0, 0, 0, ttt*MenuContentTransp, GetText("10_Alexander_Matchugovsky"));
	Y1 += Offset1;
	Y2 += Offset1;
	SizeI = (Setup.iAspectRatioWidth-FontSize(GetText("10_Alexander_Vassilyevsky")))/2;
	if (Y2 > 300) {ttt = (650 - Y2) /100.0f; if (ttt > 1.0f) ttt = 1.0f;}
	else {ttt = (Y2 - 100) /100.0f; if (ttt < 0.0f) ttt = 0.0f;}
	DrawFont(SizeI, Y2, 0, 0, 0, ttt*MenuContentTransp, GetText("10_Alexander_Vassilyevsky"));


	Y1 += Offset2;
	Y2 += Offset2;
	SizeI = (Setup.iAspectRatioWidth-FontSize(GetText("10_VOICE")))/2;
	if (Y1 > 300) {ttt = (650 - Y1) /100.0f; if (ttt > 1.0f) ttt = 1.0f;}
	else {ttt = (Y1 - 100) /100.0f; if (ttt < 0.0f) ttt = 0.0f;}
	DrawFont(SizeI, Y1, 0, 0, 1, ttt*MenuContentTransp, GetText("10_VOICE"));
	SizeI = (Setup.iAspectRatioWidth-FontSize(GetText("10_Petra_Schulten_(de)")))/2;
	if (Y2 > 300) {ttt = (650 - Y2) /100.0f; if (ttt > 1.0f) ttt = 1.0f;}
	else {ttt = (Y2 - 100) /100.0f; if (ttt < 0.0f) ttt = 0.0f;}
	DrawFont(SizeI, Y2, 0, 0, 0, ttt*MenuContentTransp, GetText("10_Petra_Schulten_(de)"));
	Y1 += Offset1;
	Y2 += Offset1;
	SizeI = (Setup.iAspectRatioWidth-FontSize(GetText("10_Elena_Zavalishina_(en,_ru)")))/2;
	if (Y2 > 300) {ttt = (650 - Y2) /100.0f; if (ttt > 1.0f) ttt = 1.0f;}
	else {ttt = (Y2 - 100) /100.0f; if (ttt < 0.0f) ttt = 0.0f;}
	DrawFont(SizeI, Y2, 0, 0, 0, ttt*MenuContentTransp, GetText("10_Elena_Zavalishina_(en,_ru)"));







	Y1 += Offset2;
	Y2 += Offset2;
	SizeI = (Setup.iAspectRatioWidth-FontSize(GetText("10_WEB_PROGRAMMING")))/2;
	if (Y1 > 300) {ttt = (650 - Y1) /100.0f; if (ttt > 1.0f) ttt = 1.0f;}
	else {ttt = (Y1 - 100) /100.0f; if (ttt < 0.0f) ttt = 0.0f;}
	DrawFont(SizeI, Y1, 0, 0, 1, ttt*MenuContentTransp, GetText("10_WEB_PROGRAMMING"));
	SizeI = (Setup.iAspectRatioWidth-FontSize(GetText("10_Pavel_Voylov")))/2;
	if (Y2 > 300) {ttt = (650 - Y2) /100.0f; if (ttt > 1.0f) ttt = 1.0f;}
	else {ttt = (Y2 - 100) /100.0f; if (ttt < 0.0f) ttt = 0.0f;}
	DrawFont(SizeI, Y2, 0, 0, 0, ttt*MenuContentTransp, GetText("10_Pavel_Voylov"));



	Y1 += Offset2;
	Y2 += Offset2;
	SizeI = (Setup.iAspectRatioWidth-FontSize(GetText("10_TRANSLATOR")))/2;
	if (Y1 > 300) {ttt = (650 - Y1) /100.0f; if (ttt > 1.0f) ttt = 1.0f;}
	else {ttt = (Y1 - 100) /100.0f; if (ttt < 0.0f) ttt = 0.0f;}
	DrawFont(SizeI, Y1, 0, 0, 1, ttt*MenuContentTransp, GetText("10_TRANSLATOR"));
	SizeI = (Setup.iAspectRatioWidth-FontSize(GetText("10_Bernd_Dau_(de)")))/2;
	if (Y2 > 300) {ttt = (650 - Y2) /100.0f; if (ttt > 1.0f) ttt = 1.0f;}
	else {ttt = (Y2 - 100) /100.0f; if (ttt < 0.0f) ttt = 0.0f;}
	DrawFont(SizeI, Y2, 0, 0, 0, ttt*MenuContentTransp, GetText("10_Bernd_Dau_(de)"));

	Y1 += Offset1;
	Y2 += Offset1;
	SizeI = (Setup.iAspectRatioWidth-FontSize(GetText("10_Michael_Kurinnoy_(en,_ru)")))/2;
	if (Y2 > 300) {ttt = (650 - Y2) /100.0f; if (ttt > 1.0f) ttt = 1.0f;}
	else {ttt = (Y2 - 100) /100.0f; if (ttt < 0.0f) ttt = 0.0f;}
	DrawFont(SizeI, Y2, 0, 0, 0, ttt*MenuContentTransp, GetText("10_Michael_Kurinnoy_(en,_ru)"));




//	Y1 += Offset2;
//	Y2 += Offset2;
//	SizeI = (Setup.iAspectRatioWidth-FontSize("LEVEL DESIGN"))/2;
//	if (Y2 > 300) {ttt = (650 - Y2) /100.0f; if (ttt > 1.0f) ttt = 1.0f;}
//	else {ttt = (Y2 - 100) /100.0f; if (ttt < 0.0f) ttt = 0.0f;}
//	DrawFont(SizeI, Y1, 0, 0, 1, ttt*MenuContentTransp, "LEVEL DESIGN");
//	SizeI = (Setup.iAspectRatioWidth-FontSize("unknown"))/2;
//	if (Y2 > 300) {ttt = (650 - Y2) /100.0f; if (ttt > 1.0f) ttt = 1.0f;}
//	else {ttt = (Y2 - 100) /100.0f; if (ttt < 0.0f) ttt = 0.0f;}
//	DrawFont(SizeI, Y2, 0, 0, 0, ttt*MenuContentTransp, "unknown");


	Y1 += Offset2;
	Y2 += Offset2;
	SizeI = (Setup.iAspectRatioWidth-FontSize(GetText("10_TESTERS")))/2;
	if (Y1 > 300) {ttt = (650 - Y1) /100.0f; if (ttt > 1.0f) ttt = 1.0f;}
	else {ttt = (Y1 - 100) /100.0f; if (ttt < 0.0f) ttt = 0.0f;}
	DrawFont(SizeI, Y1, 0, 0, 1, ttt*MenuContentTransp, GetText("10_TESTERS"));
	SizeI = (Setup.iAspectRatioWidth-FontSize(GetText("10_Dmitriy_Schigolev")))/2;
	if (Y2 > 300) {ttt = (650 - Y2) /100.0f; if (ttt > 1.0f) ttt = 1.0f;}
	else {ttt = (Y2 - 100) /100.0f; if (ttt < 0.0f) ttt = 0.0f;}
	DrawFont(SizeI, Y2, 0, 0, 0, ttt*MenuContentTransp, GetText("10_Dmitriy_Schigolev"));
	Y1 += Offset1;
	Y2 += Offset1;
	SizeI = (Setup.iAspectRatioWidth-FontSize(GetText("10_Ivan_Bobrov")))/2;
	if (Y2 > 300) {ttt = (650 - Y2) /100.0f; if (ttt > 1.0f) ttt = 1.0f;}
	else {ttt = (Y2 - 100) /100.0f; if (ttt < 0.0f) ttt = 0.0f;}
	DrawFont(SizeI, Y2, 0, 0, 0, ttt*MenuContentTransp, GetText("10_Ivan_Bobrov"));
	Y1 += Offset1;
	Y2 += Offset1;
	SizeI = (Setup.iAspectRatioWidth-FontSize(GetText("10_Vadim_Sosenko")))/2;
	if (Y2 > 300) {ttt = (650 - Y2) /100.0f; if (ttt > 1.0f) ttt = 1.0f;}
	else {ttt = (Y2 - 100) /100.0f; if (ttt < 0.0f) ttt = 0.0f;}
	DrawFont(SizeI, Y2, 0, 0, 0, ttt*MenuContentTransp, GetText("10_Vadim_Sosenko"));
	Y1 += Offset1;
	Y2 += Offset1;
	SizeI = (Setup.iAspectRatioWidth-FontSize(GetText("10_Dmitriy_Tatarinov")))/2;
	if (Y2 > 300) {ttt = (650 - Y2) /100.0f; if (ttt > 1.0f) ttt = 1.0f;}
	else {ttt = (Y2 - 100) /100.0f; if (ttt < 0.0f) ttt = 0.0f;}
	DrawFont(SizeI, Y2, 0, 0, 0, ttt*MenuContentTransp, GetText("10_Dmitriy_Tatarinov"));
	Y1 += Offset1;
	Y2 += Offset1;
	SizeI = (Setup.iAspectRatioWidth-FontSize(GetText("10_Alexey_Mosesov")))/2;
	if (Y2 > 300) {ttt = (650 - Y2) /100.0f; if (ttt > 1.0f) ttt = 1.0f;}
	else {ttt = (Y2 - 100) /100.0f; if (ttt < 0.0f) ttt = 0.0f;}
	DrawFont(SizeI, Y2, 0, 0, 0, ttt*MenuContentTransp, GetText("10_Alexey_Mosesov"));
	Y1 += Offset1;
	Y2 += Offset1;
	SizeI = (Setup.iAspectRatioWidth-FontSize(GetText("10_Bernd_Dau")))/2;
	if (Y2 > 300) {ttt = (650 - Y2) /100.0f; if (ttt > 1.0f) ttt = 1.0f;}
	else {ttt = (Y2 - 100) /100.0f; if (ttt < 0.0f) ttt = 0.0f;}
	DrawFont(SizeI, Y2, 0, 0, 0, ttt*MenuContentTransp, GetText("10_Bernd_Dau"));
	Y1 += Offset1;
	Y2 += Offset1;
	SizeI = (Setup.iAspectRatioWidth-FontSize(GetText("10_Ryan_Foster")))/2;
	if (Y2 > 300) {ttt = (650 - Y2) /100.0f; if (ttt > 1.0f) ttt = 1.0f;}
	else {ttt = (Y2 - 100) /100.0f; if (ttt < 0.0f) ttt = 0.0f;}
	DrawFont(SizeI, Y2, 0, 0, 0, ttt*MenuContentTransp, GetText("10_Ryan_Foster"));
	Y1 += Offset1;
	Y2 += Offset1;
	SizeI = (Setup.iAspectRatioWidth-FontSize(GetText("10_Jason_Crowell")))/2;
	if (Y2 > 300) {ttt = (650 - Y2) /100.0f; if (ttt > 1.0f) ttt = 1.0f;}
	else {ttt = (Y2 - 100) /100.0f; if (ttt < 0.0f) ttt = 0.0f;}
	DrawFont(SizeI, Y2, 0, 0, 0, ttt*MenuContentTransp, GetText("10_Jason_Crowell"));


	Y1 += Offset2;
	Y2 += Offset2;
	SizeI = (Setup.iAspectRatioWidth-FontSize(GetText("10_SPECIAL_THANKS_TO")))/2;
	if (Y1 > 300) {ttt = (650 - Y1) /100.0f; if (ttt > 1.0f) ttt = 1.0f;}
	else {ttt = (Y1 - 100) /100.0f; if (ttt < 0.0f) ttt = 0.0f;}
	DrawFont(SizeI, Y1, 0, 0, 1, ttt*MenuContentTransp, GetText("10_SPECIAL_THANKS_TO"));
	// система частиц + хорошие объяснения позволили быстро сделать свою
	SizeI = (Setup.iAspectRatioWidth-FontSize(GetText("10_Richard_Benson")))/2;
	if (Y2 > 300) {ttt = (650 - Y2) /100.0f; if (ttt > 1.0f) ttt = 1.0f;}
	else {ttt = (Y2 - 100) /100.0f; if (ttt < 0.0f) ttt = 0.0f;}
	DrawFont(SizeI, Y2, 0, 0, 0, ttt*MenuContentTransp, GetText("10_Richard_Benson"));
	Y1 += Offset1;
	Y2 += Offset1;
	// помогал с железом
	SizeI = (Setup.iAspectRatioWidth-FontSize(GetText("10_Alexey_Madalinskiy")))/2;
	if (Y2 > 300) {ttt = (650 - Y2) /100.0f; if (ttt > 1.0f) ttt = 1.0f;}
	else {ttt = (Y2 - 100) /100.0f; if (ttt < 0.0f) ttt = 0.0f;}
	DrawFont(SizeI, Y2, 0, 0, 0, ttt*MenuContentTransp, GetText("10_Alexey_Madalinskiy"));
	Y1 += Offset1;
	Y2 += Offset1;
	SizeI = (Setup.iAspectRatioWidth-FontSize(GetText("10_Olga_Zhuravleva")))/2;
	if (Y2 > 300) {ttt = (650 - Y2) /100.0f; if (ttt > 1.0f) ttt = 1.0f;}
	else {ttt = (Y2 - 100) /100.0f; if (ttt < 0.0f) ttt = 0.0f;}
	DrawFont(SizeI, Y2, 0, 0, 0, ttt*MenuContentTransp, GetText("10_Olga_Zhuravleva"));
	Y1 += Offset1;
	Y2 += Offset1;
	// выбор названия игры
	SizeI = (Setup.iAspectRatioWidth-FontSize(GetText("10_Nick_OConnell")))/2;
	if (Y2 > 300) {ttt = (650 - Y2) /100.0f; if (ttt > 1.0f) ttt = 1.0f;}
	else {ttt = (Y2 - 100) /100.0f; if (ttt < 0.0f) ttt = 0.0f;}
	DrawFont(SizeI, Y2, 0, 0, 0, ttt*MenuContentTransp, GetText("10_Nick_OConnell"));




	Y1 += Offset2+10;
	Y2 += Offset2+10;
	SizeI = (Setup.iAspectRatioWidth-FontSize(GetText("10_POWERED_BY")))/2;
	if (Y1 > 300) {ttt = (650 - Y1) /100.0f; if (ttt > 1.0f) ttt = 1.0f;}
	else {ttt = (Y1 - 100) /100.0f; if (ttt < 0.0f) ttt = 0.0f;}
	DrawFont(SizeI, Y1, 0, 0, 1, ttt*MenuContentTransp, GetText("10_POWERED_BY"));

	int LogoX = Setup.iAspectRatioWidth/2 - 222;
	int LogoTextX = Setup.iAspectRatioWidth/2 - 72;

	// SDL
	Y1 += Offset1-20;
	Y2 += Offset1-20;
	SetRect(&SrcRest,0,0,128,64);
	SetRect(&DstRest,LogoX,Y2,LogoX+128,Y2+64);
	if (Y2 > 300) {ttt = (650 - Y2) /100.0f; if (ttt > 1.0f) ttt = 1.0f;}
	else {ttt = (Y2 - 100) /100.0f; if (ttt < 0.0f) ttt = 0.0f;}
	vw_DrawTransparent(&DstRest, &SrcRest, vw_FindTextureByName("DATA/CREDITS/sdl.tga"), true, ttt*MenuContentTransp);

	if (Y2 > 300) {ttt = (650 - Y2) /100.0f; if (ttt > 1.0f) ttt = 1.0f;}
	else {ttt = (Y2 - 100) /100.0f; if (ttt < 0.0f) ttt = 0.0f;}
	DrawFont(LogoTextX, Y2+5, 0, 0, 0, ttt*MenuContentTransp, "Simple DirectMedia Layer");
	Y1 += Offset1;
	Y2 += Offset1;
	if (Y2 > 300) {ttt = (650 - Y2) /100.0f; if (ttt > 1.0f) ttt = 1.0f;}
	else {ttt = (Y2 - 100) /100.0f; if (ttt < 0.0f) ttt = 0.0f;}
	DrawFont(LogoTextX, Y2+5, 0, 0, 0, ttt*MenuContentTransp, "http://www.libsdl.org");


	// OpenGL
	Y1 += Offset1+20;
	Y2 += Offset1+20;
	SetRect(&SrcRest,0,0,128,64);
	SetRect(&DstRest,LogoX,Y2,LogoX+128,Y2+64);
	if (Y2 > 300) {ttt = (650 - Y2) /100.0f; if (ttt > 1.0f) ttt = 1.0f;}
	else {ttt = (Y2 - 100) /100.0f; if (ttt < 0.0f) ttt = 0.0f;}
	vw_DrawTransparent(&DstRest, &SrcRest, vw_FindTextureByName("DATA/CREDITS/opengl.tga"), true, ttt*MenuContentTransp);

	if (Y2 > 300) {ttt = (650 - Y2) /100.0f; if (ttt > 1.0f) ttt = 1.0f;}
	else {ttt = (Y2 - 100) /100.0f; if (ttt < 0.0f) ttt = 0.0f;}
	DrawFont(LogoTextX, Y2+5, 0, 0, 0, ttt*MenuContentTransp, "Open Graphics Library");
	Y1 += Offset1;
	Y2 += Offset1;
	if (Y2 > 300) {ttt = (650 - Y2) /100.0f; if (ttt > 1.0f) ttt = 1.0f;}
	else {ttt = (Y2 - 100) /100.0f; if (ttt < 0.0f) ttt = 0.0f;}
	DrawFont(LogoTextX, Y2+5, 0, 0, 0, ttt*MenuContentTransp, "http://www.opengl.org");


	// OpenAL
	Y1 += Offset1+20;
	Y2 += Offset1+20;
	SetRect(&SrcRest,0,0,128,64);
	SetRect(&DstRest,LogoX,Y2,LogoX+128,Y2+64);
	if (Y2 > 300) {ttt = (650 - Y2) /100.0f; if (ttt > 1.0f) ttt = 1.0f;}
	else {ttt = (Y2 - 100) /100.0f; if (ttt < 0.0f) ttt = 0.0f;}
	vw_DrawTransparent(&DstRest, &SrcRest, vw_FindTextureByName("DATA/CREDITS/openal.tga"), true, ttt*MenuContentTransp);

	if (Y2 > 300) {ttt = (650 - Y2) /100.0f; if (ttt > 1.0f) ttt = 1.0f;}
	else {ttt = (Y2 - 100) /100.0f; if (ttt < 0.0f) ttt = 0.0f;}
	DrawFont(LogoTextX, Y2+5, 0, 0, 0, ttt*MenuContentTransp, "Open Audio Library");
	Y1 += Offset1;
	Y2 += Offset1;
	if (Y2 > 300) {ttt = (650 - Y2) /100.0f; if (ttt > 1.0f) ttt = 1.0f;}
	else {ttt = (Y2 - 100) /100.0f; if (ttt < 0.0f) ttt = 0.0f;}
	DrawFont(LogoTextX, Y2+5, 0, 0, 0, ttt*MenuContentTransp, "http://www.openal.org");


	// TinyXML
	Y1 += Offset1+20;
	Y2 += Offset1+20;
	SetRect(&SrcRest,0,0,128,64);
	SetRect(&DstRest,LogoX,Y2,LogoX+128,Y2+64);
	if (Y2 > 300) {ttt = (650 - Y2) /100.0f; if (ttt > 1.0f) ttt = 1.0f;}
	else {ttt = (Y2 - 100) /100.0f; if (ttt < 0.0f) ttt = 0.0f;}
	vw_DrawTransparent(&DstRest, &SrcRest, vw_FindTextureByName("DATA/CREDITS/tinyxml.tga"), true, ttt*MenuContentTransp);

	if (Y2 > 300) {ttt = (650 - Y2) /100.0f; if (ttt > 1.0f) ttt = 1.0f;}
	else {ttt = (Y2 - 100) /100.0f; if (ttt < 0.0f) ttt = 0.0f;}
	DrawFont(LogoTextX, Y2+5, 0, 0, 0, ttt*MenuContentTransp, "TinyXml C++ XML parser");
	Y1 += Offset1;
	Y2 += Offset1;
	if (Y2 > 300) {ttt = (650 - Y2) /100.0f; if (ttt > 1.0f) ttt = 1.0f;}
	else {ttt = (Y2 - 100) /100.0f; if (ttt < 0.0f) ttt = 0.0f;}
	DrawFont(LogoTextX, Y2+5, 0, 0, 0, ttt*MenuContentTransp, "http://tinyxml.sourceforge.net");




	Y1 += Offset2+10;
	Y2 += Offset2+10;
	SizeI = (Setup.iAspectRatioWidth-FontSize(GetText("10_DEVELOPED_WITH")))/2;
	if (Y1 > 300) {ttt = (650 - Y1) /100.0f; if (ttt > 1.0f) ttt = 1.0f;}
	else {ttt = (Y1 - 100) /100.0f; if (ttt < 0.0f) ttt = 0.0f;}
	DrawFont(SizeI, Y1, 0, 0, 1, ttt*MenuContentTransp, GetText("10_DEVELOPED_WITH"));

	// Code::Blocks
	Y1 += Offset1-20;
	Y2 += Offset1-20;
	SetRect(&SrcRest,0,0,64,64);
	SetRect(&DstRest,LogoX+32,Y2,LogoX+32+64,Y2+64);
	if (Y2 > 300) {ttt = (650 - Y2) /100.0f; if (ttt > 1.0f) ttt = 1.0f;}
	else {ttt = (Y2 - 100) /100.0f; if (ttt < 0.0f) ttt = 0.0f;}
	vw_DrawTransparent(&DstRest, &SrcRest, vw_FindTextureByName("DATA/CREDITS/codeblocks.tga"), true, ttt*MenuContentTransp);

	if (Y2 > 300) {ttt = (650 - Y2) /100.0f; if (ttt > 1.0f) ttt = 1.0f;}
	else {ttt = (Y2 - 100) /100.0f; if (ttt < 0.0f) ttt = 0.0f;}
	DrawFont(LogoTextX, Y2+5, 0, 0, 0, ttt*MenuContentTransp, "Code::Blocks IDE");
	Y1 += Offset1;
	Y2 += Offset1;
	if (Y2 > 300) {ttt = (650 - Y2) /100.0f; if (ttt > 1.0f) ttt = 1.0f;}
	else {ttt = (Y2 - 100) /100.0f; if (ttt < 0.0f) ttt = 0.0f;}
	DrawFont(LogoTextX, Y2+5, 0, 0, 0, ttt*MenuContentTransp, "http://www.codeblocks.org");


	// gcc
	Y1 += Offset1+20;
	Y2 += Offset1+20;
	SetRect(&SrcRest,0,0,64,64);
	SetRect(&DstRest,LogoX+32,Y2,LogoX+32+64,Y2+64);
	if (Y2 > 300) {ttt = (650 - Y2) /100.0f; if (ttt > 1.0f) ttt = 1.0f;}
	else {ttt = (Y2 - 100) /100.0f; if (ttt < 0.0f) ttt = 0.0f;}
	vw_DrawTransparent(&DstRest, &SrcRest, vw_FindTextureByName("DATA/CREDITS/gnugcc.tga"), true, ttt*MenuContentTransp);

	if (Y2 > 300) {ttt = (650 - Y2) /100.0f; if (ttt > 1.0f) ttt = 1.0f;}
	else {ttt = (Y2 - 100) /100.0f; if (ttt < 0.0f) ttt = 0.0f;}
	DrawFont(LogoTextX, Y2+5, 0, 0, 0, ttt*MenuContentTransp, "GNU GCC Compiler Collection");
	Y1 += Offset1;
	Y2 += Offset1;
	if (Y2 > 300) {ttt = (650 - Y2) /100.0f; if (ttt > 1.0f) ttt = 1.0f;}
	else {ttt = (Y2 - 100) /100.0f; if (ttt < 0.0f) ttt = 0.0f;}
	DrawFont(LogoTextX, Y2+5, 0, 0, 0, ttt*MenuContentTransp, "http://gcc.gnu.org");


	// cvs
	Y1 += Offset1+20;
	Y2 += Offset1+20;
	SetRect(&SrcRest,0,0,64,64);
	SetRect(&DstRest,LogoX+32,Y2,LogoX+32+64,Y2+64);
	if (Y2 > 300) {ttt = (650 - Y2) /100.0f; if (ttt > 1.0f) ttt = 1.0f;}
	else {ttt = (Y2 - 100) /100.0f; if (ttt < 0.0f) ttt = 0.0f;}
	vw_DrawTransparent(&DstRest, &SrcRest, vw_FindTextureByName("DATA/CREDITS/cvs.tga"), true, ttt*MenuContentTransp);

	if (Y2 > 300) {ttt = (650 - Y2) /100.0f; if (ttt > 1.0f) ttt = 1.0f;}
	else {ttt = (Y2 - 100) /100.0f; if (ttt < 0.0f) ttt = 0.0f;}
	DrawFont(LogoTextX, Y2+5, 0, 0, 0, ttt*MenuContentTransp, "Concurrent Versions System");
	Y1 += Offset1;
	Y2 += Offset1;
	if (Y2 > 300) {ttt = (650 - Y2) /100.0f; if (ttt > 1.0f) ttt = 1.0f;}
	else {ttt = (Y2 - 100) /100.0f; if (ttt < 0.0f) ttt = 0.0f;}
	DrawFont(LogoTextX, Y2+5, 0, 0, 0, ttt*MenuContentTransp, "http://www.cvshome.org");


	// ubuntu
	Y1 += Offset1+20;
	Y2 += Offset1+20;
	SetRect(&SrcRest,0,0,64,64);
	SetRect(&DstRest,LogoX+32,Y2,LogoX+32+64,Y2+64);
	if (Y2 > 300) {ttt = (650 - Y2) /100.0f; if (ttt > 1.0f) ttt = 1.0f;}
	else {ttt = (Y2 - 100) /100.0f; if (ttt < 0.0f) ttt = 0.0f;}
	vw_DrawTransparent(&DstRest, &SrcRest, vw_FindTextureByName("DATA/CREDITS/ubuntu.tga"), true, ttt*MenuContentTransp);

	if (Y2 > 300) {ttt = (650 - Y2) /100.0f; if (ttt > 1.0f) ttt = 1.0f;}
	else {ttt = (Y2 - 100) /100.0f; if (ttt < 0.0f) ttt = 0.0f;}
	DrawFont(LogoTextX, Y2+5, 0, 0, 0, ttt*MenuContentTransp, "Ubuntu GNU/Linux OS");
	Y1 += Offset1;
	Y2 += Offset1;
	if (Y2 > 300) {ttt = (650 - Y2) /100.0f; if (ttt > 1.0f) ttt = 1.0f;}
	else {ttt = (Y2 - 100) /100.0f; if (ttt < 0.0f) ttt = 0.0f;}
	DrawFont(LogoTextX, Y2+5, 0, 0, 0, ttt*MenuContentTransp, "http://www.ubuntu.com");



	// логотип и копирайт
	Y1 += Offset2+30;
	Y2 += Offset2+30;
	SizeI = (Setup.iAspectRatioWidth-FontSize("Copyright 2007, Viewizard"))/2;
	if (Y2 > 300) {ttt = (650 - Y2) /100.0f; if (ttt > 1.0f) ttt = 1.0f;}
	else {ttt = (Y2 - 100) /100.0f; if (ttt < 0.0f) ttt = 0.0f;}
	DrawFont(SizeI, Y2, 0, 0, 0, ttt*MenuContentTransp, "Copyright 2007, Viewizard");
	Y1 += Offset1;
	Y2 += Offset1;
	SizeI = (Setup.iAspectRatioWidth-FontSize("http://www.viewizard.com"))/2;
	if (Y2 > 300) {ttt = (650 - Y2) /100.0f; if (ttt > 1.0f) ttt = 1.0f;}
	else {ttt = (Y2 - 100) /100.0f; if (ttt < 0.0f) ttt = 0.0f;}
	DrawFont(SizeI, Y2, 0, 0, 0, ttt*MenuContentTransp, "http://www.viewizard.com");






	int	X = Setup.iAspectRatioWidth/2 - 256 - 38;
	int Y = 165+100*5;

	if (DrawButton256(X,Y, GetText("1_MAIN_MENU"), MenuContentTransp, &Button10Transp, &LastButton10UpdateTime))
	{
		ComBuffer = MAIN_MENU;
	}
	X = Setup.iAspectRatioWidth/2 + 38;
	if (DrawButton256(X,Y, GetText("1_DONATE"), MenuContentTransp, &Button11Transp, &LastButton11UpdateTime))
	{
		// нужно свернуть игру, запустить броузер и выйти в основное меню
		SDL_WM_IconifyWindow();

#ifdef EN
		vw_OpenBrouser("http://www.viewizard.com/astromenace/donors.php");
#endif
#ifdef DE
		vw_OpenBrouser("http://www.viewizard.com/de/astromenace/donors.php");
#endif
#ifdef RU
		vw_OpenBrouser("http://www.viewizard.com/ru/astromenace/donors.php");
#endif

		ComBuffer = MAIN_MENU;
	}

}
