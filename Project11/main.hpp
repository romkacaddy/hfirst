#pragma once

#include <Windows.h>

class CWeaponInfo {
public:
	char pad00[0x18];
	struct
	{
		unsigned int bCanAim : 1;
		unsigned int bAimWithArm : 1;
		unsigned int b1stPerson : 1;
		unsigned int bOnlyFreeAim : 1;
		unsigned int bMoveAim : 1; // can move when aiming
		unsigned int bMoveFire : 1; // can move when firing
		unsigned int b06 : 1; // this bitfield is not used
		unsigned int b07 : 1; // this bitfield is not used
		unsigned int bThrow : 1;
		unsigned int bHeavy : 1; // can't run fast with this weapon
		unsigned int bContinuosFire : 1;
		unsigned int bTwinPistol : 1;
		unsigned int bReload : 1; // this weapon can be reloaded
		unsigned int bCrouchFire : 1; // can reload when crouching
		unsigned int bReload2Start : 1; // reload directly after firing
		unsigned int bLongReload : 1;
		unsigned int bSlowdown : 1;
		unsigned int bRandSpeed : 1;
		unsigned int bExpands : 1;
	} m_nFlags;
};

unsigned long* FindPlayerPed(int playerId)
{
	return ((unsigned long* (__cdecl*)(int))0x56E210)(playerId);
}

char GetWeaponSkill(unsigned long* cPed, int weaponType)
{
	return ((char(__thiscall*)(unsigned long*, int))0x5E3B60)(cPed, weaponType);
}

CWeaponInfo* GetWeaponInfo(int weaponType, unsigned char skill)
{
	return ((CWeaponInfo * (__cdecl*)(int, unsigned char))0x743C60)(weaponType, skill);
}