
#include <gal/console/backend/python.hpp>
#include <gal/console/frontend/stdio.hpp>

class console:
	virtual public gal::std::term::python,
	virtual public gal::console::frontend::stdio
{};

int main() {

	auto t = sp::make_shared<console>();

	t->init();

	//t->push('h');

	//t->enter();

	t->loop();

}

