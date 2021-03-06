

#include <gal/console/base.hpp>
#include <gal/console/backend/python.hpp>
#include <gal/console/backend/PythonStdIoRedirect.hpp>

typedef gal::console::backend::python THIS;

void			THIS::init(parent_t * const & parent)
{
	init_verb(parent->get_vr());

	setParent(parent);

	parent->prompt_end_ = ">>> ";

	// startup
	Py_Initialize();

	main_module_ = boost::python::import("__main__");
	main_namespace_ = main_module_.attr("__dict__");


	// expose redirect class
	main_namespace_["PythonStdIoRedirect"] = bp::class_<PythonStdIoRedirect>("PythonStdIoRedirect", bp::init<>())
		.def("write", &PythonStdIoRedirect::Write);

	// set redirect
	PythonStdIoRedirect python_stdio_redirector;
	bp::import("sys").attr("stderr") = python_stdio_redirector;
	bp::import("sys").attr("stdout") = python_stdio_redirector;

}
void			THIS::release()
{
}
void			THIS::exec_file(std::string filename)
{
	auto parent = getParent();

	try {
		bp::exec_file(
				filename.c_str(),
				main_namespace_,
				main_namespace_);
	} catch(bp::error_already_set const &) {

		PyErr_Clear();

		PyErr_Print();
	}

	auto output = PythonStdIoRedirect::GetOutputContainer();

	for(auto it = output.begin(); it != output.end(); ++it)
		parent->write_line(*it);//.insert(lines_.end(), output.begin(), output.end());
}
void			THIS::eval(std::string const & s)
{
	auto parent = getParent();

	bp::object o;
	try {
		o = bp::eval(s.c_str(), main_namespace_);

		if(!o.is_none()) {
			main_namespace_["temp_obj"] = o;
			bp::exec("print temp_obj", main_namespace_);
		}
	} catch(bp::error_already_set const &) {

		PyErr_Clear();

		//PyErr_Print();

		try {
			o = bp::exec(s.c_str(), main_namespace_, bp::object());
		} catch(bp::error_already_set const &) {
			PyErr_Print();
		}
		
		PyErr_Print();
	}

	auto output = PythonStdIoRedirect::GetOutputContainer();

	for(auto it = output.begin(); it != output.end(); ++it)
		parent->write_line(*it);//.insert(lines_.end(), output.begin(), output.end());

}


