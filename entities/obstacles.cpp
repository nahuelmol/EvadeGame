class Block {
    public:
        float pos_x;
        float pos_y;

        float width;
        float height;

        bool new_block = false;

        u32 color = COLOR_BLUE; 
};

class SideBlock: public Block {};
class LivingBlock: public Block {};
