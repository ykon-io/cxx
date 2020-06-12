namespace cxx
{
    template<typename T>
    class integer
    {
        public:

            static integer<T> random();
            static integer<T> min();
            static integer<T> max();

        private:

           T value;
    };

    /* 
    i8
    i16
    i32
    i64
    i128
    
    u8
    u16
    u32
    u64
    u128
    */
}