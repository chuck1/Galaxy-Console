#include <cstdio>

#include <gal/console/backend/PythonStdIoRedirect.hpp>

typedef gal::console::backend::PythonStdIoRedirect THIS;

THIS::ContainerType THIS::m_outputs;

void				THIS::Write(std::string const& str)
{
	printf("%s: \"%s\"\n", __PRETTY_FUNCTION__, str.c_str());

	m_outputs << str;

	//if (m_outputs.capacity()<100)
	//	m_outputs.resize(100);
	/*
	   if(m_outputs.empty()) {
	   m_outputs.push_back(str);
	   return;
	   }

	   if(m_outputs.back().back() == '\n') {
	   m_outputs.push_back(str);
	   return;
	   }*/


}
std::string			THIS::GetOutput()
{
	std::string ret;

	ret =  m_outputs.str();


	m_outputs.clear();
	return ret;
}
std::vector<std::string>	THIS::GetOutputContainer()
{

	std::vector< std::string > ret;

	std::string token;

	while(std::getline(m_outputs, token, '\n')) {
		ret.push_back(token);
	}

	m_outputs.clear();
	return ret;
}

