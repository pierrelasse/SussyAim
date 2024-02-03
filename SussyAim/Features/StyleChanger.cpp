#include "StyleChanger.h"

namespace StyleChanger 
{
	void UpdateSkin(int Skin) noexcept
	{
		switch (Skin) {
		case 0:
			Styles::Style1();
			break;
		case 1:
			Styles::Style2();
			break;
		default:
			break;
		}
	}
}
