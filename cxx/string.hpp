namespace cxx 
{
    class String {
        public:

            template<typename ... Args>
            static String format(const char * text, Args ... args) {
                return {};
            }
    };
}