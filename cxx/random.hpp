namespace cxx
{
    class Randomizer
    {
        public:

            static Randomizer & instance(); // thread local

            Randomizer();
            Randomizer & seed();
            Randomizer & mersenne();
            // draw(Uniform)

        private:

    };

    struct Random
    {
        class Generator
        {
            public:

                Generator & instance();
                Generator & seed();

            private:
        };
        
        class Distribution
        {

        };
    
        void seed();
    };
}