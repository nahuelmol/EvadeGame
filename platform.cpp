enum {
    BUTTON_I,
    BUTTON_J,
    BUTTON_K,
    BUTTON_L,

    BUTTON_EN,
};

struct Button_State {
	bool is_down = false;
	bool changed = false;
};

class MoveBehavior {
    public:
        virtual void move() const = 0; 
};

class Side: public MoveBehavior {
    public:
        void move() const override {
            std::cout << "moving side-to-side" << std::endl;
        }
};

class UpDown: public MoveBehavior {
    public:
        void move() const override {
            std::cout << "moving up-to-down" << std::endl;
        }
};

class Attack {
    public:
        virtual void attack() const = 0;
};

class Shooting: public Attack {
    public:
        void attack() const override {
            std::cout << "shooting" << std::endl;
        }
};

class Enemy {
    public:
        
        Button_State buttons[BUTTON_EN];
        
        float pos_x;
        float pos_y;
        float width;
        float height;
        
        std::string name;
        int id;

        MoveBehavior* moveBehavior;
        Attack* attackBehavior;

    public:
        void performMove(){
            moveBehavior->move();
        }

        void performAttack(){
            attackBehavior->attack();
        }

        void setNewMove(MoveBehavior* mb){
            moveBehavior = mb;
        }

        void setNewAttack(Attack* att){
            attackBehavior = att;
        }
        
        void setID(int id){
            this->id = id;
            this->name = this->name + std::to_string(id);
        }
        
        void setProps(float x, float y, float width, float height){
            this->pos_x= x;
            this->pos_y= y;
            this->width=width;
            this->height=height;
        }
        
        void props(){
            std::cout << this->pos_x << std::endl;
            std::cout << this->pos_y << std::endl;
            std::cout << this->width << std::endl;
            std::cout << this->height<< std::endl;
        }
};

class Nova: public Enemy{
    
    public:
        std::string name = "NOVA";
        int id;
    
    public:
        Nova(){
            moveBehavior    = new UpDown();
            attackBehavior  = new Shooting();
        }

        void Hello(){
            std::cout << "Hi, I am nova" << std::endl;
        }

        
};

class Killer: public Enemy {
    public:
        Killer(){
            moveBehavior    = new UpDown();
            attackBehavior  = new Shooting();
        }
};




enum {
	BUTTON_UP,
	BUTTON_DOWN,
	BUTTON_LEFT,
	BUTTON_RIGHT,

	BUTTON_COUNT,
};

struct Input {
	float pos_x = -40;
    float pos_y = 0;
 
    float width = 4;
    float height =4;

    std::string numbuffer = "";

    Button_State buttons[BUTTON_COUNT];
};
