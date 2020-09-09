#include <general/window.h>

int main()
{
	Undead::General::Window wnd(800, 600, "Undead Engine");
	wnd.onUpdate();

	return 0;
}