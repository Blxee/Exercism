#include "resistor_color_trio.h"

resistor_value_t color_code(resistor_band_t bands[3])
{
	static const unit_t s_units[] = { GIGAOHMS, MEGAOHMS, KILOOHMS, OHMS };
	resistor_value_t res = {0};
	int i;

	res.value = (bands[0] * 10 + bands[1]) * powl(10, bands[2]);
	res.unit = OHMS;

	i = 0;
	while (i < (int)(sizeof(s_units) / sizeof(*s_units)) && res.value)
	{
		res.unit = s_units[i];

		if (res.value % res.unit == 0)
			break;
		i++;
	}
	res.value /= res.unit;
	return (res);
}
