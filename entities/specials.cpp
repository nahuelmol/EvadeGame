class SpecialEgg {
    public:
        float pos_x;
        float pos_y;

        float lifetime;
        float limit_attempts;
};

class Star: public SpecialEgg {};
class PhilosopherStone: public SpecialEgg {};
