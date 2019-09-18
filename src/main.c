#include <stdlib.h>
#include "app.h"

int	main(void)
{
	t_app	app;

	app_make(&app, 1280, 720);
	app_run(&app);
	return (EXIT_SUCCESS);
}
