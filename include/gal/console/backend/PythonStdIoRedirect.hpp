#ifndef PYTHONSTDIOREDIRECT_HPP
#define PYTHONSTDIOREDIRECT_HPP

#include <string>
#include <vector>
#include <sstream>

class PythonStdIoRedirect {
	public:
		typedef std::stringstream ContainerType;
		void					Write( std::string const& str );
		static std::string			GetOutput();
		static std::vector< std::string >	GetOutputContainer();
	private:
		static ContainerType		m_outputs;
};


#endif


