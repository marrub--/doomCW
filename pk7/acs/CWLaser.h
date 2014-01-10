#library "CWLaser"

script "CW_LASER" ENTER
{
	while(1)
	{
		if(CheckInventory("PistolLaz") && (CheckWeapon("CPistol")||CheckWeapon("CPistolSil")))
		{
			int a = GetActorAngle(0);
			int p = GetActorPitch(0);
			LineAttack(0, a, p, 0, "LaserPointer", "NoDam", INT_MAX, FHF_NORANDOMPUFFZ);
		}
		delay(1);
	}
}