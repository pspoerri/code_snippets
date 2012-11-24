#include <boost/python.hpp>
char const* greet() {
    return "Hello world from C ;) \n";
}

BOOST_PYTHON_MODULE(libhello_ext)
{
    using namespace boost::python;
    def("greet", greet);
}
