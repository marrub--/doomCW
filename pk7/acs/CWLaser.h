#library "CWLaser"

script "CW_LASER" ENTER
{
	if((CheckInventory("PistolLaz") && CheckWeapon("CPistol")) || (CheckInventory("ShotgunLaz") && CheckWeapon("CShotgun")))
	{
		int ang = GetActorAngle(0);
		int pit = GetActorPitch(0);
		LineAttack(0, ang, pit, 0, "LaserPointer", "NoDam", INT_MAX, FHF_NORANDOMPUFFZ);
	}
	delay(1);
	restart;
}

